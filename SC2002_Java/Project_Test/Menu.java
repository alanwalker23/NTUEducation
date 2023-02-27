package SC2002_Java.Project_Test;

public class Menu {
    public static void main(String[] args) {
    }

    public void Homepage() {
        // Homepage
        // List movies (1)
        // Search (2)
        // ListTop5 (3)
        // View Booking history (4)
        // Login (5)
        System.out.println("Homepage Menu");
        System.out.println("(1) List Movies");
        System.out.println("(2) Search Movie");
        System.out.println("(3) List Top 5 Movies");
        System.out.println("(4) View Booking History");
        System.out.println("(5) Login");
        System.out.println("(0) Exit App");
    }

    public void SearchMenu() {
        // Under search
        // View details
        // Check availability
        // Buy tickets
        System.out.println("Search Menu");
        System.out.println("(1) View movie details");
        System.out.println("(2) Check movie availability");
        System.out.println("(3) Buy tickets");
    }

    public void AdminMenu() {
        System.out.println("Admin Menu");
        System.out.println("(1) Edit Movie listings");
        System.out.println("(2) Edit Cinema settings");
        System.out.println("(3) Configure System settings");
    }
    // Login menu (Admin side)
    // Movie settings --> create/update/remove movie listings
    // Cinema settings --> Create/update/remove cinema showtimes and movies
    // System settings --> Ticket price, holiday
}
