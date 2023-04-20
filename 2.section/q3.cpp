/*Workers at a particular company have won a 7.6% pay increase retroactive for six
months. Write a program that takes an employee’s previous annual salary as input
and outputs the amount of retroactive pay due the employee, the new annual
salary, and the new monthly salary. Use a variable declaration with the modifier
const to express the pay increase.*/
#include <iostream>
using namespace std;

int main() {
    int money;
    int chocolate_price = 1;
    int cupon=0;
    int total_chocolate=0;
    int cupon_chocolate=0;
    cout << "Please enter amount of money." << endl;
    cin >> money ;
    cupon=money/chocolate_price;
    total_chocolate = money/chocolate_price;
    while(cupon > 7){
        
        cupon_chocolate+= cupon/7;
        cupon=cupon_chocolate + (cupon%7);
    }
    
    cout << cupon << endl; 
    cout << total_chocolate +cupon_chocolate << endl;
    return 0;
}