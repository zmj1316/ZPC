import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.Timer;
import java.util.TimerTask;

//import java.io.FileInputStream;
//import java.io.FileOutputStream;

public class Main {
	public static MIPSCPU cpu = new MIPSCPU();
	public static Thread cpuThread=new Thread(cpu);
	public static JFrame screen=new JFrame("Virtual Machine");
	public static JPanel panelRegister=new JPanel();
	public static JPanel panelMsgBox=new JPanel();
	public static GridLayout panelRegLayout=new GridLayout(32, 2);
	public static JLabel[] regLabel=new JLabel[32];
	public static JLabel PCLabel=new JLabel();
	//==========menu==================
	public static JMenuBar menubar;
	public static JMenu menuFile;
	public static JMenuItem menuFileNew;
	public static JMenuItem menuFileOpen;
	public static JMenuItem menuFileSave;
	public static JMenuItem menuFileSaveas;
	public static JMenuItem menuFileExit;
	public static JMenu menuEdit;
	public static JMenu menuShape;
	public static JMenuItem menuShapeLine;
	public static JMenuItem menuShapeRectangle;
	public static JMenuItem menuShapeEllipse;
	public static JMenuItem menuShapeMoji;
	public static JMenu menuHelp;
	public static JMenuItem menuHelpAbout;
	//==========menu==================
	public static FileDialog openDialog;
	public static FileDialog saveDialog;
	//==========file==================
	public static File file;
	public static FileInputStream in;
	public static FileOutputStream out;
	public static String directory;
	public static String fileName;
	//==========file==================
	public static class ClickMenuItem implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			//菜单事件
			String s = e.getActionCommand();
			if (s.equals("New")) {
				
			} else if (s.equals("Open")) {
				openDialog.setVisible(true);
				directory = openDialog.getDirectory();
				fileName = openDialog.getFile();
				if (directory == null || fileName == null)
					return;
				file = new File(directory, fileName);
				try {
					in = new FileInputStream(file);
					byte[] inst = new byte[4];
					int addr=0;
					while (in.read(inst) != -1) {
						int data=0;
						for(int i=0;i<4;i++){
							data|=(((int)inst[i])&0xFF)<<(24-8*i);
						}
						cpu.writeWord(addr, data);
						addr+=2;
					}
					in.close();
					cpuThread.start();
				} catch (FileNotFoundException fnfe) {
					fnfe.printStackTrace();
				} catch (IOException ioe) {
					ioe.printStackTrace();
				}
			} else if (s.equals("Save")) {
				
			} else if (s.equals("Save as")) {
				
			} else if (s.equals("Exit")) {
				screen.dispose();
				System.exit(0);
			} else if (s.equals("About")) {
				JOptionPane.showMessageDialog(screen, "Painter 1.0", "About Painter", JOptionPane.PLAIN_MESSAGE);
			}
		}
		//菜单事件
	}
	
	public static void setMenubar(){
		menubar = new JMenuBar();
		// ================================
		menuFile = new JMenu("File");
		menubar.add(menuFile);
		menuHelp = new JMenu("Help");
		menubar.add(menuHelp);
		// ================================
		menuFileNew = new JMenuItem("New");
		menuFileNew.addActionListener(new ClickMenuItem());
		menuFile.add(menuFileNew);
		menuFileOpen = new JMenuItem("Open");
		menuFileOpen.addActionListener(new ClickMenuItem());
		menuFile.add(menuFileOpen);
		menuFile.add(new JSeparator());
		menuFileSave = new JMenuItem("Save");
		menuFileSave.addActionListener(new ClickMenuItem());
		menuFile.add(menuFileSave);
		menuFileSaveas = new JMenuItem("Save as");
		menuFileSaveas.addActionListener(new ClickMenuItem());
		menuFile.add(menuFileSaveas);
		menuFile.add(new JSeparator());
		menuFileExit = new JMenuItem("Exit");
		menuFileExit.addActionListener(new ClickMenuItem());
		menuFile.add(menuFileExit);
		// ================================
		menuHelpAbout = new JMenuItem("About");
		menuHelpAbout.addActionListener(new ClickMenuItem());
		menuHelp.add(menuHelpAbout);
		// ================================
	}
	
	public static String getRegName(int i){
		switch(i){
		case 0:
			return "$zero";
		case 1:
			return "$at";
		case 2:
		case 3:
			return "$v"+(i-2);
		case 4:
		case 5:
		case 6:
		case 7:
			return "$a"+(i-4);
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			return "$t"+(i-8);
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
			return "$s"+(i-16);
		case 24:
		case 25:
			return "$t"+(i-16);
		case 26:
		case 27:
			return "$k"+(i-26);
		case 28:
			return "$gp";
		case 29:
			return "$sp";
		case 30:
			return "$fp";
		case 31:
			return "$ra";
		default:
			return "$zero";	
		}
	}
	public static void main(String[] args) {
		setMenubar();
		screen.setSize(800, 600);
		screen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		screen.setLocationRelativeTo(null);
		screen.setResizable(false);
		screen.setJMenuBar(menubar);
		screen.setLayout(new BorderLayout(1,1));
		screen.setVisible(true);
		
		panelRegister.setLayout(panelRegLayout);
		panelRegister.setBorder(BorderFactory.createTitledBorder("Registers"));
		panelMsgBox.setLayout(new FlowLayout(FlowLayout.LEFT));
		for(int i=0;i<32;i++){
			panelRegister.add(new JLabel(getRegName(i)));
			regLabel[i]=new JLabel();
			String s=cpu.getRegister(i);
			regLabel[i].setFont(new Font("Courier New",Font.PLAIN, 12));
			regLabel[i].setText(s);
			panelRegister.add(regLabel[i]);
		}
		
		panelMsgBox.add(new JLabel("PC="));
		PCLabel.setText(cpu.getPC());
		panelMsgBox.add(PCLabel);
		screen.getContentPane().add(panelRegister, BorderLayout.WEST);
		screen.getContentPane().add(panelMsgBox, BorderLayout.SOUTH);
		cpu.setBackground(new Color(0, 0, 0));
		cpu.setLayout(new GridLayout(1, 1));
		screen.getContentPane().add(cpu, BorderLayout.CENTER);
		
		openDialog = new FileDialog(screen, "Open", FileDialog.LOAD);
		saveDialog = new FileDialog(screen, "Save", FileDialog.SAVE);
		
		TimerTask refreshReg=new TimerTask() {
			@Override
			public void run() {
				for(int i=0;i<32;i++){
					String s=cpu.getRegister(i);
					regLabel[i].setFont(new Font("Courier New",Font.PLAIN, 12));
					regLabel[i].setText(s);
					panelRegister.revalidate();
				}
				PCLabel.setText(cpu.getPC());
				panelMsgBox.revalidate();
			}
		};
		Timer timerRegister=new Timer();
		timerRegister.schedule(refreshReg, 10, 10);
		//cpuThread.start();
	}
}
