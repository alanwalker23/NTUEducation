import java.io.*;

public class Movie {
    // public enum showStatus {COMINGSOON, PREVIEW, SHOWING, ENDSHOW};

    protected String movieTitle;
    protected String Synopsis;
    protected String Director;
    protected String Casts;
    protected double Duration;
    // private showStatus Status;
    protected String Status;
    protected String Type;
    protected double totalSales;
    protected double avgRating;
    protected String Reviews;
    protected String Ratings;

    public Movie(String movieTitle, String Synopsis, String Director, String Casts,
            double Duration, String Status, String Type, double totalSales, double avgRating, String Reviews,
            String Ratings) {
        this.movieTitle = movieTitle;
        this.Synopsis = Synopsis;
        this.Director = Director;
        this.Casts = Casts;
        this.Duration = Duration;
        this.Status = Status;
        this.Type = Type;
        this.totalSales = totalSales;
        this.avgRating = avgRating;
        this.Reviews = Reviews;
        this.Ratings = Ratings;
    }

    public String getMovieTitle() {
        return movieTitle;
    }

    public String getSynopsis() {
        return Synopsis;
    }

    public String getDirector() {
        return Director;
    }

    public String getCasts() {
        return Casts;
    }

    public String getStatus() {
        return Status;
    }

    public String getType() {
        return Type;
    }

    public double getDuration() {
        return Duration;
    }

    public double gettotalSales() {
        return totalSales;
    }

    public String getReviews() {
        return Reviews;
    }

    public String getRatings() {
        return Ratings;
    }

    public double getavgRating() {
        avgRating = calculateAvgRating(Ratings);
        return avgRating;
    }

    public double calculateAvgRating(String numberList) {
        String[] splitArray = numberList.split(",");
        int n = splitArray.length;
        if (n <= 1) {
            return -1;
        }

        int[] numArray = new int[n];

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Integer.parseInt(splitArray[i]);
        }

        return Math.round((sum / n) * 10.0) / 10.0;
    }

    public void Create() throws IOException {
        FileWriter fstream = new FileWriter("MovieList.txt", true);
        BufferedWriter out = new BufferedWriter(fstream);

        String append = movieTitle + "|" + Synopsis + "|" + Director + "|" + Casts + "|" + Status + "|" +
                Type + "|" + Duration + "|" + totalSales + "|" + avgRating + "|" + Reviews + "|" + Ratings;
        out.write(append);
        out.newLine();

        // close buffer writer
        out.close();

        System.out.println("Added new movie");
    }

    public void display() {
        System.out.println(movieTitle + " " + Status + "\n"
                + "Running Time: " + Duration + "\n"
                + "Type: " + Type + "\n"
                + "Synopsis: " + Synopsis + "\n"
                + "Main Cast: " + Casts + "\n");
    }
}
