#include <cstdio>
#include <memory.h>
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    //find the median one or ones;
    int i, j, median;
    int t = 0;
    i = j = median = 0;
    int sum[nums1Size + nums2Size];
    memset(sum, 0, nums1Size + nums2Size);
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] >= nums2[j])
        {
            sum[t] = nums2[j];
            j++;
        }
        else
        {
            sum[t] = nums1[i];
            i++;
        }
        t++;
    }
    while (i < nums1Size)
    {
        sum[t] = nums1[i];
        t++;
        i++;
    }
    while (j < nums2Size)
    {
        {
            sum[t] = nums2[j];
            t++;
            j++;
        }
    }
    int a = t / 2;
    int b = t / 2 - 1;
    if (t % 2 == 0)
    {
        return (1.0 * (sum[a] + sum[b])) / 2;
    }
    else
        return 1.0 * sum[a];
}
int main()
{
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int a = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int));
    printf("%d", a);
    return 0;
}