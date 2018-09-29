bool isValid(char* s)
{
	int length = strlen(s);
	if(length == 0) return true;
	char stack[length / 2 + 1];
	int top = -1;
	int count;
	for(count = 0; count < length; count ++)
		if(s[count] == '(' || s[count] == '[' || s[count] == '{')
			top += 1, stack[top] = s[count];
		else if(s[count] == ')' || s[count] == ']' || s[count] == '}')
			if(top < 0) return false;
			else if((s[count] == ')' && stack[top] != '(') || 
			   		(s[count] == ']' && stack[top] != '[') ||
			   		(s[count] == '}' && stack[top] != '{'))
				return false;
			else
				if(-- top < -1)
					return false;
		else
			continue;
	if(top == -1) return true;
	else return false;
}