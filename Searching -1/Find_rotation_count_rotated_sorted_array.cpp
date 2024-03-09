class Solution {
public:
    int findKRotation(int arr[], int n) {
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX, idx = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // cout<<mid<<endl;
            if (arr[low] <= arr[mid])
            {
                if (ans > arr[low])
                {
                    ans = arr[low];
                    idx = low;
                }
                low = mid + 1;
            }
            else
            {
                if (ans > arr[mid])
                {
                    ans = arr[mid];
                    idx = mid;
                }
                high = mid - 1;
            }
        }
        return idx;

    }
};