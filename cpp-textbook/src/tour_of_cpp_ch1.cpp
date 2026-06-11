// A Tour of C++: Chapter 1
#include <iostream> // include the declarations of std stream I/O facilities
#include <vector>
#include <complex>
#include <string>

using namespace std; //allows us to use names from std without needing std::

// return type precedes function name; also precedes argument names
double square(double x)
// curly braces indicate logical/semantic "chunks" or blocking of code
{
    return x*x;
}

void print_square(double x)
{
    // << character "puts to" the argument on the right into the 
    // argument on the left
    cout << "The square of " << x << " is " << square(x) << "\n";
}

// Overloading: the same-named function can be defined multiple times with 
// different argument types; the computer selects the best one. However, if
// neither option is necessarily better than the other, the call is ambiguous
// and an error results
void example_print(int i) {cout << i << "\n";}
void example_print(double d) {cout << d << "\n";}
void example_print(string s) {cout << s << "\n";}
void user() 
{
    example_print("Overloading example");
    example_print(42);
    example_print(9.65);
}

// variable types: bool, char, int, double, unsigned (non-negative integer)
// use arithmetic, comparison, and logical operators as normal
    // x+y, +x, x-y, -x, x*y, x/y, x%y
    // x==y, x!=y, x<y, x>y, x<=y, x>=y
    // x&y, x|y, x^y, ~x, x&&y, x||y
    // x+=y, ++x (x=x+1), x-=y, --x (x-=1), x*=y, x/=y, x%=y

// Bitwise comparisons convert integers to binary then see which "place"
// have the same bit values
void bitwise_comparison(int i1, int i2) {
    int result = i1&i2;
    cout << result << "\n";
    // if we compare 7 and 4: 7 is represented as 111 and 4 as 100 in binary
    // 1 1 1 <--- 7's binary representation
    // 1 0 0 <--- 4's binary representation
    // ------
    // Y N N <--- Same?
    // The 4's place of binary is the only place where 7 and 4 have the same
    // value, so 7&4 = 4
}

// Logical comparisons simply return 0 (true) or 1 (false)
void logical_comparison(int i1, int i2) {
    bool result = i1&&i2;
    cout << result << "\n";
}

// There are many ways to declare/initialize variables
void variable_initialization() {
    // declare type before variable initialization when variable is in large scope
    // and we want to make type clearly visible, or if you have to distinguish
    // between two similar types (e.g. double and float)
    double d1 = 2.3;                // initialize d1 to 2.3
    double d2 {2.3};                // initialize d2 to 2.3
    complex<double> z = 1;          // complex # w/double-precision floating scalars
    complex<double> z2 {d1,d2};     //
    complex<double> z3 = {1, 2};    // the = is optional with {} 
    vector<int> {1,2,3,4,5,6};      // a vector of ints

    // int i3 = 7.3;                   // NARROWING CONVERSION: 7.3 becomes 7 
                                       // conversion from more info to less (float to int)
    // int i4 {7.3};                   // this will throw an error: using {} prevents
                                       // narrowing conversions
    
    // can also initialize without declaring type if it's obvious from the initializer:
    auto b = true;      // a bool
    auto ch = 'x';      // a char
    auto i = 123;       // an int
    auto d = 1.2;       // a double
    // auto z = sqrt(y);   // z has whatever type sqrt(y) returns
    double* pd = nullptr;   // Use nullptr as a "none" value
}

// Four increasing levels of scope
// 1. Local --> within function or lambda : {}
// 2. Class --> within a class, outside of function/lambda or enum class
// 3. Namespace --> in a namespace outside function, lambda, class, or enum class
// 4. Global --> outside of any other construct
// Objects without names can be created with "new" - see 1.6 pp. 8
// Object must be created before use and will be DESTROYED at the end of its scope!

void constants() {
    // Two types of immutability:
    // const means "I promise not to change this value". Compiler enforces
    // this promise. Once you initialize a variable this way, you cannot change it.
    const int dmv = 17;         // a constant int named dmv
                                // dmv = 18; would fail (immutable)
    int var = 17;               // a non-constant int named var
                                // var = 18; is acceptable (mutable)
    
    // constexpr means "to be evaluated at compile time"
    // constexpr shifts calculations from execution time to compilation time:
    // eliminates runtime overhead, minimizes memory use, surfaces errors earlier
    // constexpr double square(double x) { return x*x }; // constexpr functions can only take 
                                                         // a return value and computation
    // constexpr double max1 = 1.4*square(dmv);    // This is OK because dmv is a const
    // constexpr double max2 = 1.4*square(var); // error: var is not a constant expression
    // const double max3 = 1.4*square(var);        // OK, this will all evaluate at runtime


}

void pointers() {
    char v[6];  // v is a 6-length array of characters
                // in C++, an array has a fixed sized that's determined upon creation,
                // and stores its elements in contiguous memory
    v[3] = 'A';
    
    char* p = &v[3]; // the * is a POINTER, which stores/indicates/"points to" the
                     // actual MEMORY ADDRESS of an object
                     // the & operator means: "give me the memory address of this object"
    
    char x = *p;    // Now this means: go to the memory address stored in p,
                    // give me the object that's stored there and assign it to the variable x
    
    // So now we can show that x = A because we assigned the object stored at memory address *p to x
    cout << x << "\n";
}

void for_loops() {
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for (auto x : v)
        cout << x << '\n';

    // The unary & means "reference to" - this is useful for ensuring that we are
    // referring to the exact version of the object we think we are instead of
    // a copy of it
    for (auto& x : v)
        ++x;
}

bool accept() {
    cout << "Do you want to proceed (y or n)?\n";
    char answer = 0;
    // accept input from the command line
    cin >> answer;
    // switch statement compares a value against a set number of constants
    switch (answer) {
    case 'y':
        // Note that single quotes ' ' are for char, double quotes " " are for string!
        cout << "proceed";
        return true;
    case 'n':
        cout << "terminate";
        return false;
    default:
        cout << "I'll take that for a no.\n";
        return false;
    }
}

// Every C++ program must have a function called int main(). This is the core
// of the program and actually "runs" the code. The function type int indicates
// that the function exits with a code of an integer value: either 0/no value
// for a successful run or a nonzero value for an unsuccessful run
int main() {
    cout << "Hello, World!\n"; // writes second argument onto first
    print_square(1.234);

    user();

    bitwise_comparison(7, 4); // should be 4 (see func def'n for explanation)
    logical_comparison(7, 4); // should be 1 = False

    pointers();
    accept();
}