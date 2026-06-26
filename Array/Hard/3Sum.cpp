//Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.
//Brute Force
//Time Complexity:O(N3 * log(no. of unique triplets))
//Space Complexity:O(2 * no. of the unique triplets)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr, int n) {
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//Better
//Time Complexity:O(N2 * log(no. of unique triplets))
//Space Complexity:O(2 * no. of the unique triplets) + O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr, int n) {
        set<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            set<int> hashset;
            for (int j = i + 1; j < n; j++) {
                int third = -(arr[i] + arr[j]);
                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                hashset.insert(arr[j]);
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

//Optimal:
//Time Complexity:O(NlogN)+O(N2)
//Space Complexity:O(no. of triplets)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr, int n) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == 0) {
                    ans.push_back({arr[i], arr[left], arr[right]});
                    left++, right--;
                    while (left < right && arr[left] == arr[left - 1]) left++;
                    while (left < right && arr[right] == arr[right + 1]) right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }
        return ans;
    }
};