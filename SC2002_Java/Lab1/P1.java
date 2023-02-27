package SC2002_Java.Lab1;

import java.util.Scanner;

public class P1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char choice = sc.next().charAt(0);
        sc.close();
        choice = Character.toLowerCase(choice);
        switch (choice) {
            case 'a':
                System.out.printf("Action movie fan\n");
                break;
            case 'c':
                System.out.printf("Comedy movie fan\n");
                break;
            case 'd':
                System.out.printf("Drama movie fan\n");
                break;
            default:
                System.out.printf("Invalid Choice\n");
        }

        // if ((choice == 'A') || (choice == 'a'))

        // else if ((choice == 'C') || (choice == 'c'))
        // System.out.printf("Comedy movie fan\n");
        // else if ((choice == 'D') || (choice == 'd'))
        // System.out.printf("Drama movie fan\n");
        // else
        // System.out.printf("Invalid Choice\n");
    }
}
