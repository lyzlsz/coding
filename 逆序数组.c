#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void reverse_arr(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
char* reverse(char arr[])
{
	int len = strlen(arr);
	char*start = arr;
	char*end = NULL;
	char* ret = arr;
	reverse_arr(arr, arr + len - 1);
	while (*arr)
	{
		start = arr;
		while ((*arr != ' ') && (*arr != '\0'))
		{
			arr++;
		}
		end = arr - 1;
		reverse_arr(start, end);
		if (*arr == ' ')
			arr++;
	}
	return ret;
}
int main()
{
	char arr[] = "student a am i";
	printf("%s\n", reverse(arr));
	system("pause");
	return 0;
}