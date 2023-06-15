#include<bits/stdc++.h>
using namespace std;
class SGTree{
    vector<int> seg;
    public:
        void print(){
            for(int i=0;i<seg.size();i++){
                cout<<seg[i]<<endl;
            }
            cout<<endl;
        }
        SGTree(int n){
            seg.resize(4*n+1);
        }
        
        void build(int index,int low,int high,int arr[]){
        if(low == high){
            seg[index] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        seg[index] = min(seg[2*index+1], seg[2*index+2]);
        }


        int query(int index,int low,int high,int l,int r){
            // no overlap
            // l r low high or low high l r
            if(r < low or high < l){
                return INT_MAX;
            }
            
            //complete overlap
            // l low high r
            if(low >= l and high <= r){
                return seg[index];
            }
            int mid = (low + high)/2;
            int left = query(2*index+1,low,mid,l,r);
            int right = query(2*index+2,mid+1,high,l,r);
            return min(left, right);

            //partial overlap
            // 
        }

        void update(int index,int low,int high,int i,int val){
            if(low == high){
                seg[index] = val;
                return;
            }
            int mid = (low + high)/2;
            if(i <= mid){
                update(2*index+1,low,mid,i,val);
            }
            else{
                update(2*index+2,mid+1,high,i,val);
            }
            seg[index] = min(seg[2*index+1], seg[2*index+2]);
        }
};


void solve(){
    int n1;
    cin>>n1;
    SGTree sg1(n1);
    int arr[n1];
    for(int i=0;i<n1;i++){
        cin>>arr[i];
    }
    
    sg1.build(0,0,n1-1,arr);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sg1.query(0,0,n1-1,l,r)<<endl;
    }

    sg1.print();
}

int main(){
    solve();
    
}