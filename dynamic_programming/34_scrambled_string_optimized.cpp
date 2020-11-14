/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 33_scrambled_string.cpp
 * Created on    : Thursday 12 November 2020 08:21:34 AM IST
 * Last modified : Friday 13 November 2020 09:24:00 AM IST
 * Description   : 
 * ***********************************************************************/

#include <iostream>
#include <unordered_map> 

using namespace std;

unordered_map<string, bool> umap;

bool isScrambled(string s1, string s2)
{
	if(s1.compare(s2) == 0)
		return true;
	if(s1.length() != s2.length())
		return false;
	if(s1.length() <= 1)
		return false;

	/* construct key */
	string key = s1;
	key.append(" ");
	key.append(s2);

	if(umap.find(key) != umap.end()){
		return umap[key];
	}

	bool flag = false;

	for(int i = 1; i < s1.length(); i++){
		/* if swapping is done 
		 * compare s1(1st half) = s2(2nd half)
		 * compare s1(2nd half) = s1(1st half)
		 */
		bool swap = isScrambled(s1.substr(0, i), s2.substr(i, s2.length()-i)) && isScrambled(s1.substr(i, s1.length()-i), s2.substr(0, i));

		/* if there is no swapping
		 * compare s1(1st half) = s2 (1st half)
		 * compare s1(2nd half) = s2 (2nd half)
		 */
		bool noSwap = isScrambled(s1.substr(0, i), s2.substr(0, i)) && isScrambled(s1.substr(i, s1.length()-i), s2.substr(i, s2.length()-i));

		if(swap || noSwap){
			flag = true;
			break;
		}

	}

	return umap[key] = flag;
}

int main()
{
	string s1 = "coder";
	string s2 = "ocder";

	cout << "s1 and s2 are scrambled: " << isScrambled(s1, s2) << endl;

	return 0;
}
