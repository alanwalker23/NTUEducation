import java.util.Arrays;

public class DijkstraArray {

    // Base case testing
    public static int[][] matrixGraph = new int[][] {
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, // Adj List for Vertex 0
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, // Adj List for Vertex 1
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, // Adj List for Vertex 2
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, // Adj List for Vertex 3
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, // Adj List for Vertex 4
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, // Adj List for Vertex 5
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, // Adj List for Vertex 6
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, // Adj List for Vertex 7
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } // Adj List for Vertex 8
    };

    public static int[] Dijkstra(int[][] Graph, int source, int V) {

        // Initialize all default values.
        PriorityQ q = new PriorityQ(V); // create priority queue
        int[] S = new int[V]; // Set of vertices that have already been checked
        int[] d = new int[V]; // Array to store the estimated shortest lengths from the source node to all
        int[] predecessors = new int[V]; // Array to store the predecessors for each vertex

        for (int i = 0; i < V; i++) {
            d[i] = 9999; // set initial distances to "infinity"
            q.enqueue(i, d[i]);
            predecessors[i] = -1;
            S[i] = 0; // S[i] is 1 if Vertex i is in S, 0 if Vertex i is not in S.
        }

        d[source] = 0; // distance to itself is always 0.
        q.setDistance(source, d[source]); // setting distance of source node to 0

        // put all vertices in priority queue, in d[i]'s increasing order.
        // since we already have the nodes in pq in vertex order, now we have to sort
        // the nodes based on their ascending distance from source node.
        q.sortAscDistance();

        while (!q.isEmpty()) {
            int u = q.dequeue(); // retrieving the vertex with shortest distance
            S[u] = 1; // Add Vertex u to S

            for (int i = 0; i < V; i++) { // for every adjacent vertex to vertex u that has not been checked
                if ((Graph[u][i] != 0) && (S[i] != 1) && (d[i] > (d[u] + Graph[u][i]))) {
                    q.removeNode(i);
                    d[i] = d[u] + Graph[u][i];
                    predecessors[i] = u;
                    q.enqueue(i, d[i]); // reinsert vertex i with updated shortest distance value
                    q.sortAscDistance(); // sort queue again in ascending order of distance from source node
                }
            }
        }
        return d;
    }

    public static void main(String[] args) {

        int source = 0; // Selection of source vertex
        int V = 8;
        int E = 10;
        int d[] = new int[V];
        int[][] graph = new int[V][V];
        graph = MatrixGraph.GraphConstructor(V, E);
        // d = Dijkstra(matrixGraph, source,V);
        d = Dijkstra(graph, source, V);
        System.out.println("Shortest Distances from Source Vertex " + source);
        for (int i = 0; i < V; i++) {
            System.out.println("Shortest Distance to Vertex " + i + ": " + d[i]);
        }
        printAdjMatrix(graph, V);
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