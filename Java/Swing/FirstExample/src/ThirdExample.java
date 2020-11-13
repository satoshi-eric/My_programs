import javax.swing.*;

public class ThirdExample extends JFrame {
    JFrame frame;
    ThirdExample() {
        JButton button = new JButton("click");
        button.setBounds(130, 100, 100, 40);

        add(button);
        setSize(400, 500);
        setLayout(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        new ThirdExample();
    }
}
