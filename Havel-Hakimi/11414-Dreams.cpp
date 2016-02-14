#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#define mp make_pair
#define pb push_back
#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
vector<int> degree;
bool func(int a,int b)
{
    return a>b;
}

bool hakimi(int item)
{
    sort(degree.begin(),degree.end(),func);
    bool flag=true;
    int nonZero=0;
    for(int i=0;i<item;i++)
        if(degree[i])
            nonZero++;
    if(!nonZero)
        return true;
    while(degree[0])
    {
        if(degree[0]>=nonZero)
        {
            flag=false;
            break;
        }
        for(int i=1;i<=degree[0];i++)
        {
            degree[i]--;
            if(!degree[i])
                nonZero--;
        }
        degree[0]=0;
        nonZero--;
        sort(degree.begin(),degree.end(),func);
    }
    
    return flag;
    
}
int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,animals,x,sum;
    cin>>testCase;
    while(testCase--)
    {
        cin>>animals;
        sum=0;
        for(int i=0;i<animals;i++)
        {
            cin>>x;
            sum+=x;
            degree.pb(x);
        }
        
        bool ret;
        if(sum%2)
            ret=false;
        else if(hakimi(animals))
            ret=true;
        else
            ret=false;
        degree.clear();
        
        if(ret)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        
    }
    return 0;
}










