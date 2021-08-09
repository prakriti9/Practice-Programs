#include<bits/stdc++.h>
using namespace std;

vector <int> res(int ar[],int n)
{
    vector <int> v;
    stack<int> s;
    v.push_back(-1);
    s.push(ar[n-1]);
    for(int i = n-2 ;i >= 0; i--)
    {
        if(s.top() < ar[i])
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() > ar[i])
        {
            while(s.size() > 0 && s.top() > ar[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(ar[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(int);
    vector <int> v;
    v = res(arr,n);
    for(int i = 0;i<n;i++)
    {
        cout<< v[i] <<" ";
    }
    cout<< endl;
    return 0;
}