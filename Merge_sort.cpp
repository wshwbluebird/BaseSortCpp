#include<iostream>
#include <string.h>
using namespace std;
//归并排序

int n;//表示 输入元素的个数;
int Arr[1000];
int ll[100];
int rr[100];


const int inf  = 214847364;
void Merge_sort(int A[],int p, int r){
   
   if(p>=r)    return ;
   //Divide
   int m = (p+r)/2;
   
   //deal
   Merge_sort(A,p,m);
   Merge_sort(A,m+1,r);
  
  //Merge
   int n1 = m-p+1;
   int n2 = r-m;
   
  
   
   for (int i = 1; i <= n1; ++i)
   {
       ll[i] = A[p+i-1];
   }
   for (int i = 1; i <= n2; ++i)
   {
       rr[i] = A[m+i];
   }

   ll[n1+1] = inf;
   rr[n2+1] = inf;
   
   int x = 1;
   int y = 1;

   for (int i = p; i <= r; ++i)
   {
        if(ll[x] <= rr[y])  A[i] = ll[x++];
        else A[i] = rr[y++];
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
		cout<<Arr[i]<<"  ";
	}
	cout<<endl;
}

int main()
{   
    input();
    output();
    Merge_sort(Arr,1,n);
    output();
	return 0;
}
