/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arvoreb;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author meira
 */
public class Main {

    /**
     * @param args the command line arguments
     */

     void executa1() {
        ArvoreB t = new ArvoreB(4);
        ArrayList<Integer> aux = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            aux.add(i);
        }
        Collections.shuffle(aux);
        for (int i = 0; i < aux.size(); i++) {
            System.out.println("inseriu [" + aux.get(i) + "]");
            t.add(aux.get(i));
            System.out.println("" + t);
            System.out.println("SIZE:" + t.size());
            System.out.println("ALTURA:" + t.altura());
        }
        t.toXML();
    }

     void executa2() {
        int n = 10 * 1000;
        ArvoreB t = new ArvoreB(4);
        ArrayList<Integer> aux = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            aux.add(i);
        }
        Collections.shuffle(aux);
        for (int i = 0; i < aux.size(); i++) {
            t.add(aux.get(i));
        }
        System.out.println("" + t.size());
        System.out.println("" + t.altura());
        t.toXML();

    }

    public void ordena(ArrayList<Integer> l) {
        ArvoreB t = new ArvoreB(6);
        for (int i = 0; i < l.size(); i++) {
            t.add(l.get(i));
        }
        l.clear();
        t.percurso(l);
    }

     void executa3() {
        //ArvoreB t = new ArvoreB(4);
        ArrayList<Integer> aux = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            aux.add(i);
        }
        Collections.shuffle(aux);
        System.out.println(""+aux);
        ordena(aux);
         System.out.println(""+aux);
    }

     
      void executa4() {
        int n = 1000*1000;
        ArrayList<Integer> aux = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            aux.add(i);
        }
        Collections.shuffle(aux);
        for(int i=0;i<20;i++){
            System.out.print(","+aux.get(i));
        }
          System.out.println("");
        ordena(aux);
        for(int i=0;i<20;i++){
            System.out.print(","+aux.get(i));
        }
        System.out.println("");
    }
     
    public static void main2(String[] args) {

        Main m = new Main();

        m.executa1();
        m.executa2();
        //m.executa3();
        //m.executa4();

    }

}
