import java.util.Scanner;

public class Bubblesort {

    public static void main(String[] args) {
        int a[] = new int[100];
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter number of Integer elements to be sorted: ");
        int n = sc.nextInt();
        for (int i = 0; i <= n - 1; i++) {
            System.out.printf("\n\n Enter integer value for element no.%d : ", i + 1);
            a[i] = sc.nextInt();
        }
        bubble(a, n);

        System.out.printf("\n\n Finally sorted array is: ");
        for (int i = 0; i <= n - 1; i++)
            System.out.printf("%d ", a[i]);
    }

    public static void bubble(int a[], int n) {
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (a[j] > a[j + 1]) {
                    int t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
            }
        }
    }
}
