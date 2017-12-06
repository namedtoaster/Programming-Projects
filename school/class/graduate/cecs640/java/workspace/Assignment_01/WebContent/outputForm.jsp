<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Output</title>
</head>
<body>
<h1>Output Form</h1>
<%

String reverse_value = "";
Object reverse = request.getAttribute("reverse");
reverse_value = reverse.toString();
%>
<h2 style="color: blue"><%=reverse_value%></h2>

</body>
</html>