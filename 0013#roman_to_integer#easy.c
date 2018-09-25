int romanToInt(char* s)
{
	int count = 0;
	int ans = 0;
	while(s[count] == 'M')
		ans += 1000, count += 1;
	if(s[count] == 'C' && s[count + 1] == 'M')
		ans += 900, count += 2;
	if(s[count] == 'D')
		ans += 500, count += 1;
	if(s[count] == 'C' && s[count + 1] == 'D')
		ans += 400, count += 2;
	while(s[count] == 'C')
		ans += 100, count += 1;
	if(s[count] == 'X' && s[count + 1] == 'C')
		ans += 90, count += 2;
	if(s[count] == 'L')
		ans += 50, count += 1;
	if(s[count] == 'X' && s[count + 1] == 'L')
		ans += 40, count += 2;
	while(s[count] == 'X')
		ans += 10, count += 1;
	if(s[count] == 'I' && s[count + 1] == 'X')
		ans += 9, count += 2;
	if(s[count] == 'V')
		ans += 5, count += 1;
	if(s[count] == 'I' && s[count + 1] == 'V')
		ans += 4, count += 2;
	while(s[count] == 'I')
		ans += 1, count += 1;
	return ans;
}
