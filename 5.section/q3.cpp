/*The standard deviation of a list of numbers is a measure of how much the numbers
deviate from the average. If the standard deviation is small, the numbers are
clustered close to the average. If the standard deviation is large, the numbers are
scattered far from the average. The standard deviation, S, of a list of N numbers xi
is defined as follows:
S = H
a
N
i=1
1xi - x22
N
where x is the average of the N numbers x1, x2, …. Define a function that takes a
partially filled array of numbers as its argument and returns the standard deviation
of the numbers in the partially filled array. Since a partially filled array requires two
arguments, the function will actually have two formal parameters: an array parameter
and a formal parameter of type int that gives the number of array positions used.
The numbers in the array will be of type double. Embed your function in a suitable
test program.*/
#include <iostream>
#include <cmath>
using namespace std;

double calculateAvrg(double sd[], int& num){
    double total=0.0;
    for(int i=0;i<num;i++){
        total+=sd[i];
    }
        
    cout << total/num << endl;
    return total/num;
}
double calculateStandartDevition(double sd[],int& num,double& avrg){
    double sdtnDiff=0.0;
    double sdtn;
    for(int i=0;i<num;i++)
        sdtnDiff+=sqrt((sd[i] - avrg)*(sd[i] - avrg));
    sdtn=sdtnDiff/num;
    return sdtn;
}
int main()
{   
    int i;
    int num;
    cout << "How  many number do you want to fill in the array ?" << endl;
    cin >> num;
    double sd[num];
    for(i=0;i<num;i++){
        cout << i+1 << ": ";
        cin >> sd[i];
    }
    double avrg = calculateAvrg(sd,num);
    cout << avrg << endl;
    double sdtn = calculateStandartDevition(sd,num,avrg);        
    for(i=0;i<num;i++)
        cout << i+1 << ": " << sd[i] << " ";
    cout << endl << "The standart definition of this array: " << sdtn << endl;
    
    return 0;
}

