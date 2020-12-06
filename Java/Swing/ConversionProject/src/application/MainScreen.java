package application;

import javax.swing.*;

import java.awt.Font;

public class MainScreen {
    JFrame mainWindow;
    JLabel lblTitle;
    JLabel lblFrom;
    JLabel lblTo;
    JLabel lblEqual;
    JLabel lblToOutput;
    JTextField txtFieldFromInput;
    JMenuBar menuBar;
    JMenu menuFile;
    JMenu menuHelp;
    JMenuItem menuItemExit;
    JMenuItem menuItemHelp;
    JMenuItem menuItemAbout;
    JComboBox<String> comboBoxFrom;
    JComboBox<String> comboBoxTo;
    JButton buttonConvert;

    void initLabels() {
        
        lblTitle = new JLabel("Conversão de Medida");
        lblFrom = new JLabel("De:");
        lblTo = new JLabel("Para:");
        lblEqual = new JLabel("=");
        lblToOutput = new JLabel();
        lblEqual = new JLabel("=");
    }

    void configLabels() {

        lblTitle.setFont(new Font("Times New Roman", Font.PLAIN, 36));
        lblTitle.setBounds(230, 50, 400, 50);
        
        lblFrom.setFont(new Font("Times New Roman", Font.PLAIN, 24));
        lblFrom.setBounds(50, 150, 150, 30);
        
        lblTo.setFont(new Font("Times New Roman", Font.PLAIN, 24));
        lblTo.setBounds(450, 150, 150, 30);
        
        lblEqual.setFont(new Font("Times New Roman", Font.PLAIN, 36));
        lblEqual.setBounds(350, 220, 50, 30);

        lblToOutput.setFont(new Font("Times New Roman", Font.PLAIN, 18));
        lblToOutput.setBounds(450, 220, 250, 30);
    }

    void initTxtFields() {
        txtFieldFromInput = new JTextField();
    }

    void configTxtFields() {
        txtFieldFromInput.setFont(new Font("Times New Roman", Font.PLAIN, 18));
        txtFieldFromInput.setBounds(50, 220, 250, 30);
    }

    void initMenus() {
        menuItemExit = new JMenuItem("Exit");
        menuItemHelp = new JMenuItem("Help");
        menuItemAbout = new JMenuItem("About");

        menuFile = new JMenu("File");
        menuHelp = new JMenu("Help");

        menuBar = new JMenuBar();
    }

    void configMenus() {
        menuFile.add(menuItemExit);
        menuHelp.add(menuItemHelp);
        menuHelp.add(menuItemAbout);

    
        menuBar.add(menuFile);
        menuBar.add(menuHelp);
    }

    void initComboBoxes() {
        String itemsFrom[] = {"Item 1", "Item 2"};
        String itemsTo[] = {"Item 1", "Item 2"};
        comboBoxFrom = new JComboBox<>(itemsFrom);
        comboBoxTo = new JComboBox<>(itemsTo);
    }

    void configComboBoxes() {
        comboBoxFrom.setBounds(50, 270, 150, 30);
        comboBoxTo.setBounds(450, 270, 150, 30);
    }

    void initButtons() {
        buttonConvert = new JButton("Converter");
    }

    void configButtons() {
        buttonConvert.setBounds(300, 360, 120, 50);
    }

    void initMainWindow() {
        mainWindow = new JFrame("Conversão de Medida");
    }
    
    void configMainWindow() {
        mainWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainWindow.setBounds(120, 50, 800, 600);

        mainWindow.add(lblTitle);
        mainWindow.add(lblFrom);
        mainWindow.add(lblTo);
        mainWindow.add(lblEqual);
        mainWindow.add(txtFieldFromInput);
        mainWindow.add(lblToOutput);
        mainWindow.add(comboBoxFrom);
        mainWindow.add(comboBoxTo);
        mainWindow.add(buttonConvert);

        mainWindow.setJMenuBar(menuBar);

        mainWindow.setLayout(null);
        mainWindow.setVisible(true);

    }


    MainScreen() {
        // Initialize components
        initLabels();
        initTxtFields();
        initMenus();
        initComboBoxes();
        initButtons();
        initMainWindow();

        // Configuring components
        configLabels();
        configTxtFields();
        configMenus();
        configComboBoxes();
        configButtons();
        configMainWindow();

    }

    /** 
     * TODO:
     * - Adicionar comportamento ao JMenuItem menuItemExit para sair da aplicação.
     * - Adicionar comportamento aos JMenuItems menuItemHelp e menuItemAbout com 2 novas janelas para help e about.
     *  Adicionar comportamento ao JButton buttonConvert para fazer alguma coisa. Essa alguma coisa é para deixar o protótipo pronto para integração com o código das funcionaidades (conversão de unidaes)
     */
    
}
