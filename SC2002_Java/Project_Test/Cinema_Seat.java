package SC2002_Java.Project_Test;

public class Cinema_Seat {
    private int Seat_ID;
    private boolean Assigned;
    private int Cinema_ID;

    public Cinema_Seat(int seatId, Cinema cinema){
        Seat_ID = seatId;
        Assigned = false;
        Cinema_ID = cinema.getCinemaID();
    }

    public int getSeatID(){
        return Seat_ID;
    }

    public boolean isOccupied(){
        return Assigned;
    }

    public int getCinemaID(){
        return Cinema_ID;
    }

    public void assign(int seatId){
        Seat_ID = seatId;
        Assigned = true;
    }

    public void unAssign(){
        Assigned = false;
    }
}
