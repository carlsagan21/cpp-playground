//
// Created by Kim Soo on 2019/11/13.
//

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trust) {
        if (N == 1) {
            return 1;
        }
        vector<bool> isTrusting(N + 1, false);
        vector<int> isTrusted(N + 1, 0);
        for (auto const &value: trust) {
            isTrusting[value[0]] = true;
            isTrusted[value[1]]++;
        }
        for (int i = 1; i < N + 1; i++) {
            if (!isTrusting[i] && isTrusted[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};


class TestFixture : public ::testing::Test {
protected:
    TestFixture() {
        solution = new Solution();
    }

    ~TestFixture() override {
        delete solution;
    }

    Solution *solution;
};

TEST_F(TestFixture, Test) { // NOLINT(cert-err58-cpp)
    vector<vector<int>> trust{{1, 2}};
    EXPECT_EQ(solution->findJudge(2, trust), 2);
}