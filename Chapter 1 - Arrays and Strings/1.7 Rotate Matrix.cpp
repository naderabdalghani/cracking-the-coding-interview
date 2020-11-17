#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<char>>& M) {
    for (auto & i : M) {
        for (char j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void rotateMatrix(vector<vector<char>> &M) {
    int layers = M.size() / 2;
    for (int layer = 0; layer < layers; layer++) {
        int first = layer;
        int last = M.size() - 1 - layer;
        for (int j = first; j < last; j++) {
            int offset = j - first;
            char top = M[first][j];
            M[first][j] = M[last - offset][first]; // top = left
            M[last - offset][first] = M[last][last - offset]; // left = bottom
            M[last][last - offset] = M[j][last]; // bottom = right
            M[j][last] = top; // right = top (temp)
        }
    }
}

int main() {
    vector<vector<char>> M{
            {'a', 'b', 'c', 'd'},
            {'e', 'f', 'g', 'h'},
            {'i', 'j', 'k', 'l'},
            {'m', 'n', 'o', 'p'}
    };
    cout << "Before:" << endl;
    printMatrix(M);
    cout << endl;
    cout << "After:" << endl;
    rotateMatrix(M);
    printMatrix(M);
    return 0;
}
