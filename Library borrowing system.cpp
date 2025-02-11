/*Author:Shawn Ingoshe
Reg No:BSE-05-0199/2024
Group:BSE group 3
Github:SHAWNINGOSHE*/

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

// Function to calculate the difference in days between two dates
int calculateDaysOverdue(tm dueDate, tm returnDate) {
    time_t due = mktime(&dueDate);
    time_t ret = mktime(&returnDate);
    return difftime(ret, due) / (60 * 60 * 24);
}

int main() {
    string bookID;
    tm dueDate = {};
    tm returnDate = {};

    cout << "Enter Book ID: ";
    cin >> bookID;

    cout << "Enter Due Date (YYYY MM DD): ";
    cin >> dueDate.tm_year >> dueDate.tm_mon >> dueDate.tm_mday;
    dueDate.tm_year -= 2000; // Year since 2000
    dueDate.tm_mon -= 1;     // Month range is 0-11

    cout << "Enter Return Date (YYYY MM DD): ";
    cin >> returnDate.tm_year >> returnDate.tm_mon >> returnDate.tm_mday;
    returnDate.tm_year -= 2000; // Year since 2000
    returnDate.tm_mon -= 1;     // Month range is 0-11

    int daysOverdue = calculateDaysOverdue(dueDate, returnDate);
    int fine = 0;

    if (daysOverdue >= 1 && daysOverdue <= 7) {
        fine = daysOverdue * 20;
    } else if (daysOverdue >= 8 && daysOverdue <= 14) {
        fine = daysOverdue * 50;
    } else if (daysOverdue >= 15) {
        fine = daysOverdue * 100;
    }

    cout << fixed << setprecision(2);
    cout << "\nBook ID: " << bookID << endl;
    cout << "Due Date: " << dueDate.tm_year + 2000 << "-" << dueDate.tm_mon + 1 << "-" << dueDate.tm_mday << endl;
    cout << "Return Date: " << returnDate.tm_year + 2000 << "-" << returnDate.tm_mon + 1 << "-" << returnDate.tm_mday << endl;
    cout << "Days Overdue: " << daysOverdue << endl;
    cout << "Fine: Ksh. " << fine << endl;

    return 0;
}
