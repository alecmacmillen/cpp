// A Tour of C++: Chapter 2
#include <iostream> // include the declarations of std stream I/O facilities

using namespace std; //allows us to use names from std without needing std::

struct Vector {
    int sz;         // number of elements
    double* elem;   // pointer to elements
};  // interesting - compiler required a ; after } for struct

void vector_init(Vector& v, int s)
    // Vector& indicates we pass v by non-const reference
    // which allows this function to modify v
{
    v.elem = new double[s]; // allocate an array of doubles
    v.sz = s;
}

double read_and_sum(int s)
    // read s integers from cin and return their sum
    // s is assumed to be positive
{
    Vector v;
    vector_init(v,s);
    cout << "Please enter " << s << " numbers:\n";
    for (int i=0; i!=s; ++i) {
        cin>>v.elem[i];     // read input into elements
    }
    double sum = 0;
    for (int i=0; i!=s; ++i) {
        sum+=v.elem[i];
    }
    return sum;
}

int main() {
    double sum = read_and_sum(3);
    cout << sum << "\n";
}