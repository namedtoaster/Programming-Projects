package com.mypackage.content;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.mypackage.controllers.UsersController;
/**
 * Servlet implementation class Content2Servlet
 */
@WebServlet("/Content2Servlet")
public class Content2Servlet extends HttpServlet
{
    private static final long serialVersionUID = 1L;
    public String             loginUrl         = "SessionLoginServlet";
    Connection                connection       = null;
    /**
     * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<HTML>");
        out.println("<HEAD>");
        out.println("<TITLE>Welcome to Session Testing </TITLE>");
        out.println("</HEAD>");
        out.println("<BODY>");
        HttpSession session = request.getSession();
        if (session == null)
        {
            response.sendRedirect(loginUrl);
        } // end if
        else
        {
            String loggedIn = (String) session.getAttribute("loggedIn");
            if (!loggedIn.equals("true"))
            {
                response.sendRedirect(loginUrl);
            } // end if
        } // end if
        connection = (Connection) session.getAttribute("DatabaseConnection");
        if (connection != null)
        {
            try
            {
                if (connection.isClosed())
                {
                    out.println("Connection is closed");
                    out.println("<BR>");
                }
                else
                {
                    out.println("Connection is open");
                    out.println("<BR>");
                    UsersController Ucc = new UsersController(connection);
                    ResultSet rs = Ucc.getUserRecord("d0camp03", "password123");
                    try
                    {
                        while (rs.next())
                        {
                            out.println(rs.getString("FNAME"));
                            out.println("<BR>");
                        } // end while
                    }
                    catch (SQLException e)
                    {
                        e.printStackTrace();
                    }
                }
            }
            catch (SQLException e1)
            {
                e1.printStackTrace();
            } // end if
        }
        else
        {
            out.println("Connection is null");
            out.println("<BR>");
        } // end if
        out.println("Welcome to Our Company Testing.");
        out.println("</BODY>");
        out.println("</HTML>");
    }
    /**
     * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
    {
        doGet(request, response);
    }
}
