package SC2002_Java.Lab1;

import java.util.Scanner;

public class P4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("Height: ");
        int height = sc.nextInt();
        sc.close();
        for (int i = 0; i < height; i++) {
            StringBuilder s = new StringBuilder();
            for (int j = 0; j <= i; j++) {
                if (j % 2 == 0)
                    s.insert(0, "AA");
                // System.out.print("AA");
                else
                    s.insert(0, "BB");
                // System.out.print("BB");
            }
            System.out.printf(s + "\n");
        }
    }
}
