#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (auto &a : a)
    {
        cin >> a;
    }

    for (auto &b : b)
    {
        cin >> b;
    }

    sort(a.begin(), a.end()); // stores people requirement
    sort(b.begin(), b.end()); // stores apartment size

    int ans = 0;
    int apartmentIdx = 0;
    for (int i = 0; i < n; i++) // this is for the applicants
    {
        while(apartmentIdx<m && b[apartmentIdx]<a[i]-k){
            apartmentIdx++;
        }
        if(apartmentIdx<m && b[apartmentIdx]<=a[i]+k){
            ans++;
            apartmentIdx++;
            
        }
    }

    cout<<ans<<endl;
    
    return 0;
}

// 45,60,60,80
// 30,60,75