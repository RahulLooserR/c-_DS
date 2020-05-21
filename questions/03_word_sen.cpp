/* ************************************************************************
 * Created by    : Rahul Kumar Nonia
 * File name     : 03_word_sen.cpp
 * Created on    : Saturday 25 April 2020 10:06:47 PM IST
 * Last modified : Saturday 25 April 2020 10:42:09 PM IST
 * Description   :
 * ***********************************************************************/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

class WordFreqInSentence{
public:
	WordFreqInSentence(std::string str, std::string word)
	{
		sentence = str;
		frequency = 0;
		std::string temp;
		std::stringstream iss(sentence);

		while(iss >> temp){
			if(temp == word)
			frequency++;
		}
	}

	std::string sentence;
	int frequency;
	bool operator < (WordFreqInSentence& rhs) const
	{
		return frequency < rhs.frequency;
	}
};

int main()
{
	int n;
	std::string word, sentence;
	std::cout << "Enter the word: ";
	std::getline(std::cin, word);
	std::cout << "Enter the number of sentences: ";
	std::cin >> n;
	std::cout << "Enter the sentences: \n";

	std::list<WordFreqInSentence> list;

	for(auto i = 0; i <= n; i++){
		std::getline(std::cin, sentence);
		WordFreqInSentence obj(sentence, word);
		list.push_back(obj);
	}
	list.sort();

	for(auto it = list.begin(); it != list.end(); it++){
		std::cout << it->sentence << std::endl;
	}

	return 0;
}
