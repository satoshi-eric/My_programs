package code;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.HeadlessException;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;

class MainWindow extends JFrame implements ActionListener
   {
   private static final long serialVersionUID = 1L;
   private MainPanel         mainPanel;
   private JPanel            statusPanel;
   private JLabel            statusLabel;
   private JMenuBar          menuBar;
   private JMenu             menuFile;
   private JMenu             menuHelp;
   private JMenuItem         menuItemFirst;
   private JMenuItem         menuItemSecond;
   private JMenuItem         menuItemExit;
   private JMenuItem         menuItemHelp;
   private JMenuItem         menuItemDisclaimer;
   private JMenuItem         menuItemAbout;

   MainWindow(String title) throws HeadlessException
      {
      super(title);
      setupWindow();
      setupMenus();
      bindMenus();
      setupExtraComponents();
      setupWindowsListener();
      this.setStatus(Info.getLongVersion());
      }

   @Override
   public void actionPerformed(ActionEvent actionEvent)
      {
      if (actionEvent.getSource() == this.menuItemExit)
         {
         exitSystem();
         }

      if (actionEvent.getSource() == this.menuItemFirst)
         {
         firstAction();
         }

      if (actionEvent.getSource() == this.menuItemSecond)
         {
         secondAction();
         }

      if (actionEvent.getSource() == this.menuItemHelp)
         {
         new MsgScreen(this, "Help for " + Info.getLongVersion(), Info.getHelpText());
         }

      if (actionEvent.getSource() == this.menuItemDisclaimer)
         {
         new MsgScreen(this, "Disclaimer " + Info.getLongVersion(), Info.getDisclaimerText());
         }

      if (actionEvent.getSource() == this.menuItemAbout)
         {
         new MsgScreen(this, "About " + Info.getLongVersion(), Info.getAboutText());
         }
      }

   private void bindItems(ActionListener listener, JMenu menu)
      {
      for (Component target : menu.getMenuComponents())
         {
         if (target instanceof JMenuItem)
            {
            ((JMenuItem) target).addActionListener(this);
            }
         }
      }

   private void bindMenus()
      {
      for (Component target : this.getJMenuBar().getComponents())
         {
         if (target instanceof JMenu)
            {
            bindItems(this, (JMenu) target);
            }
         }
      }

   private JMenu createCustomizedMenu(String label, char shortcut)
      {
      JMenu temp = new JMenu(label);
      temp.setMnemonic(shortcut);
      return (temp);
      }

   private JMenuItem createCustomizedMenuItem(String label, char shortcut)
      {
      JMenuItem temp = new JMenuItem(label);
      temp.setMnemonic(shortcut);
      return (temp);
      }

   void exitSystem()
      {
      System.exit(0);
      }

   private void firstAction()
      {
      mainPanel.setFirstAction();
      }

   void go()
      {
      this.setVisible(true);
      }

   private void secondAction()
      {
      mainPanel.setSecondAction();
      }

   void setStatus(String message)
      {
      statusLabel.setText(message);
      }

   private void setupExtraComponents()
      {
      setupStatusPanel();
      setupMainPanel();
      }

   private void setupMainPanel()
      {
      this.mainPanel = new MainPanel();
      this.mainPanel.setBackground(Color.lightGray);
      this.mainPanel.setBorder(BorderFactory.createEtchedBorder());
      this.add(mainPanel, BorderLayout.CENTER);
      }

   private void setupMenus()
      {
      menuFile = createCustomizedMenu("File", 'F');
      menuHelp = createCustomizedMenu("Help", 'H');

      menuItemFirst = createCustomizedMenuItem("First Action", 'F');
      menuItemSecond = createCustomizedMenuItem("Second Action", 'S');
      menuItemExit = createCustomizedMenuItem("Exit", 'X');

      menuItemHelp = createCustomizedMenuItem("Help", 'L');
      menuItemDisclaimer = createCustomizedMenuItem("Disclaimer", 'D');
      menuItemAbout = createCustomizedMenuItem("About", 'A');

      // First menu
      menuFile.add(menuItemFirst);
      menuFile.add(menuItemSecond);
      menuFile.addSeparator();
      menuFile.add(menuItemExit);

      // Last menu
      menuHelp.add(menuItemHelp);
      menuHelp.add(menuItemDisclaimer);
      menuHelp.addSeparator();
      menuHelp.add(menuItemAbout);

      // JMenuBar
      menuBar = new JMenuBar();
      menuBar.add(menuFile);
      menuBar.add(menuHelp);

      this.setJMenuBar(menuBar);
      }

   private void setupStatusPanel()
      {
      this.statusPanel = new JPanel();
      this.statusLabel = new JLabel();
      this.statusPanel.add(statusLabel);
      this.statusPanel.setBackground(Color.gray);
      this.statusPanel.setBorder(BorderFactory.createEtchedBorder());
      this.add(statusPanel, BorderLayout.SOUTH);
      }

   private void setupWindow()
      {
      this.setSize((int) (Toolkit.getDefaultToolkit().getScreenSize().getWidth() * 0.3), (int) (Toolkit.getDefaultToolkit().getScreenSize().getHeight() * 0.3));
      this.setLocationRelativeTo(null);
      this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      this.setLayout(new BorderLayout(2, 2));
      }

   private void setupWindowsListener()
      {
      this.addWindowListener(new java.awt.event.WindowAdapter()
         {
         @Override
         public void windowClosing(java.awt.event.WindowEvent windowEvent)
            {
            exitSystem();
            }
         });
      }

   }
