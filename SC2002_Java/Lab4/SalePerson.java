package SC2002_Java.Lab4;

public class SalePerson implements Comparable<SalePerson> {
    private String firstName;
    private String lastName;
    private int totalSales;

    public SalePerson(String fname, String lname, int sales) {
        firstName = fname;
        lastName = lname;
        totalSales = sales;
    }

    public String toString() {
        String text = "<" + lastName + "> , <" + firstName + "> : <" + totalSales + ">";
        return text;
    }

    public boolean equals(SalePerson o) {
        if (o.firstName == firstName && o.lastName == lastName)
            return true;
        return false;
    }

    public int compareTo(SalePerson o) {
        if (totalSales < o.totalSales)
            return -1;
        else if (totalSales > o.totalSales)
            return 1;
        else
            return o.lastName.compareTo(lastName);
    }
}
