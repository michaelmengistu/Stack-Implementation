// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"
#include "TemplatedMy_vec.h"

using namespace std;
int main(){
    
// Some test cases are expected to throw an exception.
// Add more try and catch blocks as necessary for your code to finish execution.
    
try{
    // define an object v of My_vec type
    //My_vec v;
    // insert 'B' at the rank 0 into the vector v
    // use the overloaded operator << to display vector elements
    // display the vector v size
    //v.insert_at_rank(0, 'B');
    //std::cout<< v << std::endl;
    //std::cout<< v.get_size() << std::endl;
    
    
    // insert 'A' at the rank 0  to the vector v
    // use the overloaded operator << to display vector elements
    // display the vector v size
    //v.insert_at_rank(0, 'A');
    //std::cout<< v << std::endl;
    //std::cout<< v.get_size() << std::endl;
    
    
    // insert 'D' at the rank 10 into the vector v
    // use the overloaded operator << to display vector elements
    // display the vector v size
    //v.insert_at_rank(10, 'v');
    //std::cout<< v << std::endl;
    //std::cout<< v.get_size() << std::endl;
    
    
    // remove a character at the rank 1 from the vector v
    // use the overloaded operator << to display vector elements
    // display the vector v size
    //v.remove_at_rank(1);
    //std::cout<< v << std::endl;
    //std::cout<< v.get_size() << std::endl;
    
    
    // replace a character at the rank 0 by the character 'E'
    // use the overloaded operator << to display vector elements
    // display the vector v size
    //v.replace_at_rank(0, 'E');
    //std::cout<< v << std::endl;
    // std::cout<< v.get_size() << std::endl;
    
    
    // create a copy v1 of the vector v using a copy constructor
    // use the overloaded operator << to display the vector v1
    // replace a character at the rank 2 of the vector v1 with the character 'Y'
    // use the overloaded operator << to display vector v1 elements
    //My_vec v1 = v;
    //v1.replace_at_rank(0, 'Y');
    //std::cout<< v1 << std::endl;
    
    // define an object v2 of My_vec type
    // insert 'K' at the rank 0 into the vector v2
    // use the overloaded operator << to display vector elements
    // display the vector v2 size
    My_vec v2;
    v2.insert_at_rank(0, '8');
    std::cout<< v2 << std::endl;
    std::cout<< v2.get_size() << std::endl;
    
    
    // test the assignment operator and copy the vector v1 to v2
    // Set v2 to '1','2','3','4','5'
    // use the overloaded operator << to display vector v2
    // display the vector v2 size
    //v2 = v1;
    v2.insert_at_rank(0, '1');
    v2.insert_at_rank(1, '4');
    v2.insert_at_rank(2, '2');
    v2.insert_at_rank(3, '4');
    v2.insert_at_rank(4, '0');
    std::cout<< v2 << std::endl;
    
    // test the function find_max_index using v2
    std::cout <<find_max_index(v2, 5)<< std::endl;
    
    // test the function sort_max using v2
    sort_max(v2);
    std::cout <<v2<< std::endl;
    // replace in the vector v2 a character at the rank 14 with 'S'
    v2.insert_at_rank(2, 'S');
    std::cout <<v2<< std::endl;
}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}
