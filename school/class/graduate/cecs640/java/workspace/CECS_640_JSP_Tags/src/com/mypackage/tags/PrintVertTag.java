package com.mypackage.tags;

import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.*;

public class PrintVertTag extends BodyTagSupport
{
	private static final long serialVersionUID = 1L;
	
	public String createVertString (String input)
	{
		String new_string = "";
		for (int x = 0; x < input.length(); x++) {
			new_string = new_string + input.charAt(x) + "<BR>";
		}
		
		return new_string;
	}
	
	public int doAfterBody()
    {
    	String content = bodyContent.getString();  	
    	
    	try
    	{
    		JspWriter out = bodyContent.getEnclosingWriter();
    		out.println(createVertString(content));
    	}
    	catch (Exception e) {
    		System.out.println(e.getMessage());
    	}
    	
    	return SKIP_BODY;
    }
}