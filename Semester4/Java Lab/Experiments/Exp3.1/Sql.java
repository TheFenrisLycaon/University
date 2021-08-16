import java.sql.*;
import java.util.Scanner;

public class Sql {

    public static void main(String[] args) {
    
        try{ 
        
            String customerName=null;
            String productName=null;
            String quantity;

            Scanner sc=new Scanner(System.in);
            
            System.out.print("Enter the Customer Name, Product Name and Quantity::\n");
            
            customerName=sc.next();
            productName=sc.next();
            quantity=sc.next();
            
            Class.forName("org.mariadb.jdbc.Driver");
            Connection con=DriverManager.getConnection("jdbc:mysql://localhost/test","fenris","wtf"); 
            Statement stmt=con.createStatement();
            
            PreparedStatement ps=con.prepareStatement("insert into inventory values(?,?,?)"); 
            
            ps.setString(1,customerName); 
            ps.setString(2,productName); 
            ps.setString(3,quantity);
            ps.executeUpdate();
            
            System.out.println("Successfully");
            
            ResultSet rs=stmt.executeQuery("select * from inventory"); 
            
            while(rs.next()) {
            
                System.out.println(rs.getString(1)+" "+rs.getString(2)+" "+rs.getString(3));
                System.out.println("Successfully");
            }
            con.close(); 
        }
        catch(Exception e){ 
            System.out.println(e);
        } 
    }    
}
