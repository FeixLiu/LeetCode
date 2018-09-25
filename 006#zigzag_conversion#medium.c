char* convert(char* s, int numRows) 
{
    int lens = strlen(s) + 1;
    int step = 2 * numRows - 2;
    if (step < 2)
        return s;
    char* result = (char *)malloc(lens * sizeof(char));
    if (!result || lens == 0 || numRows == 0)
        return "";
    int i, j, count = 0;
    count = 0;
    for (j = 0; j < numRows; j++) 
        for (i = 0; i < (lens + numRows) ; i += step) 
        {
            if ( j != 0 && i > j && i - j < lens - 1 && j < numRows - 1) 
                result[count ++] = s[i - j];
            if ( (i + j) < lens - 1) 
                result[count ++] = s[i + j];
        }
    result[count] = 0;
    return result;
}