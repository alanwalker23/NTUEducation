package SC2002_Java.Lab4;
import java.util.Scanner;

public class Strings {
    public static void main(String[] args) {
        // Sorting sorting = new Sorting();
        String[] strList;
        int size;
        Scanner scan = new Scanner(System.in);
        System.out.print("\nHow many strings do you want to sort? ");
        size = scan.nextInt();
        strList = new String[size];
        System.out.println("\nEnter the strings...");
        for (int i = 0; i < size; i++)
        strList[i] = scan.next();
        Sorting.selectionSort(strList);
        System.out.println("\nYour strings in sorted order...");
        for (int i = 0; i < size; i++)
            System.out.print(strList[i] + " ");
        System.out.println();
    }
}
