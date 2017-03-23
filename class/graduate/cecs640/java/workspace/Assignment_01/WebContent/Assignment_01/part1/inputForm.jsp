<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Input</title>
</head>
<body>
<h1>Input Form</h1>
<%	
	String input = request.getParameter("input");
    String error_message = "";
    
	if (input != null) // It will only be null when first run
	{
		// Instead of setting an error attribute and fetching it, just display a error string
		// if the input is empty
		if (input.length() == 0)
		{
			error_message = "Input must not be empty";
		}
		else
		{
			// Set reverse attribute
			StringBuffer buffer = new StringBuffer(input);
			String reverse = buffer.reverse().toString();
			request.setAttribute("reverse", reverse);
			
			// Output url
			String url = "/outputForm.jsp";
			
			// Send value
			ServletContext context = getServletContext();
			RequestDispatcher dispatcher = context.getRequestDispatcher(url);
			dispatcher.forward(request, response);
		}
	}
%>
<form method="get" action="inputForm.jsp">
<table cellspacing="4">
	<tr>
		<td>Enter your input:</td>
		<td><input name="input" type="text" size="20"></td>
		<td style="color: red"><%=error_message%></td>
	</tr>
	<tr>
		<td></td>
		<td><input type="submit" value="Submit"></td>
		<td></td>
	</tr>
</table>
</form>
</body>
</html>