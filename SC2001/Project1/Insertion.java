package Project1;
public class Insertion {
    public static void main(String args[]) {
        int arr[];
        arr = FillArray(8);
        // System.out.println("Given Array");
        // printArray(arr);

        long startTime = System.nanoTime();
        int comparisons = 0;
        Insertion ob = new Insertion();
        comparisons += ob.insertionsort(arr);
        long endTime = System.nanoTime();
        long totalTime = endTime - startTime;

        // System.out.println("\nSorted array");
        printArray(arr);
        System.out.println(comparisons);
        System.out.println("Total time needed: " + totalTime);
    }

    int insertionsort(int arr[]) {
        int n = arr.length;
        int compare = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i; j > 0; j--) {
                compare++;
                // Swaps
                if (arr[j] < arr[j - 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    // printArray(arr);
                } else {
                    break;
                }
            }
        }
        return compare;
    }

    public static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static int[] FillArray(int size) {
        int arr[] = new int[size];
        int min = 1;
        int max = 50000;
        for (int i = 0; i < arr.length; i++) {
            int number = (int) (Math.random() * (max - min + 1) + min);
            arr[i] = number;
        }
        return arr;
    }
}
