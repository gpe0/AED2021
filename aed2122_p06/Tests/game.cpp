#include "game.h"
#include <cmath>
#include <sstream>

Circle::Circle(int p, bool s): points(p), state(s), nVisits(0) {}

int Circle::getPoints() const {
    return points;
}

bool Circle::getState() const {
    return state;
}

void Circle::changeState() {
    if (state == false)
        state = true;
    else
        state = false;
}

int Circle::getNVisits() const {
    return nVisits;
}

void Circle::incNVisits() {
    nVisits++;
}


BinaryTree<Circle>& Game::getGame() {
    return game;
}


//-----------------------------------------------------------------

BinaryTree<Circle> createTree(int height, vector<int>& points, vector<bool>& states, int index) {
    if (height == 0) {
        return BinaryTree<Circle>(Circle(points[index], states[index]));
    }

    return BinaryTree<Circle>(Circle(points[index], states[index]), createTree(height - 1, points, states, 2 * index + 1), createTree(height - 1, points, states, 2 * index + 2));
}

//TODO
Game::Game(int height, vector<int>& points, vector<bool>& states) {

    game = createTree(height, points, states, 0);

}


//TODO
int Game::play() {

    BTItrLevel<Circle> it(game);
    int ind = 0;
    int index = 0;
    int points;
    while (!it.isAtEnd()) {
        if (ind == index) {
            Circle &c = it.retrieve();

            c.incNVisits();

            if (!c.getState()) {
                index = 2 * ind + 1;
            } else {
                index = 2 * ind + 2;
            }

            c.changeState();

            points = c.getPoints();

        }
        ind++;
        it.advance();
    }

	return points;
}

//TODO
int Game::mostVisited() const {
    BTItrLevel<Circle> it(game);
    it.advance();
    int max = -1;
    while (!it.isAtEnd()) {
        Circle &c = it.retrieve();

        if (c.getNVisits() > max) {
            max = c.getNVisits();
        }

        it.advance();
    }

    return max;
}

