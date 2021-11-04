#include "postOffice.h"
#include <string>

using namespace std;

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}


//--------

// TODO
vector<Mail *> PostOffice::removePostman(string name) {
	vector<Mail *> res;

    for (int i = 0; i < postmen.size(); i++) {
        if(postmen[i].getName() == name) {
            res = postmen[i].getMail();
            postmen.erase(postmen.begin() + i);
            break;
        }
    }

	return res;
}

// TODO
vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {
    balance = 0;
	vector<Mail *> res;

    for (int i = 0; i < mailToSend.size(); i++) {

        RegularMail * regular = dynamic_cast<RegularMail *>(mailToSend[i]);
        GreenMail * green = dynamic_cast<GreenMail *>(mailToSend[i]);
        if (regular != nullptr) {
            balance += regular->getPrice();
        }
        else {
            balance += green->getPrice();
        }

        if (mailToSend[i]->getZipCode() >= firstZipCode && mailToSend[i]->getZipCode() <= lastZipCode) {
            mailToDeliver.push_back(mailToSend[i]);
            mailToSend.erase(mailToSend.begin() + i);
            i--;
        } else {
            res.push_back(mailToSend[i]);
            mailToSend.erase(mailToSend.begin() + i);
            i--;
        }
    }



	return res;
}


Postman PostOffice::addMailToPostman(Mail *m, string name) {
	Postman p1;

    for (int i = 0; i < postmen.size(); i++) {
        if (postmen[i].getName() == name) {
            postmen[i].addMail(m);
            return postmen[i];
        }
    }
    throw NoPostmanException(name);

    return p1;
}

