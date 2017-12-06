<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Input</title>
</head>
<body>
	<h1>Input Form</h1>
	<%
	    String error_message = "";
	    Object error = request.getAttribute("error");
	    if (error != null)
	        error_message = error.toString();
	%>
	<form method="get" action="Reverse">
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