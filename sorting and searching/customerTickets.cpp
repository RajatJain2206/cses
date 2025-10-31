#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>customersPrice(m);
    multiset<int>ticketPrice;
    for(int i=0;i<n;i++){
        int price;
        cin>>price;
        ticketPrice.insert(price);
    }
    
    for(auto &customer : customersPrice) cin>>customer;

    for(int i=0;i<m;i++){
        auto it = ticketPrice.upper_bound(customersPrice[i]);
        if(it == ticketPrice.begin()){
            cout<<-1<<endl;
        }
        else{
            it--;
            cout<<*it<<endl;
            ticketPrice.erase(it);
        }
    }


    return 0;
}

// brute force -> O(n*m)
// for each customer we will see if there's any ticket with a lower price and that ticket will be assigned
// since they are coming in a queue so the customer would get the lowest ticket priced less than what the customer is willing to pay
// this approach wouldnt work in case of large constraints


// optimised -> multiset -> insert O(logn) , upper bound O(logn) , erase O(logn)
// TC = O(nlogn) + m*(O(logn) + O(logn)) = O((n+m)logn)
// SC = O(n+m)
// multiset stores in sorted order and can store duplicates and provides fast search