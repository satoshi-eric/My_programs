/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package grafo;

import java.util.ArrayList;

/**
 *
 * @author meira
 */
public class Grafo {

    boolean m[][];
    int n;

    public Grafo(int n) {
        this.n = n;
        this.m = new boolean[n][n];
    }

    public String toString() {
        String ret = "";
        for (int li = 0; li < n; li++) {
            ret += "[" + li + "] ";
            for (int col = 0; col < n; col++) {
                if (m[li][col]) {
                    ret += " 1";
                } else {
                    ret += " 0";
                }
            }
            ret += " d=" + grau(li) + " viz=" + this.vizinhos(li) + "\n";
        }
        return ret;
    }

    void addE(int i, int j) {
        m[i][j] = true;
        m[j][i] = true;
    }

    int grau(int v) {
        int grau = 0;
        for (int i = 0; i < n; i++) {
            if (m[i][v]) {
                grau++;
            }
        }
        return grau;
    }

    ArrayList<Integer> vizinhos(int v) {
        ArrayList<Integer> viz = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (m[i][v]) {
                viz.add(i);
            }
        }
        return viz;
    }

    ArrayList<Integer> vizinhosDosVizinhos(int v) {
        return null;
    }

    int distancia(int u, int v) {
        return 0;
    }

    public static void main(String args[]) {
        int n = 10;
        Grafo g = new Grafo(n);
        for (int i = 0; i < n; i++) {
            g.addE(i, (i + 1) % n);
        }
        g.addE(0, 3);
        System.out.println("" + g);
    }
}
