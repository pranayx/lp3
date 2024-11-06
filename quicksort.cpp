#include <bits/stdc++.h>
using namespace std;

class Sort {
    int partition(vector<int>&arr, int low, int high) {
        int pivot = arr[low];
        int i = low, j = high;

        while(i < j) {
            while(i <= high && arr[i] <= pivot) {
                i++;
            }

            while(j >= low && arr[j] > pivot) {
                j--;
            }

            if(i < j) {
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[low], arr[j]);

        return j;
    }

    public:
    void deterministicQuickSort(vector<int>&arr, int low, int high) {
        if(low < high) {
            int partIdx = partition(arr, low, high);
            deterministicQuickSort(arr, low, partIdx - 1);
            deterministicQuickSort(arr, partIdx + 1, high);
        }
    }

    void randomizedQuickSort(vector<int>&arr, int low, int high) {
        if(low < high) {
            int random = rand() % (high - low) + low;
            swap(arr[random], arr[low]);

            int partIdx = partition(arr, low, high);
            randomizedQuickSort(arr, low, partIdx - 1);
            randomizedQuickSort(arr, partIdx + 1, high);
        }
    }
};


int main() {
    Sort S;

    vector<int>arr1{5, 3, 4, 2, 1,5,6,7,2,1};
   vector<int>arr2{5, 3, 4, 2, 5};

    S.deterministicQuickSort(arr1, 0, 9);
    S.randomizedQuickSort(arr2, 0, 4);

    for(int i = 0; i < 10; i++) {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i < 5; i++) {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    return 0;
}
