package SC2002_Java.Lab1;

import java.util.Scanner;

public class P3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("Starting: ");
        int start = sc.nextInt();
        System.out.printf("Ending: ");
        int end = sc.nextInt();
        System.out.printf("Increment: ");
        int increment = sc.nextInt();
        sc.close();
        if (start > end)
            System.out.println("Error Input!");
        else {
            System.out.println("US$\tS$");
            System.out.println("----------");
            
            // for (int i = start; i <= end; i += increment) {
            //     String s = String.format("%d\t%.2f", i, i * 1.82);
            //     System.out.println(s);
            // }

            // while (start!=(end+increment)){
            //     String s = String.format("%d\t%.2f", start, start * 1.82);
            //     System.out.println(s);
            //     start+=increment;
            // }
            
            do{
                String s = String.format("%d\t%.2f", start, start * 1.82);
                System.out.println(s);
                start+=increment;
            }while(start!=(end+increment));
        }
    }
}
