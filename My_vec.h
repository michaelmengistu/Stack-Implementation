#include <ostream>

using namespace std;

class My_vec {
    
    //member variables
    int size, capacity;
    char *ptr;
    
public:
    //member functions
    
    My_vec(); //constructor
    ~My_vec(); //destructor
    My_vec(const My_vec& vec); // copy constructor
    My_vec& operator=(const My_vec& vec); //assignment operator
    int get_size() const;
    int get_capacity() const;
    char& operator[](int i) const;
    char& operator[](int i);
    bool is_empty() const;
    char& elem_at_rank(int r) const; //index threw the array
    void insert_at_rank(int r, const char& elem);//let the user insert a new element at a given rank and resize the array if the capacity of the array is full.
    void replace_at_rank(int r, const char& elem);//let the user replace a element in the array at a given rank with a new element.
    void remove_at_rank(int r); //let the user remove a element at a given rank.
    
};

ostream& operator<<(ostream& out, const My_vec& vec); //output the array of the class.
int find_max_index(const My_vec& v,int size); //find the max index of the largest element in the array.
void sort_max(My_vec& vec); //sort the array the array from smallest to largest.
