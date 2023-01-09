/*   134. Gas Station  */

class Solution {
public:

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current=0;
        int start=0;
            int totGas = 0;
    int totCost = 0;
    for (int g : gas)
        totGas += g;
    for (int c : cost)
        totCost += c;
    if (totCost > totGas)
        return -1;
        for(int i=0;i<gas.size();i++){
            current+=(gas[i]-cost[i]);
            if(current<0){
                start=i+1;
                current=0;
            }
        }
        return start;
    }
};