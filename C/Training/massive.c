#include <stdio.h>

int main()
{
    int nums[5] = {1,2,3,4,5};
    int sum = 0;
    int max = nums[0];
    printf("%d\n", nums[0] + nums[1] + nums[2] + nums[3] + nums[4]);
    printf("Number 2\n");
    for(int i = 0; i < 5; i++){
        sum+=nums[i];
        if(nums[i] > max) {
            max = nums[i];
        }
    }
    printf("Max = %d\n", max);
    printf("Sum = %d\n", sum);
    return 0;
}