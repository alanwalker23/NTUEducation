package SC2002_Java.Lab4.Shape;

public class Pyramid extends Triangle implements _3d {

    // height refers to vertical height
    public Pyramid(int height, int base) {
        super(height, base);
    }

    public double getVolume() {
        return (1.0 / 3.0) * Math.pow(super.getBase(), 2) * super.getHeight();
    }

    @Override
    public double getSurfaceArea() {
        // TODO Auto-generated method stub
        return (super.getBase() * super.getBase() + super.getArea() * 4);
    }
}