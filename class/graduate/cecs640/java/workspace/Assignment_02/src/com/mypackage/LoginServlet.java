package com.mypackage;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class LoginServlet
 */
@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	private String            dbName       = "d0camp03";
    private String            userId       = "d0camp03";
    private String            password     = "Spring2017";
    private String            host         = "jdbc:db2://216.249.138.85:50000/";
    private String            url          = host + dbName;
    private String            driver       = "com.ibm.db2.jcc.DB2Driver";
    private static Connection dbConnection = null;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public LoginServlet() throws SQLException, ClassNotFoundException {
        super();
    }
    
    private void login(HttpServletRequest request, HttpServletResponse response, boolean errorMessage) throws ClassNotFoundException, SQLException, IOException {
    	String fName = "";
    	
    	// Load the driver
        Class.forName(driver);
        System.out.println("Driver loaded");
        
        // Establish a connection
        dbConnection = DriverManager.getConnection(url, userId, password);
        System.out.println("Database Connected");
        
        // Create a statement
        Statement s = dbConnection.createStatement();
        
        // Execute statement
        String userName = request.getParameter("userName");
        String pw = request.getParameter("password");
        String query = "SELECT * FROM USERS WHERE \"userid\" = '" + userName + "' AND \"password\" = '" + pw + "'";
        ResultSet rs = s.executeQuery(query);
        
        // Get the first name of the logged in user. If the user does not exist, set the loginError to true
        try {
        	if (rs.next()) {
        		fName = (rs.getString("FNAME"));
        	}
        	else
        		errorMessage = true;
        }
        catch (SQLException e) {
        	e.printStackTrace();
        }
        
        if (errorMessage) {
        	// Reload the webpage and set the loginError to true
			request.setAttribute("loginError", "true");
			try {
				doGet(request, response);
			} catch (ServletException | IOException e) {
				e.printStackTrace();
			}
		}
        else {
        	// Print a success page
        	response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            out.println("<HTML>");
            out.println("<HEAD>");
            out.println("<TITLE>Success!</TITLE>");
            out.println("<H2>Welcome to the website, " + fName + "!</H2>");
            out.println("</HEAD>");
            out.println("<BODY>");
            out.println("</BODY>");
            out.println("</HTML>");
        }
        
        // Close the connection
        dbConnection.close();
    }
    
    /**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<HTML>");
        out.println("<HEAD>");
        out.println("<TITLE>Login</TITLE>");
        out.println("</HEAD>");
        out.println("<BODY>");
        out.println("<CENTER>");
        
        String errorMessage = "false";
	    Object error = request.getAttribute("loginError");
	    if (error != null)
	        errorMessage = error.toString();
	    
        if (errorMessage == "true")
        {
            out.println("Login failed. Please try again.<BR>");
        }
        out.println("<BR>");
        out.println("<BR><H2>Login Page</H2>");
        out.println("<BR>");
        out.println("<BR>Please enter your user name and password.");
        out.println("<BR>");
        out.println("<BR><FORM METHOD=POST>");
        out.println("<TABLE>");
        out.println("<TR>");
        out.println("<TD>User Name:</TD>");
        out.println("<TD><INPUT TYPE=TEXT NAME=userName></TD>");
        out.println("</TR>");
        out.println("<TR>");
        out.println("<TD>Password:</TD>");
        out.println("<TD><INPUT TYPE=PASSWORD NAME=password></TD>");
        out.println("</TR>");
        out.println("<TR>");
        out.println("<TD ALIGN=RIGHT COLSPAN=2>");
        out.println("<INPUT TYPE=SUBMIT VALUE=Login></TD>");
        out.println("</TR>");
        out.println("</TABLE>");
        out.println("</FORM>");
        out.println("</CENTER>");
        out.println("</BODY>");
        out.println("</HTML>");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// Try to login with the given credentials
		try {
			login(request, response, false);
		} catch (ClassNotFoundException | SQLException e) {
			e.printStackTrace();
		}
	}

}
