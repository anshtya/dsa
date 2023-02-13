#include<iostream>
#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
        for(int i = 0; i < 4; i++){
        cout << arr[i] << " ";
        }
        cout << endl;
    } 
}

int main(){
    vector<int> v{5,3,2,1};
    insertionSort(4, v);
    for(int i = 0; i < 4; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}