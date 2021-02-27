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
vector<bool> visited;
vector<vector<int>> graph;

void solve()
{
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n, false);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    bool isans = true;
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            q.push(i);
            visited[i] = true; 
            ans[i] = 1;
            while(!q.empty())
            {
                int  u = q.front();
                q.pop();
                for(auto x: graph[u])
                {
                    if(!visited[x])
                    {
                        visited[x] = true;
                        ans[x] = 3 - ans[u];
                        q.push(x);
                    }
                    else
                    {
                        
                        if(ans[x] == ans[u])
                        {
                            isans = false;
                        }
                    }
                }
            }
                
        }
    }
    if(isans)
    for(auto x: ans)
    cout << x << " ";
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