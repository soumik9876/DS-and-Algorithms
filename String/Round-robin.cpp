#include<bits/stdc++.h>
using namespace std;

struct properties
{
    int id,AT,BT,CT,WT,RT,TAT;
};
bool comp(properties a,properties b)
{
    if(a.AT==b.AT)
        return a.BT<b.BT;
    return a.AT<b.AT;
}
bool comp1(properties a,properties b)
{
    return a.id<b.id;
}
int main()
{
    int n,tq,total=0;
    cout<<"How many processes?"<<endl;
    cin>>n;
    queue<int> q;
    vector<properties> process(n+1);
    int remaining[n+1];
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter the arrival time and burst time of process p"<<i<<":"<<endl;
        cin>>process[i].AT>>process[i].BT;
        process[i].id=i;
        remaining[i]=process[i].BT;
    }
    sort(process.begin(),process.end(),comp);
    for(int i=1;i<=n;i++)
        q.push(process[i].id);
    cout<<"Enter the time quantum : "<<endl;
    cin>>tq;
    while(1)
    {
        bool check=false;
        for(int i=1;i<=n;i++)
        {
            int p=process[i].id;
            if(remaining[p]>0)
            {

                check=true;
                if(remaining[p]==process[i].BT)
                    process[i].RT=total;
                if(remaining[p]>tq)
                {
                    total+=tq;
                    remaining[p]-=tq;
                }
                else
                {
                    total+=remaining[p];
                    remaining[p]=0;
                    process[i].CT=total;
                    process[i].TAT=process[i].CT-process[i].AT;
                    process[i].WT=process[i].CT-process[i].AT;
                }
            }
        }
        if(check==false)
            break;
    }
    cout<<total<<endl;
    sort(process.begin(),process.end(),comp1);
    cout<<"Process\tA.T.\tB.T.\tC.T.\tT.A.T.\tW.T.\tR.T."<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<process[i].id<<"\t"<<process[i].AT<<"\t"<<process[i].BT<<"\t"<<process[i].CT<<"\t"<<process[i].TAT<<"\t"<<process[i].WT<<"\t"<<process[i].RT<<endl;
    }

}
