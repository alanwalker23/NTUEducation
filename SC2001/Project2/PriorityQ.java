
//An object class for the priority queue array
import java.util.Arrays;

public class PriorityQ {

    // The priority queue array that stores nodes (or vertexes), containing their
    // index number and distance from source node.
    private Node[] q;

    private static int position = 0; // position index of the array to "enqueue" a node/vertex
    private static int size = 0; // size of priority queue array

    // constructor, takes in size of priority queue array to be created
    public PriorityQ(int size) {
        q = new Node[size];
    }

    // "enqueue" a node/vertex into the array
    public void enqueue(int vertex, int distance) {
        q[position] = new Node(vertex, distance);
        position++;
        size++;
    }

    // "dequeue" a node/vertex from the array, so the head is always removed first.
    // In the algorithm, the queue should be sorted first so that the head node
    // being dequeued is always the unchecked node with the shortest distance from
    // source node
    public int dequeue() {
        Node temp = q[0];
        if (size > 1) {
            for (int i = 1; i < size; i++) { // shifting forward rest of nodes in the array after removal
                q[i - 1] = q[i];
            }
        }
        q[size - 1] = null;
        size--;
        position--;
        return temp.getVertex();
    }

    // function to sort the priority queue array (vertexes) in ascending order of
    // distance from source vertex
    public void sortAscDistance() {
        for (int i = 1; i < size; i++) {
            for (int j = i; j > 0; j--) {
                if (q[j].getdistanceFromSource() < q[j - 1].getdistanceFromSource()) {
                    Node temp = q[j];
                    q[j] = q[j - 1];
                    q[j - 1] = temp;
                } else
                    break;
            }
        }
    }

    public boolean isEmpty() {
        if (size == 0) {
            return true;
        } else
            return false;
    }

    // function to update the distance of a node with index v, setting d as the new
    // shortest distance from source node
    public void setDistance(int v, int d) {
        for (int i = 0; i < size; i++) {
            if (q[i].getVertex() == v) {
                q[i].setDistanceFromSource(d);
            }
        }
    }

    // function to remove a specific node of index v (Vertex v) from the queue.
    public void removeNode(int v) {
        for (int i = 0; i < size; i++) {
            if (q[i].getVertex() == v) {
                for (int j = i + 1; j < size; j++) { // shifting forward rest of the nodes within the array after
                                                     // removal
                    q[j - 1] = q[j];
                }
            }
        }
        q[size - 1] = null;
        size--;
        position--;
    }

}