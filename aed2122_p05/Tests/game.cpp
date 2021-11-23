#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

//-----------------------------------------------------------------

// TODO
void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}

// TODO
list<Kid> Game::getKids() const {
    return kids;
}

// TODO
void Game::setKids(const list<Kid>& l1) {
    kids = l1;
}

// TODO
Kid Game::loseGame(string phrase) {
    int n = numberOfWords(phrase);

    int last = 0;
    while (kids.size() > 1) {
        list<Kid>::iterator it = kids.begin();
        int ind = (n + last - 1) % kids.size();
        last = ind;

        if (last == kids.size() - 1) {
            last = 0;
        }

        for (int i = 0; i < ind; i++) {
            it++;
            if (it == kids.end()) {
                it = kids.begin();
                last = 0;
            }
        }
        kids.erase(it);
    }

    Kid k;
    for (auto x: kids) {
        k = x;
    }

    return k;
}

// TODO
list<Kid> Game::removeOlder(unsigned id) {
    list<Kid> removed;

    bool rem = true;
    while (rem) {
        rem = false;
        for (list<Kid>::iterator it = kids.begin(); it != kids.end(); it++) {
            if (it->getAge() > id) {
                removed.push_back(*it);
                kids.erase(it);
                rem = true;
                break;
            }
        }
    }

    return removed;
}

// TODO
queue<Kid> Game::rearrange() {
    list<Kid> k1;
    list<Kid> k2;

    for (auto x : kids) {
        if (x.getSex() == 'm') {
            k1.push_back(x);
        } else {
            k2.push_back(x);
        }
    }

    queue<Kid> q;

    kids.clear();

    if (k2.size() < k1.size()) {
        int p = k1.size() / k2.size();
        while (true) {

            if (k2.size() == 0) break;
            list<Kid>::iterator it = k2.begin();

            for (int i = 0; i < 1; i++) {
                kids.push_back(*it);
                k2.pop_front();
            }

            if (k1.size() < p) break;
            it = k1.begin();
            for (int i = 0; i < p; i++) {
                kids.push_back(*it);
                k1.pop_front();
                it++;

            }
        }
        for (auto x : k1) {
            q.push(x);
        }
    } else  {
        int p = k2.size() / k1.size();
        while (true) {

            if (k1.size() == 0) break;
            list<Kid>::iterator it = k1.begin();

            for (int i = 0; i < 1; i++) {
                kids.push_back(*it);
                k1.pop_front();
            }

            if (k2.size() < p) break;
            it = k2.begin();
            for (int i = 0; i < p; i++) {
                kids.push_back(*it);
                k2.pop_front();
                it++;
            }
        }
        for (auto x : k2) {
            q.push(x);
        }

    }

    return q;
}

// TODO
bool Game::operator==(Game& g2) {
	bool eq = true;

    list<Kid>::iterator it1 = kids.begin();
    list<Kid>::iterator it2 = g2.kids.begin();

    for (int i = 0; i < kids.size(); i++) {
        if (!(*it1 == *it2)) {
            eq = false;
            break;
        }
        it1++;
        it2++;
    }

    return eq;

}

// TODO
list<Kid> Game::shuffle() const {
	list<Kid> newkids;
    list<Kid> temp;
    while (temp.size() > 0) {
        list<Kid>::iterator it = temp.begin();

        for (int i = 0; i < (rand() % temp.size()); i++) {
            it++;
        }

        newkids.push_back(*it);
        temp.erase(it);

    }

    return newkids;
}
