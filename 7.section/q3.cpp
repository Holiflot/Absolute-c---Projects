/*My mother always took a little red counter to the grocery store. The counter was
used to keep tally of the amount of money she would have spent so far on that visit
to the store if she bought everything in the basket. The counter had a four-digit
display, increment buttons for each digit, and a reset button. An overflow indicator
came up red if more money was entered than the $99.99 it would register. (This
was a long time ago.)
Write and implement the member functions of a class Counter that simulates and
slightly generalizes the behavior of this grocery store counter. The constructor should
create a Counter object that can count up to the constructor’s argument. That is,
Counter(9999) should provide a counter that can count up to 9999. A newly constructed
counter displays a reading of 0. The member function void reset( );
sets the counter’s number to 0. The member function void incr1( ); increments
the units digits by 1, void incr10( ); increments the tens digit by 1, and void
incr100( ); and void incr1000( ); increment the next two digits, respectively.
Accounting for any carrying when you increment should require no further action than
adding an appropriate number to the private data member. A member function bool
overflow( ); detects overflow. (Overflow is the result of incrementing the counter’s
private data member beyond the maximum entered at counter construction.)
Use this class to provide a simulation of my mother’s little red clicker. Even though
the display is an integer, in the simulation, the rightmost (lower order) two digits
are always thought of as cents and tens of cents, the next digit is dollars, and the
fourth digit is tens of dollars.
Provide keys for cents, dimes, dollars, and tens of dollars. Unfortunately, no choice of
keys seems particularly mnemonic. One choice is to use the keys asdfo: a for cents,
followed by a digit 1 to 9; s for dimes, followed by a digit 1 to 9; d for dollars, followed
by a digit 1 to 9; and f for tens of dollars, again followed by a digit 1 to 9. Each entry
(one of asdf followed by 1 to 9) is followed by pressing the Return key. Any overflow
is reported after each operation. Overflow can be requested by pressing the o key.*/
#include <iostream>
#include <vector>
using namespace std;


class Counter {
public:
    Counter(int m);
    int getCent();
    int getDime();
    int getDollar();
    int getTenDollar();
    void output();
    void reset();
    void incr1();
    void incr10();
    void incr100();
    void incr1000();
    void overflow();
private:
    int money;
    static int cent;
    static int dime;
    static int dollar;
    static int tenDollar;
};
int Counter::cent=0;
int Counter::dime=0;
int Counter::dollar=0;
int Counter::tenDollar=0;


Counter::Counter(int m) {
    money = m;
}

int Counter::getCent() {
    return cent;
}

int Counter::getDime() {
    return dime;
}

int Counter::getDollar() {
    return dollar;
}
int Counter::getTenDollar() {
    return tenDollar;
}
void Counter::incr1(){
    int temp;
    temp=money % 10;
    for(int i=0;i<temp;i++)
        cent++;
}
void Counter::incr10(){
    int temp,number;
    number = money/10;
    temp=number % 10;
    for(int i=0;i<temp;i++)
        cent++;
}
void Counter::incr100(){
    int temp,number;
    number = money/100;
    temp=number % 10;
    for(int i=0;i<temp;i++)
        cent++;
}
void Counter::incr1000(){
    int temp;
    temp = money/1000;
    for(int i=0;i<temp;i++){
        cent++;
        overflow();
    }
        
}

void Counter::output() {
    
}

void Counter::reset(){
    cent=0;
    dime=0;
    dollar=0;
    tenDollar=0;
}
void Counter::overflow(){
    if(tenDollar==9 && dollar==9 && dime==9 && cent==9){
        "Counter overflowed" << endl;
        exit(1);
    }
        
}

int main() {
      
        
    return 0;
}