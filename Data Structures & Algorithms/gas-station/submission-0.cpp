class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int current_tank = 0;
        int start_index = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            total_tank += diff;
            current_tank += diff;
            if (current_tank < 0) {
                start_index = i + 1;
                current_tank = 0; 
            }
        }

        return total_tank >= 0 ? start_index : -1;
    }
};