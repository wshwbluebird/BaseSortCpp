#include<iostream>
#include <string.h>
using namespace std;
//桶排序  哈西映射链表

int n;//表示 输入元素的个数;
int Arr[1000];
int Brr[1000];
int head[100];
int nexte[1000];
int hash(int A[], int i){
   return A[i]/10;
}


void make_bucket(int A[]){
   memset(head,-1,sizeof(head));
   for (int i = 1; i <= n; ++i)
   {
      int e = hash(A,i);
      nexte[i] = head[e];
      head[e] = i;
      //cout<<"head: "<<e<<"  i:  "<<A[i]<<endl;

   }
}

void bucket_sort(int A[],int B[]){
   make_bucket(A);
   int j = 1;
   for (int i = 0; i <= 99; ++i)
   {    
        int e = head[i];
        while(e!=-1){
            int m = j; 
            while( m>1 && B[m-1] > A[e])
            {
                B[m] = B[m-1];
                m--;
            }
            B[m] = A[e];
            //cout<<m<<"   :  "<<A[e]<<endl;
            j++;
            e = nexte[e];
        }
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
    bucket_sort(Arr,Brr);
    output();
	return 0;
}