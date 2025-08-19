/*
Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/
class Staticvariable
{
public static int age; // Declared static/Class Variable
void bscit()
{
age=25;//you can use this.age
System.out.println("Age=: " + age);
}
public static void main(String[] args)
{
Staticvariable obj=new Staticvariable();
obj.bscit();
}
}