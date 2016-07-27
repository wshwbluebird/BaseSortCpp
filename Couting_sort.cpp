#include<iostream>
#include <string.h>
using namespace std;
//计数排序

int n;//表示 输入元素的个数;
int Arr[100];
int Brr[100];

int pre_couting(int A[]){
  int maxnum = -1;
  for (int i = 1; i <= n; ++i)
  {
       if(A[i] > maxnum)  maxnum = A[i];
  }
  return maxnum;
}

void couting_sort(int A[],int B[],int k){
   int c[1000];
   memset(c,0,sizeof(c));
   for (int i = 1; i <= n; ++i)
   {
     c[A[i]]++;
   }

   for (int i = 1; i <= k; ++i)
   {
     c[i] += c[i-1];
   }

   for (int i = 1; i <= n; ++i)
   {
     B[c[A[i]]] = A[i];
     c[A[i]] --;
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
		cout<<Brr[i]<<" ";
	}
	cout<<endl;
}

int main()
{   
    input();
    //output();
    couting_sort(Arr,Brr,pre_couting(Arr));
    output();
	return 0;
}