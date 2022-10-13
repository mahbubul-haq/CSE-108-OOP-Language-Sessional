package package1;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        Shape shape;

        while(true){
            System.out.println("Please Select Your Choice:");
            System.out.println("1. Circle");
            System.out.println("2. Cylinder");
            System.out.println("3. Sphere");
            System.out.println("4. Square");
            System.out.println("5. Cube");
            System.out.println("6. Exit");

            int input=sc.nextInt();

            if(input==1){
                System.out.print("Enter Radius: ");
                double radius=sc.nextDouble();
                try{
                    if(radius<0.00) throw new MyException();
                }
                catch(Exception e){
                    System.out.println(e);
                    continue;
                }
                shape=new Circle(radius);
                System.out.println("Name: "+shape.getShape());
                System.out.println("Area: "+shape.area());
                System.out.println();
            }
            else if(input==2){
                System.out.print("Enter radius: ");
                double radius=sc.nextDouble();
                try{
                    if(radius<0.00) throw new MyException();
                }
                catch(Exception e){
                    System.out.println(e);
                    continue;
                }
                System.out.print("Enter height: ");
                double height=sc.nextDouble();
                try{
                    if(height<0.00) throw new MyException();
                }
                catch(Exception e){
                    System.out.println(e);
                    continue;
                }
                shape=new Cylinder(radius,height);
                System.out.println("Name: "+shape.getShape());
                System.out.println("Area of the base: "+shape.base_area());
                System.out.println("Area of surface: "+shape.surface_area());
                System.out.println("Volume: "+shape.volume());
                System.out.println();
            }
            else if(input==3){
                System.out.print("Enter radius: ");
                double radius=sc.nextDouble();
                try{
                    if(radius<0.00) throw new MyException();
                }
                catch(Exception e){
                    System.out.println(e);
                    continue;
                }
                shape=new Sphere(radius);
                System.out.println("Name: "+shape.getShape());
                System.out.println("Volume: "+shape.volume());
                System.out.println();
            }
            else if(input==4){
                System.out.print("Enter side: ");
                double side=sc.nextDouble();
                try{
                    if(side<0.00) throw new MyException();
                }
                catch(Exception e){
                    System.out.println(e);
                    continue;
                }
                shape=new Square(side);
                System.out.println("Name: "+shape.getShape());
                System.out.println("Area: "+shape.area());
                System.out.println();
            }
            else if(input==5){
                System.out.print("Enter side: ");
                double side=sc.nextDouble();
                try{
                    if(side<0.00) throw new MyException();
                }
                catch(Exception e){
                    System.out.println(e);
                    continue;
                }
                shape=new Cube(side);
                System.out.println("Name: "+shape.getShape());
                System.out.println("Volume: "+shape.volume());
                System.out.println();
            }
            else System.exit(0);

        }











    }
}
