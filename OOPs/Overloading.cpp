#include <bits/stdc++.h>
using namespace std;

class Sum{
    public:
        int x;

        Sum(int x) {
            this->x = x;
        }

        // '+' overloading
        Sum operator+(Sum &s1){     // (Sum const &s1) -> const keyword will not allow to change the s1 value;
            Sum ans(0);

            int total = this->x + s1.x;

            ans.x = total;

            return ans;
            
        }    

        // '==' overloading
        bool operator==(Sum &s1){
            return this->x == s1.x;
        }


        // '++a' preIncrement overloading
        // in pre Increment it is required to return by reference
        // because while doing ++(++a) types operations
        // if you do b = ++(++a) the 'b' will have the answer a+2 init;
        // but a will be only incremented by one
        Sum &operator++(){
            this->x = this->x + 1;

            return *this;
        }


        // 'a++' postIncrement overloading
        // No need to do by reference because we can do some thing like (a++)++  <- "XXX" Not allowed
        Sum operator++(int){
            Sum a(-1);
            a.x = this->x;
            this->x = this->x + 1;

            return a;
        }

        void operator+=(Sum &s1){
            this->x += s1.x;
        }

        int operator--(){

        }

        // Made changes in the same "this"
        void add(Sum &s1){
            this->x += s1.x;
        }
};

int main(){
    Sum a(7);
    Sum b(9);
    

    Sum c = a + b;

    a.add(b);    
    cout << c.x << "\n" << a.x <<"\n";

    cout << "== ans -> " << (a == b);


    Sum d(11);
    ++d;
    //++ ++d;
    Sum e = ++d;
    
    cout << "pre(++) overloaded -> " <<d.x << "\n";

    cout << "pre(++) overloaded (e) -> " << e.x << "\n";


    Sum p(23);
    Sum q = p++;



    cout << "post(++) overloaded-> q: " << q.x <<"\n";
    cout << "post(++) overloaded-> p: " << p.x <<"\n";


    q += p;

    cout << "(+=) overloaded -> q: " << q.x << "\n";


}