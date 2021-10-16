#include <stdio.h>

int Bsearch(int ar[], int len, int target)
{
	int	first = 0;
	int last = len - 1;
	int	mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == ar[mid])
			return mid;
		else
		{
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

int	main(void)
{
	int	arr[] = {1, 3, 5, 7, 9};
	int	idx;

	idx = Bsearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);
	
	idx = Bsearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);
	
	return 0;
}