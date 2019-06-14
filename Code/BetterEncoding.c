/*
effective encoding
there is an encoding in which each alphabet is followed by the frequency of that particular 
alphabet in the string.
but there is a small problem with existing solution, that is there might be multiple entries for 
same alphabet
write a function to take the string as argument and return the string without duplication

eg:
input a12b14c23d1b2
output a12b16c23d1


*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h> 
#include<ctype.h>
#include<string.h>
char *effectiveEnc(char *s)
{
	char *out = (char*)malloc(130);
	int count[26];
	char ch;
	char buf[6];
	int i = 0,j,k;
	int num=0;
	int index=0;
	memset(count, 0, 26 * sizeof(int));
	
	do
	{
		if (isalpha(s[i]) != 0)
		{
			index = s[i] - 'a';
			num = 0;
		}
		else
		{
			num = num * 10 + (s[i] - '0');
			if (isalpha(s[i + 1]) != 0 || s[i + 1] == '\0')
			{
				count[index] += num;
			}
		}
		i++;
	} while (s[i] != '\0');
	for (j = 0,k=0; j < 26; j++) 
	{
		if (count[j] != 0)
		{
			*(out + k) = j + 'a';
			k++;
			k+=sprintf((out + k), "%d", count[j]);
		}
	}
	*(out + k) = '\0';
	return out;
}

int main()
{
	char in[] = "a12b23c12a1";
	char *output;
	output = effectiveEnc(in);
	printf("%s", output);

}