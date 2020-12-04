/*
 Michael Menigstu
 july 10, 2018
 ...
 */
#include "My_vec.h"
#include <ostream>
#include <stdexcept>

using namespace std;

My_vec::My_vec(): size(-1), capacity(10), ptr(new char[capacity]){};

My_vec::~My_vec(){delete[] ptr;};

My_vec::My_vec(const My_vec& vec){
    size = vec.get_size()-1;
    capacity = vec.get_capacity();
    ptr = new char[capacity];
    for (unsigned int i = 0; i < vec.get_size(); ++i) {
        ptr[i] = vec.elem_at_rank(i);
    }
};

My_vec& My_vec::operator=(const My_vec& vec){
    if(this == &vec){
        return *this;
    }
    size = vec.get_size()-1;
    capacity = vec.get_capacity();
    ptr = new char[capacity];
    for (unsigned int i = 0; i < vec.get_size(); ++i) {
        ptr[i] = vec.elem_at_rank(i);
    }
    return *this;
};

int My_vec::get_size() const {return size+1; };
int My_vec::get_capacity() const {return capacity; };
char& My_vec::operator[](int i) const {return ptr[i]; };
char& My_vec::operator[](int i){return ptr[i]; };
bool My_vec::is_empty() const {return size == -1; };
char& My_vec::elem_at_rank(int r) const {return ptr[r]; };
void My_vec::insert_at_rank(int r, const char& elem){
    //adds when current size is less then capacity and when rank equals size
    if(r == get_size() && get_size() < capacity){
        ptr[r] = elem;
        size++;
    }
    else if( get_size() < capacity && r <= size){
        for (unsigned int i = size+1; i > r; --i) {
            ptr[i] = ptr[i - 1];
        }
        ptr[r] = elem;
        size++;
    }
    else if(size+1 >= capacity && r-1 == size){
        capacity *=2;
        char* newPtr = new char[capacity];
        for (unsigned int i = 0; i < get_size(); ++i) {
            newPtr[i] = elem_at_rank(i);
        }
        ptr = newPtr;
        ptr[r] = elem;
        size++;
    }
    else if(get_size() >= capacity && r < get_size()){
        capacity*= 2;
        char* newPtr = new char[capacity];
        for (unsigned int i = 0; i <= get_size(); ++i) {
            if( i < r ){
                newPtr[i] = elem_at_rank(i);
            }
            else if(i == r){
                newPtr[i] = elem;
            }
            else{
                newPtr[i] = elem_at_rank(i-1);
            }
        }
        ptr = newPtr;
        size++;
        }
    else{
        throw runtime_error("Error: out of bounds.");
    }
};

void My_vec::replace_at_rank(int r, const char& elem){
    if(r >= 0 && r < get_size() ){
        ptr[r] = elem;
    }
    else{
        throw runtime_error("Error: out of bounds.");
    }
};
    
void My_vec::remove_at_rank(int r){
    if(r >= 0 && r < get_size() ){
        char* newPtr = new char[capacity];
        for(int i = 0; i < get_size(); ++i){
            if( i < r ){
                newPtr[i] = elem_at_rank(i);
            }
            else if(i == r){
                ++i;
            }
            else{
                newPtr[i-1] = elem_at_rank(i);
            }
         }
        ptr = newPtr;
        size--;        }
    else{
        throw runtime_error("Error: out of bounds.");
    }
};

ostream& operator<<(ostream& out, const My_vec& vec){
    for (int i = 0; i < vec.get_size() ; ++i) {
        out << vec.elem_at_rank(i);
    }
    return out;
};
int find_max_index(const My_vec& v,int size){
    int maxIndex = 0;
    char maxValue = v[0];
    if(size <= v.get_size() ){
        for(int i = 1; i < size; ++i){
            if(maxValue <=  v[i]){
                maxIndex = i;
                maxValue = v[i];
            }
        }
        return maxIndex;
    }
    else{
        throw runtime_error("Error: out of bounds.");
    }
};
void sort_max(My_vec& vec){
    int size = vec.get_size();
    int maxIndex = find_max_index(vec, size);
    for(int i = size-1; i >= 0; --i){
        char temp = vec[i];
        vec[i] = vec[maxIndex];
        vec[maxIndex] = temp;
        size--;
        maxIndex = find_max_index(vec, size);
    }
    
};

