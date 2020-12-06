#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H
#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882353787593751957781857780532171226806613001927876611195909216420198938095257201065485863278865936153381827968230301952035301852968995773622599413891249721775283479131515574857242454150695950829533116861727855889075098381754637464939319255060400927701671139009848824012858361603563707660104710181942955596198946767837449448255379774726847104047534646208046684259069491293313677028989152104752162056966024058038150193511253382430035587640247496473263914199272604269922796782354781636009341721641219924586315030286182974555706749838505494588586926995690927210797509302955321165344987202755960236480665499119881834797753566369807426542527862551818417574672890977772793800081647060016145249192173217214772350141441973568548161361157352552133475741849468438523323907394143334547762416862518983569485562099219222184272550254256887671790494601653466804988627232791786085784383827967976681454100953883786360950680064225125205117392984896084128488626945604241965285022210661186306744278622039194945047123713786960956364371917287467764657573962413890865832645995813390478027590099465764078951269468398352

const float E = exp(1);

/*
     * the complex number starts 0 + 0i by standart
     * real: real part
     * img: imaginary part
*/  
class complexNumber{
    public:
        float a;
        float b;

        complexNumber(){}
        complexNumber(float real, float img):a(real), b(img){
            this->a = real;
            this->b = img;
        }

        complexNumber operator+(complexNumber &n){
            complexNumber res;
            res.a = this->a + n.a;
            res.b = this->b + n.b;
            return res;
        }
        complexNumber operator-(complexNumber &n){
            complexNumber res;
            res.a = this->a + n.a;
            res.b = this->b + n.b;
            return res;
        }
        complexNumber operator*(complexNumber &n){
            complexNumber res;
            res.a = this->a*n.a - this->b*n.b;
            res.b = this->a*n.b + this->b*n.a;
            return res;
        }
        complexNumber operator/(complexNumber &n){
            complexNumber res;
            res.a = (this->a * n.a + this->b * n.b)/(pow(n.a, 2) + pow(n.b, 2));
            res.b = (n.a * this->b - this->a * n.b)/(pow(n.a, 2) + pow(n.b, 2));
        }
        complexNumber operator^(complexNumber &n){
            complexNumber res;
            res.a = pow(this->complexModulus(), n.a)/exp(this->argRadian()*n.b)*(cos(this->argRadian()*n.a + log(this->complexModulus()*n.b)));
            res.b = pow(this->complexModulus(), n.a)/exp(this->argRadian()*n.b)*(sin(this->argRadian()*n.a + log(this->complexModulus()*n.b)));
            return res;
        }
        
        float Re(){
            return this->a;
        }
        float Im(){
            return this->b;
        }
        float argRadian(){
            return atan(this->b/this->a);
        }
        float argDegree(){
            return (this->argRadian()/PI)*180;
        }
        float complexModulus(){
            return sqrt(pow(this->a, 2) + pow(this->b, 2));
        }
        void printComplexNumber(){
            printf("%.2f + %.2fi", this->a, this->b);
        }
        void printPolarForm(){
            printf("|%.2f|*(cos(%.0f) + isin(%.0f)", this->complexModulus(), this->argDegree(), this->argDegree());
        }
};

complexNumber complexSin(complexNumber n1){
    complexNumber n2;
    n2.a = ((exp(n1.b)*sin(n1.a))+(exp(-n1.b)*sin(n1.a)))/2; 
    n2.b = ((exp(n1.b)*cos(n1.a))+(exp(-n1.b)*cos(n1.a)))/2;
    return n2;
}
    
complexNumber complexCos(complexNumber n1){
    complexNumber n2;
    n2.a = (cos(n1.a) * ((1/exp(n1.b)) + exp(n1.b)))/2;
    n2.b = (sin(n1.a) * ((1/exp(n1.b)) + exp(n1.b)))/2;
    return n2;
}

complexNumber complexTan(complexNumber n1){
    complexNumber n2;
    n2.a = ((exp(2*n1.b) - exp(-2*n1.b)) * (pow(cos(n1.a), 2) - pow(sin(n1.a),2)))/(pow(exp(-n1.b) + exp(n1.b), 2));
    n2.b = (-2*sin(n1.a)*cos(n1.a)*(exp(2*n1.b) - exp(-2*n1.b)))/(pow(exp(-n1.b) + exp(n1.b), 2));
    return n2;
}

complexNumber complexLn(complexNumber n1){
    complexNumber n2;
    n2.a = log(n1.complexModulus());
    n2.b = n1.argRadian();
    return n2;
}

#endif