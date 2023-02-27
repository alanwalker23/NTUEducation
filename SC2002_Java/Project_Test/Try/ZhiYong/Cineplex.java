package MOBLIMA;

import java.util.Currency;

public class Cineplex {
    private static int TotalNumOfCineplex = 0;
    private int Cineplex_ID;
    private String Location;
    private Cinema[] CinemaHalls;

    public Cineplex(String place, Cinema[] halls) {
        this.Cineplex_ID = TotalNumOfCineplex;
        TotalNumOfCineplex++;
        this.Location = place;
        this.CinemaHalls = halls;
    }

    // Need to decide order of initialization,
    // thinking to init cinema first then cineplex
    // Would array of Cinema halls just be IDS or actual cinema object?

    public int getCineplexID() {
        return Cineplex_ID;
    }

    public String getLocation() {
        return Location;
    }

    public Cinema[] getHalls() {
        return CinemaHalls;
    }

    public Movie[] getMovies() {
        Cinema[] halls = this.CinemaHalls;
        Movie[] movies = new Movie[halls.length];
        for (int i = 0; i < halls.length; i++) {
            movies[i] = halls[i].getMovie();
        }
        return movies;
    }

    public void displayMovies() {
        Cinema[] halls = this.CinemaHalls;
        Movie[] movies = new Movie[halls.length];
        System.out.printf("List of movies within %s: \n", this.Location);
        for (int i = 0; i < halls.length; i++) {
            Movie current = halls[i].getMovie();
            if (current != null)
                System.out.print(current.getMovieTitle() + "\n");
            movies[i] = halls[i].getMovie();
        }
        System.out.println();
    }
}