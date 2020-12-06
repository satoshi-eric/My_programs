import javax.swing.*;

public class SecondExample {
    JFrame frame;
    SecondExample() {
        frame = new JFrame();

        JButton button = new JButton("click");
        button.setBounds(130, 100, 100, 40); // posição x e y. largura e altura

        frame.add(button);
        frame.setSize(400, 500);
        frame.setLayout(null);
        frame.setVisible(true);
        
    }

    public static void main(String[] args) {
        new SecondExample();
    }
}
