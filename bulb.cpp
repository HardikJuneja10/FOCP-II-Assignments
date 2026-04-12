#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>> m;

    string l;
    cin >> l;

    for(int k=1;k<=n;k++){
        int moves = 0;
        for (int i=0;i<n;){
            if(l[i]=='1'){
                moves++;
                i=i+ k;
            } 
            else 
                i++;
        }

        if (moves<=m) {
            cout<<k;
        }
    }
    return 0;
}