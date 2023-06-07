#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pi acos(-1)
using namespace std;
const int sz = 1e5+5;
ll arr[2*sz], segTree[4*sz];

void build(ll nod, ll lo, ll hi)
{
    //cout<<lo<<endl;
    if(lo==hi){
        segTree[nod] = arr[lo];
        return;
    }
    ll mid=(lo+hi)>>1;
    build(nod*2, lo, mid);
    build(nod*2+1, mid+1, hi);
    segTree[nod]= segTree[nod*2]+ segTree[nod*2+1];
}
ll query(ll nod, ll lo, ll hi, ll l, ll r)
{
    if(lo>r || hi<l) return 0;
    if(lo>=l && hi<=r){
        return segTree[nod];
    }
    ll mid=(lo+hi)>>1;
    ll x = query(nod*2, lo, mid, l, r);
    ll y = query(nod*2+1, mid+1, hi, l, r);

    return x+y;
}
void update(ll nod, ll lo, ll hi, ll pos, ll val)
{
    if(lo>pos || hi<pos) return;
    if(lo>=pos && hi<=pos){
        segTree[nod]=val;
        return;
    }
    ll mid=(lo+hi)>>1;
    update(nod*2, lo, mid, pos, val);
    update(nod*2+1, mid+1, hi, pos, val);
    segTree[nod] = segTree[nod*2] + segTree[nod*2+1];
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        // for getting innput from in.txt
        // freopen("input.txt", "r", stdin);
        // for writing output to out.txt
        //freopen("output.txt", "w", stdout);
    #endif

    ll n, q;
    cin>>n>>q;

    for(ll i=1; i<=n; i++) cin>>arr[i];

    build(1, 1, n);
    //cout<<12<<endl;
    for(ll j=0; j<q; j++){
        int x; cin>>x;
        if(x==1){
            int pos, val;
            cin>>pos>>val;
            update(1, 1, n, pos, val);
        }
        else{
            ll l, r;
            cin>>l>>r;
            cout<<query(1, 1, n, l, r)<<endl;
        }
    }

    return 0;
}




/*

8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4

*/
