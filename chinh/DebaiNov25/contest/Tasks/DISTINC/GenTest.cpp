#include <bits/stdc++.h>
#include <direct.h>
using namespace std;
#define Task "DISTINC"
const int nTest = 4, startTest = 0;
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
const int N = 200000;
int n, k;
cc a[N + 1];
map <cc, int> mm;
set <cc> s;

void make_input() {
    n = N;
    n = 5000;
    k = rand() % n + 1;
    for (int i = 1; i <= n; i++) a[i] = 1ll * (rand() % 1000000) * (rand() % 1000000);
    //for (int i = 1; i <= n; i++) a[i] = rand() % 1000000;
    //for (int i = 1; i <= n; i++) s.insert(a[i]);
    //k = int(s.size()) + 1;
    mm.clear(); s.clear();
    input << n << " " << k << "\n";
    for (int i = 1; i <= n; i++) input << a[i] << " ";
}

void make_output() {
    int res = n + 1;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (j <= n && int(s.size()) < k) {
            s.insert(a[j]);
            mm[a[j]]++;
            j++;
        }
        if (int(s.size()) >= k) res = min(res, j - i);
        if (mm[a[i]] == 1) s.erase(a[i]);
        mm[a[i]]--;
    }
    if (res == n + 1) output << -1; else
    output << res << "\n";
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
    for (int i = startTest; i < nTest; i++) {
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
