package package1;

public abstract class Shape implements Area, Volume{

    private String shape="DummyShape";

    Shape(String shape){
        this.shape=shape;
    }

    public String getShape() {
        return shape;
    }

    public void setShape(String shape) {
        this.shape = shape;
    }

    public double area(){
        return 0.00;
    }

    public double volume(){
        return 0.00;
    }

    @Override
    public double base_area() {
        return 0;
    }

    @Override
    public double surface_area() {
        return 0;
    }
}
