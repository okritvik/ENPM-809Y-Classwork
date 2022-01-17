/*
    Robot can walk to each table.
    A human places each object on a table.
    Each table can contain only one of the three objects.
    Rules: The robot can pick up:
        Book: if the robot is in front of the blue table and the book is on the blue table.
        Pan: if the robot is in front of the purple table and the pan is on the purple table.
        Glass: if the robot is in front of the green table and the glass is on the green table.
*/
#include <iostream>
using std::cin;
using std::cout;
int main(){
    char table;
    char object;
    cout << "Which table should the robot go to? (b)lue/(p)urple/(g)reen: ";
    cin >> table;
    cout << "Which object is on that table? (b)ook/(p)an/(g)lass: ";
    cin >> object;
    if(table==object){
        if(table=='g'){
            cout << "Success: The robot picks up the glass from the green table" << "\n";
        }
        else if(table=='p'){
            cout << "Success: The robot picks up the pan from the purple table" << "\n";
        }
        else{
            cout << "Success: The robot picks up the book from the blue table" << "\n";
        }
    }
    else{
        if(table=='g'){
            if(object == 'p'){
                cout << "Failure: The robot cannot pick up pan from green table" << "\n";
            }
            else{
                cout << "Failure: The robot cannot pick up book from green table" << "\n";
            }
        }
        else if(table == 'p'){
            if(object == 'g'){
                cout << "Failure: The robot cannot pick up glass from purple table" << "\n";
            }
            else{
                cout << "Failure: The robot cannot pick up book from purple table" << "\n"; 
            }
        }
        else{
            if(object == 'g'){
                cout << "Failure: The robot cannot pick up glass from blue table" << "\n";
            }
            else{
                cout << "Failure: The robot cannot pick up pan from blue table" << "\n"; 
            }
        }
    }
}        