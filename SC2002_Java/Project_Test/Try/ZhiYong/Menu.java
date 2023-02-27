package MOBLIMA;

public class Menu {
    public static void main(String[] args) {
    }

    public static void Homepage() {
        // Homepage
        // List movies (1)
        // Search (2)
        // ListTop5 (3)
        // View Booking history (4)
        // Login (5)
        System.out.println("Homepage Menu");
        System.out.println("(1) List Movies");
        System.out.println("(2) Search Movie");
        System.out.println("(3) Buy Tickets");
        System.out.println("(4) List Top 5 Movies");
        System.out.println("(5) View Booking History");
        System.out.println("(6) Login");
        System.out.println("(0) Exit App");
    }

    public static void BuyMenu() {
        // Under search
        // View details
        // Check availability
        // Buy tickets
        System.out.println("Buy Menu");
        System.out.println("(1) View movie details");
        System.out.println("(2) Check movie availability");
        System.out.println("(3) Buy tickets");
        System.out.println("(0) Exit Search Menu");
    }

    public void AdminMenu() {
        System.out.println("Admin Menu");
        System.out.println("(1) Edit Movie listings");
        System.out.println("(2) Edit Cinema settings");
        System.out.println("(3) Configure System settings");
        System.out.println("(0) Exit Admin Menu");
    }

    public void EditMovieMenu() {
        System.out.println("Edit Movie Menu");
        System.out.println("(1) Create Movie listings");
        System.out.println("(2) Update Movie listings");
        System.out.println("(3) Remove Movie listings");
        System.out.println("(0) Exit Edit Movie Menu");
    }

    public void EditMovieDetails() {
        System.out.println("(1) Change Movie Title");
        System.out.println("(2) Change Synopsis");
        System.out.println("(3) Change Director");
        System.out.println("(4) Change Casts");
        System.out.println("(5) Change Duration");
        System.out.println("(6) Change Status");
        System.out.println("(7) Change Type");
        System.out.println("(8) Change Total Sales");
        System.out.println("(9) Update Average Rating");
        System.out.println("(10) Reviews");
        System.out.println("(11) Ratings");
        System.out.println("(0) Exit Edit Movie Menu");
    }

    public void EditCinemaMenu() {
        // Jurong West Cineplex Hall 4 - Movie Title - Showtime 1100 1400 1800
        System.out.println("Edit Cinema Menu");
        System.out.println("(1) Select Cinema");
        System.out.println("(2) Add Cinema Showtimes");
        System.out.println("(3) Edit Cinema Showtimes");
        System.out.println("(4) Remove Cinema Showtimes");
        System.out.println("(5) Edit Cinema Movie");
        System.out.println("(0) Exit Edit Cinema Menu");
    }

    public void EditSystemMenu() {
        System.out.println("Edit System Menu");
        System.out.println("(1) Edit Ticket Pricing");
        System.out.println("(2) Edit Holidays");
        System.out.println("(0) Exit Edit System Menu");
    }
    // Login menu (Admin side)
    // Movie settings --> create/update/remove movie listings
    // Cinema settings --> Create/update/remove cinema showtimes and movies
    // System settings --> Ticket price, holiday
}
