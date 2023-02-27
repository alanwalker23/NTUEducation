package SC2002_Java.Project_Test;
import java.util.Scanner;

public class Main_App {
    

    public static void main(String[] args){
        Cinema hall1 = new Cinema(0, 0, null);
        hall1.showSeats();
        System.out.println(hall1.EmptySeats());
        Cinema hall2 = new Cinema(1, 1, null);
        Cinema hall3 = new Cinema(2, 2, null);
        Cinema[] halls = {hall1,hall2,hall3};
        Cineplex jurong = new Cineplex(0,"Jurong Point", halls);
        System.out.println(jurong.getLocation());
        
    }
}
