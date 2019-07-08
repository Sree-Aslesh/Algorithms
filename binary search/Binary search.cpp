#include <bits/stdc++.h>

using namespace std;


int bin_search(int* arr,int s, int e, int val)
{
    cout << "checking in between idx " << s << "  " << e <<endl;
    if(s==e)
    {
        if(*(arr+s)==val)
            return s;
        else
            return -1;
    }
        int mid = (s+e)/2;
        if(*(arr+mid)>=val)
            return bin_search(arr,s,mid,val);
        else
            return bin_search(arr,mid+1,e,val);
        return -1;

}

int main()
{
    int arr[7] = {2,5,7,8,12,16,19};
    int val =  16;
    int num = sizeof(arr)/sizeof(arr[0]);
    cout << "Number of elements in the array are " << num << endl;
    int ret = bin_search(arr,0,num-1,val);
    cout << ret << endl;

}
