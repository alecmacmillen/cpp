// A Tour of C++: Chapter 2
#include <iostream> // include the declarations of std stream I/O facilities

using namespace std; //allows us to use names from std without needing std::

struct VectorS {
    int sz;         // number of elements
    double* elem;   // pointer to elements
};  // interesting - compiler required a ; after } for struct

void vector_init(VectorS& v, int s)
    // Vector& indicates we pass v by non-const reference
    // which allows this function to modify v
{
    v.elem = new double[s]; // allocate an array of doubles
    v.sz = s;
}

double read_and_sum_struct(int s)
    // read s integers from cin and return their sum
    // s is assumed to be positive
{
    VectorS v;
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

class VectorC {
    public:
        // class constructor creates members elem and sz
        VectorC(int s) :elem{new double[s]}, sz{s} { }
        // member for accessing i'th element: operator refers
        // to the name of the Vector, and [](int i) means you
        // pass an int value within [] to get the i'th value
        double& operator[](int i) { return elem[i]; }
        int size() { return sz; }
    private:
        double* elem;
        int sz;
};

double read_and_sum_class(int s) {
    VectorC v(s);
    cout<<"Please enter " << s << " numbers:\n";
    for (int i=0; i!=s; ++i) {
        cin>>v[i];
    }
    double sum = 0;
    for (int i=0; i!=s; ++i) {
        sum+=v[i];
    }
    return sum;
}

int main() {
    double sum_struct = read_and_sum_struct(3);
    cout << sum_struct << "\n";

    double sum_class = read_and_sum_class(2);
    cout << sum_class << "\n";
}
