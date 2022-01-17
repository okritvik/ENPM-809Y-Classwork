/*
    Write the code to find the sum of the product of all pairs of vector elements.
*/

#include<iostream>
#include<vector>
int main(){
    long sum=0;
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);
    //We can add more elements
    unsigned short int vec_size = vec.size();
    if(vec_size==0){
        std::cout << "Vector is empty";
    }
    else if(vec_size==1){
        std::cout << "Result is " << vec.at(0) << "\n";
    }
    else{
        for(int i=0;i<vec_size-1;i++){
            for(int j=i+1;j<vec_size;j++){
                sum = sum + (vec.at(i)*vec.at(j));
            }
        }
        std::cout << "Result is " << sum << "\n";
    }
    
}