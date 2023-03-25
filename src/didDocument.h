//
// Created by wld on 05.03.23.
//

#ifndef E_VOTING_DIDDOCUMENT_H
#define E_VOTING_DIDDOCUMENT_H


#include <sstream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ostream>
#include "did.h"
#include "didVerificationMethod.h"
#include "didAuthentication.h"

struct didService {
    did id;
    std::set<std::string> type;
    std::string serviceEndpoint;

    friend std::ostream &operator<<(std::ostream &os, const didService &service) {
        std::stringstream types_stream;

        types_stream << "[";
        std::for_each(service.type.begin(), service.type.end(), [&types_stream, service](std::string type){
            types_stream  << "\"" << type << "\"";
            if(*service.type.rbegin() != type){
                types_stream << ",";
            }
        });
        types_stream << "]";

        os << "{"
            << (service.id.methodSpecifierIdentier.empty() ? "": "\"id\":" + service.id.str() +",")
            << (service.type.empty() ? "": "\"type\":" + types_stream.str() + ",")
            << (service.serviceEndpoint.empty() ? "": R"("serviceEndpoint":")" + service.serviceEndpoint + "\"");
        os << "}";
        return os;
    };
};

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
    std::set<std::string> also_known_as = {};
    did controller;
    std::set<did> controllers = {};
    didAuthentication authentication;
    std::set<didVerificationMethod> verification_method;
    std::set<didService> service;

    std::string aliasesAsString(){
        std::stringstream aliases_string;
        aliases_string << "[";
        std::for_each(also_known_as.begin(), also_known_as.end(), [&aliases_string, this](std::string alias){
            aliases_string <<  alias;
            if(also_known_as.rbegin()->data() != alias.data()){
                aliases_string << ",";
            }
        });
        aliases_string << "]";
        return aliases_string.str();
    }

    std::string serviceAsString(){
        std::stringstream service_stream;
        service_stream << "[";
        std::for_each(service.begin(), service.end(), [&service_stream, this](didService service_element){
            service_stream << service_element;
            if(service.rbegin()->id != service_element.id){
                service_stream << ",";
            }
        });
        service_stream << "]";
        return service_stream.str();
    }

    std::string verificationMethodAsString(){
        std::stringstream verification_method_stream;
        verification_method_stream << "[";
        verification_method_stream;
        std::for_each(verification_method.begin(), verification_method.end(), [&verification_method_stream, this](didVerificationMethod method){
            verification_method_stream << "{"
                << "\"id\":" << method.id << ","
                << "\"type\":" << method.type << ","
                << "\"controller\":" << method.controller << ","
                << "\"publicKeyMultibase\":" << method.publicKeyMultibase << "}";
            if(verification_method.rbegin()->id != method.id){
                verification_method_stream << ",";
            }
        });
        verification_method_stream << "]";
        return verification_method_stream.str();
    }

    std::string controllersAsString(){
        std::stringstream sstream;
        sstream << "[";
        std::for_each(controllers.begin(), controllers.end(), [&sstream, this](did _controller){
            sstream << _controller;
            if(*controllers.rbegin() != _controller){
                sstream << ",";
            }
        });
        sstream << "]";
        return sstream.str();
    }

    friend std::ostream &operator<<(std::ostream &os, didDocument document) {
        os << "{"
           << "\"id\":" << document.id << ","
           << (document.also_known_as.empty() ? "" :  "\"aliases\":" + document.aliasesAsString() + ",")
           << (document.controllers.empty() ? "" :"\"controllers\":" + document.controllersAsString() + ",")
           << "\"authentication\":" << document.authentication << ","
           << "\"verificationMethod\":" << document.verificationMethodAsString()
           << (document.service.empty() ? "": ",\"service\":[" + document.serviceAsString() + "]")
           << "}";
        return os;
    }
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


#endif //E_VOTING_DIDDOCUMENT_H
