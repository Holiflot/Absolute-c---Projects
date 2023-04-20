/*Define a class for a type called Fraction. This class is used to represent a ratio
of two integers. Include mutator functions that allow the user to set the numerator
and the denominator. Also include a member function that returns the value
of the numerator divided by the denominator as a double. Include an additional
member function that outputs the value of the fraction reduced to lowest terms.
For example, instead of outputting 20/60 the function should output 1/3. This will
require finding the greatest common divisor for the numerator and denominator,
and then dividing both by that number. Embed your class in a test program.*/
#include <iostream>
using namespace std;

class Fraction{
    public:
    void setFraction(int x,int y);
    void input();
    void output();
    void simplifiedFraction();
    private:
    int numerator;
    int  denominator;
    double result;
};
void Fraction::setFraction(int x,int y){
    numerator=x;
    denominator=y;
    result=double(numerator)/double(denominator);
}
void Fraction::input(){
    int a,b;
    cout <<"Enter numerator and denominator value." << endl;
    cin >> a >> b;
    setFraction(a,b);
}
void Fraction::output(){
    cout << "numerator / denominator = " << numerator << " / " << denominator << endl;
    cout << "Result = " << result << endl;
}
void Fraction::simplifiedFraction(){
    int gcd;
    for(int i=2;i<numerator && i<denominator;i++){
        if(numerator%i==0 && denominator%i==0)
            gcd=i;
    }
    numerator/=gcd;
    denominator/=gcd;
}


int main(){
    Fraction fraction;
    fraction.input();
    fraction.simplifiedFraction();
    fraction.output();
    return 0;
}