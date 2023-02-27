package SC2002_Java.Project_Test;

public class Cineplex {
    private int Cineplex_ID;
    private String Location;
    private Cinema[] CinemaHalls;

    public Cineplex(int id, String place, Cinema[] halls) {
        this.Cineplex_ID = id;
        this.Location = place;
        this.CinemaHalls = halls;
    }
    
    // Need to decide order of initialization, 
    // thinking to init cinema first then cineplex
    // Would array of Cinema halls just be IDS or actual cinema object?
    
    public int getCineplexID(){
        return Cineplex_ID;
    }

    public String getLocation(){
        return Location;
    }

    public Cinema[] getHalls(){
        return CinemaHalls;
    }
}
