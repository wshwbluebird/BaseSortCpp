#include<iostream>
using namespace std;
//两种快排

int n;//表示 输入元素的个数;
int Arr[1000];
void quick_sort(int A[],int m, int n){
   
   if(m>=n)  return ;

   int key = A[n];
   int j = m -1s;
   for (int i = m; i < n; ++i)
     {
        if(A[i] < key){
          j++;
          int temp = A[j];
          A[j] = A[i];
          A[i] = temp;
        }
     }  
    j++;
    int temp = A[j];
    A[j] = A[n];
    A[n] = temp;
    
    quick_sort(A,m,j-1);
    quick_sort(A,j+1,n);



}

void Hoare_Quick_sort(int A[],int m, int n){
    if(m>=n) return ;

    int key = A[m];
    int front = m;
    int rear = n;

    while(front<rear){
      while(front<rear && key<=A[rear]) rear--;
      int temp = A[rear];
      A[rear] = key;
      A[front] = temp;
      //front ++;
      while(front<rear &&  A[front]<=key ) front++;
      temp = A[front];
      A[front] = key;
      A[rear] = temp;
    }

    Hoare_Quick_sort(A,m,front-1);
    Hoare_Quick_sort(A,front+1,n);

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
    //quick_sort(Arr,1,n);
    //cout<<"quick sort: ";
    //output();
    Hoare_Quick_sort(Arr,1,n);
    cout<<"Hoare quick sort: ";
    output();
  return 0;
}