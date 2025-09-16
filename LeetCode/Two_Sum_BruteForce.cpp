// My full code
#include<iostream>
using namespace std;

void input(int Arr[], int size) {


    if (size >= 100) return;

    for (int i = 0; i < size; i++) {
        cin >> Arr[i];
    }
}

void Solution(int Arr[], int size, int target) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (Arr[i] + Arr[j] == target && i != j) {
                cout << i << " " << j << endl;
                return;
            }

        }
    }
}

int main() {
    int Size;
    cout << "Enter size of array: ";
    cin >> Size;
    int nums[100];

    input(nums, Size);
    Solution(nums, Size, 4);
}

// LeetCode Solution
// As Submitted on 17 September 2025, 12:30 AM

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (nums[i] + nums[j] == target && i != j) {
                    return { i, j };
                }
            }
        }
        return {};
    }
};
*/

