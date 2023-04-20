/*Write a function called deleteRepeats that has a partially filled array of characters
as a formal parameter and that deletes all repeated letters from the array. Since a
partially filled array requires two arguments, the function will actually have two
formal parameters: an array parameter and a formal parameter of type int that
gives the number of array positions used. When a letter is deleted, the remaining
letters are moved forward to fill in the gap. This will create empty positions at
the end of the array so that less of the array is used. Since the formal parameter is
a partially filled array, a second formal parameter of type int will tell how many
array positions are filled. This second formal parameter will be a call-by-reference
parameter and will be changed to show how much of the array is used after the
repeated letters are deleted. For example, consider the following code:
char a[10];
a[0] = 'a';
a[1] = 'b';
a[2] = 'a';
a[3] = 'c';
int size = 4;
deleteRepeats(a, size);
After this code is executed, the value of a[0] is 'a', the value of a[1] is 'b', the
value of a[2] is 'c', and the value of size is 3. (The value of a[3] is no longer
of any concern, since the partially filled array no longer uses this indexed variable.)
You may assume that the partially filled array contains only lowercase letters. Embed
your function in a suitable test program.*/
#include <iostream>
using namespace std;
void deleteRepeats (char a[], int& size){
    int i;
    for(i =0 ; i<size-1; i++){
        for(int j=i+1;j<size;j++)
        if(a[i]==a[j]){
            a[j]=' ';
        }
    }
    for( i =0 ; i<size; i++){
        if(a[i]==' ' && a[i+1]!=' '){
            a[i]=a[i+1];
            size --;
        }
            
    }
}
int main()
{   
    int i;
    int num;
    cout << "How  many character do you want to fill in the array ?" << endl;
    cin >> num;
    char a[num];
    for(i=0;i<num;i++){
        cout << i+1 << ": ";
        cin >> a[i];
    }

    cout << "Before same elemets are deleteed :";
    for(i=0;i<num;i++)
        cout << i+1 << ": " << a[i] << ", ";
        cout << endl;
    deleteRepeats(a,num);
    for(i=0;i<num;i++)
        cout << i+1 << ": " << a[i] << ", ";
    return 0;
}

