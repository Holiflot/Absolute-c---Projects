/*Define a class for a type called CounterType. An object of this type is used to
count things, so it records a count that is a nonnegative whole number. Include a
mutator function that sets the counter to a count given as an argument. Include
member functions to increase the count by one and to decrease the count by one.
Be sure that no member function allows the value of the counter to become negative.
Also, include a member function that returns the current count value and one
that outputs the count. Embed your class definition in a test program.*/
#include <iostream>
using namespace std;

class CounterType{
    public:
        void setCounter(int number);
        int getCounter();
        void increment();
        void decrement();
        void output();
    private:
        int counter;
};
void CounterType::setCounter(int number){
    if(number>=0)
        counter = number;
    else
        counter = 0;
}
int CounterType::getCounter(){return counter;}

void CounterType::increment(){
    if(counter > 0)
        counter ++;
}
void CounterType::decrement(){
    if(counter > 0)
        counter --;
}
void CounterType::output(){
    cout << "Counter is " << counter << endl;
}
int main(){
    CounterType count;
    count.setCounter(8);
    count.output();
    for(int i=0;i<3;i++){
        count.increment();
        count.output();
    }
        
    for(int i=0;i<13;i++){
        count.decrement();
        count.output();
    }
        

    return 0;
}