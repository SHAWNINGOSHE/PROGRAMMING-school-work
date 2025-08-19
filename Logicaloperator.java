/*
Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/
class Logicaloperator {
public static void main(String[] args) {
// && operator
System.out.println((5 > 3) && (8 > 5)); // true
System.out.println((5 > 3) && (8 < 5)); // false
// || operator
System.out.println((5 < 3) || (8 > 5)); // true
System.out.println((5 > 3) || (8 < 5)); // true
System.out.println((5 < 3) || (8 < 5)); // false
// ! operator
System.out.println(!(5 == 3)); // true
System.out.println(!(5 > 3)); // false
}
}