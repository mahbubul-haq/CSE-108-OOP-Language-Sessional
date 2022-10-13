package tcpdiff;

import java.util.Scanner;

import util.NetworkUtil;

public class Client {

    RSmessage rSmessage;

    public Client(String serverAddress, int serverPort) {
        try {
            System.out.print("Enter name of the client: ");
            Scanner scanner = new Scanner(System.in);
            String clientName = scanner.nextLine();
            System.out.println("Enter password of the client: ");
            String clientPass=scanner.nextLine();

            rSmessage=new RSmessage(clientName,clientPass);

            String namepass=clientName+" "+clientPass;

            NetworkUtil nc = new NetworkUtil(serverAddress, serverPort);
            nc.write(namepass);
            new ReadThread(nc);
            new WriteThreadClient(nc, namepass);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String args[]) {
        String serverAddress = "127.0.0.1";
        int serverPort = 33333;
        Client client = new Client(serverAddress, serverPort);
    }
}

