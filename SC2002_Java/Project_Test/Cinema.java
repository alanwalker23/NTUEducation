import java.io.*;
import java.util.*;
import java.nio.file.*;
import java.text.*;

//Creation of objects and reading file
public class Cinema {
    private int Cinema_ID;
    private int Type;
    private Date[] Showtime;
    private Seatings[] Seating;
    private Movie movie; // read name from csv then convert to movie object
    // {0 1 2} only 3 possible values
    // 0 = standard = 50 (3 4 3)x5
    // 1 = gold = 20 (5 5)x2
    // 2 = platinum = 8 (2 2) x2

    public Cinema(int hallID) throws IOException, ParseException {
        // read the file and create an array of movie objects
        // DateFormat dateFormat = new SimpleDateFormat("yyyy-mm-dd hh:mm:ss");
        Cinema_ID = hallID;
        ArrayList<Date> Showtime_arrayList = new ArrayList<Date>();
        ArrayList<Seatings> Seatings_arrayList = new ArrayList<Seatings>();
        String fileName = "SeatsAvail.txt";
        Path path = Paths.get(fileName);
        int n = (int) Files.lines(path).count();
        ArrayList stringArray = (ArrayList) read(fileName);
        // this.seats = new String[n - 1];
        for (int i = 1; i < n; i++) {
            String st = (String) stringArray.get(i);
            StringTokenizer star = new StringTokenizer(st, "|");
            String ID = star.nextToken().trim();
            String type = star.nextToken().trim();
            String arr = star.nextToken().trim();
            String ST = star.nextToken().trim();
            String[] check = { ID, type, arr, ST };
            SimpleDateFormat formatter = new SimpleDateFormat("E, HH:mm");
            Date newDate = formatter.parse(ST);
            // System.out.println("CineID is " + (current + 1));
            // System.out.println("Check[0] is " + check[0]);
            if (check[0].compareTo(Integer.toString(hallID)) == 0) {
                Showtime_arrayList.add(newDate);
                Seatings session = new Seatings(newDate, Integer.parseInt(type), arr, hallID);
                Seatings_arrayList.add(session);
            }
        }
        Date[] showtimes = new Date[Showtime_arrayList.size()];
        showtimes = Showtime_arrayList.toArray(showtimes);
        Seatings[] seatingArrangements = new Seatings[Seatings_arrayList.size()];
        seatingArrangements = Seatings_arrayList.toArray(seatingArrangements);
        this.Showtime = showtimes;
        this.Seating = seatingArrangements;
        // For debugging reading text file
        // for (int i = 0; i<showtimes.length;i++)
        // {
        // System.out.println(showtimes[i]+"\t"+seatingArrangements[i]);
        // seatingArrangements[i].showSeats();
        // }
    }

    // public Cinema(int type, Date[] showtimes) {
    // this.Cinema_ID = TotalNumOfCinemaHalls;
    // TotalNumOfCinemaHalls++;
    // this.Type = type;
    // this.movie = null;
    // if (type == 0)
    // this.TotalNumOfSeat = 50;
    // else if (type == 1)
    // this.TotalNumOfSeat = 20;
    // else
    // this.TotalNumOfSeat = 8;
    // this.Showtime = showtimes;
    // seats = new Cinema_Seat[this.TotalNumOfSeat];
    // for (int i = 0; i < this.TotalNumOfSeat; i++) {
    // seats[i] = new Cinema_Seat(i, this);
    // }
    // }

    public int getCinemaID() {
        return Cinema_ID;
    }

    public Date[] getShowtimes() {
        return Showtime;
    }

    public int getType() {
        return this.Type;
    }

    public Movie getMovie() {
        return movie;
    }

    public Seatings[] getSeatings() {
        return Seating;
    }

    public void displayShowtimes() {
        SimpleDateFormat _12HourSDF = new SimpleDateFormat("hh:mm a");
        if (this.movie == null || Showtime == null)
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

    public void addShowtimes(String input) throws IOException {
        SimpleDateFormat _24HourSDF = new SimpleDateFormat("HH:mm");
        SimpleDateFormat _12HourSDF = new SimpleDateFormat("hh:mm a");
        try {
            Date _24HourDt = _24HourSDF.parse(input);
            DateFormat dateFormat = new SimpleDateFormat("HH:mm");  
            String strDate = dateFormat.format(_24HourDt);  
            if (Showtime != null) {
                ArrayList<Date> arrayList = new ArrayList<Date>(Arrays.asList(this.Showtime));
                arrayList.add(_24HourDt);
                this.Showtime = arrayList.toArray(Showtime);
            } else {
                Date[] timings = new Date[1];
                timings[0] = _24HourDt;
                this.Showtime = timings;
            }
            //edit file
            String fileName = "SeatsAvail.txt";
            Path path = Paths.get(fileName);
            int n = (int) Files.lines(path).count();

            String[] lines = new String[n+1]; // overwrite with this
            lines[0] = "CinemaID, Type, Arrangement, Showtime";
            
            ArrayList stringArray = (ArrayList) read(fileName);
            for (int i = 1; i < n; i++) {
                String st = (String) stringArray.get(i);
                lines[i] = st;
            }
            lines[n+1] = Integer.toString(Cinema_ID) + "|" + Integer.toString(Type) + "|00000000000000000000000000000000000000000000000000|" + strDate;
            write(fileName, lines);

            System.out.println("Showtime " + _12HourSDF.format(_24HourDt) + " added.");
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public void editShowtimes(String input, int choice) throws IOException {
        SimpleDateFormat _24HourSDF = new SimpleDateFormat("HH:mm");
        SimpleDateFormat _12HourSDF = new SimpleDateFormat("hh:mm a");
        try {
            Date _24HourDt = _24HourSDF.parse(input);  //new value
            DateFormat dateFormat = new SimpleDateFormat("HH:mm");  
            String newDate = dateFormat.format(_24HourDt); 
            String oldDate = dateFormat.format(this.Showtime[choice]);
            System.out.println("Showtime changed to " + _12HourSDF.format(_24HourDt) + ".");
            this.Showtime[choice] = _24HourDt;

            //edit file
            String fileName = "SeatsAvail.txt";
            Path path = Paths.get(fileName);
            int n = (int) Files.lines(path).count();

            String[] lines = new String[n]; // overwrite with this
            lines[0] = "CinemaID, Type, Arrangement, Showtime";
            
            ArrayList stringArray = (ArrayList) read(fileName);
            for (int i = 1; i < n; i++) {
                String st = (String) stringArray.get(i);
                StringTokenizer star = new StringTokenizer(st, "|");
                String CD = star.nextToken().trim();
                String type = star.nextToken().trim();
                String arr = star.nextToken().trim();
                String ST = star.nextToken().trim();

                String[] check = { CD, type, arr, ST };
                if (Integer.toString(Cinema_ID).compareTo(CD) == 0 & oldDate.compareTo(ST) == 0) {
                    
                    check[3] = newDate;
                }
                lines[i] = String.join("|", check);
            }
            write(fileName, lines);

        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public void removeShowtimes(int choice) throws IOException {
        DateFormat dateFormat = new SimpleDateFormat("HH:mm");
        String strDate = dateFormat.format(this.Showtime[choice]);
        ArrayList<Date> arrayList = new ArrayList<Date>(Arrays.asList(this.Showtime));
        arrayList.remove(choice);
        System.out.println("Showtime removed.");
        this.Showtime = arrayList.toArray(Showtime);

        //edit file
        String fileName = "SeatsAvail.txt";
        Path path = Paths.get(fileName);
        int n = (int) Files.lines(path).count();

        String[] lines = new String[n-1]; // overwrite with this
        lines[0] = "CinemaID, Type, Arrangement, Showtime";
        int count = 1;
        
        ArrayList stringArray = (ArrayList) read(fileName);
        for (int i = 1; i < n; i++) {
            String st = (String) stringArray.get(i);
            StringTokenizer star = new StringTokenizer(st, "|");
            String CD = star.nextToken().trim();
            String type = star.nextToken().trim();
            String arr = star.nextToken().trim();
            String ST = star.nextToken().trim();

            String[] check = { CD, type, arr, ST };
            if (Integer.toString(Cinema_ID).compareTo(CD) == 0 & strDate.compareTo(ST) == 0)
            {continue;}
            lines[count] = String.join("|", check);
            count++;
        }
        write(fileName, lines);
    }

    public void assignMovie(Movie mov) {
        this.movie = mov;
    }

    public static List read(String fileName) throws IOException {
        List data = new ArrayList();
        Scanner scanner = new Scanner(new FileInputStream(fileName));
        try {
            while (scanner.hasNextLine()) {
                data.add(scanner.nextLine());
            }
        } finally {
            scanner.close();
        }
        return data;
    }

    public static void write(String fileName, String[] lines) throws IOException {
        PrintWriter out = new PrintWriter(new FileWriter(fileName));

        try {
            for (int i = 0; i < lines.length; i++) {
                out.println(lines[i]);
            }
        } finally {
            out.close();
        }
    }

}
