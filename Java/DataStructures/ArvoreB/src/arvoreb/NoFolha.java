/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arvoreb;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author meira
 */
public class NoFolha implements INo {

    public static int SIZE;
    List<Integer> l = new ArrayList<>();

    public NoAndValue add(int valor) {
        if (l.isEmpty()) {
            l.add(valor);
            return null;
        }
        if (valor >= l.get(l.size() - 1)) {
            l.add(valor);

        } else {
            int i = 0;
            while (valor > l.get(i)) {
                i++;
            }
            l.add(i, valor);
        }
        if (l.size() <= SIZE) {
            return null;
        }
        return split();

    }

    public NoAndValue split() {
        NoFolha aux = new NoFolha();
        NoAndValue ret = new NoAndValue();
        int meio = SIZE / 2;
        ret.no = aux;
        ret.value = this.l.get(meio);
        aux.l = sublist(l, meio + 1, SIZE + 1);
        this.l = sublist(l, 0, meio);
        return ret;

    }

    public String toString() {
        String ret = "[";
        for (int i = 0; i < l.size(); i++) {
            ret += l.get(i);
            if (i < l.size() - 1) {
                ret += ",";
            }
        }
        ret += "]";

        return ret;
    }

    public static ArrayList<Integer> sublist(List<Integer> x, int start, int end) {
        ArrayList<Integer> novo = new ArrayList<>();
        for (int i = start; i < end; i++) {
            novo.add(x.get(i));
        }
        return novo;
    }

    public static ArrayList<INo> sublist2(List<INo> x, int start, int end) {
        ArrayList<INo> novo = new ArrayList<>();
        for (int i = start; i < end; i++) {
            novo.add(x.get(i));
        }
        return novo;
    }

    public int size() {
        return this.l.size();
    }

    public int altura() {
        return 0;
    }

    @Override
    public void percurso(ArrayList<Integer> lista) {
        int i = 0;
        for (i = 0; i < l.size(); i++) {
            lista.add(l.get(i));
        }
    }

    @Override
    public void toXML(BufferedWriter bw) {
        try {
            int i;
            bw.write("<no>\n");
            for (i = 0; i < this.l.size(); i++) {
                bw.write(l.get(i) + "");
                if (i < l.size() - 1) {
                    bw.write(",");
                }

            }
            bw.write("</no>\n");
        } catch (IOException ex) {
            Logger.getLogger(No.class.getName()).log(Level.SEVERE, null, ex);
            ex.printStackTrace();
            System.exit(0);
        }

    }

    public static void main(String args[]) {
        NoFolha.SIZE = 4;
        ArvoreB t = new ArvoreB(4);
        t.add(1);
        System.out.println("" + t);
        t.add(5);

        System.out.println("" + t);
        t.add(3);

        System.out.println("" + t);
        t.add(2);

        System.out.println("" + t);

        t.add(4);

        System.out.println("" + t);

        t.add(6);

        System.out.println("" + t);

        t.add(7);

        System.out.println("" + t);

        t.add(8);

        System.out.println("" + t);

        t.add(9);

        System.out.println("" + t);

        t.add(10);

        System.out.println("" + t);

        t.add(11);

        System.out.println("" + t);

        t.add(12);

        System.out.println("" + t);

        t.add(13);

        System.out.println("" + t);

        t.add(14);

        System.out.println("" + t);
        
                t.add(16);

        System.out.println("" + t);

                t.add(17);

        System.out.println("" + t);


                t.add(18);

        System.out.println("" + t);

        
        
        
        
    }

}
