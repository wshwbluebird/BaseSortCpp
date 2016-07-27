#include<iostream>
#include <string.h>
using namespace std;


int n;//表示 输入元素的个数;
int Arr[1000];
int heap_size=0;


const int inf  = 214847364;


void Max_Heapify(int A[] , int i){
     int left = 2*i;
     int right = 2*i +1;
     int largest = i;
     if(left <= heap_size && A[left] > A[largest])
        largest = left;
     if(right <= heap_size && A[right] > A[largest])
        largest = right;

      if(largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        Max_Heapify(A,largest);
      }
}

void Build_Max_Heap(int A[]){

         heap_size = n;
    for (int i = n/2; i >= 1; i--)
    {    
         
         Max_Heapify(A,i);
    }

}

void Heap_sort(int A[]){
     Build_Max_Heap(A);
     for (int i = n; i > 1; --i)
     {
          int temp = A[i];
          A[i] = A[1];
          A[1] = temp;
          heap_size--;
          Max_Heapify(A,1);
     }


}
void input(){
	cin>>n;
	for (int i = 1; i <=  n; ++i)
	{
		cin>>Arr[i];
	}
}

void output(){
	for (int i = 1; i <=  n; ++i)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{   
    input();
    output();
    Heap_sort(Arr);
    output();
	return 0;
}