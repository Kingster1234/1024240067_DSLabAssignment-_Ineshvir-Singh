#include <stdio.h>

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums)/sizeof(nums[0]);

    int hash[1000] = {0}; 

    for(int i = 0; i < n; i++) {
        if(hash[nums[i]] == 1) {
            printf("true\n");
            return 0;
        }
        hash[nums[i]] = 1;
    }

    printf("false\n");
    return 0;
}
