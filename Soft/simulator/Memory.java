package tk.zmj1316.CPU;

/**
 * Created by Key on 2015/9/20.
 */
public class Memory {
    private byte [] mem;
    public Memory(){
        mem=new byte[2048];
    }
    public int getWord(int addr){
//        Big-Endian
        return (int)(mem[addr]<<24
                    |mem[addr+1]<<16
                    |mem[addr+2]<<8
                    |mem[addr+3]);
    }
    public void setWord(int addr,int value){
        mem[addr]=(byte)(value>>24&0xFF);
        mem[addr+1]=(byte)(value>>16&0xFF);
        mem[addr+2]=(byte)(value>>8&0xFF);
        mem[addr+3]=(byte)(value&0xFF);
    }
}
