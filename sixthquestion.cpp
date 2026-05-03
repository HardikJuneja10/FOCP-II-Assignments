#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<string, long long> acc;

public:
    bool create(string x, long long y) {
        if (acc.find(x) == acc.end()) {
            acc[x] = y;
            return true;
        } else {
            acc[x] += y;
            return false;
        }
    }

    bool debit(string x, long long y) {
        if (acc.find(x) == acc.end() || acc[x] < y) {
            return false;
        }
        acc[x] -= y;
        return true;
    }

    bool credit(string x, long long y) {
        if (acc.find(x) == acc.end()) {
            return false;
        }
        acc[x] += y;
        return true;
    }

    long long balance(string x) {
        if (acc.find(x) == acc.end()) {
            return -1;
        }
        return acc[x];
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    Bank bank;

    while (Q--) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        string type, x;
        long long y;

        ss >> type;

        if (type == "CREATE") {
            ss >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << endl;
        }
        else if (type == "DEBIT") {
            ss >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << endl;
        }
        else if (type == "CREDIT") {
            ss >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << endl;
        }
        else if (type == "BALANCE") {
            ss >> x;
            cout << bank.balance(x) << endl;
        }
    }

    return 0;
}