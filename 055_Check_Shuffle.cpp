// Anagram Search --> Easy Version

#include<iostream>
#include<cstring>
#define MAX 256
using namespace std;

// Note that compare operation runs in O(1) time due to the fixed length of the array.
bool compare(char arr1[], char arr2[]){
	for (int i=0; i<MAX; i++)
		if (arr1[i] != arr2[i])
			return false;
	return true;
}


bool search(char *pat, char *txt){
	int M = strlen(pat), N = strlen(txt);
	char countP[MAX] = {0}, countTxt[MAX] = {0};
	for (int i = 0; i < M; i++){
		countP[pat[i]]++;
		countTxt[txt[i]]++;
	}
	for (int i = M; i < N; i++){
		if (compare(countP, countTxt))
			return true;
		countTxt[txt[i]]++;
		countTxt[txt[i-M]]--;
	}
	// Explicitly check for last window.
	if (compare(countP, countTxt))
		return true;
		return false;
}

int main()
{
	char txt[] = "BACFDG";
	char pat[] = "ABCD";
	if (search(pat, txt))
	cout << "Yes";
	else
	cout << "No";
	return 0;
}
