/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 04_coinSet.cpp
 * Created on    : Sunday 26 April 2020 01:58:21 AM IST
 * Last modified : Sunday 26 April 2020 01:58:45 AM IST
 * Description   :
 * ***********************************************************************/


#include <iostream>
#include <string>
#include <list>

char* getset(std::string str)
{
	std::list<char> set;
	for(auto i = 0; i < str.length(); i++){
		bool found = false;
		for(auto it = set.begin(); it != set.end(); it++){
			if(*it == str[i]){
				found = true;
			}
		}
		if(found == false){
			set.push_back(str[i]);
		}
	}
	const int size = set.size();
	std::array<char, size>
	int i = 0;
	for(auto it = set.begin(); it != set.end(); it++){
		arr[i] = *it;
		i++;
	}
	return arr;
}

int main()
{
	std::string str;
	std::cout << "Enter the string: ";
	std::getline(std::cin, str);

	int* set = getset(str);
	int windowsize = set.size();

	std::list<char>::iterator it = set.begin();

	std::cout <<  << std::endl;

	return 0;
}