#include<iostream>
#include <string.h>
using namespace std;
//基数排序

int n;//表示 输入元素的个数;
int Arr[100];
int Brr[100];
int Prr[100];
int m=10;
void couting_sort(int A[],int B[],int P[],int k){
   int c[10];
   memset(c,0,sizeof(c));
   cout<<"P: ";
   for (int i = 1; i <= n; ++i)
   {
     cout<<P[i]<<"  ";
   }
   cout<<endl;


   for (int i = 1; i <= n; ++i)
   {
     c[P[i]]++;
   }

   for (int i = 1; i <= k; ++i)
   {
     c[i] += c[i-1];
   }

   for (int i = n; i >= 1; --i)
   {
     B[c[P[i]]] = A[i];
     c[P[i]] --;
   }


}


void input(){
  cin>>n;
  for (int i = 1; i <=  n; ++i)
  {
    cin>>Arr[i];
    Prr[i] = Arr[i];
  }
}

void output(){
  for (int i = 1; i <=  n; ++i)
  {
    cout<<Arr[i]<<" ";
  }
  cout<<endl;
}


void radix_sort(int A[] ,int B[],int P[]){
     int flag = 1;
     int c[100];
     memset(c,0,sizeof(c));
     for (int i = 1; i <= n; ++i)
     {
         c[i] = P[i] %10;
          if(P[i]!=0) flag = 0;

     }     
     if(flag)  return ;
     
     couting_sort(A,B,c,9) ;

     for (int i = 1; i <= n; ++i){
        A[i] = B[i];
        P[i] = A[i]/m;

     }
      m = m*10;
     output();
     radix_sort(A,B,P);
}



int main()
{   
    input();
    //output();
    radix_sort(Arr,Brr,Prr);
    //output();
	return 0;
}
