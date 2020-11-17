#include <iostream>
using namespace std;

// The following implementation doesn't require the true length of the string

string URLify(string s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            for (int j = s.length() - 1; j > i + 2; --j) {
                s[j] = s[j - 2];
            }
            s[i] = '%';
            s[i + 1] = '2';
            s[i + 2] = '0';
        }
    }
    return s;
}

int main() {
    string input;
    getline(cin, input);
    cout << URLify(input) << endl;
    return 0;
}
