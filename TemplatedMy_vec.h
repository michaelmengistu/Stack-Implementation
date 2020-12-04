/*My_vec.h
 Your name
 Header file for a vector data structure.
 */

#include <ostream>
#include <stdexcept>

using namespace std;

template<typename T>
class TemplatedMy_vec {
    
    //member variables
    int size, capacity;
    T* ptr;
    
public:
    //member functions
    //constructor
    TemplatedMy_vec(): size(-1), capacity(10), ptr(new T[capacity]){};
    //destructor
    ~TemplatedMy_vec(){delete[] ptr; };
    // copy constructor
    TemplatedMy_vec(const TemplatedMy_vec<T>& vec){
        size = vec.get_size()-1;
        capacity = vec.get_capacity();
        ptr = new T[capacity];
        for (unsigned int i = 0; i < vec.get_size(); ++i) {
            ptr[i] = vec.elem_at_rank(i);
        }
    };
    //assignment operator
    TemplatedMy_vec<T>& operator=(const TemplatedMy_vec<T>& vec){
        if(this == &vec){
            return *this;
        }
        size = vec.get_size()-1;
        capacity = vec.get_capacity();
        ptr = new T[capacity];
        for (unsigned int i = 0; i < vec.get_size(); ++i) {
            ptr[i] = vec.elem_at_rank(i);
        }
        return *this;
    };
    int get_size() const {return size+1; };
    int get_capacity() const {return capacity; };
    T& operator[](int i) const {return ptr[i]; };
    T& operator[](int i){return ptr[i]; };
    bool is_empty() const {return size == -1; };
    //index threw the array
    T& elem_at_rank(int r) const {return ptr[r]; };
    //let the user insert a new element at a given rank and resize the array if the capacity of the array is full.
    void insert_at_rank(int r, const T& elem){
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
            T* newPtr = new T[capacity];
            for (unsigned int i = 0; i < get_size(); ++i) {
                newPtr[i] = elem_at_rank(i);
            }
            ptr = newPtr;
            ptr[r] = elem;
            size++;
        }
        else if(get_size() >= capacity && r < get_size()){
            capacity*= 2;
            T* newPtr = new T[capacity];
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
    //let the user replace a element in the array at a given rank with a new element.
    void replace_at_rank(int r, const T& elem){
        if(r >= 0 && r < get_size() ){
            ptr[r] = elem;
        }
        else{
            throw runtime_error("Error: out of bounds.");
        }
    };
    //let the user remove a element at a given rank.
    void remove_at_rank(int r){
        if(r >= 0 && r < get_size() ){
            T* newPtr = new T[capacity];
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
            size--;
        }
        else{
            throw runtime_error("Error: out of bounds.");
        }
    };
};
//output the array of the class.
template<typename T>
ostream& operator<<(ostream& out, const TemplatedMy_vec<T>& vec){
    for (int i = 0; i < vec.get_size() ; ++i) {
        out << vec.elem_at_rank(i);
    }
    return out;
};

//find the max index of the largest element in the array.
template<typename T>
int find_max_index(const TemplatedMy_vec<T>& v,int size){
    int maxIndex = 0;
    T maxValue = v[0];
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

//sort the array the array from smallest to largest.
template<typename T>
void sort_max(TemplatedMy_vec<T>& vec){
    int size = vec.get_size();
    int maxIndex = find_max_index(vec, size);
    for(int i = size-1; i >= 0; --i){
        T temp = vec[i];
        vec[i] = vec[maxIndex];
        vec[maxIndex] = temp;
        size--;
        maxIndex = find_max_index(vec, size);
        }
};
