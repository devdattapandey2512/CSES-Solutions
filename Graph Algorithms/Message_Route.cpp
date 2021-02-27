/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna)
Date: --/--/---- 

Finding logic and writing code is an art. It is once intellectual property.
So please don't copy or use it only for reference. Try to solve the question yourself.
*/


#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <chrono>
#include <complex>
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001 

using namespace std; 
int n, m;
vector<vector<int>> graph;

void solve()
{
    cin >> n >> m;
    graph.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<pair<int, int>> q;
    vector<bool> visited(n, false);
    vector<int> father(n);
    for(int i = 0; i < n; i++)
    {
        father[i] = i;
    }
    visited[0] = true;
    father[0] = 0;
    q.push({0, 1});
    while(!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for(auto x: graph[u.first])
        {
            if(!visited[x])
            {
                father[x] = u.first;
                visited[x] = true;
                q.push({x, u.second+1});
            }
        }
    }
    // for(int i = 0; i < n; i++)
    // {
    //     cout << i << " " << father[i] << endl;
    // }
    if(father[n-1] != n-1)
    {
        int h = n-1;
        stack<int> s;
        while(h != 0)
        {
            s.push(h);
            h = father[h];
        }
        s.push(0);
        cout << s.size() << endl;
        while(!s.empty())
        {
            cout << s.top()+1 << " ";
            s.pop();
        }
    }
    else
    cout << "IMPOSSIBLE";

}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}