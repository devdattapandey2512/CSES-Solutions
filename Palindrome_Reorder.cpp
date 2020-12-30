/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001

using namespace std;

void solve()
{
    string s;
    cin >> s;
    unordered_map<char, ll> m;
    for(auto x: s)
    m[x]++;
    ll odd = 0;
    char middle = 'a';
    for(auto x: m)
    {
        if(x.second%2 != 0)
        {
            middle = x.first;
            odd++;
        }
        
    }
    if(odd > 1)
    cout << "NO SOLUTION" << endl;
    else
    {
        if(odd == 0)
        {
            stack<char> s;
            for(auto x: m)
            {
                for(ll i=1; i<=x.second/2; i++)
                {
                    cout << x.first;
                    s.push(x.first);
                }
                
            }
            while(!s.empty())
            {
                char c= s.top();
                cout << c;
                s.pop();
            }
            

        }
        else
        {
            stack<char> s;
            for(auto x: m)
            {
                for(ll i=1; i<=x.second/2; i++)
                {
                    cout << x.first;
                    s.push(x.first);
                }
                
            }
            cout << middle;
            while(!s.empty())
            {
                cout << s.top();
                s.pop();
            }
        }
    }

}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}