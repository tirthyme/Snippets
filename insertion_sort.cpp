#include <bits/stdc++.h>
using namespace std;
insertion_sort(int arr[],int l)
{
    for(int a=1;a<l;a++)
    {
        if(arr[a-1]>arr[a])
        {
            int temp=arr[a];
            int q=a;
            do
            {
                arr[q]=arr[q-1];
                q--;
            }
            while(arr[q-1]>temp &&q>0);
            arr[q]=temp;
        }
    }
    for(int a=1;a<l;a++)
        cout<<arr[a]<<" ";
}
int main()
{
    int arr[]={0,9,8,7,6,5,4,3,2,1,0,12,31,21,10};
    insertion_sort(arr,sizeof(arr)/sizeof(int));
}
