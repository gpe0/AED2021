#include "mail.h"
#include <string>
#include <iostream>


Mail::Mail(string send, string rec, string zcode):
			sender(send),receiver(rec), zipCode(zcode)
{ }

Mail::~Mail()
{ }

string Mail::getZipCode() const {
	return zipCode;
}


RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w):
			Mail(send, rec, zcode), weight(w)
{ }


GreenMail::GreenMail(string send, string rec, string zcode, string t):
			Mail(send, rec, zcode), type(t)
{ }


//--------

// TODO
unsigned int Mail::getPrice() const {
    return 0;
}

unsigned int RegularMail::getPrice() const {
    unsigned w = this->weight;
    if (w <= 20) {
        return 50;
    } else if (w <= 100) {
        return 75;
    } else if (w <= 500) {
        return 140;
    } else {
        return 325;
    }
}

unsigned int GreenMail::getPrice() const {
    std::string t = this->type;
    if (t == "envelope") {
        return 80;
    } else if (t == "bag") {
        return 200;
    } else if (t == "box"){
        return 240;
    }
}