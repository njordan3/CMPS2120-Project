int binarySearch(int *arr, int left, int right, int target)
{
    while (left <= right) {
        int position = left + (right - left) / 2;
        //check if the target is in the middle
        if (arr[position] == target)
            return position;
        //ignore the left half if the target is larger
        if (arr[position] < target)
            left = position + 1;
        //ignore the right half if the target is smaller
        else
            right = position - 1;
    }
    //target wasn't found
    return -1;
}

int linearSearch(int *arr, int amount, int target)
{
    //iterate through the array amount times until the target is found
    for (int i = 0; i < amount; i++) {
        if (arr[i] == target)
            return i;
    }
    //target wasn't found
    return -1;
}

int interpolationSearch(int *arr, int amount, int target)
{
    //find indexes of two corners
    int lo = 0, hi = amount - 1;

    while (lo <= hi && target >= arr[lo] && target <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == target)
                return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (target - arr[lo]));
        //condition of target found
        if (arr[pos] == target)
            return pos;
        //target is in the upper part
        if (arr[pos] < target)
            lo = pos + 1;
        //target is in the lower part
        else
            hi = pos - 1;
    }
    //target wasn't found
    return -1;
}
