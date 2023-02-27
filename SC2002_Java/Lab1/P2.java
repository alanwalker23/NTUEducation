package SC2002_Java.Lab1;

import java.util.Scanner;

public class P2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Salary:");
        int salary = sc.nextInt();
        System.out.println("Merit:");
        int merit = sc.nextInt();
        sc.close();
        if ((salary >= 700) && (merit >= 20))
            System.out.printf("Grade A");
        else if ((salary >= 600) && (merit >= 10))
            System.out.printf("Grade B");
        else
            System.out.printf("Grade C");
    }
}
