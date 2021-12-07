// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2012]

#include "funWithBSTs.h"
#include "bst.h"
#include <map>
#include <set>
#include <list>

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------
// TODO
int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {

    map<int, int> c;

    for (auto x : collection) {
        if (c.find(x) == c.end()) {
            c[x] = 0;
        }
    }

    for (auto x : bag) {
        if (c.find(x) == c.end()) {
            c[x] = 1;
        }
    }

    int count = 0;

    for (auto ele : c) {
        count += ele.second;
    }

    return count;
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------
// TODO
int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {

    multiset<int> sA;
    multiset<int> sB;

    for (int card : alice) {
        sA.insert(card);
    }

    for (int card : bruno) {
        sB.insert(card);
    }

    int maxA;
    int maxB;
    while (!sA.empty() && !sB.empty()) {
        auto it1 = --sA.end();
        maxA = (*it1);
        auto it2 = --sB.end();
        maxB = (*it2);

        if (maxA > maxB) {
            sB.erase(it2);
            sA.erase(it1);
            sA.insert(maxA - maxB);
        } else if (maxA < maxB) {
            sB.erase(it2);
            sA.erase(it1);
            sB.insert(maxB - maxA);
        }
        else {
            sB.erase(it2);
            sA.erase(it1);
        }
    }
    if (sA.empty() && sB.empty()) {
        return 0;
    } else if (sA.empty()) {
        return (-1) * sB.size();
    } else {
        return sA.size();
    }


}

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// ..............................
// a) Contando Filmes
// TODO
int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
    set<string> s;
    for (auto x : reviews) {
        s.insert(x.first);
    }
    return s.size();
}

// ..............................
// b) O filme com mais reviews
// TODO
void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
    map<string, int> map;

    string currentM = "";
    m = 0;
    n = 0;

    for (auto x: reviews) {
        if (map.find(x.first) != map.end()) {
            map[x.first]++;
        } else {
            map[x.first] = 1;
        }
    }

    for (auto x : map) {
        if (x.second > m) {
            m = x.second;
            n = 1;
        } else if (x.second == m) {
            n++;
        }
    }
}

// ..............................
// c) Os melhores filmes
// TODO
vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    map<string, list<int>> map;

    for (auto x: reviews) {
        map[x.first].push_back(x.second);
    }
    return answer;
}
