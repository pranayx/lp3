#include <bits/stdc++.h>
using namespace std;

class Knapsack {
    public:
    int knapsack(int n, vector<int> weight, vector<int> value, int maxCapacity);
    int solve(int index, vector<int> weight, vector<int> value, int capacity);
    int tabulation(int n, vector<int> weight, vector<int> value, int capacity);
};

int Knapsack :: tabulation(int n, vector<int> weight, vector<int> value, int capacity) {
    vector<vector<int>> dp(n, vector<int> (capacity + 1, 0));

    //Initialization of using only first item
    for(int i = weight[0]; i <= capacity; i++) {
        dp[0][i] = value[0];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= capacity; j++) {
            int include = 0, exclude = 0;

            if(weight[i] <= j) {
                include = value[i] + dp[i - 1][j - weight[i]];
            }

            exclude = dp[i - 1][j];

            dp[i][j] = max(include, exclude);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= capacity; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n - 1][capacity];
}

int Knapsack :: solve(int index, vector<int> weight, vector<int> value, int capacity) {
    if(index == 0) {
        if(weight[0] <= capacity) {
            return value[0];
        }
        else {
            return 0;
        }
    }

    int take = 0;

    if(weight[index] <= capacity) {
        take = value[index] + solve(index - 1, weight, value, capacity - weight[index]);
    }

    int notTake = solve(index - 1, weight, value, capacity);

    return max(take, notTake);
}

int Knapsack :: knapsack(int n, vector<int> weight, vector<int> value, int maxCapacity) {
    return solve(n - 1, weight, value, maxCapacity);
}

int main() {
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;

    vector<int> weight(n), value(n);
    
    for(int i = 0; i < n; i++) {
        cout<<"Enter weight: ";
        cin>>weight[i];

        cout<<"Enter value: ";
        cin>>value[i];
    }

    int weightKnapsack;
    cout<<"Enter the weight of Knapsack: ";
    cin>>weightKnapsack;

    Knapsack K;
    cout<<K.solve(n, weight, value, weightKnapsack)<<endl;
    cout<<K.tabulation(n, weight, value, weightKnapsack)<<endl;
    return 0;
}