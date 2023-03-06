//
// Created by wld on 05.03.23.
//

#ifndef E_VOTING_DID_H
#define E_VOTING_DID_H

#include <string>
#include <ostream>

//TODO: Implement Syntax rules

struct did {
    std::string method;
    std::string methodSpecifierIdentier;

    friend std::ostream &operator<<(std::ostream &os, const did &did) {
        os << "did:" << did.method << ":" << did.methodSpecifierIdentier;
        return os;
    }
};

#endif //E_VOTING_DID_H
