package Project1;
public class Mergesort {
    public static void main(String args[]) {
        int arr[];
        arr = FillArray(100);

        Mergesort ob = new Mergesort();
        long startTime = System.nanoTime();
        int comparisons = ob.sort(arr, 0, arr.length - 1);

        long endTime = System.nanoTime();
        long totalTime = endTime - startTime;
        // System.out.println("\nSorted array");
        // printArray(arr);
        System.out.println("Key Comparisons: " + comparisons);
        System.out.println("Total time needed: " + totalTime);
    }

    /* Java program for Merge Sort */
    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    int merge(int arr[], int l, int m, int r) {
        // Find sizes of two subarrays to be merged
        int compare = 0;
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        int L[] = new int[n1];
        int R[] = new int[n2];

        /* Copy data to temp arrays */
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarray array
        int k = l;
        while (i < n1 && j < n2) {
            compare++;
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        return compare;
    }

    // Main function that sorts arr[l..r] using
    // merge()
    int sort(int arr[], int l, int r) {
        int count = 0;
        if (l < r) {
            // Find the middle point
            int m = l + (r - l) / 2;
            // Sort first and second halves
            count += sort(arr, l, m);
            count += sort(arr, m + 1, r);

            // Merge the sorted halves
            count += merge(arr, l, m, r);
        }
        return count;
    }

    /* A utility function to print array of size n */
    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    private static int[] FillArray(int size) {
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