package SC2002_Java.Lab4.Shape;

public class Cuboid extends Rectangle implements _3d {

    private int height;

    public Cuboid(int length, int width, int height) {
        super(length, width);
        this.height = height;
    }

    public double getVolume() {
        return super.getLength() * super.getWidth() * this.height;
    }

    @Override
    public double getSurfaceArea() {
        // TODO Auto-generated method stub
        return 0;
    }
}
