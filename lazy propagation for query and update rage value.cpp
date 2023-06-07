#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int mx = 1e5 + 10;
ll a[mx];
struct Node{
    ll sm, prop;
}seg[4*mx];

void build(ll nod, ll lo, ll hi)
{
    if(lo==hi){
        seg[nod].sm=a[lo];
        return;
    }
    ll mid = (lo+hi)>>1;
    build(nod*2, lo, mid);
    build(nod*2+1, mid+1, hi);
    seg[nod].sm = seg[nod*2].sm + seg[nod*2+1].sm;
    seg[nod].prop = 0;
}
ll query(ll nod, ll lo, ll hi, ll l, ll r, ll cary)
{
    if(lo>r || hi<l) return 0;
    if(lo>=l && hi<=r){
        return seg[nod].sm + cary*(r-l+1);
    }
    ll mid=(lo+hi)>>1;
    ll x = query(nod*2, lo, mid, l, r, cary + seg[nod].prop);
    ll y = query(nod*2+1, mid+1, hi, l, r, cary + seg[nod].prop);

    return x+y;
}

void update(ll nod, ll lo, ll hi, ll l, ll r, ll val)
{
    if(lo>r || hi<l) return;
    if(lo>=l && hi<=r){
        seg[nod].sm += ((r-l+1) * val);
        seg[nod].prop += val;
        return;
    }
    ll mid=(lo+hi)>>1;
    update(nod*2, lo, mid, l, r, val);
    update(nod*2+1, mid+1, hi, l, r, val);
    seg[nod].sm = seg[nod*2].sm + seg[nod*2+1].sm + (r-l+1) * seg[nod].prop;

}

int main()
{
    ll n, q;
    cin>>n>>q;
    for(ll i=0; i<n; i++) cin>>a[i];

    build(1, 0, n-1);

    for(ll i=0; i<q; i++){
        int x;
        cin>>x;
        if(x==1){
            ll l , r;
            cin>>l>>r;
            cout<<query(1, 0, n-1, l, r, 0)<<endl;
        }
        else{
            ll val, l, r;
            cin>>l>>r>>val;
            update(1, 0, n-1, l, r, val);
        }
    }
}
