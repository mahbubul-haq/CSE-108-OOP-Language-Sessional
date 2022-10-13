package package1;

public class Sphere extends Shape {
    private double radius;
    static int num=1;

    Sphere(double radius){
        super("Sphere"+num);
        num++;
        this.radius=radius;
    }
    public double volume(){
        return 4.00*radius*radius*radius/3.00;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }
}
