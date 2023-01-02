#include <bits/stdc++.h>
typedef char NameFile[1000];

using namespace std;
string namefile = "CONGTRU";

NameFile input, output, answer;
ifstream fi, fo, fa;

int readInput() {
  fi.open(input);
}

int readOutput() {
  fo.open(output);
}

int readAnswer() {
  fa.open(answer);
}
long long n, m;
string s_ans, s;
bool check() {
    fi >> n >> m; fo >> s; fa >> s_ans;
    //cin >> n >> m >> s;
    if (s_ans == "Impossible") {
        if (s == s_ans)
            return true;
        else {
            return false;
            //cout << " dasddas";
        }
    }
    if (s[0] != '1') {
        //if (s.size() < 20) cout << s << "\n";
        return false;
    }
    long long cur = 1;
    int i = 1;
    int cnt = 2;
    while (i < s.size()) {
        int j = i;
        int num = 0;
        while (j < s.size() - 1 && s[j + 1] >= '0' && s[j + 1] <= '9') {
            num = num * 10 + (s[j + 1] - '0');
            j++;
        }
        int dau = 1;
        if (s[i] == '-') dau = -1;
        if (num != cnt || cnt > n) {
            //if (s.size() < 20) cout << s << "\n";

            cout << "WRONG ANSWER";
            return false;
        }
        cnt++;
        cur += dau * num;
        i = j + 1;
    }
    if (cur == m) {
        //cout << cur << " " << m << "\n" << s<< " dsa\n";
        cout << "CORRECT!";
        return true;
    }
    //if (s.size() < 20) cout << s << "\n";
    cout << "WRONG ANSWER";
    return false;
}

main() {
  gets(input); gets(output);
  strcpy(answer, input);
  strcat(input,  (namefile + ".inp").c_str());
  strcat(output, (namefile + ".out").c_str());
  strcat(answer, (namefile + ".out").c_str());

  readInput();
  readOutput();
  readAnswer();

  cout << ((check()) ? "1.00" : "0.00");
  fi.close();
  fo.close();
  fa.close();
//  system("pause");
    return 0;
}
