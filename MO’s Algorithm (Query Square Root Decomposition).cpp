#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pi acos(-1)
#define inf 1000000000012
#define MAX 1000005

using namespace std;

const int asz = 30004;
const int mx = 1000006;
const int qsz =  200000;

int n, q, block_size, ans=0;
int cnt[MAX], arr[MAX],answer[MAX];
pair<pair<int,int>, int> qry[MAX];


bool mo_cmp(pair< pair<int,int>,int >a, pair< pair<int,int>,int >b)
{
    int block_a = a.first.first/block_size;
    int block_b = b.first.first/block_size;

    if(block_a != block_b) return block_a < block_b;

    return a.first.second < b.first.second;
}

void add(int x)
{
    if(cnt[x]==0) ans++;
    cnt[x]++;
}

void del(int x)
{
    cnt[x]--;
    if(cnt[x]==0) ans--;
}


int main()
{

    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    cin>>q;
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;

        qry[i].first.first = l;
        qry[i].first.second = r;

        qry[i].second = i;
    }
    block_size = sqrt(n)+1000;

    sort(qry, qry+q, mo_cmp);

    int cl=0, cr=-1;

    for(int i=0; i<q; i++){

        int l = qry[i].first.first;
        int r = qry[i].first.second;

        while(cr<r){
            cr++;
            add(arr[cr]);
        }
        while(cr>r){
            del(arr[cr]);
            cr--;
        }
        while(cl<l){
            del(arr[cl]);
            cl++;
        }
        while(cl>l){
            cl--;
            add(arr[cl]);
        }
        answer[qry[i].second]=ans;

    }

    for(int i=0; i<q; i++){
        cout<<answer[i]<<endl;
    }

}

/*
10 5
1 2 3 4 5 6 7 8 9 10
1 10
5 8
4 9
3 4
1 7
*/

