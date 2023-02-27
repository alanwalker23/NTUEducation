package SC2002_Java.Lab2;

import java.util.Random;
import java.util.Scanner;
import java.math.*;

public class Lab2p1 {
    public static void main(String[] args) {
        int choice;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Perform the following methods:");
            System.out.println("1: miltiplication test");
            System.out.println("2: quotient using division by subtraction");
            System.out.println("3: remainder using division by subtraction");
            System.out.println("4: count the number of digits");
            System.out.println("5: position of a digit");
            System.out.println("6: extract all odd digits");
            System.out.println("7: quit");
            choice = sc.nextInt();

            int m;
            int n;
            int answer;
            switch (choice) {
                case 1: /* add mulTest() call */
                    mulTest();
                    break;
                case 2: /* add divide() call */
                    System.out.printf("Enter integer M: ");
                    m = sc.nextInt();
                    System.out.printf("Enter integer N: ");
                    n = sc.nextInt();
                    answer = divide(m, n);
                    System.out.println("Answer is " + answer + "\n");
                    break;
                case 3: /* add modulus() call */
                    System.out.printf("Enter integer M: ");
                    m = sc.nextInt();
                    System.out.printf("Enter integer N: ");
                    n = sc.nextInt();
                    answer = modulus(m, n);
                    System.out.println("Answer is " + answer + "\n");
                    break;
                case 4: /* add countDigits() call */
                    System.out.printf("Enter integer N: ");
                    n = sc.nextInt();
                    answer = countDigits(n);
                    if (answer == 0)
                        System.out.println("Error input!!\n");
                    else
                        System.out.println("count = " + answer + "\n");
                    break;
                case 5: /* add position() call */
                    System.out.printf("Enter integer N: ");
                    n = sc.nextInt();
                    System.out.printf("Enter digit: ");
                    int digit = sc.nextInt();
                    answer = position(n, digit);
                    System.out.println("Position = " + answer + "\n");
                    break;
                case 6: /* add extractOddDigits() call */
                    System.out.printf("Enter integer N: ");
                    long newn = sc.nextLong();
                    if (newn < 0)
                        System.out.println("Error input!!\n");
                    else {
                        long newanswer = extractOddDigits(newn);
                        System.out.println("oddDigits = " + newanswer + "\n");
                    }
                    break;
                case 7:
                    System.out.println("Program terminating...");
            }
        } while (choice < 7);
    }

    /* add method code here */
    private static void mulTest() {
        int correct = 0;
        for (int i = 0; i < 5; i++) {
            int a = (int) (Math.random() * 9) + 1;
            int b = (int) (Math.random() * 9) + 1;
            System.out.printf("How much is " + a + " times " + b + "? ");
            Scanner sc = new Scanner(System.in);
            int answer = sc.nextInt();
            if (answer == a * b)
                correct++;
        }
        System.out.println(correct + " answers out of 5 are correct\n");
    }

    public static int divide(int m, int n) {
        int answer = 0;
        while (m > 0 && m >= n) {
            m -= n;
            answer++;
        }
        return answer;
    }

    public static int modulus(int m, int n) {
        while (m > 0 && m >= n) {
            m -= n;
        }
        return m;
    }

    public static int countDigits(int n) {
        int digits = 0;
        while (n > 0) {
            n /= 10;
            digits++;
        }
        return digits;
    }

    public static int position(int n, int digit) {
        int position = 0;
        while (n > 0) {
            position++;
            int lastdigit = modulus(n, 10);
            if (lastdigit == digit)
                return position;
            n /= 10;
        }
        return -1;
    }

    public static long extractOddDigits(long n) {
        long answer = 0;
        int position = 1;
        while (n > 0) {
            int lastdigit = modulus((int) (n), 10);
            //System.out.println(lastdigit);
            // int check = modulus(lastdigit, 2);
            // System.out.println(check);
            if (modulus(lastdigit, 2) == 1) {
                answer += (position * lastdigit);
                // System.out.println("Added:"+lastdigit);
                position *= 10;
            }
            n /= 10;
        }
        if (answer == 0)
            return -1;
        return answer;
    }
}
