#include<iostream>
#include<vector>
using std::cin;

int binary_search(const std::vector<int> &vec,const int &element);

int main(){
    std::vector<int> vec;
    std::cout << "Enter elements\n";
    int input;
    while(true){
        cin >> input;
        if(input<0){
            break;
        } 
        else{
            vec.push_back(input);
        }
    }
    int element;
    std::cout << "Enter searching element\n";
    cin >> element;
    int index = binary_search(vec,element);
    if(index>0){
        std::cout<< " element found"<<" at index " << index << '\n';
    }
    else{
        std::cout << "Element not found\n";
    }

}

int binary_search(const std::vector<int> &vec,const int &element){
    int low = 0;
    int high = vec.size()-1;
    while(true){
        if(vec.at(low)==element){
            return low;
        }
        else if(vec.at(high)==element){
            return high;
        }
        else{
                if(vec.at((low+high)/2)>=element){
                    high = (low+high)/2;
                }
                else{
                    low = (low+high)/2;
                }
            }
        if(high==low){
            break;
        }
        }
    return -1;
}