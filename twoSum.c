#include <cstdio>
#include <cstdlib>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    unsigned int *nums_t = (unsigned int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
            nums_t[i] = nums[i] * (-1);
        else
            nums_t[i] = nums[i] * 2;
        printf("%d: %d\n", i + 1, nums_t[i]);
    }
    int init_size = nums_t[0];
    int *i_j = (int *)malloc(sizeof(int) * 2);
    int *hash_table = (int *)malloc(init_size * sizeof(int));
    printf("%d", init_size * sizeof(int));
    memset(hash_table, 0, init_size * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {

        if (nums_t[i] > init_size)
        {
            printf("%d", nums_t[i]);
            hash_table = (int *)realloc(hash_table, nums_t[i] * sizeof(int));
            memset(hash_table, 0, sizeof(int) * nums_t[i]);
            init_size = nums_t[i];
        }
        hash_table[nums_t[i]] = i + 1;
    }
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d", hash_table[nums_t[i]]);
    }
    for (int i = 0; i < numsSize; i++)
    {
        int target_j = target - hash_table[nums_t[i]];
        if (target_j < 0)
            target_j = -1 * target_j;
        else
            target_j = 2 * target_j;
        if (hash_table[target_j] != 0)
        {
            i_j[0] = i;
            i_j[1] = hash_table[target_j];
        }
    }
    return i_j;
}