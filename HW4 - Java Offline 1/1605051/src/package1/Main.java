package package1;
import java.util.*;
import java.io.*;

public class Main {

    private static final String INPUT_FILE_NAME = "in.txt";
    private static final String OUTPUT_FILE_NAME = "out.txt";

    public static void main(String[] args) {

        Scanner scn=new Scanner(System.in);
        int option=0;
        List<Car> carList = new ArrayList();

        try {
            String line;
            BufferedReader br = new BufferedReader(new FileReader(INPUT_FILE_NAME));
            while (true) {
                line = br.readLine();
                if (line == null) break;
                String []info=line.split(",");
                carList.add(new Car(info[0],info[1],info[2],info[3],info[4],info[5],info[6],info[7]));
            }
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        for(Car c:carList){
            System.out.println(c.regNum+","+c.yearMade+","+c.firstColor+","+c.secondColor+","+c.thirdColor+","+c.carMake+","+c.getCarModel()+","+c.getCarPrice());
        }

        while(true){
            System.out.print("(1) Search Cars\n");
            System.out.print("(2) Add Car\n");
            System.out.print("(3) Delete Car\n");
            System.out.print("(4) Exit System\n\n");

            option=scn.nextInt();
            if(option==1){
                int carSearchOption=0;
                while(true){
                    System.out.println("(1) By Registration Number");
                    System.out.println("(2) By Car Make and Car Model");
                    System.out.println("(3) Back to Main Menu\n");
                    carSearchOption=scn.nextInt();

                    if(carSearchOption==1){
                        System.out.println("Enter registration number:");
                        scn.nextLine();
                        String searchRegNum=scn.nextLine();
                        int i=0;
                        for(i=0;i<carList.size();i++){
                            if(carList.get(i).regNum.equals(searchRegNum)){
                                Car c=carList.get(i);
                                System.out.println(c.regNum+","+c.yearMade+","+c.firstColor+","+c.secondColor+","+c.thirdColor+","+c.carMake+","+c.getCarModel()+","+c.getCarPrice());
                                break;
                            }
                        }
                        if(i!=carList.size()){
                            break;
                        }
                        else{
                            System.out.println("There is no car with this registration number!");
                        }
                    }
                    else if(carSearchOption==2){
                        System.out.println("Enter carMake:");
                        scn.nextLine();
                        String input=scn.nextLine();
                        int i=0;
                        for(i=0;i<carList.size();i++){
                            if(carList.get(i).carMake.toUpperCase().equals(input.toUpperCase())){
                                System.out.println("Enter carModel:");
                                String carmod=scn.nextLine();

                                if(carmod.toUpperCase().equals("ANY")){
                                    for(int i1=0;i1<carList.size();i1++){
                                        if(input.toUpperCase().equals(carList.get(i1).carMake.toUpperCase())){
                                            Car c=carList.get(i1);
                                            System.out.println(c.regNum+","+c.yearMade+","+c.firstColor+","+c.secondColor+","+c.thirdColor+","+c.carMake+","+c.getCarModel()+","+c.getCarPrice());
                                        }
                                    }
                                }
                                else{
                                    int i1=0;
                                    boolean count=false;
                                    for(i1=0;i1<carList.size();i1++){
                                        if(carmod.toUpperCase().equals(carList.get(i1).carModel.toUpperCase())&&input.toUpperCase().equals(carList.get(i1).carMake.toUpperCase())){
                                            Car c=carList.get(i1);
                                            count =true;
                                            System.out.println(c.regNum+","+c.yearMade+","+c.firstColor+","+c.secondColor+","+c.thirdColor+","+c.carMake+","+c.getCarModel()+","+c.getCarPrice());
                                        }
                                    }
                                    if(count==false){
                                        System.out.println("There is not car with this carModel in "+input.toUpperCase()+" carMake");
                                    }
                                }

                                break;
                            }
                        }
                        if(i==carList.size()){
                            System.out.println("There is no car with this carMake!");
                        }

                    }
                    else if(carSearchOption==3){
                        break;
                    }
                    else{
                        System.out.println("Please Enter Correct Car Searching Option\n");
                    }
                }
            }
            else if(option==2){
                String addNewCar=null;
                scn.nextLine();
                System.out.println("Enter the information of the new Car:");
                addNewCar=scn.nextLine();
                String []splitted=addNewCar.split(",");

                boolean cnt=false;
                for(int i=0;i<carList.size();i++){
                    if(splitted[0].equals(carList.get(i).regNum)){
                        cnt=true;
                    }
                }

                if(cnt==true){
                    System.out.println("The registration number already exists");
                }

                else if(splitted.length!=8){
                    System.out.println("Invalid Car!");
                }

                else {
                    carList.add(new Car(addNewCar));

                    try {
                        BufferedWriter bw = new BufferedWriter(new FileWriter(INPUT_FILE_NAME));

                        for (int ii = 0; ii < carList.size(); ii++) {
                            bw.write(carList.get(ii).getStr());
                        }

                        bw.close();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }

            }
            else if(option==3){
                String deleteC=null;
                scn.nextLine();
                System.out.println("Enter the registration number to delete:");
                deleteC=scn.nextLine();

                boolean cnt=false;
                for(int i=0;i<carList.size();i++){
                    if(deleteC.equals(carList.get(i).regNum)){
                        cnt=true;
                        carList.remove(i);
                    }
                }

                if(cnt==false){
                    System.out.println("The registration number does not exists");
                }
                else{
                    try {
                        BufferedWriter br = new BufferedWriter(new FileWriter(INPUT_FILE_NAME));

                        for (int i = 0; i < carList.size(); i++) {
                            br.write(carList.get(i).getStr());
                        }
                        br.close();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }

            else if(option ==4){
                System.exit(0);
            }
            else{
                System.out.println("Please Press Correct Option!\n");
            }
        }
    }
}
