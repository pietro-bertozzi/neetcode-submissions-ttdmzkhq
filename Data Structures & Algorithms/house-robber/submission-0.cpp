class Solution {
public:
    int rob(vector<int>& nums) {
        // è dp monodimensionale e dp[n] è il massimo bottino se ci fossero solo le prime n case
        //devo esprimere dp[n] in funzioen dei precedenti
        //è il massimo tra due opzioni a) quello subito prima copiato b) quello prima di 2 + la casa nuova
        // quindi bastano due variabili non il vettore intero

        int one = 0, two = 0, temp;
        for (int i = 0; i < nums.size(); ++i) {
            temp = two;
            two = max(one + nums[i], two);
            one = temp;
        }
        return max(one, two);
    }
};
