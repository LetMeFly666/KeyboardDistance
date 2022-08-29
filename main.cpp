#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 

class KeyboardDistance {
private:
    int dis[26][26];
    string line[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

    void initDistance() {
        // same line
        for (int lineNum = 0; lineNum < 3; lineNum++) {
            for (int i = 0; i < line[lineNum].size(); i++) {
                for (int j = 0; j < line[lineNum].size(); j++) {
                    char a = line[lineNum][i];
                    char b = line[lineNum][j];
                    dis[a - 'a'][b - 'a'] = dis[b - 'a'][a - 'a'] = abs(i - j);
                }
            }
        }
    
        // adjacent line
        for (int lineNum1 = 0; lineNum1 < 2; lineNum1++) {
            int lineNum2 = lineNum1 + 1;
            for (int j = 0; j < line[lineNum2].size(); j++) {
                dis[line[lineNum1][j] - 'a'][line[lineNum2][j] - 'a'] = 1;
                dis[line[lineNum2][j] - 'a'][line[lineNum1][j] - 'a'] = 1;
                dis[line[lineNum1][j + 1] - 'a'][line[lineNum2][j] - 'a'] = 1;
                dis[line[lineNum2][j] - 'a'][line[lineNum1][j + 1] - 'a'] = 1;
                
                int from = j;
                while (from > 0) {
                    from--;
                    dis[line[lineNum1][from] - 'a'][line[lineNum2][j] - 'a'] = dis[line[lineNum1][from + 1] - 'a'][line[lineNum2][j] - 'a'] + 1;
                    dis[line[lineNum2][j] - 'a'][line[lineNum1][from] - 'a'] = dis[line[lineNum1][from + 1] - 'a'][line[lineNum2][j] - 'a'] + 1;
                }
    
                from = j + 1;
                while (from + 1 < line[lineNum1].size()) {
                    from++;
                    dis[line[lineNum1][from] - 'a'][line[lineNum2][j] - 'a'] = dis[line[lineNum1][from - 1] - 'a'][line[lineNum2][j] - 'a'] + 1;
                    dis[line[lineNum2][j] - 'a'][line[lineNum1][from] - 'a'] = dis[line[lineNum1][from - 1] - 'a'][line[lineNum2][j] - 'a'] + 1;
                }
            }
        }
    
        // 1 3
        for (int i = 0; i < line[0].size(); i++) {
            for (int j = 0; j < line[2].size(); j++) {
                int ans = 100;
                for (int k = 0; k < line[1].size(); k++) {
                    ans = min(ans, dis[line[0][i] - 'a'][line[1][k] - 'a'] + dis[line[1][k] - 'a'][line[2][j] - 'a']);
                }
                dis[line[0][i] - 'a'][line[2][j] - 'a'] = ans;
                dis[line[2][j] - 'a'][line[0][i] - 'a'] = ans;
            }
        }
    }

public:
    KeyboardDistance() {
        initDistance();
    }

    int getDistance(char a, char b) {
        return dis[a - 'a'][b - 'a'];
    }
};

void testDistance() {
    KeyboardDistance kd;
    char a, b;
    while (cin >> a >> b) {
        cout << kd.getDistance(a, b) << endl;
    }
}
 
int main() {
    testDistance();
    return 0;
}