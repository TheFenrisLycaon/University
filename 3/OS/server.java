import java.net.*;  
import java.io.*;  

class server{  
    public static void main(String args[])throws Exception{  
        ServerSocket serverSocket=new ServerSocket(3333);  
        Socket s=serverSocket.accept();  

        DataInputStream dataIn=new DataInputStream(s.getInputStream());  
        DataOutputStream dataOut=new DataOutputStream(s.getOutputStream());  
        BufferedReader input=new BufferedReader(new InputStreamReader(System.in));  
        
        String str="", stringMade="";  

        while(!str.equals("stop")){  

            str=dataIn.readUTF();  
            System.out.println("Fenris: "+str);  
            stringMade=input.readLine();  
            dataOut.writeUTF(stringMade);  
            dataOut.flush();  

            }  
        dataIn.close();  
        s.close();  
        serverSocket.close();  
    }
}  