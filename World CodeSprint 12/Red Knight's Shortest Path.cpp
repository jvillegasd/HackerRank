#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

bool visited[250][250] = {0};
const int rows[] = {-2, -2, 0, 2, 2, 0}, cols[] = {-1, 1, 2, 1, -1, -2};
const string mov[] = {"UL", "UR" , "R", "LR", "LL", "L"};
int n;

struct Node{
    int row, col, moves;
    int indices[3000];
    void init(int row, int col, int moves){
        this->row = row;
        this->col = col;
        this->moves = moves;
    }
};

bool validValues(int row, int col){
    if(row < 0 || col < 0 || row > n || col > n) return false;
    return true;
}

bool BFS(Node in, int rowF, int colF){
    queue<Node> cola;
    cola.push(in);
    while(!cola.empty()){
        Node nodo = cola.front();
        cola.pop();
        int row2 = nodo.row;
        int col2 = nodo.col;
        if(row2 == rowF && col2 == colF){
            printf("%d\n", nodo.moves);
            for(int i = 0; i < nodo.moves; i++){
                printf("%s", mov[nodo.indices[i]].c_str());
                if(i != nodo.moves - 1) printf(" ");
            }
            printf("\n");
            return true;
        }
        if(visited[row2][col2]) continue;
        visited[row2][col2] = true;
        for(int i = 0; i < 6; i++){
            int nRow = row2 + rows[i];
            int nCol = col2 + cols[i];
            if(validValues(nRow, nCol)){
                Node nNodo;
                nNodo.init(nRow, nCol, nodo.moves + 1);
                nodo.indices[nodo.moves] = i;
                for(int j = 0; j < nodo.moves + 1; j++) nNodo.indices[j] = nodo.indices[j];
                cola.push(nNodo);
            }
        }  
    }
    return false;
}

int main() {
    int rowO, colO, row, col;
    cin >> n;
    cin >> rowO >> colO >> row >> col;
    Node in;
    in.init(rowO, colO, 0);
    if(!BFS(in, row, col)) printf("Impossible\n");
    return 0;
}