/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arvoreb;

import static arvoreb.NoFolha.sublist;
import static arvoreb.NoFolha.sublist2;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author meira
 */
public class No implements INo {

    //public static final int SIZE = NoFolha.SIZE;
    ArrayList<Integer> l = new ArrayList<>();
    ArrayList<INo> p = new ArrayList<>();

    public No(INo esq, int valor, INo dir) {
        l.add(valor);
        p.add(esq);
        p.add(dir);
    }

    public No() {
    }

    public NoAndValue add(int valor) {

        NoAndValue ret;
        if (valor >= l.get(l.size() - 1)) {
            INo ultimo = p.get(l.size());
            ret = ultimo.add(valor);
            if (ret != null) {
                l.add(ret.value);
                p.add(ret.no);
            }
        } else {
            int i = 0;
            while (valor > l.get(i)) {
                i++;
            }
            INo no = p.get(i);
            ret = no.add(valor);
            if (ret != null) {
                l.add(i, ret.value);
                p.add(i + 1, ret.no);
            }
        }
        if (l.size() <= NoFolha.SIZE) {
            return null;
        }

        return this.split();

    }

    public NoAndValue split() {

        No aux = new No();
        NoAndValue ret = new NoAndValue();
        int meio = NoFolha.SIZE / 2;
        ret.no = aux;
        ret.value = l.get(meio);
        aux.l = sublist(l, meio + 1, NoFolha.SIZE + 1);
        aux.p = sublist2(p, meio + 1, NoFolha.SIZE + 2);
        //assert(aux.p.size()==1);
        l = sublist(l, 0, meio);
        p = sublist2(p, 0, meio + 1);
        //assert(p.size()==1);
        //System.out.println(""+p);
        //System.out.println(""+aux.p);

        //System.out.println(""+l);
        //System.out.println(""+aux.l);
        //System.exit(0);
        return ret;

    }

    public String toString() {
        String xml = "[";
        int i;
        for (i = 0; i < l.size(); i++) {
            xml += p.get(i);
            xml += l.get(i);
        }
        xml += p.get(i);
        xml += "]";
        return xml;
    }

    public int size() {
        int size = 0;
        for (int i = 0; i < p.size(); i++) {
            size += p.get(i).size();
        }
        return size + l.size();
    }

    public int altura() {
        int hfilho = this.p.get(0).altura();

        for (int i = 0; i < p.size(); i++) {
            int aux = p.get(i).altura();
            assert (aux == hfilho);
        }
        return hfilho + 1;

    }

    @Override
    public void percurso(ArrayList<Integer> lista) {
        int i = 0;
        for (i = 0; i < l.size(); i++) {
            this.p.get(i).percurso(lista);
            lista.add(l.get(i));
        }
        this.p.get(i).percurso(lista);
    }

    @Override
    public void toXML(BufferedWriter bw) {
        try {
            int i;
            bw.write("<no>\n");
            for (i = 0; i < this.l.size(); i++) {

                this.p.get(i).toXML(bw);
                bw.write(l.get(i) + "");

            }
            this.p.get(i).toXML(bw);
            bw.write("</no>\n");
        } catch (IOException ex) {
            Logger.getLogger(No.class.getName()).log(Level.SEVERE, null, ex);
            ex.printStackTrace();
            System.exit(0);
        }
        

    }

}
