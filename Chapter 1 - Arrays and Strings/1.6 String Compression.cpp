#include <iostream>

using namespace std;

string stringCompression(const string &s) {
    string compressed_string;
    char current_letter = s[0];
    int current_letter_count = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (current_letter == s[i]) {
            current_letter_count++;
        }
        else {
            compressed_string += string(1,current_letter) + to_string(current_letter_count);
            current_letter = s[i];
            current_letter_count = 1;
        }
    }
    compressed_string += string(1,current_letter) + to_string(current_letter_count);
    return compressed_string.length() < s.length() ? compressed_string : s;
}

int main() {
    string input;
    cin >> input;
    cout << stringCompression(input) << endl;
    return 0;
}
