package network;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import java.awt.*;
import java.awt.event.*;

public class GUIServer implements ActionListener {
    private JFrame mainWindow;
    private JTextField addressField;
    private JButton connectButton;

    private void initComponents() {
        mainWindow = new JFrame("Server");
        mainWindow.setBounds(200, 200, 600, 400);
        mainWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        addressField = new JTextField();
        connectButton = new JButton();
        connectButton.addActionListener(this);
        addressField = new JTextField();

        mainWindow.add(addressField);
        mainWindow.add(connectButton);

    }

    public GUIServer() {
        initComponents();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        

    }
}
