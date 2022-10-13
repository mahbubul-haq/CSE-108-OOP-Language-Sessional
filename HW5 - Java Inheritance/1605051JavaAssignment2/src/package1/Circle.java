package package1;

public class Circle extends Shape {
    private double radius;
    static int num=1;

    Circle(double radius){
        super("Circle"+num);
        this.radius=radius;
        num++;
    }
    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double area(){
        return 3.1416*radius*radius;
    }

}
