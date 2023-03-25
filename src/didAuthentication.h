//
// Created by wld on 12.03.23.
//

#ifndef E_VOTING_DIDAUTHENTICATION_H
#define E_VOTING_DIDAUTHENTICATION_H


#include <ostream>

struct didAuthentication {
    did id;
    std::string type;
    did controller;
    std::string publicKeyMultibase;

    bool isAuthenticated(){
        if(id.method.empty() && publicKeyMultibase.empty()){
            return false;
        }
        return true;
    }

    friend std::ostream &operator<<(std::ostream &os, const didAuthentication &authentication) {
        os << "{" << (authentication.id.methodSpecifierIdentier.empty() ? "": "\"id\": " + authentication.id.str())
            << (authentication.type.empty() ? "": R"(,"type":")" + authentication.type)
            << (authentication.controller.methodSpecifierIdentier.empty() ? "": (R"(","controller":)") + authentication.controller.str())
            << (authentication.publicKeyMultibase.empty() ? "": R"(,"publicKeyMultibase":")" + authentication.publicKeyMultibase +"\"")
            << "}";
        return os;
    }
};


#endif //E_VOTING_DIDAUTHENTICATION_H
