#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int n;
    vector<vector<int>> board;
    vector<vector<int>> ans;
    vector<vector<vector<int>>> answer;

    Solution(int n) {
        this -> n = n;

        board.resize(n, vector<int> (n, 0));
        ans.resize(n, vector<int> (n, 0));
    }
    
    void solve(int row, int start_row);
    void addSolution(vector<vector<int>> ans);
    bool isSafe(int row, int col);
};

void Solution :: addSolution(vector<vector<int>> ans) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 1) {
                count++;
            }
        }
    }

    if(count == n) {
        answer.push_back(ans);
    }
}

bool Solution :: isSafe(int row, int col) {
    //Check column
    for(int i = 0; i < n; i++) {
        if(board[i][col] == 1) {
            return false;
        }
    }
    
    //Check row
    for(int i = 0; i < n; i++) {
        if(board[row][i] == 1) {
            return false;
        }
    }

    //Check for upper left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }

    //Check for lower left diagonal
    for(int i = row, j = col; i < n && j >= 0; i++, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }

    //Check for upper right diagonal 
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1) {
            return false;
        }
    }

    //Check for lower right diagonal
    for(int i = row, j = col; i < n && j < n; i++, j++) {
        if(board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void Solution :: solve(int row, int start_row) {
    if(row == n) {
        ans = board;
        addSolution(ans);
    }

    if(row == start_row) {
        solve(row + 1, start_row);
    }

    for(int i = 0; i < n; i++) {
        if(isSafe(row, i)) {
            board[row][i] = 1;
            solve(row + 1, start_row);
            board[row][i] = 0;
        }
    }
}

int main() {
    int n;
    cout<<"Enter the size of board: ";
    cin>>n;

    int start_col, start_row;
    
    cout<<"Enter start row: ";
    cin>>start_row;

    cout<<"Enter start column: ";
    cin>>start_col;

    Solution S(n);

    S.board[start_row][start_col] = 1;

    S.solve(0, start_row);

    for(int i = 0; i < S.answer.size(); i++) {
        cout<<"Solution No: "<<i+1<<endl;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout<<S.answer[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
  return  0;
}