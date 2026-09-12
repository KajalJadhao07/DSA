class Solution {
public:
    struct State {
        long long score;
        vector<int> ids;

        State(long long s = 0, vector<int> v = {})
            : score(s), ids(v) {}
    };

    bool smaller(const vector<int>& a, const vector<int>& b) {
        return lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end()
        );
    }

    State getBetter(const State& a, const State& b) {
        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        return smaller(a.ids, b.ids) ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<array<long long, 4>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(arr.begin(), arr.end(),
            [](const auto& a, const auto& b) {
                if (a[1] != b[1])
                    return a[1] < b[1];

                return a[0] < b[0];
            });


        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = arr[i][1];

        vector<int> prev(n);

        for (int i = 0; i < n; i++) {

            prev[i] = lower_bound(
                ends.begin(),
                ends.begin() + i,
                arr[i][0]
            ) - ends.begin();
        }

    
        vector<vector<State>> dp(
            5,
            vector<State>(n + 1)
        );

        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= n; i++) {
                State skip = dp[k][i - 1];
                State take = dp[k - 1][prev[i - 1]];
                take.score += arr[i - 1][2];

                take.ids.push_back(
                    (int)arr[i - 1][3]
                );

                sort(take.ids.begin(), take.ids.end());
                dp[k][i] = getBetter(skip, take);
            }
        }

        return dp[4][n].ids;
    }
};