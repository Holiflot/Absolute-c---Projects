/*This Programming Project requires you to first complete Programming Project 6.7
from Chapter 6, which is an implementation of a Pizza class. Add an Order class
that contains a private vector of type Pizza. This class represents a customer’s
entire order, where the order may consist of multiple pizzas. Include appropriate
functions so that a user of the Order class can add pizzas to the order (type is deep
dish, hand tossed, or pan; size is small, medium, or large; number of pepperoni or
cheese toppings). You can use constants to represent the type and size. Also write
a function that outputs everything in the order along with the total price. Write a
suitable test program that adds multiple pizzas to an order(s).*/
#include <iostream>
#include <vector>
using namespace std;

const int DEEPDISH = 1;
const int HANDTOSSED = 2;
const int PAN = 3;
const int SMALL = 1;
const int MEDIUM = 2;
const int LARGE = 3;

class Pizza {
public:
    Pizza(int t, int s, int to);
    int getType();
    int getSize();
    int getToppings();
    void output();
    int computeCost();
private:
    int type;
    int size;
    int toppings;
};

class Order {
public:
    void addPizza(Pizza& pizza);
    void output();
    int getTotalPrice(int priceOfPizza);
private:
    vector<Pizza> pizzas;
};

Pizza::Pizza(int t, int s, int to) {
    type = t;
    size = s;
    toppings = to;
}

int Pizza::getType() {
    return type;
}

int Pizza::getSize() {
    return size;
}

int Pizza::getToppings() {
    return toppings;
}

int Pizza::computeCost() {
    int price;
    switch (size) {
    case SMALL:
        price = 10; break;
    case MEDIUM:
        price = 14; break;
    case LARGE:
        price = 17; break;
    }

    price += toppings * 2;

    return price;
}

void Pizza::output() {
    switch (size) {
    case SMALL:
        cout << "Small "; break;
    case MEDIUM:
        cout << "Medium "; break;
    case LARGE:
        cout << "Large "; break;
    default:
        cout << "Unknown sized ";
    }

    switch (type) {
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

void Order::addPizza(Pizza& pizza) {
    pizzas.push_back(pizza);
}

void Order::output() {
    int pizzaNum = 1;
    for (Pizza p : pizzas) {
        cout << "Pizza #" << pizzaNum << ": ";
        p.output();
        cout << endl;
        pizzaNum++;
    }
}

int main() {
    Order order;
    char addAnother;
    int priceOfPizza;
    int total=0;
    do {
        char pType, pSize;
        int t = 0, s = 0, to = 0;

        cout << "What size pizza would you like (S/M/L): ";
        cin >> pSize;
        switch (pSize) {
        case 'S': case 's':
            s = SMALL; break;
        case 'M': case 'm':
            s = MEDIUM; break;
        case 'L': case 'l':
            s = LARGE; break;
        }

        cout << "What type pizza would you like ((D)eepdish/(H)and-tossed/(P)an): ";
        cin >> pType;
        switch (pType) {
        case 'D': case 'd':
            t = DEEPDISH; break;
        case 'H': case 'h':
            t = HANDTOSSED; break;
        case 'P': case 'p':
            t = PAN; break;
        }
        cout << "How many toppings do you want?" << endl;
        cin >> to;
        Pizza pizza(t, s, to);
        order.addPizza(pizza);
        pizza.output();
        priceOfPizza=pizza.computeCost();
        total+=priceOfPizza;
        cout << "Price of pizza: " << priceOfPizza << "$" << endl;
        cout << "New order" << endl;
        cin >>addAnother;
    }while(addAnother =='y');
        order.output();
        cout << "Total Pizza Price: " << total << endl;
        
        
    return 0;
}
       
