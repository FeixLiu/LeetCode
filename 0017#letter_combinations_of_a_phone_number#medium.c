/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void getLetterCombinations(char**, char*, char*, int, char [][5], int*); //have to define the second length of two dimensions array
char** letterCombinations(char* digits, int* returnSize)
{
	char letters[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	char **result, *temp;
	int num = 1, length = 0, top = 0;
	while(digits[length])
	{
		if(digits[length] == '0' || digits[length] == '1') continue;
		else if(digits[length] == '7' || digits[length] == '9') num *= 4;
		else num *= 3;
		length ++;
	}
	result = (char**)malloc(sizeof(char*) * num);
	if(length == 0)
	{
		*returnSize = 0;
		return result;
	}
	temp = (char*)malloc(sizeof(char) * length);
	getLetterCombinations(result, digits, temp, 0, letters, &top);
	*returnSize = top;
	return result;
}

void getLetterCombinations(char** result, char* digits, char* temp, int index, char letters[10][5], int* top)
{
	int i, digit = digits[index] - '0';
	char* letter;
	if(digits[index] == '\0')
	{
		letter = (char*)malloc(sizeof(char) * index);
		temp[index] = '\0';
		strcpy(letter, temp);
		result[*top] = letter;
		(*top) ++;
		return;
	}
	for(i = 0; letters[digit][i]; i ++)
	{
		temp[index] = letters[digit][i];
		getLetterCombinations(result, digits, temp, index + 1, letters, top);
	}
}
