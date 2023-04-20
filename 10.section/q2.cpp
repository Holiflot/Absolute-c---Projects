/*Using dynamic arrays, implement a polynomial class with polynomial addition,
subtraction, and multiplication.
Discussion: A variable in a polynomial does nothing but act as a placeholder for
the coefficients. Hence, the only interesting thing about polynomials is the array
of coefficients and the corresponding exponent. Think about the polynomial
x*x*x + x + 1
Where is the term in x*x? One simple way to implement the polynomial class is to
use an array of type double to store the coefficients. The index of the array is the
exponent of the corresponding term. If a term is missing, then it simply has a zero
coefficient.
There are techniques for representing polynomials of high degree with many missing
terms. These use so-called sparse matrix techniques. Unless you already know
these techniques, or learn very quickly, do not use these techniques.
Provide a default constructor, a copy constructor, and a parameterized constructor
that enables an arbitrary polynomial to be constructed.
Supply an overloaded operator = and a destructor.
Provide these operations:
polynomial + polynomial, constant + polynomial, polynomial + constant,
polynomial - polynomial, constant - polynomial, polynomial - constant.
polynomial * polynomial, constant * polynomial, polynomial * constant,
Supply functions to assign and extract coefficients, indexed by exponent.
Supply a function to evaluate the polynomial at a value of type double.
You should decide whether to implement these functions as members, friends, or
standalone functions.*/
#include <iostream>
#include <cmath>
using namespace std;    
class Polynomial{
    public:
        Polynomial();
        Polynomial(int arr[],int c);
        ~Polynomial();
        Polynomial operator+(Polynomial& obj);
        Polynomial operator-(Polynomial& obj);
        Polynomial operator*(Polynomial& obj);
        Polynomial& operator=(const Polynomial& obj);
        Polynomial(const Polynomial& obj);
        int evaluate(const int& number);
        int mySize(){return *coef+1;};
        int& operator[](int degree);
        const int& operator[](int degree) const;
    private:
        int *func;
        int* coef; // changed from int coef;
};

Polynomial::Polynomial(){
    func=nullptr;
    coef=nullptr;
}
Polynomial::Polynomial(int arr[],int c){
    coef=new int;
    *coef=c;
    func=new int[*coef];
    for(int i=0;i<*coef;i++){
        func[i]=arr[i];
    }
}
Polynomial::~Polynomial(){
    delete[] func;
    delete coef;
}
Polynomial::Polynomial(const Polynomial& obj) {
    coef = new int(*obj.coef);
    func = new int[*coef];
    for (int i = 0; i < *coef; i++) {
        func[i] = obj.func[i];
    }
}

Polynomial& Polynomial::operator=(const Polynomial& obj) {
    if (this == &obj) { // check for self-assignment
        return *this;
    }
    delete[] func;
    delete coef;
    coef = new int(*obj.coef);
    func = new int[*coef];
    for (int i = 0; i < *coef; i++) {
        func[i] = obj.func[i];
    }
    return *this;
}

Polynomial Polynomial::operator+(Polynomial& obj){
    int i=0; // initialize i
    Polynomial res;
    res.coef = new int;
    *res.coef = max(*coef, *obj.coef);
    res.func = new int[*res.coef];
    for(i=0;i<*coef;i++){
        res.func[i]=func[i];
    }
    for(i=0;i<*obj.coef;i++){
        res.func[i]+=obj.func[i];
    }
    return res;
}
Polynomial Polynomial::operator-(Polynomial& obj){
    int i=0; // initialize i
    Polynomial res;
    res.coef = new int;
    *res.coef = max(*coef, *obj.coef);
    res.func = new int[*res.coef];
    for(i=0;i<*coef;i++){
        res.func[i]=func[i];
    }
    for(i=0;i<*obj.coef;i++){
        res.func[i]-=obj.func[i];
    }
    return res;
}
Polynomial Polynomial::operator*(Polynomial& obj){
    int i=0, j=0; // initialize i and j
    Polynomial temp;
    temp.coef=new int;
    *temp.coef=*coef+*obj.coef-1;
    temp.func=new int[*temp.coef];
    for(i=0;i<*temp.coef;i++){
        temp.func[i]=0;
    }
    for(i=0;i<*coef;i++){
        for(j=0;j<*obj.coef;j++){
            temp.func[i+j]+=func[i]*obj.func[j];
        }
    }
    return temp;
}
int Polynomial::evaluate(const int& number){
    int result = 0;
    for (int i = 0; i < *coef; i++) {
        result += func[i] * pow(number, i);
    }
    return result;
}
int& Polynomial::operator[](int degree){
    return func[degree];
}
const int& Polynomial::operator[](int degree) const{
    return func[degree];
}
int main()
{
    Polynomial empty;
    int one[] = {1};
    Polynomial One(one, 1);
    int quad[] = {3, 2, 1};
    int cubic[] = {1, 2, 0, 3};
    Polynomial q(quad, 3); // q is 3 + 2*x + x*x
    Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
    Polynomial p = q;
    Polynomial r;
    r = q; //test operator=
    r = c;
    cout << "Polynomial q " << endl;
    {for(int i = 0; i < 3; i++)
    cout << "term with degree " << i
    << " has coefficient " << q[i] << endl;
    }
    cout << "Polynomial c " << endl;
    {for(int i = 0; i < 4; i++)
    cout << "term with degree " << i
    << " has coefficient " << c[i] << endl;
    }
    cout << "value of q(2) is " << q.evaluate(2) << endl;
    cout << "value of p(2) is " << p.evaluate(2) << endl;
    cout << "value of r(2) is " << r.evaluate(2) << endl;
    cout << "value of c(2) is " << c.evaluate(2) << endl;
    r = q + c;
     cout << "value of (q + c)(2) is " << r.evaluate(2) << endl;
    r = q - c;
    cout << "value of (q - c)(2) is " << r.evaluate(2) << endl;
    r = q * c;
    // cout << "size of q*c is " << r.mySize() << endl;
    // cout << "Polynomial r (= q*c) " << endl;
    // for(int i = 0; i < r.mySize(); i++)
    // cout << "term with degree " << i
    // << " has coefficient " << r[i] << endl;
    cout << "value of (q * c)(2) is " << r.evaluate(2) << endl;
   
    return 0;
}
