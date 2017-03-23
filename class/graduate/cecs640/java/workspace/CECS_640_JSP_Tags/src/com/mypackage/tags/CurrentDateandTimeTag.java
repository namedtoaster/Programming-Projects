package com.mypackage.tags;

import java.io.IOException;
import java.util.Date;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspTagException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
public class CurrentDateandTimeTag extends TagSupport
{
    private static final long serialVersionUID = 3595647087368526750L;
    public String makeBoldHelveticaRed(Date input)
    {
    	return new String();
    }
    public int doStartTag() throws JspException
    {
    	JspWriter out = pageContext.getOut();
        Date now = new Date();
        
        try
        {
            out.print("<div class=\"bold-red\">" + now + "</div>");
        }
        catch (IOException e)
        {
            throw new JspTagException("CurrentDateTimeTag: " + e.getMessage());
        } // end try catch
        return SKIP_BODY;
    }
}