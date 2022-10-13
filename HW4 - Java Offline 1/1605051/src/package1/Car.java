package package1;

public class Car {

    String regNum,yearMade,firstColor,secondColor,thirdColor,carMake,carModel,carPrice;

    public Car(String regNum,String yearMade,String firstColor,String secondColor,String thirdColor,String carMake,String carModel,String carPrice){
        this.regNum=regNum;
        this.yearMade=yearMade;
        this.firstColor=firstColor;
        this.secondColor=secondColor;
        this.thirdColor=thirdColor;
        this.carMake=carMake;
        this.carModel=carModel;
        this.carPrice=carPrice;
    }
    public Car(String line){
        try {
            String[] str = line.split(",");
            this.regNum = str[0];
            this.yearMade = str[1];
            this.firstColor = str[2];
            this.secondColor = str[3];
            this.thirdColor = str[4];
            this.carMake = str[5];
            this.carModel = str[6];
            this.carPrice = str[7];
        }
        catch(Exception e){
            System.out.println(e);
        }
    }

    public  String getStr(){
        return regNum+","+yearMade+","+firstColor+","+secondColor+","+thirdColor+","+carMake+","+carModel+","+carPrice+"\n";
    }

    public String getRegNum() {
        return regNum;
    }

    public void setRegNum(String regNum) {
        this.regNum = regNum;
    }

    public String getYearMade() {
        return yearMade;
    }

    public void setYearMade(String yearMade) {
        this.yearMade = yearMade;
    }

    public String getFirstColor() {
        return firstColor;
    }

    public void setFirstColor(String firstColor) {
        this.firstColor = firstColor;
    }

    public String getSecondColor() {
        return secondColor;
    }

    public void setSecondColor(String secondColor) {
        this.secondColor = secondColor;
    }

    public String getThirdColor() {
        return thirdColor;
    }

    public void setThirdColor(String thirdColor) {
        this.thirdColor = thirdColor;
    }

    public String getCarMake() {
        return carMake;
    }

    public void setCarMake(String carMake) {
        this.carMake = carMake;
    }

    public String getCarModel() {
        return carModel;
    }

    public void setCarModel(String carModel) {
        this.carModel = carModel;
    }

    public String getCarPrice() {
        return carPrice;
    }

    public void setCarPrice(String carPrice) {
        this.carPrice = carPrice;
    }
}
