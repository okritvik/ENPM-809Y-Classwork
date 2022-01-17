/*

    This exercise must be performed with C++ Style array
    1. Initialize an array of int which consists of 3 elements
    2. Set all elements to the value 9 using the fill method
    3. Get the size of the array with the size() method and store the result in the variable size_array
    4. Set the value of the first element of the array to 1.
    5. Set the value of the last element of the array to 7.
    6. Use the size_array and at() method to display: "The array has 3 elements: 1,9,7"

*/
#include <iostream>
#include <array>
int main(){
    // Initializing an array
    std::array<int,3> my_array{};
    // Setting all elements of the array to 9
    my_array.fill(9);
    std::cout << my_array.at(0) << "\n";
    // Getting the size of array
    unsigned short size_array = my_array.size();
    // Setting the first element of array to 1
    my_array.at(0) = 1;
    // Setting the value of last element of the array to 7
    my_array.at(size_array-1) = 7;
    // Display of elements inside the array
    std::cout << "The array has 3 elements: ";
    for(int i{0};i<size_array;i++){
        std::cout << my_array.at(i);
        if(i==size_array-1){
            break;
        }
        else{
            std::cout << ", ";
        }
    }
    std::cout<< "\n";
    return 0;
}