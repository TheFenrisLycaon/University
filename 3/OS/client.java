import java.net.*;  
import java.io.*;  

class client{  
	public static void main(String args[])throws Exception{  
		
		Socket s=new Socket("localhost",3333);  
		DataInputStream dataIn=new DataInputStream(s.getInputStream());  
		DataOutputStream dataOut=new DataOutputStream(s.getOutputStream());  
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));  
		
		String str="",stringMade=""; 

		while(!str.equals("stop")){  
			str=input.readLine();  
			dataOut.writeUTF(str);  
			dataOut.flush();  
			stringMade=dataIn.readUTF();  
			System.out.println("Lyaon: "+stringMade);  
			}  
		
		dataOut.close();  
		s.close();  
	}
}  