/*
Title:Library management demonstrating inheritance
Author:Shawn Ingoshe
Reg no:BSE-05-0199/2024
*/

#include <iostream>
#include <string>

using namespace std;

//parent class: Person
class Person {
protected:
    string name;

public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }
};

//child : LibraryMember
class LibraryMember : public Person {
private:
    int memberID;
    int booksBorrowed;

public:
    LibraryMember(string n, int id, int books) : Person() { // Call base class constructor
        setName(n);
        memberID = id;
        booksBorrowed = books;
    }

    int getMemberID() {
        return memberID;
    }

    int getBooksBorrowed() {
        return booksBorrowed;
    }
};

//child: PremiumMember
class PremiumMember : public LibraryMember {
private:
    double membershipFee;

public:
    PremiumMember(string n, int id, int books, double fee) : LibraryMember(n, id, books) { // Call LibraryMember constructor
        membershipFee = fee;
    }

    double getMembershipFee() {
        return membershipFee;
    }
};

int main() {
    //a LibraryMember object
    LibraryMember member1("Douglas", 101, 2);
    cout << "Member Name: " << member1.getName() << endl;
    cout << "Member ID: " << member1.getMemberID() << endl;
    cout << "Books Borrowed: " << member1.getBooksBorrowed() << endl;

    //a PremiumMember object
    PremiumMember premiumMember1("Shawn", 201, 5, 50.0);
    cout << "\nPremium Member Name: " << premiumMember1.getName() << endl;
    cout << "Premium Member ID: " << premiumMember1.getMemberID() << endl;
    cout << "Books Borrowed: " << premiumMember1.getBooksBorrowed() << endl;
    cout << "Membership Fee: $" << premiumMember1.getMembershipFee() << endl;

    return 0;
}