#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 256; // ASCII codes table size

string checkPermutation(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return "False";
    }
    vector<int> s1_letter_count(ALPHABET_SIZE, 0), s2_letter_count(ALPHABET_SIZE, 0);
    for (int i = 0; i < s1.length(); ++i) {
        s1_letter_count[int(s1[i])]++;
        s2_letter_count[int(s2[i])]++;
    }

    for (int i = 0; i < s1_letter_count.size(); ++i) {
        if (s1_letter_count[i] != s2_letter_count[i]) {
            return "False";
        }
    }
    return "True";
}

int main() {
    string input1, input2;
    cin >> input1 >> input2;
    cout << checkPermutation(input1, input2) << endl;
    return 0;
}
