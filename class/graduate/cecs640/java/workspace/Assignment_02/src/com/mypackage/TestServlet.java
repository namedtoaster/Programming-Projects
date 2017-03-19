package com.mypackage;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class TestServlet
 */
@WebServlet("/TestServlet")
public class TestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	//private Connection connection = null;
	//private PreparedStatement statement = null;
	//private ResultSet rs = null;
	
	/**
     * @see HttpServlet#HttpServlet()
     */
    public TestServlet() {
        super();
        
        // Create a connection
        /*String dbName = "docamp03", userid = "d0camp03", password = "Spring2017",
        		host = "jdbc:db2://216.249.138.85:50000/", url = null, driver = "com.ibm.db2.jcc.DB2Driver",
        		connection = null;
        new DatabaseConnectionController(dbName, userid, password, host, url, driver, connection);*/
    }
	
    /*public Connection connectToDb(String driver, String url, String DBUserId, String DBPassword) {
        try
        {
            Class.forName(driver).newInstance();
            System.out.println("Connected to '" + url + "' database using JDBC type 4 driver.");
        }
        catch (InstantiationException e)
        {
            System.out.println("Driver class cannot be instantiated.\n");
        }
        catch (IllegalAccessException e)
        {
            System.out.println("Driver class cannot be accessed.\n");
        }
        catch (ClassNotFoundException e)
        {
            System.out.println("Driver class not found, please check the PATH" + " and CLASSPATH system variables to ensure they are correct.\n");
        }
        try
        {
            connection = DriverManager.getConnection(url, DBUserId, DBPassword);
        }
        catch (SQLException sqle)
        {
            System.out.println("Cannot get database connection: " + sqle.getMessage() + "\n");
            sqle.printStackTrace();
        }
        return connection;
    }
    
    public PreparedStatement executeStatement(String query) {
    	try
        {
            statement = connection.prepareStatement(query);
        }
        catch (SQLException sqle)
        {
            System.out.println("Error preparing statement: " + sqle.getMessage() + "\n");
            sqle.printStackTrace();
        }
    	return statement;
    }
    
    public void executeQuery(PreparedStatement statement) throws SQLException {
    	try
        {
            rs = statement.executeQuery();
            ResultSetMetaData rsmd = rs.getMetaData();
            int count = rsmd.getColumnCount();
            while (rs.next()) {
            	for (int x = 0; x < count; x++) {
            		System.out.print(rs.getString(x + 1) + " ");
            	}
            }
        }
        catch (SQLException sqle)
        {
            System.out.println("Execute Query SQL Error: " + sqle.getMessage() + "\n");
            sqle.printStackTrace();
        }
        finally
        {
            if (rs != null)
            {
				rs.close();
            } // end if
            if (statement != null)
            {
                statement.close();
            } // end if
            if (connection != null)
            {
                connection.close();
            } // end if
        }
    }
    
	public void execute() throws SQLException
    {
        String Driver = "com.ibm.db2.jcc.DB2Driver", URL = "jdbc:db2://216.249.138.85:50000/d0camp03", 
        		DBUserId = "d0camp03",DBPassword = "Spring2017";
        
        connection = connectToDb(Driver, URL, DBUserId, DBPassword);
        
        // TODO: case statements that determine what the user is trying to do
        int choice = 1;
        
        if (choice == 1) {
        	// TODO: get info for user login
        	statement = executeStatement("SELECT * FROM d0camp03.USERS WHERE userid = d0camp03 AND password = password123");
        }
        executeQuery(statement);
    }*/
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Set up connection and do things
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
