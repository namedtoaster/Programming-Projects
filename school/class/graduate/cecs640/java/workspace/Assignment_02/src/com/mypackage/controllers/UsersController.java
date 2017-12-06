package com.mypackage.controllers;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
//import org.apache.commons.lang3.StringUtils;

public class UsersController
{
    private Connection dbConnection = null;
    /**
     * 
     */
    public UsersController(Connection dbConnection)
    {
        this.dbConnection = dbConnection;
    }
    public int insertUser(String id, String pw, String fName, String mInit, String lName, int access)
    {
        int rc = 0;
        String template = "INSERT INTO USERS VALUES(?, ?, ?, ?, ?, ?)";
        try
        {
            PreparedStatement ps = dbConnection.prepareStatement(template);
            ps.setString(1, id);
            ps.setString(2, pw);
            ps.setString(3, fName);
            ps.setString(4, mInit);
            ps.setString(5, lName);
            ps.setInt(6, access);
            rc = ps.executeUpdate();
        }
        catch (SQLException e)
        {
            System.out.println(e.getMessage());
        } // end try catch
        return (rc);
    }
    public int updateUser(String id, String pw, String fName, String mInit, String lName, int access)
    {
        int rc = 0;
        String template = "UPDATE USERS SET FNAME = ?, MINIT = ?, LNAME = ?, ACCESS = ? where ID = ? and PASSWORD = ?";
        try
        {
            PreparedStatement ps = dbConnection.prepareStatement(template);
            ps.setString(1, fName);
            ps.setString(2, mInit);
            ps.setString(3, lName);
            ps.setInt(4, access);
            ps.setString(5, id);
            ps.setString(6, pw);
            rc = ps.executeUpdate();
        }
        catch (SQLException e)
        {
            System.out.println(e.getMessage());
        } // end try catch
        return (rc);
    }
    public int deleteUser(String id, String pw)
    {
        int rc = 0;
        String template = "DELETE FROM USERS WHERE ID=? and PASSWORD=?";
        try
        {
            System.out.println("About to delete user " + id + " with password " + pw);
            PreparedStatement ps = dbConnection.prepareStatement(template);
            ps.setString(1, id);
            ps.setString(2, pw);
            rc = ps.executeUpdate();
        }
        catch (SQLException e)
        {
            System.out.println(e.getMessage());
        } // end try catch
        return (rc);
    }
    public boolean findUser(String id, String pw)
    {
        System.out.println("I will look for user");
        boolean rc = false;
        String template = "SELECT * FROM USERS WHERE userid = '" + id + "' AND password = '" + pw + "'";
        try
        {
            Statement s = dbConnection.createStatement();
            ResultSet rs = s.executeQuery(template);
            if (rs.next())
            {
                rc = true;
            } // end if
        }
        catch (SQLException e)
        {
            System.out.println(e.getMessage());
        } // end try catch
        return (rc);
    }
    public ResultSet getUsersList(String keyword)
    {
        ResultSet rs = null;
        String template = "SELECT * FROM Users" + " WHERE FNAME LIKE '%" + keyword + "%'" + " OR LNAME LIKE '%" + keyword + "%'";
        try
        {
            Statement s = dbConnection.createStatement();
            rs = s.executeQuery(template);
        }
        catch (SQLException e)
        {
            System.out.println(e.getMessage());
        } // end try catch
        return (rs);
    }
    public ResultSet getUserRecord(String id, String pw)
    {
        ResultSet rs = null;
        String template = "SELECT * FROM USERS WHERE \"userid\"= '" + id + "' AND \"password\" = '" + pw + "'";
        try
        {
            Statement s = dbConnection.createStatement();
            rs = s.executeQuery(template);
        }
        catch (SQLException e)
        {
            System.out.println(e.getMessage());
        } // end try catch
        return (rs);
    }
}
