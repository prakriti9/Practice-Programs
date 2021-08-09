#include<bits/stdc++.h>
using namespace std;

vector <int> res(int ar[],int n)
{
    vector <int> v;
    stack<pair<int,int>> s;
    
    for(int i = 0;i < n;i++)
    {
        if(s.size() == 0)
        {
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top().first > ar[i])
        {
            v.push_back(s.top().second);
        }
        else if(s.size() > 0 && s.top().first <= ar[i])
        {
            while(s.size() > 0 && s.top().first <= ar[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({ar[i],i});
    }
    for(int i = 0; i < n;i++)
    {
        v[i] = i - v[i];
    }
    return v;
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(int);
    vector <int> v;
    v = res(arr,n);
    for(int i =0;i<n;i++)
    {
        cout<< v[i] <<" ";
    }
    cout<< endl;
    return 0;
}