#include<iostream>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;
        Heap(){
            arr[0] = -1;
            size = 0;
        }
        void insert(int val){
            size = size+1;
            int index = size;
            arr[index] = val;

            while (index > 1)
            {
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else
                    return;
            }
            
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        void deletion(){
            if(size < 0 ){
                cout<<"Empty heap"<<endl;
                return;
            }
            arr[1] = arr[size];
            size--;
            int i=1;
            while(size > i){
                int left = 2*i;
                int right = 2*i+1;
                if((left < size and right < size) and (arr[left] > arr[i] and arr[right] > arr[i])){
                    int maxi;
                    if(arr[left] > arr[right]){
                        maxi = left;
                    }
                    else{
                        maxi = right;
                    }
                    swap(arr[i],arr[maxi]);
                    i = maxi;
                }
                else if(left < size and arr[left] > arr[i]){
                    swap(arr[i],arr[left]);
                    i = left;
                }
                else if(right < size and arr[right] > arr[i]){
                    swap(arr[i],arr[right]);
                    i = right;                    
                }
                else{
                    return;
                }   
            }
        }
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left < n and arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n and arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
int main(){
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(5);
    h.insert(2);
    h.print();
    h.deletion();
    h.print();
    return 0;
}
