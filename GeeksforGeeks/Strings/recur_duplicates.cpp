// C/C++ program to remove all 
// adjacent duplicates from a string
#include <iostream>
#include <string.h>

using namespace std;

// Recursively removes adjacent 
// duplicates from str and returns
// new string. las_removed is a 
// pointer to last_removed character
char* removeUtil(char *str, char *last_removed)
{
	
	// If length of string is 1 or 0
	if (str[0] == '\0' || str[1] == '\0')
		return str;

	// Remove leftmost same characters 
	// and recur for remaining 
	// string
	if (str[0] == str[1])
	{
		*last_removed = str[0];
		while (str[1] && str[0] == str[1])
			str++;
		str++;
		return removeUtil(str, last_removed);
	}
    cout<<str<<" "<<*last_removed<<" ";

	// At this point, the first character 
	// is definiotely different 
	// from its adjacent. Ignore first 
	// character and recursively 
	// remove characters from remaining string
	char* rem_str = removeUtil(str+1, 
							last_removed);
    cout<<rem_str<<" "<<endl;

	// Check if the first character 
	// of the rem_string matches with 
	// the first character of the 
	// original string
	if (rem_str[0] && rem_str[0] == str[0])
	{
		*last_removed = str[0];
	
		// Remove first character
		return (rem_str+1); 
	}

	// If remaining string becomes 
	// empty and last removed character
	// is same as first character of 
	// original string. This is needed
	// for a string like "acbbcddc"
	if (rem_str[0] == '\0' && 
				*last_removed == str[0])
		return rem_str;

	// If the two first characters 
	// of str and rem_str don't match, 
	// append first character of str 
	// before the first character of
	// rem_str. 
	rem_str--;
	rem_str[0] = str[0];
	return rem_str;
}

// Function to remove
char *remove(char *str)
{
	char last_removed = '\0';
	return removeUtil(str, &last_removed);
}

// Driver program to test 
// above functions
int main()
{
	char str1[] = "acbbc";
	cout << remove(str1) << endl;

	// char str2[] = "azxxxzy";
	// cout << remove(str2) << endl;

	// char str3[] = "caaabbbaac";
	// cout << remove(str3) << endl;

	// char str4[] = "gghhg";
	// cout << remove(str4) << endl;

	// char str5[] = "aaaacddddcappp";
	// cout << remove(str5) << endl;

	// char str6[] = "aaaaaaaaaa";
	// cout << remove(str6) << endl;

	// char str7[] = "qpaaaaadaaaaadprq";
	// cout << remove(str7) << endl;

	// char str8[] = "acaaabbbacdddd";
	// cout << remove(str8) << endl;

	// char str9[] = "acbbcddc";
	// cout << remove(str9) << endl;

	return 0;
}