import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

//0000 0000 -->ram begin
//...
//9FFF FFFF -->ram end
//A000 0000 -->gm begin
//...
//AFFF FFFF -->gm end

public class MMU {
	private final int mem0000Size = 8096;
	private final int memA000Size = 8096;
	private final int memB000Size = 8096;
	private final int memD000Size = 8096;
	private char mem0000[] = new char[mem0000Size];
	private char memA000[] = new char[memA000Size];
	private char memB000[] = new char[memB000Size];
	private char memD000[] = new char[memD000Size];
	private RandomAccessFile vhd;

	MMU() {
		int i;
//		for (i = 0; i < mem0000Size; i++) {
//			mem0000[i] = 0;
//			memA000[i] = 0;
//			memB000[i] = 0;
//			memD000[i] = 0;
//		}
		try {
			vhd = new RandomAccessFile("0.vhd", "rw");
		} catch (FileNotFoundException e) {
			vhd = null;
			e.printStackTrace();
		}
	}

	public int getSegment(int addr) {
		return (addr >> 16) & 0xFFFF;
	}

	private int getAddr(int addr) {
		return addr & 0xFFFF;
	}

	public char memReadByte(int addr) {
		int seg = getSegment(addr);
		int adr = getAddr(addr);
		if (seg < 0xA000) {
			return this.mem0000[adr];
		} else if (seg == 0xA000) {
			return this.memA000[adr];
		} else if (seg == 0xB000) {
			return this.memD000[adr];
		} else if (seg == 0xD000) {
			if (adr == 0x202) {
				readSector(memD000[0x200]);
			}
			return (char)(this.memD000[adr]&0x00FF);
		} else {
			return 0;
		}
	}

	public void memWriteByte(int addr, char data) {
		int seg = getSegment(addr);
		int adr = getAddr(addr);
		if (seg < 0xA000) {
			this.mem0000[adr] = data;
		} else if (seg == 0xA000) {
			this.memA000[adr] = data;
		} else if (seg == 0xB000) {
			this.memB000[adr] = data;
		} else if (seg == 0xD000) {
			if (adr == 0x202) {
				writeSector(memD000[0x200]);
			}
			this.memD000[adr] = data;
		} else {
			// hehe
		}
	}

	public int memReadWord(int addr) {
		int seg = getSegment(addr);
		int adr = getAddr(addr);
		int low = 0;
		int high = 0;
		if (seg < 0xA000) {
			low = this.mem0000[adr];
			high = this.mem0000[adr + 1];
			return (high << 16) | low;
		} else if (seg == 0xA000) {
			low = this.memA000[adr];
			high = this.memA000[adr + 1];
			return (high << 16) | low;
		} else if (seg == 0xB000) {
			low = this.memB000[adr];
			high = this.memB000[adr + 1];
			return (high << 16) | low;
		} else if (seg == 0xD000) {
			if (adr == 0x202) {
				readSector(memD000[0x200]);
			}
			low = this.memD000[adr]&0x00FF;
			high = 0;
			return (high << 16) | low;
		} else {
			return 0;
		}
	}

	public void memWriteWord(int addr, int data) {
		int seg = getSegment(addr);
		int adr = getAddr(addr);
		char low = (char) (data & 0xFFFF);
		char high = (char) ((data >> 16) & 0xFFFF);
		if (seg < 0xA000) {
			this.mem0000[adr] = low;
			this.mem0000[adr + 1] = high;
		} else if (seg == 0xA000) {
			this.memA000[adr] = low;
			this.memA000[adr + 1] = high;
		} else if (seg == 0xB000) {
			this.memB000[adr] = low;
			this.memB000[adr + 1] = high;
		} else if (seg == 0xD000) {
			if (adr == 0x202) {
				writeSector(memD000[0x200]);
			}
			this.memD000[adr] = (char) (low&0xFF);
//			this.memD000[adr + 1] = high;
		} else {
			// hehe
		}
	}

	private void readSector(int sec) {
		byte[] win = new byte[512];
		try {
			vhd.seek(512 * sec);
			vhd.read(win, 0, 512);
			for (int i = 0; i < 512; i++) {
				memD000[i] = (char) win[i];
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void writeSector(int sec) {
		byte[] win = new byte[512];
		for (int i = 0; i < 512; i++) {
			win[i] = (byte) memD000[i];
		}
		try {
			vhd.seek(512 * sec);
			vhd.write(win, 0, 512);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}