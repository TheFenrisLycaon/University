import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Auction_data extends HttpServlet {
    private static final long serialVersionUID = 1L;
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        response.setContentType("text/html"); 
        PrintWriter out = response.getWriter(); 
        String n=request.getParameter("userName"); 
        String p=request.getParameter("productName"); 
        int e=Integer.parseInt(request.getParameter("bidValue")); 
        try{ 
            Class.forName("com.mysql.jdbc.Driver"); 
            Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/aiml2_b_2021","root",""); 
            Statement stmt=con.createStatement(); 
            PreparedStatement ps=con.prepareStatement("insert into user values(?,?,?)"); 
            ps.setString(1,n); 
            ps.setString(2,p); 
            ps.setInt(3,e); 
            int i=ps.executeUpdate(); 
            if(i>0) 
            out.print("You are successfully registered..."); 
            ResultSet rs=stmt.executeQuery("select * from user where user='"+n+"'"); 
            while(rs.next()) 
            out.println("<br>Your data is:"+rs.getString(1)+" "+rs.getString(2)+" "+rs.getInt(3));  
            con.close();
        }   catch (Exception e2)
        {   System.out.println(e2); } 
        out.close(); 
    } 
}
