#include <iostream>
#include <vector>
#include <set>

using namespace std;

void printVector(const vector<vector<int>> &M) {
    for (auto &i : M) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void zeroMatrix(vector<vector<int>> &M) {
    set<int> rowsToZero;
    set<int> columnsToZero;
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[i].size(); ++j) {
            if (M[i][j] == 0) {
                rowsToZero.insert(i);
                columnsToZero.insert(j);
            }
        }
    }
    // In case each and every row has a zero
    if (rowsToZero.size() == M.size()) {
        for (auto row : rowsToZero) {
            for (int i = 0; i < M[row].size(); ++i) {
                M[row][i] = 0;
            }
        }
        return;
    }
    // In case each and every column has a zero
    if (columnsToZero.size() == M[0].size()) {
        for (auto column : columnsToZero) {
            for (int i = 0; i < M.size(); ++i) {
                M[i][column] = 0;
            }
        }
        return;
    }
    for (auto row : rowsToZero) {
        for (int i = 0; i < M[row].size(); ++i) {
            M[row][i] = 0;
        }
    }
    for (auto column : columnsToZero) {
        for (int i = 0; i < M.size(); ++i) {
            M[i][column] = 0;
        }
    }
}

int main() {
    vector<vector<int>> M{
            {1, 3, 1, 8, 5},
            {1, 9, 7, 0, 5},
            {1, 3, 0, 6, 5},
            {1, 3, 2, 8, 5}
    };
    cout << "Before:" << endl;
    printVector(M);
    cout << endl;
    cout << "After:" << endl;
    zeroMatrix(M);
    printVector(M);
    return 0;
}
