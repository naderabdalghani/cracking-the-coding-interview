#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 256; // ASCII codes table size (Assumption)

// This algorithm is case sensitive

string oneAway(string s1, string s2) {
    if (s1.length() == s2.length()) {
        bool one_away = false;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                if (one_away)
                    return "False";
                one_away = true;
            }
        }
        return "True";
    }
    else {
        vector<int> letters_count1(ALPHABET_SIZE, 0), letters_count2(ALPHABET_SIZE, 0);
        for (char i : s1) letters_count1[int(i)]++;
        for (char i : s2) letters_count2[int(i)]++;

        bool one_away = false;
        for (int i = 0; i < letters_count1.size(); i++) {
            if (letters_count1[i] != letters_count2[i]) {
                if (one_away)
                    return "False";
                one_away = true;
            }
        }
        return "True";
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << oneAway(s1, s2) << endl;
    return 0;
}
