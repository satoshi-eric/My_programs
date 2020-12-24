package view;

import javax.swing.*;
import java.awt.*;


public class MainWindow {
    private JFrame mainWindowFrame;
    private JMenuBar menuBar;
    private JMenu menuFile;
    private JMenu menuHelp;
    private JMenuItem menuItemExit;
    private JMenuItem menuItemHelp;
    private JMenuItem menuItemDisclaimer;
    private JMenuItem menuItemAbout;

    private void initComponents() {
        mainWindowFrame = new JFrame("Client");
        menuBar = new JMenuBar();
        menuFile = new JMenu("File");
        menuHelp = new JMenu("Help");
        menuItemExit = new JMenuItem("Exit");
        menuItemHelp = new JMenuItem("Help");
        menuItemDisclaimer = new JMenuItem("Disclaimer");
        menuItemAbout = new JMenuItem("About");

        menuFile.add(menuItemExit);
        menuHelp.add(menuItemHelp);
        menuHelp.add(menuItemDisclaimer);
        menuHelp.add(menuItemAbout);
        
        menuBar.add(menuFile);
        menuBar.add(menuHelp);

        mainWindowFrame.setJMenuBar(menuBar);

        mainWindowFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        mainWindowFrame.setBounds(300, 300, 600, 400);
        mainWindowFrame.setVisible(true);
    }

    MainWindow() {
        initComponents();;
    }

    public static void main(String[] args) {
        new MainWindow();
    }
}
