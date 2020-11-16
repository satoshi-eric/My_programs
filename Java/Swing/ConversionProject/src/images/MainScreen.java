package images;

import javax.swing.*;

public class MainScreen {
    JFrame mainScreenFrame;
    JLabel titlelbl;
    JLabel fromlbl;
    JLabel tolbl;
    JLabel equallbl;

    MainScreen() {
        mainScreenFrame = new JFrame("Conversão de Medida");
        titlelbl = new JLabel("Conversão de Medida");
        mainScreenFrame.setBounds(50, 20, 300, 100);

        
        mainScreenFrame.setVisible(true);

        
    }

    public static void main(String[] args) {
        new MainScreen();
    }
}
