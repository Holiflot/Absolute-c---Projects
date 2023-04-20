/*Write a program to gauge the rate of inflation for the past year. The program asks
for the price of an item (such as a hot dog or a one-carat diamond) both one year
ago and today. It estimates the inflation rate as the difference in price divided by
the year-ago price. Your program should allow the user to repeat this calculation
as often as the user wishes. Define a function to compute the rate of inflation. The
inflation rate should be a value of type double giving the rate as a percentage, for
example 5.3 for 5.3%.*/
#include <iostream>
using namespace std;

double calculateİnfilation(double p1, double p2){
    return (p2-p1)/p1*100;
}

int main(){
    
    double oldPrice;
    double currentPrice;
    cout << "Enter price of the item last year: ";
    cin >> oldPrice;
    cout << "Enter current price of the item: ";
    cin >> currentPrice;

    
    cout << "The infilation rate is %" << calculateİnfilation(oldPrice,currentPrice) << endl;

    return 0;
}
