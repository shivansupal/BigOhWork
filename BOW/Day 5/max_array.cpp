#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum element in each sliding
// window of size k

vector<int> maxSlidingWindow(vector<int>& arr, int k)
{
	vector<int> ans;

	set<pair<int, int>, greater<pair<int,int>>> st;

	// Initialize the set with the first k elements

	for (int i = 0; i < k; i++)
		st.insert({ arr[i], i });

	// The maximum element in the first window

	ans.push_back((st.begin())->first);

	// Process the remaining elements

	for (int i = k; i < arr.size(); i++) {

		// Add the current element to the set
		st.insert({ arr[i], i });

		// Remove the (i-k)th element from the window
		st.erase({ arr[i - k], (i - k) });

		// The maximum element in the current window
		ans.push_back(st.begin()->first);
	}

	return ans;
}

int main()
{
	vector<int> arr = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
    
	int k = 3;

	// Find the maximum element in each sliding window of
	// size k
	vector<int> result = maxSlidingWindow(arr, k);

	// Print the results
	for (auto i : result)
		cout << i << " ";

	return 0;
}
