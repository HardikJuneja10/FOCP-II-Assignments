#include <cstdio>
#include <cstring>


const int MAXN = 10000001;
int spf[MAXN];
int ans[MAXN];


char outbuf[1 << 25];
int outpos = 0;

void writeInt(int x){
    if(x == 0){
        outbuf[outpos++] = '0';
        outbuf[outpos++] = '\n';
        return;
    }
    char tmp[12];
    int len = 0;
    while(x > 0){
        tmp[len++] = '0' + x % 10;
        x /= 10;
    }
    for(int i = len - 1; i >= 0; i--)
        outbuf[outpos++] = tmp[i];
    outbuf[outpos++] = '\n';
}


char inbuf[1 << 25];
int inpos = 0, inlen = 0;

int readInt(){
    while(inbuf[inpos] < '0') inpos++;
    int x = 0;
    while(inbuf[inpos] >= '0')
        x = x * 10 + inbuf[inpos++] - '0';
    return x;
}

int main(){
    // build spf sieve
    for(int i = 2; i < MAXN; i += 2) spf[i] = 2;
    for(int i = 1; i < MAXN; i += 2) spf[i] = i;

    for(int i = 3; (long long)i * i < MAXN; i += 2){
        if(spf[i] == i){
            for(int j = i * i; j < MAXN; j += 2 * i){
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }

   
    ans[1] = 1;
    for(int i = 2; i < MAXN; i++){
        int n = i;
        int count = 0;
        while(n > 1){
            int p = spf[n];
            count++;
            while(n % p == 0)
                n /= p;
        }
        ans[i] = 1 << count;
    }

  
    inlen = fread(inbuf, 1, sizeof(inbuf), stdin);

    int T = readInt();
    while(T--){
        int n = readInt();
        writeInt(ans[n]);
    }

    fwrite(outbuf, 1, outpos, stdout);

    return 0;
}