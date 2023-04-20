/*Write the definition for a class named GasPump to be used to model a pump at an
automobile service station. Before you go further with this programming exercise,
write down the behavior you expect from a gas pump from the point of view of the
purchaser.
The following are listed things a gas pump might be expected to do. If your list
differs, and you think your list is as good or better than these, then consult your
instructor. You and your instructor should jointly decide what behavior you are to
implement. Then implement and test the agreed upon design for a gas pump class.
a. A display of the amount dispensed
b. A display of the amount charged for the amount dispensed
c. A display of the cost per gallon, liter, or other unit of volume that is used where
you reside
d. Before use, the gas pump must reset the amount dispensed and amount charged
to zero.
e. Once started, a gas pump continues to dispense fuel, keep track of the amount
dispensed, and compute the charge for the amount dispensed until stopped.
f. A stop dispensing control of some kind is needed.
Implement the behavior of the gas pump as declarations of member functions of
the gas pump class, then write implementations of these member functions. You
will have to decide if there is data the gas pump has to keep track of that the user
of the pump should not have access to. If so, make these private member variables.*/
#include <iostream>
using namespace std;
class GasPump{
    public:
        void input();
        void setGas(double gasP);
        double getGasPrice();
        double getGasLiter();
        double getTotalGasPrice();
        void addGass();
        void reset();
        void output();
    private:
        double gasPrice;
        double gasLiter;
        double totalGasPrice;
};

void GasPump::setGas(double gasP){
    gasPrice=gasP;
    gasLiter=0.0;
    totalGasPrice=0.0;
}
double GasPump::getGasPrice(){return gasPrice;}
double GasPump::getGasLiter(){return gasLiter;}
double GasPump::getTotalGasPrice(){return totalGasPrice;}
void GasPump::addGass(){
    double gas;
    cout << "How much liter will you add gass in your car?" << endl;
    cin >> gas;
    gasLiter+=gas;
    totalGasPrice+=gas*gasPrice;
}
void GasPump::reset(){
    gasLiter=0.0;
    totalGasPrice=0.0;
}
void GasPump::output(){
    cout << "Gas Price: " << gasPrice << " Gas Liter: " << gasLiter << " Total amount of gas price: " << totalGasPrice << endl;
}
void GasPump::input(){
    double price;
    cout << "how much is the gas price in your city?" << endl;
    cin >> price;
    setGas(price);
}
int main(){
    char choose,choose2;
    GasPump gas;
    gas.input();
    do
    {
        cout << "Welcome to gas station" << endl;
        do
        {
            gas.addGass();
            gas.output();
            cout << "Will you add gas? y/n" << endl;
            cin >> choose;
        } while (choose != 'n');
        gas.reset();
        cout << "Job is finished or not? y/n" << endl;
        cin >> choose2;
    } while (choose != 'y');
    
    
    

    return 0;
}