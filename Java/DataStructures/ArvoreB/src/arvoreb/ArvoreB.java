/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arvoreb;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author meira
 */
public class ArvoreB {

    INo raiz = new NoFolha();

    public ArvoreB(int B) {
        assert (B % 2 == 0);
        NoFolha.SIZE = B;
    }

    public void add(int valor) {
        NoAndValue ret = raiz.add(valor);

        if (ret != null) {
            
            System.out.println("ESQ "+this.raiz);
            System.out.println("Meio "+ret.value);
            System.out.println("DIR "+ret.no);
            
            INo aux = new No(raiz, ret.value, ret.no);
            raiz = aux;
        }

    }

   


    public String toString() {
        return raiz.toString();
    }

    int size() {
        return this.raiz.size();
    }

    int altura() {
        return this.raiz.altura();
    }
    
    
    void percurso(ArrayList<Integer>l){
        this.raiz.percurso(l);
    }
    
    public void toXML(){
        BufferedWriter bw = null;
        try {
            bw = new BufferedWriter(new FileWriter(new File("Tree.xml")));
            bw.write("<Tree>\n");
            this.raiz.toXML(bw);
            bw.write("</Tree>\n");
            bw.close();
        } catch (IOException ex) {
            Logger.getLogger(ArvoreB.class.getName()).log(Level.SEVERE, null, ex);
            ex.printStackTrace();
            System.exit(0);
        } 
    }    
}
