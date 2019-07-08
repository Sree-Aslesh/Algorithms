#include <bits/stdc++.h>

using namespace std;

int left_child_idx(int num)
{
    return(2*num+1);
}

int right_child_idx(int num)
{
    return(2*num+2);
}

int parent_idx(int num)
{
    return((num-1)/2);
}


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = left_child_idx(i);
    int right = right_child_idx(i);

    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr, n , largest);
    }
}

void heapsort(int arr[], int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i = n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}


int main()
{
    int arr[] = {7,5,2,1,13,0,4,22,198,6,11,87};
//      int arr[] = {5,4,3,2,1};
      int n = sizeof(arr)/sizeof(arr[0]);

      heapsort(arr,n);

      for (int i=0;i<n;i++)
        cout << arr[i] << " " <<endl;
}
