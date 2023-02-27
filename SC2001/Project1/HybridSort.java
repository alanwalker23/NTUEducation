package Project1;

public class HybridSort {

    public static void main(String args[]) {
        int arr[];
        int size = 8;
        arr = FillArray(size);
        printArray(arr);
        // printArray(arr);
        // arr = FillArray(8);
        // arr = AscArray(8);
        // arr = DescArray(10000000);
        int Marr[] = new int[size];
        System.arraycopy(arr, 0, Marr, 0, size);
        int Inarr[] = new int[size];
        System.arraycopy(arr, 0, Inarr, 0, size);
        int comparisons = 0;
        long startTime, endTime, totalTime;

        // MergeSort (No need to run)
        // Mergesort ob = new Mergesort();
        // comparisons = 0;
        // startTime = System.nanoTime();
        // comparisons += ob.sort(Marr, 0, arr.length - 1);
        // endTime = System.nanoTime();
        // totalTime = endTime - startTime;
        // System.out.println("MergeSort - Key Comparisons: " + comparisons);
        // System.out.println("MergeSort - Total time needed: " + totalTime);

        // InsertionSort
        // HybridSort insert = new HybridSort();
        // comparisons = 0;
        // //printArray(Inarr);
        // startTime = System.nanoTime();
        // comparisons += insert.insertionsort(Inarr,0,Inarr.length-1);
        // endTime = System.nanoTime();
        // totalTime = endTime - startTime;

        // System.out.println("InsertionSort - Key Comparisons: " + comparisons);
        // System.out.println("InsertionSort - Total time needed: " + totalTime);

        // Hybridsort
        // HybridSort obhs1 = new HybridSort();
        // comparisons = 0;
        // printArray(HSarr);
        // startTime = System.nanoTime();
        // comparisons += obhs1.hsort(HSarr, 0, arr.length - 1, 5);
        // endTime = System.nanoTime();
        // totalTime = endTime - startTime;
        // System.out.println("HybridSort(5) - Key Comparisons: " + comparisons);
        // System.out.println("HybridSort(5) - Total time needed: " + totalTime);

        for (int i = 2; i <= 10; i++) {
            HybridSort obhs = new HybridSort();
            int HSarr[] = new int[size];
            System.arraycopy(arr, 0, HSarr, 0, size);
            //System.out.println("Element 1: "+arr[0]+"Element 20: "+arr[20]+"Element 50: "+arr[80]);
            comparisons = 0;
            startTime = System.nanoTime();
            comparisons += obhs.hsort(HSarr, 0, arr.length - 1, i);
            endTime = System.nanoTime();
            totalTime = endTime - startTime;
            System.out.println("HybridSort(" + i + ") - Key Comparisons: " + comparisons);
            System.out.println("HybridSort(" + i + ") - Total time needed: " + totalTime);
        }
    }

    int insertionsort(int arr[], int l, int r) {
        // int n = r - l + 1;
        int n = r;
        // System.out.println("L is " + l + " R is " + r + " n is " + n);
        int compare = 0;
        for (int i = (l + 1); i <= n; i++) {
            for (int j = i; j > l; j--) {
                compare++;
                // printArray(arr);
                if (arr[j] < arr[j - 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                } else {
                    break;
                }
            }
        }
        return compare;
    }

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

    int hsort(int arr[], int l, int r, int s) {
        int compare = 0;
        if (r - l > s) {
            // Find the middle point
            int m = l + (r - l) / 2;
            // Sort first and second halves
            compare += hsort(arr, l, m, s);
            compare += hsort(arr, m + 1, r, s);

            // Merge the sorted halves
            compare += merge(arr, l, m, r);
        } else {
            compare += insertionsort(arr, l, r);
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

    public static int[] AscArray(int size) {
        int arr[] = new int[size];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i + 1;
        }
        return arr;
    }

    public static int[] DescArray(int size) {
        int arr[] = new int[size];
        int current = 0;
        for (int i = arr.length; i > 0; i--) {
            arr[current] = i;
            current++;
        }
        return arr;
    }
}
