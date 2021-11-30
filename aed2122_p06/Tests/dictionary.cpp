#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "dictionary.h"
#include "binaryTree.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

BST<WordMean> Dictionary::getWords() const {
	return words;
}

// ---------------------------------------------

bool WordMean::operator<(const WordMean& w) const{
    return this->word < w.word;
}

//TODO
void Dictionary::readFile(ifstream &f) {
    string word;
    string meaning;
    while (!f.eof()) {
        getline(f, word);
        getline(f, meaning);
        const WordMean w(word, meaning);
        words.insert(w);
    }
}

//TODO
string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {
    string w = "word not found";
    for (iteratorBST<WordMean> it = words.begin(); it != words.end(); it++) {

        if (word1 < (*it).getWord()) {
            previous = *it;
        }
        if (word1 == (*it).getWord()) {
            w = (*it).getMeaning();
            it++;
            if (it != words.end()) {
                next = *it;
            }
        }

    }

    return w;

}

//TODO
bool Dictionary::update(string word1, string mean1) {
    WordMean w(word1, "");
    WordMean bn = words.find(w);
    if (bn.getWord() != "") {
        WordMean old = bn;
        bn.setMeaning(mean1);
        words.remove(old);
        words.insert(bn);
        return true;
    } else {
        words.insert(WordMean(word1, mean1));
        return false;
    }
}

//TODO
void Dictionary::print() const {

    for (iteratorBST<WordMean> it = words.begin(); it != words.end(); it++) {
        cout << (*it).getWord() << endl;
        cout << (*it).getMeaning() << endl;
    }
}
