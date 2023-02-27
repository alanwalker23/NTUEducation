//Node class to represent a vertex, containing its vertex index number and its distance from source node

public class Node {
    private int vertex;
    private int distanceFromSource;

    public Node(int v, int d) {
        vertex = v;
        distanceFromSource = d;
    }

    public int getVertex() {
        return vertex;
    }

    public int getdistanceFromSource() {
        return distanceFromSource;
    }

    public void setDistanceFromSource(int d) {
        distanceFromSource = d;
    }
}