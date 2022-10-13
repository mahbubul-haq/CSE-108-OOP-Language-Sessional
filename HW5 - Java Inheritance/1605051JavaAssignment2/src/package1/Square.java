package package1;

public class Square extends Shape {

    private double side;
    static int num=1;

    Square(double side){
        super("Square"+num);
        num++;
        this.side=side;
    }

    public double area(){
        return side*side;
    }

    public double getSide() {
        return side;
    }

    public void setSide(double side) {
        this.side = side;
    }
}
