#include <iostream>
#include <set>

using namespace std;

bool isSubstring(string s1, string s2) {
    int M = s1.length();
    int N = s2.length();

    for (int i = 0; i <= N - M; i++) {
        int j;

        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return true;
    }
    return false;
}


bool stringRotation(const string &s1, string s2) {
    string doubleS1 = s1 + s1;
    return isSubstring(s2, doubleS1);
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << stringRotation(s1, s2);
    return 0;
}
