package MOBLIMA;

public class Ticket {
    // private long TicketID;
    private String typeOfMovie; // 2d or 3d
    private int cinemaClass; // gold, standard, platinum
    private String movieStatus;
    // private int[] showTime;
    private int ticketType; // senior citizen, standard, student
    private String seatID;
    private int cinemaID;
    private double ticketPrice;

    public Ticket(String typeOfMovie, int cinemaClass, String movieStatus, int ticketType, String seatID, int cinemaID,
            double ticketPrice) {
        this.typeOfMovie = typeOfMovie;
        this.cinemaClass = cinemaClass;
        this.movieStatus = movieStatus;
        this.ticketType = ticketType;
        this.seatID = seatID;
        this.cinemaID = cinemaID;
        this.ticketPrice = ticketPrice;
    }
    // constructor

    // get and set ticket type, get the price of the ticket type from price
    public String getTypeOfMovie() {
        return typeOfMovie;
    }

    public int getCinemaClass() {
        return cinemaClass;
    }

    public String getMovieStatus() {
        return movieStatus;
    }

    public int getTicketType() {
        return ticketType;
    }

    public String getSeatID() {
        return seatID;
    }

    public int getCinemaID() {
        return cinemaID;
    }

    public double getTicketPrice() {
        return ticketPrice;
    }

}