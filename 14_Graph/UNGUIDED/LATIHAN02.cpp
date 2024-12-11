#include <iostream>
#include <vector>
using namespace std;

void initializeMatrix_2311104008(vector<vector<int>>& matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = 0;
        }
    }
}

void inputEdges_2311104008(vector<vector<int>>& matrix, int edges) {
    int u, v;
    for (int i = 0; i < edges; ++i) {
        cout << "Masukkan pasangan simpul: ";
        cin >> u >> v;
        --u; // Menyesuaikan index ke 0-based
        --v;
        matrix[u][v] = 1;
        matrix[v][u] = 1; // Graf tidak berarah
    }
}

void printMatrix_2311104008(const vector<vector<int>>& matrix) {
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int jumlahSimpul, jumlahSisi;

    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;

    vector<vector<int>> adjacencyMatrix(jumlahSimpul, vector<int>(jumlahSimpul));

    initializeMatrix_2311104008(adjacencyMatrix, jumlahSimpul);
    inputEdges_2311104008(adjacencyMatrix, jumlahSisi);
    printMatrix_2311104008(adjacencyMatrix);

    return 0;
}
