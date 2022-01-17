/*
    
    Write a program which:
    1) Prompts the user to enter 3 integer numbers, where each number represents a side of a triangle.
    2) Outputs the type of the triangle (equilateral, isosceles, or scalene)

*/
#include <iostream>
#include <array>
using std::cout;
using std::cin;
void nl(){
    cout << "\n";
}

int main(){
    std::array<int,3> triangle;
    // Taking input from the user
    cout << "Enter the length of each side of the triangle: ";
    for(int i=0;i<3;i++){
        cin >> triangle[i];
    }

    // Logic to check if the triangle is equilateral or isosceles or scalene
    if((triangle[0]==triangle[1]) && (triangle[1]==triangle[2])){
        cout << "The triangle is Equilateral";
        nl();
    }
    else{
        if((triangle[0]==triangle[1])||(triangle[0]==triangle[2])||(triangle[1]==triangle[2])){
            cout << "The triangle is Isosceles";
            nl();
        }
        else{
            cout << "The triangle is Scalene";
            nl();
        }
    }
}