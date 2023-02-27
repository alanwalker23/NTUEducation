package MOBLIMA;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;

public class Cinema {
    private static int TotalNumOfCinemaHalls = 0;
    private static int occupiedSeats = 0;
    private int Cinema_ID;
    private int TotalNumOfSeat;
    private Date[] Showtime;
    private int Type;
    private Cinema_Seat[] seats;
    private Movie movie; // read name from csv then convert to movie object
    // {0 1 2} only 3 possible values
    // 0 = standard = 50 (3 4 3)x5
    // 1 = gold = 20 (5 5)x2
    // 2 = platinum = 8 (2 2) x2

    public Cinema(int type, Date[] showtimes) {
        this.Cinema_ID = TotalNumOfCinemaHalls;
        TotalNumOfCinemaHalls++;
        this.Type = type;
        this.movie = null;
        if (type == 0)
            this.TotalNumOfSeat = 50;
        else if (type == 1)
            this.TotalNumOfSeat = 20;
        else
            this.TotalNumOfSeat = 8;
        this.Showtime = showtimes;
        seats = new Cinema_Seat[this.TotalNumOfSeat];
        for (int i = 0; i < this.TotalNumOfSeat; i++) {
            seats[i] = new Cinema_Seat(i, this);
        }
    }

    public int getCinemaID() {
        return Cinema_ID;
    }

    public Date[] getShowtimes() {
        return Showtime;
    }

    public int getType() {
        return Type;
    }

    public Movie getMovie() {
        return movie;
    }

    // Show the row and column (Alphabets and Numbers, e.g. A1 for 00 seat)
    public void showSeats() {
        char[] alphabet = "ABCDE".toCharArray();
        int row = 0;
        System.out.println();
        if (Type == 0) {
            int leftStairs = 3;
            int rightStairs = 7;
            System.out.println("  1    4    7   10");
            System.out.print(alphabet[row] + " ");
            for (int i = 0; i < TotalNumOfSeat; i++) {
                if (i == leftStairs || i == rightStairs) {
                    System.out.print("   ");
                }
                if (seats[i].isOccupied())
                    System.out.print("X");
                else
                    System.out.print("O");
                if (i % 10 == 9 && i < TotalNumOfSeat - 1) {
                    leftStairs += 10;
                    rightStairs += 10;
                    row++;
                    System.out.print("\n" + alphabet[row] + " ");
                }
            }
        } else if (Type == 1) {
            int Stairs = 5;
            System.out.println("  1    5 6   10");
            System.out.print(alphabet[row] + " ");
            for (int i = 0; i < TotalNumOfSeat; i++) {
                if (i == Stairs) {
                    System.out.print("   ");
                }
                if (seats[i].isOccupied())
                    System.out.print("X");
                else
                    System.out.print("O");
                if (i == 9) {
                    Stairs += 10;
                    row++;
                    System.out.print("\n" + alphabet[row] + " ");
                }
            }
        } else {
            int Stairs = 2;
            System.out.println("  1 2 3 4");
            System.out.print(alphabet[row] + " ");
            for (int i = 0; i < TotalNumOfSeat; i++) {
                if (i == Stairs) {
                    System.out.print("   ");
                }
                if (seats[i].isOccupied())
                    System.out.print("X");
                else
                    System.out.print("O");
                if (i == 3) {
                    Stairs += 4;
                    row++;
                    System.out.print("\n" + alphabet[row] + " ");
                }
            }
        }
        System.out.println();
    }

    public int EmptySeats() {
        int spaces = TotalNumOfSeat;
        for (int i = 0; i < TotalNumOfSeat; i++) {
            if (seats[i].isOccupied())
                spaces--;
        }
        return spaces;
    }

    public void displayShowtimes() {
        SimpleDateFormat _12HourSDF = new SimpleDateFormat("hh:mm a");
        if (this.movie == null || Showtime[0] == null)
            System.out.println("No movie showing.");
        else {
            System.out.printf("Showtimes for %s are:\n", this.movie.movieTitle);
            if (this.Showtime == null)
                System.out.println("Currently no showtimes available for this movie.");
            else {
                for (int i = 0; i < Showtime.length; i++) {
                    if (Showtime[i] != null)
                        System.out.println("(" + (i + 1) + ") " + _12HourSDF.format(Showtime[i]));
                }
            }
        }
    }

    public void addShowtimes(String input) {
        SimpleDateFormat _24HourSDF = new SimpleDateFormat("HH:mm");
        SimpleDateFormat _12HourSDF = new SimpleDateFormat("hh:mm a");
        try {
            Date _24HourDt = _24HourSDF.parse(input);
            if (Showtime != null) {
                ArrayList<Date> arrayList = new ArrayList<Date>(Arrays.asList(this.Showtime));
                arrayList.add(_24HourDt);
                this.Showtime = arrayList.toArray(Showtime);
            } else {
                Date[] timings = new Date[1];
                timings[0] = _24HourDt;
                this.Showtime = timings;
            }
            System.out.println("Showtime " + _12HourSDF.format(_24HourDt) + " added.");
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public void editShowtimes(String input, int choice) {
        SimpleDateFormat _24HourSDF = new SimpleDateFormat("HH:mm");
        SimpleDateFormat _12HourSDF = new SimpleDateFormat("hh:mm a");
        try {
            Date _24HourDt = _24HourSDF.parse(input);
            System.out.println("Showtime changed to " + _12HourSDF.format(_24HourDt) + ".");
            this.Showtime[choice] = _24HourDt;
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public void removeShowtimes(int choice) {
        ArrayList<Date> arrayList = new ArrayList<Date>(Arrays.asList(this.Showtime));
        arrayList.remove(choice);
        System.out.println("Showtime removed.");
        this.Showtime = arrayList.toArray(Showtime);
    }

    public void assignMovie(Movie mov) {
        this.movie = mov;
    }

    public void reserveSeats(Cinema_Seat seating) {
        if (seating.isOccupied())
            System.out.println("Seat already reserved.");
        else {
            seating.assign(occupiedSeats);
            occupiedSeats++;
        }
    }

    public void unreserveSeats(Cinema_Seat seating) {
        seating.unAssign();
        occupiedSeats--;
    }

    public Cinema_Seat findSeats(String input) {
        char row = input.charAt(0);
        char[] alphabet = "ABCDE".toCharArray();
        int column = Integer.parseInt(input.substring(1, input.length()));
        System.out.printf("Selected seat is in Row %c and Column %d\n", row, column);
        int seatposition = 0;
        for (int i = 0; i < alphabet.length; i++) {
            if (this.Type != 0 && alphabet[i] == 'C') {
                System.out.println("Invalid seat selected.");
                return null;
            }
            if (row == alphabet[i])
                break;
            seatposition++;
        }
        if (this.Type == 2) {
            if (column > 4) {
                System.out.println("Invalid seat selected.");
                return null;
            }
            seatposition *= 4;
        } else {
            seatposition *= 10;
        }
        seatposition += column - 1;
        System.out.println(seats[seatposition].getSeatID());
        return this.seats[seatposition];
    }
}