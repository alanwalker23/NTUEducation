import java.io.*;
import java.util.*;

public class Dijkstra_Minheap {
    static class AdjListNode {
        int vertex, weight;

        AdjListNode(int v, int w) {
            vertex = v;
            weight = w;
        }

        int getVertex() {
            return vertex;
        }

        int getWeight() {
            return weight;
        }
    }

    static ArrayList<ArrayList<AdjListNode>> convert(int[][] a) {
        // no of vertices
        int l = a[0].length;
        ArrayList<ArrayList<AdjListNode>> graph = new ArrayList<>();

        // Create a new list for each
        // vertex such that adjacent
        // nodes can be stored
        for (int i = 0; i < l; i++) {
            graph.add(new ArrayList<>());
        }

        int i, j;
        for (i = 0; i < a[0].length; i++) {
            for (j = 0; j < a.length; j++) {
                if (a[i][j] >= 1) {
                    graph.get(i).add(new AdjListNode(j, a[i][j]));
                    // adjListArray.get(i).add(j);
                }
            }
        }

        return graph;
    }

    // Function to find the shortest distance of all the
    // vertices from the source vertex S.
    public static int[] dijkstra(int V, ArrayList<ArrayList<AdjListNode>> graph, int src)
    // V is the total number of vectors
    // Graph is an array of arrray of adjListNode [v,w],[v,w]...
    // src is source (starting node)
    {
        int[] distance = new int[V]; // Array distance is created for all vectors
        for (int i = 0; i < V; i++)
            distance[i] = Integer.MAX_VALUE; // Start by denoting all distances to be max
        distance[src] = 0; // Set starting vector to 0

        PriorityQueue<AdjListNode> pq = new PriorityQueue<>((v1, v2) -> v1.getWeight() - v2.getWeight());
        // Call the class Priority Queue which
        pq.add(new AdjListNode(src, 0)); // [0,0] added to pq

        while (pq.size() > 0) {
            AdjListNode current = pq.poll(); // Retrieves and removes head of queue --> current = [0,0]
            // System.out.println("Current is:" + current.vertex);
            for (AdjListNode n : graph.get(current.getVertex())) {
                // System.out.println(graph.get(current.getVertex()));
                // System.out.println(n.vertex);
                if (distance[current.getVertex()] + n.getWeight() < distance[n.getVertex()]) {
                    distance[n.getVertex()] = n.getWeight() + distance[current.getVertex()];
                    pq.add(new AdjListNode(n.getVertex(), distance[n.getVertex()]));
                }
            }
        }
        // If you want to calculate distance from source to
        // a particular target, you can return
        // distance[target]
        return distance;
    }

    public static void main(String[] args) {

        int V = 9;
        int E = 16;
        int[][] Matrixgraph = new int[V][V];
        Matrixgraph = MatrixGraph.GraphConstructor(V, E);
        ArrayList<ArrayList<AdjListNode>> graph = convert(Matrixgraph);
        printAdjMatrix(Matrixgraph, V);
        // for (int i = 0; i < V; i++) {
        // graph.add(new ArrayList<>());
        // }
        // graph.get(0).add(new AdjListNode(1, 4));
        // graph.get(0).add(new AdjListNode(7, 8));
        // graph.get(1).add(new AdjListNode(2, 8));
        // graph.get(1).add(new AdjListNode(7, 11));
        // graph.get(1).add(new AdjListNode(0, 7));
        // graph.get(2).add(new AdjListNode(1, 8));
        // graph.get(2).add(new AdjListNode(3, 7));
        // graph.get(2).add(new AdjListNode(8, 2));
        // graph.get(2).add(new AdjListNode(5, 4));
        // graph.get(3).add(new AdjListNode(2, 7));
        // graph.get(3).add(new AdjListNode(4, 9));
        // graph.get(3).add(new AdjListNode(5, 14));
        // graph.get(4).add(new AdjListNode(3, 9));
        // graph.get(4).add(new AdjListNode(5, 10));
        // graph.get(5).add(new AdjListNode(4, 10));
        // graph.get(5).add(new AdjListNode(6, 2));
        // graph.get(6).add(new AdjListNode(5, 2));
        // graph.get(6).add(new AdjListNode(7, 1));
        // graph.get(6).add(new AdjListNode(8, 6));
        // graph.get(7).add(new AdjListNode(0, 8));
        // graph.get(7).add(new AdjListNode(1, 11));
        // graph.get(7).add(new AdjListNode(6, 1));
        // graph.get(7).add(new AdjListNode(8, 7));
        // graph.get(8).add(new AdjListNode(2, 2));
        // graph.get(8).add(new AdjListNode(6, 6));
        // graph.get(8).add(new AdjListNode(7, 1));
        int source = 0;
        int[] distance = dijkstra(V, graph, source);
        // Printing the Output
        System.out.println("Vertex "
                + " Distance from Source");
        for (int i = 0; i < V; i++) {
            System.out.println(i + "			 "
                    + distance[i]);
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
