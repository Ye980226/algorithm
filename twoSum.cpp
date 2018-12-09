#include <cstdio>
#include <cstdlib>
#include <memory.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define POSITIVE -1
#define NEGETIVE -2
int *twoSum(int *nums, int numsSize, int target)
{
    int *i_j = (int *)malloc(sizeof(int) * 2);
    i_j[0] = -1;
    i_j[1] = -1;
    int count = 0; //如果有0，防止程序去世,单独处理，要是程序有解，则有且只有2个0
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0 && count == 1)
        {
            i_j[1] = i;
            count++;
        }

        if (nums[i] == 0 && count == 0)
        {
            i_j[0] = i;
            count++;
        }
        if (count == 2)
            return i_j;
    }
    int *nums_p = (int *)malloc(sizeof(int) * numsSize);
    int *nums_n = (int *)malloc(sizeof(int) * numsSize);
    // memset(nums_p, POSITIVE, numsSize);
    // memset(nums_n, NEGETIVE, numsSize);
    int size_n = 0;
    int size_p = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
        {
            nums_n[i] = nums[i] * -1;
            nums_p[i] = POSITIVE;

            // printf("%d:%d\n", i, nums_n[i]);
        }
        else
        {
            nums_p[i] = nums[i];
            nums_n[i] = NEGETIVE;
            // printf("%d:%d\n", i, nums_p[i]);
        } // printf("%d: %d\n", i + 1, nums_t[i]);
    }

    int p = nums_p[0];
    int n = nums_n[0];
    int maxsize_p = p;
    int maxsize_n = n;
    // printf("nums_p\n");
    for (int i = 0; i < numsSize; i++)
    {
        // printf("%d\n", nums_p[i]);
        maxsize_p = nums_p[i] > maxsize_p ? nums_p[i] : maxsize_p;
    }
    // printf("nums_n\n");
    for (int i = 0; i < numsSize; i++)
    {
        // printf("%d\n", nums_n[i]);

        maxsize_n = nums_n[i] > maxsize_n ? nums_n[i] : maxsize_n;
    }
    if (maxsize_n < 0)
        maxsize_n = 0;
    if (maxsize_p < 0)
        maxsize_p = 0;
    // printf("maxsize_p:%d\n", maxsize_p);
    // printf("maxsize_n:%d", maxsize_n);

    int *hashTable_p = (int *)malloc(maxsize_p * sizeof(int));
    if (!hashTable_p)
    {
        return i_j;
    }
    int *hashTable_n = (int *)malloc(maxsize_n * sizeof(int));
    if (!hashTable_n)
    {
        return i_j;
    }
    // printf("%d\n", init_size * sizeof(int));
    memset(hashTable_p, POSITIVE, (maxsize_p + 1) * sizeof(int));
    memset(hashTable_n, NEGETIVE, sizeof(int) * (maxsize_n + 1));
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            hashTable_p[nums[i]] = i;
            // printf("\n%d:%d:%d\n", nums[i], hashTable_p[nums[i]], i);
        }
        else
        {
            hashTable_n[nums[i] * -1] = i;
            // printf("\n%d:%d:%d\n", nums[i], hashTable_n[nums[i] * -1], i);
        }
        // printf("hashTable_n:\n");
        // for (int i = 0; i < maxsize_n; i++)
        // {

        // printf("%d:%d\n", i, hashTable_n[i]);
        // }
        // printf("hashTable_p:\n");
        // for (int i = 0; i < maxsize_p; i++)
        // {

        // printf("%d:%d\n", i, hashTable_p[i]);
        // }
        // printf("****************\n");
    }
    for (int i = 0; i < numsSize; i++)
    {

        int target_j = target - nums[i];
        // printf("\ntarget_j:%d\n", target_j);

        if (target_j < 0 && hashTable_n[target_j * -1] != NEGETIVE && (-1 * target_j) <= maxsize_n)
        {
            i_j[0] = i;
            i_j[1] = hashTable_n[target_j * -1];
            // printf("hashtable:%d", i_j[1]);
        }
        else if (target_j >= 0 && hashTable_p[target_j] != POSITIVE && target_j <= maxsize_p)
        {

            i_j[0] = i;
            i_j[1] = hashTable_p[target_j];

            // printf("hashtable:%d", i_j[1]);
        }
        if (i_j[0] != -1 && i_j[1] != -1 && i_j[0] != i_j[1])
        {
            return i_j;
        }
        // printf("nums_t[i]-1:%d,target_j:%d\n", nums_t[i] - 1, target_j);
        // if (hash_table[target_j] != 0)
        // {
        // printf("%d:%d", i, hash_table[target_j - 1] - 1);
        // int i_return = i < hash_table[target_j] - 1 ? i : hash_table[target_j] - 1;
        // int j_return = i > hash_table[target_j] - 1 ? i : hash_table[target_j] - 1;
        // i_j[0] = i_return;
        // i_j[1] = j_return;
        // }
        // }
    }
    return i_j;
}
int main()
{
    int nums[] = {3, 2, 4};
    int target = 6;
    int *i_j = twoSum(nums, sizeof(nums) / sizeof(int), target);
    printf("\ni:%d\n", i_j[0]);
    printf("j:%d\n", i_j[1]);
    return 0;
}