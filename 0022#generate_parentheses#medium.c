/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize)
{
	char** res;
	char* temp = (char*)malloc(sizeof(char) * (n * 2 + 1));
	int l = n, r = n;
	res = (char**)malloc(sizeof(char*) * 100000);
	*returnSize = 0;
	generate(res, returnSize, l, r, temp, 0);
	return res;
}

void generate(char** res, int* size, int l, int r, char* temp, int index)
{
	if(l ==0  && r == 0)
	{
		printf("%s\n", temp);
		temp[index] = 0;
		res[*size] = (char*)malloc(sizeof(char) * index);
		strcpy(res[*size], temp);
		(*size) ++;
		return;
	}
	if(l > 0)
	{
		temp[index] = '(';
		generate(res, size, l - 1, r, temp, index + 1);
	}
	if(r > 0 && l < r)
	{
		temp[index] = ')';
		generate(res, size, l, r - 1, temp, index + 1);
	}
}
