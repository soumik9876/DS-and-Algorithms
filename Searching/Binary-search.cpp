//O(logn) time complexity
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sz;
    cout<<"How many numbers?"<<endl;
    cin>>sz;
    vector<int> a(sz+1);
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<sz;i++)
        cin>>a[i];
    int n;
    cout<<"Enter number to search:"<<endl;
    while(cin>>n)
    {
        int top=sz-1,bottom=0,mid,pos=-1;
        while(bottom<=top){
            mid=bottom+((top-bottom)>>1);
            if(n==a[mid]){
                pos=mid;
                break;
            }
            if(n<a[mid]){
                top=mid-1;
            }
            else {
                bottom=mid+1;
            }
        }
        if(pos==-1){
            printf("It's not in the array\n");
        }
        else
            printf("%d is in position %d\n",n,pos+1);
    }
    return 0;
}
