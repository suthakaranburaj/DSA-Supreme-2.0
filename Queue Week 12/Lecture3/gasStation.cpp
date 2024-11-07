#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;
        int balance = 0;
        int start =0;

        for(int i=0;i<gas.size();i++){
            balance = balance +gas[i] - cost[i];

            if(balance < 0){
                deficit += abs(balance);
                start = i+1;
                balance=0;
            }
        }

        if(balance - deficit >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
int main(){
    vector<int> gas={2,3,4};
    vector<int> cost={3,4,3};

    int ans = canCompleteCircuit(gas,cost);
    cout<<ans;
return 0;
}