#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    signed short int date;
    signed short int month;
    signed short int year;
    cout << "Please enter your date of birth in the format: d m y ";
    cin >> date;
    cin >> month;
    cin >> year;
    //cout << "\n";
    cout << "Your date of birth is: " << month << "/" << date << "/" << year << endl;

    return 0;
}