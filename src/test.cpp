#include <iostream>
#include <string>
#include <algorithm>

using std::cout; using std::cin;
using std::endl; using std::string;

bool isNumber(const string& str)
{
    return str.find_first_not_of( ".0123456789" ) == string::npos &&
        str.front() != '.' && str.back() != '.';
}
void swap_numbers(int* a, int* b){
    int temp  = *a;
    *a = *b;
    *b = temp;
}

int main(){
    std::cout << std::string(20,'-');
}
