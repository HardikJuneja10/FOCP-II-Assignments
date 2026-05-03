#include <iostream>
using namespace std;
int XOR_r(int r){
		if (r%4==0){return r;}
		if(r%4==1){ return 1;}
		if(r%4==2){return r+1;}
		if(r%4==3){return 0;}
	}
int main() {
	int L,R;
	cin>>L>>R;    
	int x= XOR_r(R)^XOR_r(L-1);

	if(x%2==0){cout<<"even";}
	else cout<<"odd";
	
}