package SC2002_Java.Lab3;

import java.util.Scanner;

public class PlaneApp {
    public static void main(String[] args) {
        int choice;
        int seatId;
        int cust_id;
        // Initialize
        Plane plane = new Plane();
        Scanner sc = new Scanner(System.in);
        do {
            PrintMenu();
            System.out.print("Enter the number of your choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    plane.showNumEmptySeats();
                    break;
                case 2:
                    plane.EmptySeats();
                    break;
                case 3:
                    plane.showAssignedSeats(true);
                    break;
                case 4:
                    plane.showAssignedSeats(false);
                    break;
                case 5:
                    System.out.println("Assigning Seat..");
                    System.out.print("Please enter SeatID: ");
                    seatId = sc.nextInt();
                    System.out.print("Please enter Customer ID: ");
                    cust_id = sc.nextInt();
                    plane.assignSeat(seatId, cust_id);
                    break;
                case 6:
                    System.out.print("Enter SeatID to unassign customer from: ");
                    seatId = sc.nextInt();
                    plane.unAssignSeat(seatId);
                    break;
            }
            System.out.println();
        } while (choice < 7);
        sc.close();
    }

    private static void PrintMenu() {
        System.out.println("(1) Show number of empty seats");
        System.out.println("(2) Show the list of empty seats");
        System.out.println("(3) Show the list of seat assignments by seat ID");
        System.out.println("(4) Show the list of seat assignments by customer ID");
        System.out.println("(5) Assign a customer to a seat");
        System.out.println("(6) Remove a seat assignment");
        System.out.println("(7) Exit");
    }
}
