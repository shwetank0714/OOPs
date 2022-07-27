#include <bits/stdc++.h>
using namespace std;

// Base Class
class Vehicle{
    private:
        int maxSpeed;
    protected:
        int numTyres;
    public:
        string color;
};

// Derived Class
// Class name: Access_modifier Base Class
class car: public Vehicle{

};


// Constructor/Destructor calling in Inheritence!!
class A{
    public:
    A(){
        cout << "Constructor A\n";
    }

    ~A(){
        cout << "Destructor A\n";
    }
};

// In any access modifier (public/private/protected) the constructor/Destructor calling will be done like 
// A() -> B() -> ~B() -> ~A()

// If the constructor of parent class is parameterized like A(int k) -> "Say"
// constructor calling in B would be then
//
//                                       ----> B():A(k){ cout << "Constructor B"};
//                                             if we try something like B(){ cout <<"---"} only then it 
//                                             would throw the error because the constructor in base class is 
//                                             parameterized here if default contructor would also have been there
//                                             the it wouldn't throw any error.

class B: private A{
    public:

    B(){
        cout << "Constructor B\n";
    }

    ~B(){
        cout << "Destructor B\n";
    }
};



// The Diamond Problem (Hybrid Inheritence)     (-- - -- --- - -- -- - -- IMPORTANT -- -- - -- - -- - -- -- ---) 



// In below hybrid inherited classes 
// the constructor calling is done in the below way
// main() S a;

// Constructors -> P() -> Q() -> P() -> R() -> S();
// Here we can se that we have created an extra copy of constructor P()
// To avoid the extra calling of constructors we add a virtual keyword befor the access modifiers of the class

// Therefore after adding the virtual keyword we will have the constructor calling in below way
// P() -> Q() -> R() -> S()  "Here we avoided the exxtra calling of the p constructor" 



// Hybrid Inheritence show below
class P{
    public:
        P(){
            cout << "Constructor P\n";
        }

        ~P(){
            cout << "Destructor P\n";
        }

};

class Q: virtual public P{
    public:
        
        Q(){
            cout << "Constructor Q\n";
        }

        ~Q(){
            cout << "Destructor Q\n";
        }
};


class R: virtual public P{
    public:
        R(){
            cout << "Constructor R\n";
        }

        ~R(){
            cout << "Destructor R\n";
        }
};



class S: public Q, public R{
    public:
        S(){
            cout << "Constructor S\n";
        }

        ~S(){
            cout << "Destructor S\n";
        }
};

int main(){

    S a;

}