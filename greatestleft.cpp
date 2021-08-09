#include<bits/stdc++.h>
using namespace std;
vector <int> res(int ar[],int n)
{
    vector <int> v;
    stack<int> s;
    
    v.push_back(-1);
    s.push(ar[0]);
    for(int i = 1;i < n; i++)
    {
        if(s.size() > 0 && s.top() > ar[i])
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() < ar[i])
        {
            while(s.size() > 0 && s.top() <ar[i])
            {
                s.pop();
            }
            if(s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(ar[i]);
    }
    return v;
}
int main()
{
    int arr[] = {1, 3, 2, 4};
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