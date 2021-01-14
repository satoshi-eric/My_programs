/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arvoreb;

import static arvoreb.NoFolha.SIZE;
import java.io.BufferedWriter;
import java.util.ArrayList;

/**
 *
 * @author meira
 */
public interface INo {

    public NoAndValue add(int valor);
    public int size();
    public int altura();
    public void percurso(ArrayList<Integer>l);
    public void toXML(BufferedWriter bw);

}
