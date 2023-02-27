import java.util.Random;

public class MatrixGraph {

    public static void main(String[] args) {
        int V = 8;
        int E = 14;
        int[][] graph = new int[V][V];
        graph = GraphConstructor(V, E);
        printAdjMatrix(graph, V);
    }

    public static int[][] GraphConstructor(int V, int E) {
        int[][] graph = new int[V][V];
        int edges = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V - i; j++) {
                if (j == 0 || edges == E)
                    graph[i][j + i] = 0;
                else {
                    Random rand = new Random();
                    int upperbound = 10;
                    int chance = rand.nextInt(10);
                    if (chance > 4) {
                        int num = rand.nextInt(upperbound);
                        graph[i][j + i] = num;
                        graph[j + i][i] = num;
                        edges++;
                    } else {
                        graph[i][j + i] = 0;
                        graph[j + i][i] = 0;
                    }
                }
            }
        }
        //System.out.println("Edges - " + edges);
        return graph;
    }

    static void printAdjMatrix(int Adj[][], int V) {
        // Traverse the Adj[][]
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Print the value at Adj[i][j]
                System.out.printf("%2d ",Adj[i][j]);
            }
            System.out.println();
        }
    }
}
