class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0, costSum = 0;
        for(int i=0; i<gas.size(); i++) {
            gasSum += gas[i];
            costSum += cost[i];
        }

        if(gasSum<costSum) return -1;

        int sum=0;
        int starting=0;
        for(int i=0; i<gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            if(sum<0) {
                starting = i+1;
                sum=0;
            }
        }

        return starting;
    }
};