package tcpdiff;

public class RSmessage {

    public String username=null;
    public String password=null;

    public RSmessage(String username,String password){
        this.username=username;
        this.password=password;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassowrd() {
        return password;
    }

    public void setPassowrd(String psasowrd) {
        this.password = psasowrd;
    }
}
