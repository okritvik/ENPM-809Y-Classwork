/*
    
    Initialize a vector of int with the numbers: 1000,100,10,1
    Display the size of the vector
    Display each element of the vector
    Prompt the user to enter 4 int numbers
    Modify each element of the vector using the values the user entered.
    Display each element of the vector using the at() method
    Insert the value 2000 at the end of the vector
    Delete the 2nd and 4th element from the vector
    Display each element of the vector using array syntax
    Display the size of the vector (number of elements)

*/
#include <iostream>
#include <vector>
int main(){
    // Initialize a vector of int with numbers given
    std::vector<int> my_vector;
    my_vector.push_back(1000);
    my_vector.push_back(100);
    my_vector.push_back(10);
    my_vector.push_back(1);
    // Display the size of the vector
    std::cout << "The size of the vector is: "<< my_vector.size()<<"\n";
    unsigned short vector_size = my_vector.size();
    // Display each element of the vector
    std::cout << "Elements of the vector: ";
    for( int i{0}; i<vector_size; i++){
        std::cout << my_vector.at(i)<< " ";
    }
    // Taking 4 integers input
    std::cout << "\n";
    std::cout << "Please enter 4 integer numbers: ";
    int user_int=0;
    for(int i{0}; i<4; i++){
        std::cin >> user_int;
        my_vector.at(i) = user_int;
    }
    
    // Display the elements of vector using at() method
    vector_size = my_vector.size();
    std::cout << "Elements in the vector: ";
    for(int i{0}; i<vector_size; i++){
        std::cout << my_vector.at(i)<<" ";
    }
    std::cout << "\n";
    
    // Inserting 2000 at the end of the vector (segmentation fault)
    my_vector.push_back(2000);
    //std::cout << my_vector[4];
    
    // Delete 2nd and 4th element from the vector
    my_vector.erase(my_vector.begin()+1);
    my_vector.erase(my_vector.begin()+2); // When the 2nd element is removed, 4th element becomes 3rd element in the new vector
    
    //Display each element of the vector using array syntax
    vector_size = my_vector.size();
    std::cout << "Display vector elements using the array syntax: ";
    for(int i{0}; i<vector_size; i++){
        std::cout << my_vector[i] << " ";
    }
    std::cout << "\n";
    std::cout << "The size of the vector is: " << vector_size << "\n";

}