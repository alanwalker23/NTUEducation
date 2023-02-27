import java.io.*;
import java.util.*;

public class Dijkstra {

    public static void main(String[] args) {
        // int V = 10;
        // int E = 15;
        // int source = 0;
        // int d[] = new int[V]; // for Part A
        // int[][] graph = new int[V][V];
        // graph = MatrixGraph.GraphConstructor(V, E); //Part A
        // ArrayList<ArrayList<Dijkstra_Minheap.AdjListNode>> linkedlist =
        // Dijkstra_Minheap.convert(graph); //Part B
        // printAdjMatrix(graph, V);

        // Part A
        // d = DijkstraArray.Dijkstra(graph, source, V);
        // System.out.println("Shortest Distances from Source Vertex " + source);
        // for (int i = 0; i < V; i++) {
        // System.out.println("Shortest Distance to Vertex " + i + ": " + d[i]);
        // }
        // Part B
        // int[] distance = Dijkstra_Minheap.dijkstra(V, linkedlist, source);
        // // Printing the Output
        // System.out.println("Vertex " + " Distance from Source");
        // for (int i = 0; i < V; i++) {
        // System.out.println(i + " " + distance[i]);
        // }

        // Part C
        // Complete Graph: e = n(n-1)/2
        // Density Ratio: r = 2e/n(n-1)
        long startTime, endTime, totalTime1, totalTime2;
        for (int i = 50; i < 1000; i+=10) {
            int source = 0;
            //int complete = i * (i - 1) / 2;
            //int edges = complete/10*6;
            int d[] = new int[i]; // for Part A
            int distance[] = new int[i]; // for Part B
            int[][] graph = new int[i][i];
            graph = MatrixGraph.GraphConstructor(i, 50);
            ArrayList<ArrayList<Dijkstra_Minheap.AdjListNode>> linkedlist = Dijkstra_Minheap.convert(graph);
            startTime = System.nanoTime();
            d = DijkstraArray.Dijkstra(graph, source, i);
            endTime = System.nanoTime();
            totalTime1 = endTime - startTime;
            startTime = System.nanoTime();
            distance = Dijkstra_Minheap.dijkstra(i, linkedlist, source);
            endTime = System.nanoTime();
            totalTime2 = endTime - startTime;
            System.out.printf("%d %d %d %d\n",i,50,totalTime1,totalTime2);
            //printAdjMatrix(graph, i);
        }
    }

    static void printAdjMatrix(int Adj[][], int V) {
        // Traverse the Adj[][]
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Print the value at Adj[i][j]
                System.out.printf("%2d ", Adj[i][j]);
            }
            System.out.println();
        }
    }
}
