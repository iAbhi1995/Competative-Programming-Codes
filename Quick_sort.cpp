#include<bits/stdc++.h>
using namespace std;

int partition(int* arr,int low,int high)
{
	int pivot=low+rand()%(high-low);
	int j=low-1;
	int temp=arr[pivot];
		arr[pivot]=arr[high-1];
		arr[high-1]=temp;
	pivot=high-1;
	for(int i=low;i<high-1;i++)
	{
		if(arr[i]<arr[pivot])
		{
			j++;
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	temp=arr[j+1];
	arr[j+1]=arr[pivot];
	arr[pivot]=temp;
	return (j+1);
}




void quicksort(int* arr,int low,int high)
{
	if(low<high)
	{
		int pivot = partition(arr,low,high);
		quicksort(arr,low,pivot);
		quicksort(arr,pivot+1,high);
	}
}



int main()
{
	int n=5;
	cout<<"Enter the number of elements : ";
	cin>>n;
	cout<<"Enter the array elements \n";
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	quicksort(arr,0,n);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}
