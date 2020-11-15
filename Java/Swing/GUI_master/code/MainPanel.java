package code;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

class MainPanel extends JPanel
   {
   private enum LocalShapes
      {
       OVAL,
       RECTANGLE,
       EMPTY
      }
   private static final long serialVersionUID = 1L;
   private Color             foreground;
   private Color             background;

   private LocalShapes       shape;

   MainPanel()
      {
      super();
      shape = LocalShapes.EMPTY;
      }

   @Override
   public void paint(Graphics graphics)
      {
      super.paint(graphics);
      Graphics2D canvas = (Graphics2D) graphics;
      int xPoint = (int) (this.getWidth() * .1);
      int yPoint = (int) (this.getHeight() * .1);
      int width = (int) (this.getWidth() * .8);
      int height = (int) (this.getHeight() * .8);

      switch (shape)
         {
         case OVAL:
            {
            canvas.setColor(foreground);
            canvas.setBackground(background);
            canvas.clearRect(0, 0, this.getWidth(), this.getHeight());
            canvas.fillOval(xPoint, yPoint, width, height);
            }
            break;
         case RECTANGLE:
            {
            canvas.setColor(foreground);
            canvas.setBackground(background);
            canvas.clearRect(0, 0, this.getWidth(), this.getHeight());
            canvas.fillRect(xPoint, yPoint, width, height);
            }
            break;
         default:
            {
            canvas.setColor(Color.black);
            canvas.setBackground(Color.lightGray);
            canvas.clearRect(0, 0, this.getWidth(), this.getHeight());
            }
            break;
         }
      }

   void setFirstAction()
      {
      foreground = Color.blue;
      background = Color.yellow;
      shape = LocalShapes.RECTANGLE;
      this.repaint();
      }

   void setSecondAction()
      {
      foreground = Color.red;
      background = Color.white;
      shape = LocalShapes.OVAL;
      this.repaint();
      }

   }
