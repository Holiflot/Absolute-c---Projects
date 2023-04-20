/*Define a class called Pizza that has member variables to track the type of pizza
(either deep dish, hand tossed, or pan) along with the size (either small, medium,
or large) and the number of pepperoni or cheese toppings. You can use constants to
represent the type and size. Include mutator and accessor functions for your class.
Create a void function, outputDescription( ), that outputs a textual description
of the pizza object. Also include a function, computePrice( ), that computes the
cost of the pizza and returns it as a double according to the following rules:
Small pizza = $10 + $2 per topping
Medium pizza = $14 + $2 per topping
Large pizza = $17 + $2 per topping
Write a suitable test program that creates and outputs a description and price of
various pizza objects.*/
#include <iostream>
using namespace std;

const int DEEPDISH = 1; 
const int HANDTOSSED = 2; 
const int PAN = 3; 
const int SMALL = 1; 
const int MEDIUM = 2; 
const int LARGE = 3; 

class Pizza{
    public:
    int getType(); 
    int getSize(); 
    int getCheese();  
    void setType(int t); 
    void setSize(int s); 
    void setCheese(int to); 
    int computerCost();
    void input();
    void output();
    private:
    int type;
    int size;
    int toppings;
};

void Pizza::setType(int t) 
{ 
    type = t;
} 
 
void Pizza::setSize(int s) 
{ 
    size = s; 
} 
void Pizza::setCheese(int to) 
{ 
    toppings = to; 
} 
int Pizza::getType() 
{ 
return type; 
} 
 
int Pizza::getSize() 
{ 
return size; 
} 
 
int Pizza::getCheese() 
{ 
return toppings; 
} 
void Pizza::input(){
    char pType, pSize; 
    int t = 0, s = 0,to; 
    
    cout << "What size pizza would you like (S/M/L): "; 
    cin >> pSize; 
    switch (pSize) 
    { 
        case 'S': case 's': 
        s = SMALL; break; 
        case 'M': case 'm': 
        s = MEDIUM; break; 
        case 'L': case 'l': 
        s = LARGE; break; 
    } 
    
    cout << "What type pizza would you like ((D)eepdish/(H)and-tossed/(P)an): "; 
    cin >> pType; 
    switch (pType) 
    { 
        case 'D': case 'd': 
        t = DEEPDISH; break; 
        case 'H': case 'h': 
        t = HANDTOSSED; break; 
        case 'P': case 'p': 
        t = PAN; break; 
    } 
    cout << "How many toppings do you want?" << endl;
    cin >> to;
    setSize(s); 
    setType(t);
    setCheese(to); 
    
}
int Pizza::computerCost(){
    int price;
    switch (size) 
    { 
        case SMALL: 
        price = 10; break; 
        case MEDIUM: 
        price = 14; break; 
        case LARGE: 
        price = 17; break; 
    } 
    cout << price << endl;
    price+=toppings*2;
 
    return price; 
    
}
void Pizza::output(){ 
    switch (size) 
    { 
        case SMALL: 
        cout << "Small "; break; 
        case MEDIUM: 
        cout << "Medium "; break; 
        case LARGE: 
        cout << "Large "; break; 
        default: 
        cout << "Unknown sized "; 
    } 
 
    switch (type) 
    { 
        case DEEPDISH: 
        cout << "deepdish "; break; 
        case HANDTOSSED: 
        cout << "hand tossed "; break; 
        case PAN: 
        cout << "pan "; break; 
        default: 
        cout << "unknown type "; 
    } 
}

int main(){
    Pizza pizza;
    pizza.input();
    pizza.output();
    int priceOfPizza=pizza.computerCost();
    cout << "Price of pizza: " << priceOfPizza << "$" << endl;
    return 0;
}