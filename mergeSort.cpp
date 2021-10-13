//Merge sort
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;

class ms
{	int low,high;
	public:
		int mSort(int*,int,int);
		int merge(int*,int,int,int);
};
int ms::mSort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high-1)/2;
		mSort(a,low,mid);
		mSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
	return 0;
}
int ms::merge(int a[],int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	int c[10000];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			c[k++]=a[i++];
		}
		else
		{
			c[k++]=a[j++];
		}
	}
	while(i<=mid)
	{
		c[k++]=a[i++];
	}
	while(j<=high)
	{
		c[k++]=a[j++];
	}
	for(i=low;i<=high;i++)
	{
		a[i]=c[i];
	}
	return 0;
}
int main()
{
	int *a,no,i;
	ms obj;
	cout<<"Enter the no elelments"<<endl;
	cin>>no;
	a=new int[no];
	srand(time(0));
	cout<<"Unsorted array: "<<endl;
	for(i=0;i<no;i++)
	{
	 	a[i]=rand()%100;
		cout<<a[i]<<" ";	
	}
	auto start=high_resolution_clock::now();
	obj.mSort(a,0,no-1);
	auto end=high_resolution_clock::now();
	cout<<endl<<"Sorted array: "<<endl;
	for(i=0;i<no;i++)
	{
		cout<<a[i]<<" ";	
	}
	cout<<endl<<"Time taken: "<<duration_cast<nanoseconds>(end-start).count()<<" nanoseconds"<<endl;
	cout<<"Space consumed: "<<no*sizeof(a)+sizeof(no)+sizeof(i)+sizeof(obj)<<" bytes"<<endl;
	return 0;
}
