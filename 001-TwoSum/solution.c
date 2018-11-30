/*#############################################################
 *     File Name    : solution.c
 *     Author       : winddoing
 *     Created Time : Thu Nov 29 21:25:56 2018
 *     Description  :
 *############################################################*/

#include <stdio.h>
#include <stdlib.h>

struct object {
    int val;
    int index;
};

static int compare(const void *a, const void *b)
{
    return ((struct object *) a)->val - ((struct object *) b)->val;
}

/* Test execution time: 36ms */
int* twoSum1(int *nums, int numsSize, int target)
{
    int i, j;
    struct object *objs = malloc(numsSize * sizeof(*objs));

    for(i = 0; i < numsSize; i++) {
        objs[i].val = nums[i];
        objs[i].index = i;
    }

    qsort(objs, numsSize, sizeof(*objs), compare);

    int count = 0;
    int *results = malloc(2 * sizeof(int));
    i = 0;
    j = numsSize - 1;

    while(i < j) {
        int diff = target - objs[i].val;

        if(diff > objs[j].val) {
            while(++i < j && objs[i].val == objs[i - 1].val) {}
        } else if(diff < objs[j].val) {
            while(--j > i && objs[j].val == objs[j + 1].val) {}
        } else {
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            return results;
        }
    }

    return NULL;
}

/* Test execution time: 76ms */
int* twoSum2(int* nums, int numsSize, int target)
{
    static int a[2] = {0};

    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                a[0] = i;
                a[1] = j;
                return a;
            }
        }
    }

    return 0;
}

/* Test execution time: 116ms */
int* twoSum3(int* nums, int numsSize, int target)
{
    int *num;
    int i, j;

    num = (int *)malloc(sizeof(int) * 2);

    for(i = 0; i < numsSize; i++) {
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                num[0] = i;
                num[1] = j;
                return num;
            }
        }
    }

    return 0;
}

#if 0
int main(void)
{
    //int nums[] = {-1, -2, -3, -4, -5};
    //int target = -8;
    //int nums[] = {0,4,3,0};
    //int target = 0;
    int nums[] = { 3, 2, 3 };
    int count = sizeof(nums) / sizeof(*nums);
    int target = 6;
    int *indexes = twosum(nums, count, target);

    if(indexes != NULL) {
        printf("%d %d\n", indexes[0], indexes[1]);

    } else {
        printf("Not found\n");
    }

    return 0;
}
#endif
