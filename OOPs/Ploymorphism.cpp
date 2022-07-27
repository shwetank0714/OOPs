#include<bits/stdc++.h>
using namespace std;
// Polymorphism -> Poly(Many) Morphism(Forms)

// Two types:
    // 1. Compile Time -> For a set of code deciding at (Compile time) that what task is needed to be performed.
    // 2. Run Time -> For a set of code deciding at (Run time) that what task is needed to be performed.



//  -----------------------------------------COMPILE TIME POLYMORPHISM ------------------------------------------
// CAn be acheived by two methodologies
        // 1. Function overloading
        // 2. Operator overloading



//  1. Function Overloading
//  function with same name with different number of arguments and there data types (example below)

int test(int a){}

int test(int a, int b){}

int test(string c){}


// We cant differentiat functions on the basis of return type
            // eg:   int test() and void test() cant be created in a single file 


// 2. Opeartor overloading
//  decided at compile time accordingly For eg: '+' behaves differently for addition float/int/double/enum etc

// -------------------------x--------------------------x--------------------------x---------------------------


// 3. Method/Function Overriding 
//  -> Same function present in both child and Parent classs Basically child class overrided the function
//

class Vehicle{
    public:
        void print(){
            cout << "Vehicle:\n";
        }
};

class Car: public Vehicle{
    public:
        
        void print(){
            cout << "Car:\n";
        }
};


int main(){
    Car c;
    Vehicle v;
    
    //NOTE: Base class pointers can point to child class pointers , but the vice-versa is not allowed at all
    Vehicle *k = &c;    // Since this is a vehicle type pointer it will always print Vehicles print() function
    
    // At compile time it is check that what type of object is k and it directly goes to Vehicle class and performs
    // its print() method.

    v.print();      // Vehicle
    c.print();      // Car
    k->print();     // vehicle  Note: Printing Car using k->print() is acheived by Run time polymorphism
}





//  --------------------------------------- RUN TIME POLYMORPHISM ------------------------------------------------
//  We decide at run time that what method is to be implemented
//  "Virtual" keyword is generally added infront of the function to achieve run time polymorphism


//  ##  Virtual Functions: Functions which are present in base class and are overriden in derived class ##

//  due to virtual keyword we tell compiler to decide at run time