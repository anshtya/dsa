#include <iostream>
using namespace std;
class myArray{
    int total_size, used_size, *ptr;
    public:
        myArray(int, int);
        void setVal(myArray*);
        void showVal(myArray*);
        void show();
};
myArray ::myArray(int tSize, int uSize)
{
    total_size = tSize;
    used_size = uSize;
    ptr = new int[tSize];
}
void myArray ::setVal(myArray* a)
{
    for(int i = 0; i < (*a).used_size; i++){
        cout<<"Enter element "<< i + 1 <<": ";
        cin>>(*a).ptr[i];
    }
}
void myArray ::showVal(myArray* a)
{
    cout<<"Show running"<<endl;
    for(int i = 0; i < (*a).used_size; i++){
        cout<<(*a).ptr[i]<<endl;
    }
}
int main(){
    myArray a(100, 2);
    a.setVal(&a);
    a.showVal(&a);
    return 0;
}