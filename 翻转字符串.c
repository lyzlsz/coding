#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int strlen(const char* str);
void reverse_string(char* str)
{
	assert(str);
	char tmp = 0;
	int len = strlen(str);
	if (len>0)
	{
		tmp = str[0];
		str[0] = str[len] - 1;
		str[len - 1] = '\0';
		reverse_string(str + 1);
		str[len - 1] = tmp;
	}
}
int main()
{
	char arr[] = "abcdfe";
	reverse_string(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}



