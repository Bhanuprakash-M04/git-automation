#include <bits/stdc++.h>
using namespace std;
#include "../solutions/solution.cpp"

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
    cout << "]" << endl;
}

void runTestCases()
{
    vector<vector<vector<int>>> testCases = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{1, 2}, {3, 4}},
        {{1}},
        {},
        {{1}, {2}, {3}}};

    vector<vector<int>> expectedResults = {
        {1, 2, 3, 6, 9, 8, 7, 4, 5},
        {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7},
        {1, 2, 4, 3},
        {1},
        {},
        {1, 2, 3}};

    Solution sol;
    int passed = 0, failed = 0;

    for (size_t i = 0; i < testCases.size(); i++)
    {
        vector<int> result = sol.spiralOrder(testCases[i]);

        cout << "Test Case " << i + 1 << ":" << endl;
        cout << "Expected: ";
        printVector(expectedResults[i]);
        cout << "Got:      ";
        printVector(result);

        if (result == expectedResults[i])
        {
            cout << "✅ Passed" << endl;
            passed++;
        }
        else
        {
            cout << "❌ Failed" << endl;
            failed++;
        }
    }

    cout << "Test Cases Passed: " << passed << endl;
    cout << "Test Cases Failed: " << failed << endl;
    cout << "Total Test Cases: " << passed + failed << endl;
}

int main()
{
    runTestCases();
    return 0;
}
