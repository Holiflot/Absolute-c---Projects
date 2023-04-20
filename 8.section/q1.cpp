/*1. Modify the definition of the class Money shown in Display 8.5 so that the following
are added:
a. The operators <, <=, >, and >= have each been overloaded to apply to the type
Money. (Hint: See Self-Test Exercise 8.)
b. The following member function has been added to the class definition. (We
show the function declaration as it should appear in the class definition. The
definition of the function itself will include the qualifier Money::.)
const Money percent(int percentFigure) const;
//Returns a percentage of the money amount in the calling
//object. For example, if percentFigure is 10, then the value
//returned is 10% of the amount of money represented by the
//calling object.
For example, if purse is an object of type Money whose value represents the
amount $100.10, then the call
purse.percent(10);
returns 10% of $100.10; that is, it returns a value of type Money that represents
the amount $10.01.*/
#include <iostream>

class Money {
private:
    int dollars_;
    int cents_;
    double amount_;

public:
    Money(int dollars = 0, int cents = 0) : dollars_(dollars), cents_(cents), amount_(dollars + static_cast<double>(cents) / 100.0) {}

    friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << "$" << money.dollars_ << ".";

        if (money.cents_ < 10) {
            os << "0";
        }
        os << money.cents_;
        return os;
    }
};

int main() {
    Money amount1(10, 99), amount2(20, 50);
    std::cout << "Amount 1: " << amount1 << std::endl;
    std::cout << "Amount 2: " << amount2 << std::endl;

    return 0;
}
