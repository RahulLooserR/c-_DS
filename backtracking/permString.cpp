/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : permString.cpp
 * Created on    : Sunday 05 April 2020 01:41:23 PM IST
 * Last modified : Monday 06 April 2020 12:54:51 PM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int count = 0;

void perm(char str[], int k)
{
	int i, len = strlen(str);
	static int* flag = new int[len];
	static char* result = new char[len];

	if(str[k] == '\0'){
		result[k] = '\0';
		count++;
		cout << count << ": " << result << endl;
		return;	
	}

	for(i = 0; str[i] !='\0'; i++){
		if(flag[i] == 0){
			result[k] = str[i];
			flag[i] = 1;
			perm(str, k + 1);
			flag[i] = 0;
		}
	}
}

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permSwap(char str[], int low, int high)
{
	if(low == high){
		count++;
		cout << count << ": " << str << endl;
		return;
	}
	for(int i = low; i <= high; i++){
		swap(&str[low], &str[i]);
		permSwap(str, low + 1, high);
		swap(&str[low], &str[i]);
	}
}

int main()
{
	char str[] = "test";
	int len = strlen(str);
	perm(str, 0);
	
	count = 0;
	
	permSwap(str, 0, len - 1);

	return 0;
}
