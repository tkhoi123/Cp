#include <bits/stdc++.h>
#include <direct.h>
using namespace std;
#define Task "CONGTRU"
const int nTest = 19;
const string Directory = "D:/test/";
string Problem_name;

bool make_folder() {
    if(mkdir((Directory + Task).c_str())) return true;
    return false;
}

ofstream input;
ofstream output;

typedef long long cc;
typedef pair <int, int> pii;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
const int N = 100005;
int n;
cc s;
bool Minus[N];

void make_input() {
    n = rand() % 100000 + 1;
    input << n << " ";
    s = 1ll * (1 + rand() % n) * (1 + rand() % (n + 1)) / 2;
    input << s;
    memset(Minus, 0, sizeof(Minus));
}

void make_output() {
    cc sum = 1ll * n * (n + 1) / 2;
    if (sum < s) output << "Impossible";
    else {
        int need = sum - s;
        if (need % 2 == 1) {
            output << "Impossible";
            return;
        }
        need /= 2;
        for (int i = n; i > 1; i--)
            if (need >= i) {
                Minus[i] = true;
                need -= i;
                if (need == 1) need += i, Minus[i] = false;
            }
        if (need != 0) {
            output << "Impossible";
            return ;
        }
        output << 1;
        for (int i = 2; i <= n; i++) {
            if (Minus[i]) output << "-"; else output << "+";
            output << i;
        }
    }
}

void make_test(string test_address) {
    input.open((test_address + "/" + Task + ".inp").c_str());
    make_input();
    input.close();
    //-----------------------------------------------------------------
    output.open((test_address + "/" + Task + ".out").c_str());
    make_output();
    output.close();
}

void Gen() {
    for (int i = 0; i < nTest; i++) {
        stringstream ss;
        string test_id = "";
        ss << i; ss >> test_id;
        string thisTest_address = Directory + Task + "/" + "Test0" + test_id;
        mkdir(thisTest_address.c_str());
        make_test(thisTest_address);
        cout << "Test " << i << " done!\n";
    }
}

int main() {
    srand(time(NULL));
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Problem_name = Task;
    make_folder();
    Gen();
    return 0;
}
