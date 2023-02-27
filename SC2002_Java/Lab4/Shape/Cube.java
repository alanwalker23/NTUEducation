package SC2002_Java.Lab4.Shape;

public class Cube extends Square implements _3d {
    public Cube(int side) {
        super(side);
    }

    public double getVolume() {
        return Math.pow(super.getSide(), 3);
    }

    @Override
    public double getSurfaceArea() {
        // TODO Auto-generated method stub
        return 0;
    }
}
