import java.util.Scanner;

public class Shape2DApp {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int numShapes = 0;
        int shapeChoice = 0;
        int tempLength, tempWidth, tempHeight, tempBase;

        System.out.println("Enter number of shapes to produce:");
        numShapes = sc.nextInt();
        Shape[] shapeArr = new Shape[numShapes];

        for (int i = 0; i < numShapes; i++) {
            shapeChoice = 0;
            System.out.println("...Choose shape #" + (i + 1));
            System.out.println("Enter 1 for Circle, 2 for Rectangle, 3 for Square, 4 for Triangle");
            Shape shape;
            do {
                shapeChoice = sc.nextInt();
                switch (shapeChoice) {
                    case 1:
                        System.out.println("Circle chosen");
                        System.out.println("...Enter radius");
                        shape = new Circle(sc.nextInt());
                        System.out.println("Area is " + shape.getArea());
                        break;

                    case 2:
                        System.out.println("Rectangle chosen");
                        System.out.println("...Enter length");
                        tempLength = sc.nextInt();
                        System.out.println("...Enter width");
                        tempWidth = sc.nextInt();
                        shape = new Rectangle(tempLength, tempWidth);
                        System.out.println("Area is " + shape.getArea());
                        break;

                    case 3:
                        System.out.println("Square chosen");
                        System.out.println("...Enter side");
                        Square square = new Square(sc.nextInt());
                        System.out.println("Area is " + square.getArea());
                        break;

                    case 4:
                        System.out.println("Triangle chosen");
                        System.out.println("...Enter height");
                        tempHeight = sc.nextInt();
                        System.out.println("...Enter base");
                        tempBase = sc.nextInt();
                        Triangle triangle = new Triangle(tempHeight, tempBase);
                        System.out.println("Area is " + triangle.getArea());
                        break;

                    default:
                        shapeChoice = 0;
                }
            } while (shapeChoice == 0);
        }
        double ttlArea = 0.0;
        for (Shape s : shapeArr) {
            ttlArea += s.getArea();
        }

        System.out.println(String.format("Total area of all the shape is %f", totalArea));
        System.out.println("### Program ended ###");
        System.exit(0);
    }
}