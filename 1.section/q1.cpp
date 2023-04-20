#include <iostream>
using namespace std;
int main(){
    double const metricTon = 35273.92;
    double weightOfPackage;
    double packageNumber;
    double ounceOfCreal;
    double metricTonOfCreal;
    cout << "Enter breakfast creal weight in ounce" << endl;
    cin >> ounceOfCreal;
    weightOfPackage = ounceOfCreal / metricTon;
    cout << "The weight of creal is " << weightOfPackage << endl;
    packageNumber = metricTon/ounceOfCreal;
    cout << "The number of package is " << packageNumber << endl;
    return 0;
}