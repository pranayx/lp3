#include <bits/stdc++.h>
using namespace std;

class Fib{
public:

    void iterative(int n){
        int i1=0;
        int i2=1;
        cout<<i1<<" "<<i2<<" ";
        
        for(int i=2;i<n;i++){
            int ans= i1+i2;
            cout <<ans<<" ";
            i1=i2;
            i2=ans;
        }
        cout<<endl;
    }

    void recursive(int n,int i1,int i2){
        if(n==2){
            return ;
        }

        int ans= i1+i2;
        cout <<ans <<" ";
        recursive(n-1,i2,ans);
    }

};

int main(){
    Fib f;
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Iterative Fibonacci Series is: ";
    f.iterative(n);

    cout<<"Recursice Fibonacci Series is: 0 1 ";
    f.recursive(n, 0, 1);
}