public class Circle {

    private double radius;
    private static final double pi = 3.14;

    // Default Constructor
    public Circle() {
        this.radius = 1.0;
    }

    // Specified Constructor
    public Circle(double rad) {
        radius = rad;
    }

    public void setRadius(double rad) {
        radius = rad;
        System.out.println();
    }

    public double getRadius() {
        return this.radius;
    }

    public double area() {
        return this.radius * this.radius * pi;
    }

    public double circumference() {
        return 2 * pi * this.radius;
    }

    public void printArea() {
        System.out.println("Area is: " + area());
    }

    public void printCircumference() {
        System.out.println("Cir is: " + circumference());
    }
}
