package package1;

public class Cylinder extends Shape{
    private double radius,height;
    static int num=1;

    Cylinder(double radius, double height){
        super("Cylinder"+num);
        num++;
        this.radius=radius;
        this.height=height;
    }

    public double volume(){
        return 3.1416*radius*radius*height;
    }

    public double surface_area(){
        return 2*3.1416*radius*height;
    }

    public double base_area(){
        return 3.1416*radius*radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }
}
