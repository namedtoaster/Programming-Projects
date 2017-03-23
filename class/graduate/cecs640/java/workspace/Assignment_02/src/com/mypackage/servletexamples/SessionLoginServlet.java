package com.mypackage.servletexamples;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.mypackage.controllers.DatabaseConnectionController;
import com.mypackage.controllers.UsersController;
/**
 * Servlet implementation class SessionLoginServlet
 */
@WebServlet("/SessionLoginServlet")
public class SessionLoginServlet extends HttpServlet
{
    private static final long                   serialVersionUID = 1L;
    private static DatabaseConnectionController dbCC             = null;
    private static Connection                   connection       = null;
    /**
     * 
     */
    public SessionLoginServlet()
    {
        dbCC = new DatabaseConnectionController("d0camp03");
        dbCC.establishDBConnection();
        connection = dbCC.getDbConnection();
    }
    /**
     * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        sendLoginForm(response, false);
    }
    /**
     * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        String userName = request.getParameter("userId");
        String password = request.getParameter("password");
        if (login(userName, password))
        {
            HttpSession session = request.getSession(true);
            session.setAttribute("loggedIn", new String("true"));
            session.setAttribute("DatabaseConnection", connection);
            response.sendRedirect("Welcome");
        }
        else
        {
            sendLoginForm(response, true);
        }
    }
    private void sendLoginForm(HttpServletResponse response, boolean errorMessage) throws ServletException, IOException
    {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">");
        out.println("<html>");
        out.println("<head>");
        out.println("<link rel=\"stylesheet\" href=\"style.css\">");
        out.println("<link href=\"https://fonts.googleapis.com/css?family=Cabin\" rel=\"stylesheet\">");
        out.println("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=ISO-8859-1\">");
        out.println("<title>Login</title>");
        out.println("</head>");
        out.println("<body>");
        if (errorMessage)
        {
            out.println("<h4>Login failed! Please try again.</h4>");
        }
        out.println("<h3>Login</h3>");
        out.println("<form method=\"post\" action=\"SessionLoginServlet\">");
        out.println("<input type=\"text\" name=\"userId\" placeholder=\"User ID\">");
        out.println("<input type=\"password\" name=\"password\" placeholder=\"Password\">");
        out.println("<input class=\"button\" type=\"submit\" value=\"Submit\">");
        out.println("</form>");
        out.println("</body>");
        out.println("</html>");
    }
    public static boolean login(String userId, String password)
    {
        boolean exists = false;
        UsersController user = new UsersController(connection);
        System.out.println(connection);
        if (user.findUser(userId, password))
        {
            exists = true;
        }
        return exists;
    }
}
