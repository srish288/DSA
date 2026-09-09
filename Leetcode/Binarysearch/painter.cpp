
bool possible(vector<int>& boards, int limit, int k) {
    int painters = 1;
    int curr = 0;

    for(int board : boards) {
        if(curr + board <= limit) {
            curr += board;
        }
        else {
            painters++;
            curr = board;
        }
    }

    return painters <= k;
}

int partition(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());

    int high = 0;
    for(int c : boards) {
        high += c;
    }

    int res = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(possible(boards, mid, k)) {
            res = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return res;
}
```
