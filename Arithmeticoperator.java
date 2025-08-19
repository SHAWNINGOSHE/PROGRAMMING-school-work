/*
Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/
public class Arithmeticoperator {
public static void main(String[] args) {
// declare variables
int a = 12, b = 5;
// addition operator
System.out.println("a + b = " + (a + b));
// subtraction operator
System.out.println("a - b = " + (a - b));
// multiplication operator
System.out.println("a * b = " + (a * b));
/*
division operator
If we use the division operator with two integers, then the resulting quotient will also be an integer.
And, if one of the operands is a floating-point number, we will get the result will also be in floating-
point.
(9 / 2) is 4
(9.0 / 2) is 4.5
(9 / 2.0) is 4.5
(9.0 / 2.0) is 4.5
*/
System.out.println("a / b = " + (a / b));
// modulo operator
System.out.println("a % b = " + (a % b));
}
}