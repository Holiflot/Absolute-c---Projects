/*Enhance your program from the previous exercise by having it also print out the
estimated price of the item in one and in two years from the time of the calculation.
The increase in cost over one year is estimated as the inflation rate times the price
at the start of the year. Define a second function to determine the estimated cost
of an item in a specified number of years, given the current price of the item and
the inflation rate as arguments.*/
#include <iostream>
using namespace std;

double calculateİnfilation(double p1, double p2){
    return (p2-p1)/p1*100;
}
double calculatePrice(double r,int y,double p){
    for(int i=0;i<y;i++){
        p+=p*r/100;
    }
        
    return p;
}
int main(){
    
    double oldPrice;
    double currentPrice;
    cout << "Enter price of the item last year: ";
    cin >> oldPrice;
    cout << "Enter current price of the item: ";
    cin >> currentPrice;
    double rate = calculateİnfilation(oldPrice,currentPrice);
    
    cout << "The infilation rate is %" << rate << endl;
    int year;
    cout << "Calculate the value of the item after how many years: ";
    cin >> year;

    double newPrice = calculatePrice(rate,year,currentPrice);

    cout <<"The estimated value of the item after " << year << " years is " << newPrice << endl;  
    return 0;
}