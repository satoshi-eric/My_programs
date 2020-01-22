#include <iostream>
#include <math.h>
using namespace std;

/*
 * a: real part 
 * b: imaginary part
*/ 
class complexNumber{
    public:
        complexNumber(float real = 0.0, float img = 0.0){
            this->a = real;
            this->b = img;
        }
        float a;
        float b;
        void setNumber(float real, float img){
            this->a = real;
            this->b = img;
        }
};

complexNumber soma(complexNumber n1, complexNumber n2){
    complexNumber n3;
    n3.a = n1.a + n2.a;
    n3.b = n1.b + n2.b;
    return n3;
}

complexNumber mult(complexNumber n1, complexNumber n2){
    complexNumber n3;
    n3.a = n1.a*n2.a - n1.b*n2.b;
    n3.b = n1.a*n2.b + n1.b*n2.a;
    return n3;
}

int main(){
    
}