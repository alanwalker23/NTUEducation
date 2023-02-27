package SC2002_Java.Lab3;

public class Plane {
    private PlaneSeat[] seat;
    private int numEmptySeat;

    public Plane(){
        this(12);
    }

    public Plane(int numEmptySeat) {
        this.numEmptySeat = numEmptySeat;
        seat = new PlaneSeat[numEmptySeat];
        for (int i = 0; i < numEmptySeat; i++) {
            seat[i] = new PlaneSeat(i + 1);
        }
    }
    //Comparable (interface) and compartor
    private PlaneSeat[] sortSeats() {
        PlaneSeat[] arr = new PlaneSeat[seat.length];
        System.arraycopy(seat, 0, arr, 0, seat.length);
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].isOccupied()) {
                for (int j = i; j > 0; j--) {
                    if (arr[j].isOccupied() && arr[j].getCustomerID() > arr[i].getCustomerID()) {
                        PlaneSeat temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        return arr;
    }

    public void showNumEmptySeats() {
        System.out.println("There are " + numEmptySeat + " empty seats.");
    }

    public void EmptySeats() {
        for (int i = 0; i < seat.length; i++) {
            if (!seat[i].isOccupied()) {
                System.out.println("SeatID " + seat[i].getSeatID());
            }
        }
    }

    public void showAssignedSeats(boolean bySeatId) {
        if (bySeatId) {
            for (int i = 0; i < seat.length; i++) {
                if (seat[i].isOccupied()) {
                    System.out.print("SeatID " + seat[i].getSeatID());
                    System.out.print(" assigned to CustomerID " + seat[i].getCustomerID() + "\n");
                }
            }
        } else {
            PlaneSeat[] arr = new PlaneSeat[seat.length];
            arr = sortSeats();
            for (int i = 0; i < arr.length; i++) {
                if (arr[i].isOccupied()) {
                    System.out.print("SeatID " + arr[i].getSeatID());
                    System.out.print(" assigned to CustomerID " + arr[i].getCustomerID() + "\n");
                }
            }
        }
    }

    public void assignSeat(int seatId, int cust_id) {
        if (seat[seatId - 1].isOccupied()) {
            System.out.println("Seat already assigned to a customer.");
        } else {
            seat[seatId - 1].assign(cust_id);
            numEmptySeat--;
            System.out.println("Seat Assigned!");
        }
    }

    public void unAssignSeat(int seatId) {
        if (seat[seatId - 1].isOccupied()) {
            seat[seatId - 1].unAssign();
            numEmptySeat++;
            System.out.println("Seat Unassigned!");
        } else {
            System.out.println("Seat already empty.");
        }
    }
}
