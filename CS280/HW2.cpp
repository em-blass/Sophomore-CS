/**
CS280 HW2
@file HW2.cpp
@author Emmet Blassingame
@version 9/17/2022
*/

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <sstream>
using namespace std;

int numDoubles = 0;

struct wordItem
{
	string word;
	int count;
};

void doubleArraySize(wordItem*& wordItemList, int& length) {
	int tempLength = length;
	length = length * 2;
	wordItem* newArr = new wordItem[length];

	for (int i = 0; i < tempLength; i++) {
		newArr[i] = wordItemList[i];
	}

	delete[] wordItemList;
	wordItemList = newArr;
}

void addWord(wordItem*& wordItemList, int& wordIndex, int& length, string nextWord, int& numDoubles) {
	bool found = false;
	for (int i = 0; i < length; i++) {
		if (wordItemList[i].word == nextWord) {
			if (wordItemList[i].count == 1);
			wordItemList[i].count++;

			found = true;
		}
	}

	if (!found) {
		if (wordIndex == length) {
			doubleArraySize(wordItemList, length);
			numDoubles++;
		}

		wordItemList[wordIndex].word = nextWord;
		wordItemList[wordIndex].count = 1;
		wordIndex++;
	}
}

void arraySort(wordItem wordItemList[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (wordItemList[i].count < wordItemList[j].count)
			{
				wordItem temp = wordItemList[i];
				wordItemList[i] = wordItemList[j];
				wordItemList[j] = temp;
			}
		}
	}
}

void printTopN(wordItem wordItemList[], int length, int topN)
{
	for (int i = 0; i < topN; i++)
	{
		cout << wordItemList[i].word << ", " << wordItemList[i].count << endl;
	}
}

void printArr(wordItem wordItemList[], int wordIndex)
{
	for (int i = 0; i < wordIndex; i++)
	{
		if (wordItemList[i].count > 1) {
			cout << wordItemList[i].word << ", " << wordItemList[i].count << endl;
		}
	}
}


int main()
{
	int numDoubles = 0;

	string inputFile = "shakespeare.txt";
	ifstream file(inputFile);

	if (!file)
	{
		cout << "Failed to open " << inputFile << endl;
		return 1;
	}

	int length = 1;
	int wordIndex = 0;
	int topN = 4;

	wordItem* wordItemList = new wordItem[length];
	string nextWord;

	while (file >> nextWord)
	{
		addWord(wordItemList, wordIndex, length, nextWord, numDoubles);
	}

	cout << "(printTopN) Top" << " " << topN << " " << "most common words: " << endl;
	cout << " " << endl;

	arraySort(wordItemList, length);
	printTopN(wordItemList, length, topN);

	cout << " " << endl;
	cout << "Array Doubles: " << numDoubles << " " << endl;
	cout << " " << endl;

	cout << "(printArr) Print all words with duplicates? (yes/no)" << endl;
	string x;
	cin >> x;

	if (x == "yes") {
		printArr(wordItemList, wordIndex);
	}

	delete[] wordItemList;
	file.close();
	return 0;
}
