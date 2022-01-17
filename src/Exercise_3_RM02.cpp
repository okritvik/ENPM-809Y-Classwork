// Write a code which displays the score to get a letter grade (A,B,C,D or F) based on user's input
#include <iostream>
using std::cout;
using std::cin;

int main(){
    char grade;
    char selection;
    cout << "Expected final letter grade for this course (A/B/C/D/F)?";
    cin >> grade;
    switch (grade){
    case 'A':
    case 'a':
        cout << "You need a 90 or above\n";
        break;
    case 'B':
    case 'b':
        cout << "You need 80-89 for a B \n";
        break;
    case 'C':
    case 'c':
        cout << "You need 70-79 for an average grade\n";
        break;
    case 'D':
    case 'd':
        cout << "You need 60-69\n";
        break;
    case 'F':
    case 'f':
        cout << "Are you sure (Y/N)? ";
        cin >> selection;
        switch(selection){
            case 'Y':
            case 'y':
                cout << "It seems you didn't study.\n";
                break;
            case 'N':
            case 'n':
                cout << "Good answer, now go study!\n";
                break;
        }
        break;
    default:
        cout << "Not a valid grade \n";
        break;
    }

}