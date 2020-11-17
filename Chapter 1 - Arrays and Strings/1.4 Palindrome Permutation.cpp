#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 256; // ASCII codes table size (Assumption)

// This algorithm is case sensitive and neglects spaces

string isPalindromePermutation(string s) {
    if (s.length() == 1)
        return "True"; // since by definition, a single letter is always a palindrome

    vector<int> letters_count(ALPHABET_SIZE, 0);
    for (char i : s) {
        if (i != ' ')
            letters_count[int(i)]++;
    }

    bool odd_flag = false;
    for (int i : letters_count) {
        if (i % 2 != 0) {
            if (odd_flag) {
                return "False";
            }
            else {
                odd_flag = true;
            }
        }
    }
    return "True";
}

int main() {
    string input;
    getline(cin, input);
    cout << isPalindromePermutation(input) << endl;
    return 0;
}
