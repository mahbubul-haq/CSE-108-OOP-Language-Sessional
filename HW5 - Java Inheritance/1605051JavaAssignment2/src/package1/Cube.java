package package1;

public class Cube extends Shape {

    private double side;
    static int num=1;

    public double getSide() {
        return side;
    }

    public void setSide(double side) {
        this.side = side;
    }

    Cube(double side){
        super("Cube"+num);
        num++;
        this.side=side;
    }

    @Override
    public double volume() {
        return side*side*side;
    }
}
