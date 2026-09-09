
bool possible(vector<int>& pages, int limit, int k) {
    // your code
    int stu = 1;
    int curr = 0;

    for(int page : pages) {
        if(curr + page <= limit) {
            curr += page;
        }
        else {
            stu++;
            curr = page;
        }
    }

    return stu <= k;
}

int partition(vector<int>& pages, int k) {
    int low = *max_element(boards.begin(), boards.end());

    int high = 0;
    for(int c : pages) {
        high += c;
    }

    int res = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;```cpp
bool possible(vector<int>& pages, int limit, int k) {
    int stu = 1;
    int curr = 0;

    for(int page : pages) {
        if(curr + page <= limit) {
            curr += page;
        }
        else {
            stu++;
            curr = page;
        }
    }

    return stu <= k;
}

int partition(vector<int>& pages, int k) {
    int low = *max_element(pages.begin(), pages.end());

    int high = 0;
    for(int page : pages) {
        high += page;
    }

    int res = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(possible(pages, mid, k)) {
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


        if(possible(pages, mid, k)) {
            res = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return res;
}

