//
// Created by wld on 05.03.23.
//

#ifndef E_VOTING_DIDPVOTERESOLVER_H
#define E_VOTING_DIDPVOTERESOLVER_H


#include <string>
#include <nlohmann/json.hpp>
#include "didDocument.h"

struct didResolutionOptions {
    std::string accept;
    // Examples include:
    //  application/did+ld+json
    //  application/did+json
};

struct didResolutionMetadata {
    std::string content_type;
    std::string error; //invalidDid, notFound, representationNotSupported
};


struct didResolution {
    didResolutionMetadata resolution_metadata;
    didDocument document;
    didDocumentMetadata document_metadata;
};

struct didByteStreamResolution {
    didResolutionMetadata resolution_metadata;
    didDocumentStream document_stream;
    didDocumentMetadata document_metadata;
};

struct contentMetadata{

};

struct dereferencingMetadata{
    std::string content_type;
    std::string error; //invalidDidUrl, notFound
};

struct didDereference {
    dereferencingMetadata dereferencing_metadata;
    std::string content_stream;
    contentMetadata content_metadata;
};

struct didDereferenceOptions {
    std::string accept;
    // Examples include:
    //  application/did+ld+json
    //  application/did+json
};

class didPVoteResolver {

public:
    didResolution resolve(did identifier,
                           didResolutionOptions resolutionOptions);
    didByteStreamResolution resolveRepresentation(did identifier,
                                                  didResolutionOptions resolutionOptions);
    didDereference dereference(std::string didUrl, didDereferenceOptions dereferenceOptions);
};




#endif //E_VOTING_DIDPVOTERESOLVER_H
