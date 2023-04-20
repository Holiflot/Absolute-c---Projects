/*One problem with dynamic arrays is that once the array is created using the new
operator the size cannot be changed. For example, you might want to add or delete
entries from the array similar to the behavior of a vector. This project asks you
to create a class called DynamicStringArray that includes member functions that
allow it to emulate the behavior of a vector of strings.
The class should have the following:
• A private member variable called dynamicArray that references a dynamic array
of type string.
• A private member variable called size that holds the number of entries in the
array.
• A default constructor that sets the dynamic array to nullptr and sets size
to 0.
• A function that returns size.
• A function named addEntry that takes a string as input. The function should
create a new dynamic array one element larger than dynamicArray, copy all
elements from dynamicArray into the new array, add the new string onto the
end of the new array, increment size, delete the old dynamicArray, and then
set dynamicArray to the new array.
• A function named deleteEntry that takes a string as input. The function
should search dynamicArray for the string. If not found, it returns false. If
found, it creates a new dynamic array one element smaller than dynamicArray.
It should copy all elements except the input string into the new array, delete
dynamicArray, decrement size, and return true.
• A function named getEntry that takes an integer as input and returns the
string at that index in dynamicArray. It should return nullptr if the index is
out of dynamicArray’s bounds.
• A copy constructor that makes a copy of the input object’s dynamic array.
• Overload the assignment operator so that the dynamic array is properly copied
to the target object.
• A destructor that frees up the memory allocated to the dynamic array.
Embed your class in a suitable test program.*/
#include <iostream>
#include <string>
using namespace std;

class DynamicArrayString{
    public:
        DynamicArrayString();
        DynamicArrayString(string A[],int s);
        int mySize(){return size;};
        DynamicArrayString addEntry(const string& value);
        bool deleteEntry(const string& value);
        string& getEntry(const int& index);
        DynamicArrayString(const DynamicArrayString& obj);
        DynamicArrayString& operator=(const DynamicArrayString& rvalue);
        ~DynamicArrayString();
    private:
        string *dynamicArray;
        int size;
};
DynamicArrayString::DynamicArrayString(){
    size=0;
    *dynamicArray=nullptr;
}
DynamicArrayString::DynamicArrayString(string A[],int s){
    size=s;
    dynamicArray=new string[size];
    for(int i=0;i<size;i++)
        dynamicArray[i]=A[i];
}
DynamicArrayString DynamicArrayString::addEntry(const string& value){
    string *temp = new string[size+1];
    for(int i=0;i<size;i++)
        temp[i]=dynamicArray[i];
    delete [] dynamicArray;
    temp[size]=value;
    size+=1;
    dynamicArray=temp;
    return *this;
}

bool DynamicArrayString::deleteEntry(const string& value){
    for(int i=0;i<size;i++){
        if(dynamicArray[i]==value){
            for(int j=i;j<size-1;j++)
                dynamicArray[j]=dynamicArray[j+1];
            size-=1;
            string *temp= new string[size];
            for(int i=0;i<size;i++)
                temp[i]=dynamicArray[i];
            delete [] dynamicArray;
            dynamicArray = temp;
            return true;
        }     
    }
      return false;      
}
string& DynamicArrayString::getEntry(const int& index){
    if(index>=size || index<-1){
        throw std::out_of_range("Invalid index provided.");
    }
    return dynamicArray[index];
}
DynamicArrayString::DynamicArrayString(const DynamicArrayString& obj){
    size=obj.size;
    dynamicArray=new string[size];
    for(int i=0;i<size;i++)
        dynamicArray[i]=obj.dynamicArray[i];
}
DynamicArrayString& DynamicArrayString::operator=(const DynamicArrayString& rvalue){
    if(this == &rvalue)
        return *this;
    size=rvalue.size;
    delete [] dynamicArray;
    dynamicArray = new string[size];
    for(int i=0;i<size;i++)
        dynamicArray[i]=rvalue.dynamicArray[i];
    return *this;
}
DynamicArrayString::~DynamicArrayString(){
    delete [] dynamicArray;
}

int main(){
    string arr[]= {"Osman", "Ayşegül","Merve"};
    string arr2[]= {"Osman", "Ayşegül"};
    DynamicArrayString a(arr,3);
    cout << " size:" << a.mySize() << endl;
    string b="Mehmet Ali",c="Merve",d="Mustafa";
    for(int i=0;i<a.mySize();i++)
        cout << a.getEntry(i) << " " ;
    cout << endl;
    a.addEntry(b);
    for(int i=0;i<a.mySize();i++)
        cout << a.getEntry(i) << " " ;
    cout << endl;
    cout << a.deleteEntry(c) << endl;
    cout << a.deleteEntry(d) << endl;
    for(int i=0;i<a.mySize();i++)
        cout << a.getEntry(i) << " " ;
    cout << endl;
    DynamicArrayString second(a);
    for(int i=0;i<second.mySize();i++)
        cout << second.getEntry(i) << " " ;
    cout << endl;
    DynamicArrayString third(arr2,2);
    third=a;
    for(int i=0;i<third.mySize();i++)
        cout << third.getEntry(i) << " " ;
    cout << endl;
    return 0;
}