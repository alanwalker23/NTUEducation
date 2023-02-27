package MOBLIMA;

import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.Date;
import java.util.Scanner;

public class Price {

    private String moviestatus;// premiere, showing
    private String movieType; // 2d 3d
    private int cinemaclass;// 0 standard, 1 gold, 2 platinum
    // private int ticketType;//0 student, 1 senior citizen, 2 standard
    private boolean checkPH;
    private int getDayOfWeek;

    // need to set prices
    private double PH;
    private double standard;
    private double seniorCitizen;
    private double student;
    private double normal_class;
    private double platinum_class;
    private double gold_class;
    private double PREVIEW;
    private double NOWSHOWING;

    private double twoD;
    private double threeD;

    public Price() throws IOException {
        String fileName = "src/PriceList.txt";
        Path path = Paths.get(fileName);

        Scanner read = new Scanner(new File(fileName));
        read.useDelimiter("|");

        // String PH, standard, seniorCitizen, student, normal_class, platinum_class,
        // gold_class, PREVIEW, NOWSHOWING, twoD, threeD;
        ArrayList stringArray = (ArrayList) read(fileName);
        String st = (String) stringArray.get(1);
        StringTokenizer star = new StringTokenizer(st, "|");

        PH = Double.parseDouble(star.nextToken().trim());
        standard = Double.parseDouble(star.nextToken().trim());
        seniorCitizen = Double.parseDouble(star.nextToken().trim());
        student = Double.parseDouble(star.nextToken().trim());
        normal_class = Double.parseDouble(star.nextToken().trim());
        platinum_class = Double.parseDouble(star.nextToken().trim());
        gold_class = Double.parseDouble(star.nextToken().trim());
        PREVIEW = Double.parseDouble(star.nextToken().trim());
        NOWSHOWING = Double.parseDouble(star.nextToken().trim());
        twoD = Double.parseDouble(star.nextToken().trim());
        threeD = Double.parseDouble(star.nextToken().trim());
    }

    // SETTING PRICES
    // SET PH Price;
    public void setPrice_PH(double PH) throws IOException {
        edit(PH, 0);
        this.PH = PH;
        System.out.println("Price for Public Holiday set to " + this.PH);

    }

    // SETTERS
    // 1. standard
    public void setPrice_standard(double standard) throws IOException {
        edit(standard, 1);
        this.standard = standard;
        System.out.println("Price for Standard set to " + this.standard);
    }

    // 2. seniorCitizen
    public void setPrice_seniorCitizen(double seniorCitizen) throws IOException {
        edit(seniorCitizen, 2);
        this.seniorCitizen = seniorCitizen;
        System.out.println("Price for Senior Citizen set to " + this.seniorCitizen);
    }

    // 3. student
    public void setPrice_student(double student) throws IOException {
        edit(student, 3);
        this.student = student;
        System.out.println("Price for Student set to " + this.student);
    }

    // 4. normal_class for CINEMA
    public void setPrice_normal(double normal_class) throws IOException {
        edit(normal_class, 4);
        this.normal_class = normal_class;
        System.out.println("Price for Standard Class set to " + this.normal_class);
    }

    // 5. premium class for CINEMA
    public void setPrice_platinum(double platinum_class) throws IOException {
        edit(platinum_class, 5);
        this.platinum_class = platinum_class;
        System.out.println("Price for Platinum Class set to " + this.platinum_class);
    }

    // 6. gold class for CINEMA
    public void setPrice_gold(double gold_class) throws IOException {
        edit(gold_class, 6);
        this.gold_class = gold_class;
        System.out.println("Price for Gold Class set to " + this.gold_class);
    }

    // 7. PREVIEW for MOVIE STATUS
    public void setPrice_PREVIEW(double PREVIEW) throws IOException {
        edit(PREVIEW, 7);
        this.PREVIEW = PREVIEW;
        System.out.println("Price for PREVIEW set to " + this.PREVIEW);
    }

    // 8. NOWSHOWING for MOVIE STATUS
    public void setPrice_NOWSHOWING(double NOWSHOWING) throws IOException {
        edit(NOWSHOWING, 8);
        this.NOWSHOWING = NOWSHOWING;
        System.out.println("Price for NOW SHOWING set to " + this.NOWSHOWING);
    }

    // 9. 2D for MOVIE TYPE
    public void setPrice_twoD(double twoD) throws IOException {
        edit(twoD, 9);
        this.twoD = twoD;
        System.out.println("Price for 2D movie set to " + this.twoD);
    }

    // 10. 3D for MOVIE TYPE
    public void setPrice_threeD(double threeD) throws IOException {
        edit(threeD, 10);
        this.threeD = threeD;
        System.out.println("Price for 3D movie set to " + this.threeD);
    }

    // getters for the prices;
    public double getPH() {
        return PH;
    }

    public double getStandard() {
        return standard;
    }

    public double getSeniorCitizen() {
        return seniorCitizen;
    }

    public double getStudent() {
        return student;
    }

    public double getNormal_class() {
        return normal_class;
    }

    public double getPlatinum_class() {
        return platinum_class;
    }

    public double getGold_class() {
        return gold_class;
    }

    public double getPREVIEW() {
        return PREVIEW;
    }

    public double getNOWSHOWING() {
        return NOWSHOWING;
    }

    public double getTwoD() {
        return twoD;
    }

    public double getThreeD() {
        return threeD;
    }

    // setters for the personalised price
    public void setchosen_Moviestatus(String moviestatus) {
        this.moviestatus = moviestatus;
    }

    public void setchosen_MovieType(String movieType) {
        this.movieType = movieType;
    }

    public void setchosen_Cinemaclass(int cinemaclass) {
        this.cinemaclass = cinemaclass;
    }

    public void setchosen_CheckPH(boolean checkPH) {
        this.checkPH = checkPH;
    }

    public void setchosen_GetDayOfWeek(int getDayOfWeek) {
        this.getDayOfWeek = getDayOfWeek;
    }

    // print all prices
    public void printPrices() {
        System.out.println("PublicHoliday");
        System.out.println(PH);
        System.out.println("Standard Price|Senior Citizen|Student");
        System.out.println(standard + " | " + seniorCitizen + " | " + student);

        System.out.println("2D | 3D");
        System.out.println(2D + " | " + 3D);
        System.out.println("Standard | Platinum | Gold");
        System.out.println(normal_class + " | " + platinum_class + " | " + gold_class);
        System.out.println("Preview  | Now Showing");
        System.out.println(PREVIEW + " | " + NOWSHOWING);
    }

    // upon setting the price, just return;
    public double[] setFinalPrice() {
        double finalPrice = 0;

        double[] agePrice = new double[3]; // store age price of moviegoer
        for (int i = 0; i < 3; i++) {
            agePrice[0] = 0;
        }
        double cinemaStatusPrice = 0; // store cinema status price
        double movieStatusPrice = 0; // showing or premiere price;
        double movieTypePrice = 0; // 2d or 3d

        // check if public holiday or saturday or sunday
        if (checkPH || getDayOfWeek == 6 || getDayOfWeek == 7) { // if public holiday, saturday, sunday
            for (int i = 0; i < 3; i++) {
                agePrice[i] = PH;
            }
        } else { // normal date
            // check age
            agePrice[0] = standard; // standard
            agePrice[1] = seniorCitizen; // senior citizen
            agePrice[2] = student; // student
        }

        // check cinemaStatus
        cinemaStatusPrice = normal_class; // 0 = standard = 50 (3 4 3)x5 // 1 = gold = 20 (5 5)x2 // 2 = platinum = 8 (2
                                          // 2) x2
        if (cinemaclass == 1) {
            cinemaStatusPrice = gold_class;
        } else if (cinemaclass == 2) {
            cinemaStatusPrice = platinum_class;
        }

        // check status of movie
        movieStatusPrice = NOWSHOWING;
        if (moviestatus == "PREVIEW") {
            movieStatusPrice = PREVIEW;
        }

        movieTypePrice = twoD;
        if (movieType == "3D") {
            movieTypePrice = threeD;
        }
        // IF PH, regardless of age, it is still the PH price
        for (int i = 0; i < 3; i++) {
            agePrice[i] = agePrice[i] * cinemaStatusPrice * movieStatusPrice * movieTypePrice;
        }

        return agePrice;
    }

    private void edit(double replace, int col) throws IOException {
        String PH, standard, seniorCitizen, student, normal_class, platinum_class, gold_class, PREVIEW, NOWSHOWING,
                twoD, threeD;

        String fileName = "src/PriceList.txt";
        Path path = Paths.get(fileName);
        int n = (int) Files.lines(path).count();

        String[] lines = new String[n];
        lines[0] = "PH|standard|seniorCitizen|student|normal_class|platinum_class|gold_class|PREVIEW|NOWSHOWING|2D|3D";
        int count = 1;

        ArrayList stringArray = (ArrayList) read(fileName);
        String st = (String) stringArray.get(1);
        StringTokenizer star = new StringTokenizer(st, "|");

        PH = star.nextToken().trim();
        standard = star.nextToken().trim();
        seniorCitizen = star.nextToken().trim();
        student = star.nextToken().trim();
        normal_class = star.nextToken().trim();
        platinum_class = star.nextToken().trim();
        gold_class = star.nextToken().trim();
        PREVIEW = star.nextToken().trim();
        NOWSHOWING = star.nextToken().trim();
        twoD = star.nextToken().trim();
        threeD = star.nextToken().trim();

        String[] check = { PH, standard, seniorCitizen, student, normal_class, platinum_class, gold_class, PREVIEW,
                NOWSHOWING, twoD, threeD };
        check[col] = Double.toString(replace);
        lines[1] = String.join("|", check);

        write(fileName, lines);
    }

    private static List read(String fileName) throws IOException {
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

    private static void write(String fileName, String[] lines) throws IOException {
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