#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 256; // ASCII codes table size

string isUnique(string s) {
    if (s.length() > ALPHABET_SIZE) {
        return "False";
    }
    vector<bool> bitVector(ALPHABET_SIZE, false);
    for (char i : s) {
        if(bitVector[int(i)]) {
            return "False";
        }
        bitVector[int(i)] = true;
    }
    return "True";
}

int main() {
    string input;
    cin >> input;
    cout << isUnique(input) << endl;
    return 0;
}
