//
// Created by wld on 10.03.23.
//

#ifndef E_VOTING_DIDVERIFICATIONMETHOD_H
#define E_VOTING_DIDVERIFICATIONMETHOD_H


#include <ostream>
#include "did.h"

struct didVerificationMethod {
    did id;
    std::string type;
    did controller;
    std::string publicKeyMultibase;

    bool operator<(const didVerificationMethod &rhs) const {
        if (id < rhs.id)
            return true;
        if (rhs.id < id)
            return false;
        if (type < rhs.type)
            return true;
        if (rhs.type < type)
            return false;
        if (controller < rhs.controller)
            return true;
        if (rhs.controller < controller)
            return false;
        return publicKeyMultibase < rhs.publicKeyMultibase;
    }

    bool operator>(const didVerificationMethod &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const didVerificationMethod &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const didVerificationMethod &rhs) const {
        return !(*this < rhs);
    }

    bool operator==(const didVerificationMethod &rhs) const {
        return id == rhs.id &&
               type == rhs.type &&
               controller == rhs.controller &&
               publicKeyMultibase == rhs.publicKeyMultibase;
    }

    bool operator!=(const didVerificationMethod &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const didVerificationMethod &method) {
        os << "{ id: \"" << method.id << "\", type: \"" << method.type << "\", controller: \"" << method.controller
           << "\", publicKeyMultibase: \"" << method.publicKeyMultibase << "\" }";
        return os;
    }
};


#endif //E_VOTING_DIDVERIFICATIONMETHOD_H
