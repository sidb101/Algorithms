#include <bits/stdc++.h>

using namespace std;

class FenwickTree{
private:
    int n;
    vector<int> ftree;
    vector<int> arr;
    
    int getLSB(int val){
        return val&(-val);
    }
    
    void adjust(int idx, int val) { // 1-index
        if (idx>n || idx<1)
            return;
        ftree[idx] += val;
        adjust(idx+getLSB(idx), val);
    }
    
    int getPrefixSum(int idx) { // 1-index
        if (idx>n || idx<1)
            return 0;
        return ftree[idx] + getPrefixSum(idx - getLSB(idx));
    }
    
public:
    FenwickTree(vector<int> &src_arr) {
        n = src_arr.size();
        arr.resize(n+1, 0);
        ftree.resize(n+1, 0);
        for(int i=0; i<n; i++) {
            arr[i+1]=src_arr[i];
            adjust(i+1, arr[i+1]);
        }
    }
    
    void update(int idx, int val){
        assert(idx>=0 && idx<n); // expect 0-index
        adjust(idx+1, -1*arr[idx+1]); 
        arr[idx+1]=val;
        adjust(idx+1, arr[idx+1]);
    }
    
    int range_query(int from, int upto){
        assert(from>=0 && from<n && upto>=0 && upto<n); //expect 0-index
        from++, upto++; // make 1-index
        return getPrefixSum(upto) - getPrefixSum(from-1);
    }
    
    void printTree(){
        for(int i=1; i<=n; i++)
            cout << ftree[i] << " ";
        cout << endl;
    }
};

void solve(){
    vector<int> a = {3, 7, 8, 1, 5, 2, 6, 4};
    FenwickTree ft1(a);
    ft1.printTree();
    cout << ft1.range_query(0, 7) << endl; 
    cout << ft1.range_query(2, 2) << endl;
    cout << ft1.range_query(2, 5) << endl;
    ft1.update(4, 1);
    ft1.printTree();
    cout << ft1.range_query(0, 7) << endl; 
    cout << ft1.range_query(2, 2) << endl;
    cout << ft1.range_query(2, 5) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;   
    while(t--){
    	solve();
    }
    return 0;
}

/* stdout
3 10 8 19 5 7 6 36 
36
8
16
3 10 8 19 1 3 6 32 
32
8
12
*/

