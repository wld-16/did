//
// Created by wld on 05.03.23.
//

#include "didDocument.h"

std::ostream &operator<<(std::ostream &os, const verificationMethod &method) {
    os << "{\n\tid: " << method.id <<
        ",\n\tcontroller: " << method.controller <<
        ",\n\ttype: " << method.type <<
        ",\n\tpublicKeyMultibase: " << method.publicKeyMultibase << "\n}";
    return os;
}
