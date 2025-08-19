/*
Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/
class Instancevariable
{
public int age; // Declared instance / non-static Variable
void bscit()
{
age=25;//you can use this.age
System.out.println("Age=: " + age);
}
public static void main(String[] args)
{
Instancevariable obj=new Instancevariable();
obj.bscit();
}
}