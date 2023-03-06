//
// Created by wld on 05.03.23.
//

#include "didPvoteResolver.h"

didResolution didPVoteResolver::resolve(did identifier, didResolutionOptions resolutionOptions) {
    return didResolution();
}

didByteStreamResolution
didPVoteResolver::resolveRepresentation(did identifier, didResolutionOptions resolutionOptions) {
    return didByteStreamResolution();
}

didDereference didPVoteResolver::dereference(std::string didUrl, didDereferenceOptions dereferenceOptions) {
    //derefOptions is required, but structure may be empty

    //derefMetadata is required
    //derefMetadata must not be empty in case of error

    //contentStream must contain a resource corresponding to the did url
    //contentMetadata must be a metadata structure, but structure may be empty
    return didDereference();
}
