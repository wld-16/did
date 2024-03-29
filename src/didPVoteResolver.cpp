//
// Created by wld on 05.03.23.
//

#include "didPVoteResolver.h"

didResolution didPVoteResolver::resolve(did identifier, didResolutionOptions resolutionOptions) {
    if(identifier.methodSpecifierIdentier.starts_with("node")) {
        // Verify whether node exists or create document
    }
    return didResolution{
        {},
        {did("::"),{},did("::"),{},{did(""),"",did(""),""}, {},{}},
        {"","",false,"","","", {},did("::")}};
}

didByteStreamResolution
didPVoteResolver::resolveRepresentation(did identifier, didResolutionOptions resolutionOptions) {
    const didByteStreamResolution &resolution = didByteStreamResolution{
        {},
        {},
        {"","",false,"", ", ", "", std::set<did>{},did("")}};
    return resolution;
}

didDereference didPVoteResolver::dereference(std::string didUrl, didDereferenceOptions dereferenceOptions) {
    //derefOptions is required, but structure may be empty

    //derefMetadata is required
    //derefMetadata must not be empty in case of error

    //contentStream must contain a resource corresponding to the did url
    //contentMetadata must be a metadata structure, but structure may be empty
    return didDereference();
}
