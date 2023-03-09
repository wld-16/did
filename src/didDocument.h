//
// Created by wld on 05.03.23.
//

#ifndef E_VOTING_DIDDOCUMENT_H
#define E_VOTING_DIDDOCUMENT_H


#include <string>
#include <set>
#include <map>
#include <ostream>
#include "did.h"

struct didDocumentMetadata {
    std::string created; //YYYY-MM-DDThh:mm:ssZ
    std::string updated; //YYYY-MM-DDThh:mm:ssZ
    bool deactivated;
    std::string next_update; //YYYY-MM-DDThh:mm:ssZ
    std::string version_id;
    std::string nextVersion_id;
    std::set<did> equivalent_id;
    did canonical_id;
};

struct didDocument {
    did id; // is required
    std::set<std::string> also_known_as;
    did controller;
    std::set<did> controllers;
    std::string authentication;
    std::string verification_method;
    std::string service;
    std::string service_endpoint;
};

struct didDocumentStream {
    std::string stream;
};

struct verificationMethod {
    did id;
    did controller;
    std::string type;
    //std::map<std::string, std::string> publicKeyJwk; // Check RFC7517
    std::string publicKeyMultibase;

    friend std::ostream &operator<<(std::ostream &os, const verificationMethod &method);
};

struct service {
    std::string id;
    std::set<std::string> type;
    std::string serviceEndpoint;
};


#endif //E_VOTING_DIDDOCUMENT_H
