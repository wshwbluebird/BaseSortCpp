#include<iostream>
using namespace std;
//插入排序

int n;//表示 输入元素的个数;
int Arr[1000];
void insertion_sort(int A[]){
   for (int i = 2; i <=  n; ++i)
   {
   	  int key = A[i];
   	  int m = i-1;
   	  while(m>0 && key<A[m] ){
   	  	A[m+1] = A[m];
   	  	m--;
   	  }
   	  A[m+1] = key;  //＊＊＊＊＊＊＊imp
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
    insertion_sort(Arr);
    output();
	return 0;
}