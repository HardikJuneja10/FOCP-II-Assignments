#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> arr){
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    vector<int> v;
    for(int i=0;i<n;i++) {
        int count=0;
        for(int j=0;j<v.size(); j++){
            if(v[j]==arr[i]) 
                count++;
        }
        if(count<2) {
            v.push_back(arr[i]);
        }
    }
 
    int alex=0,bob=0;
    for(int i=0;i<v.size(); i++) {
        if(i%2==0) 
            alex += v[i];
        else 
            bob += v[i];
    }
    
    if(alex>bob) return "Alex";
    else return "Bob";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(n, arr) << "\n";
    }
}