//
// Created by wld on 05.03.23.
//

#include <sstream>
#include "didDocument.h"

std::ostream &operator<<(std::ostream &os, const verificationMethod &method) {
    os << "{id:" << method.id <<
        ",controller:" << method.controller <<
        ",type:" << method.type <<
        ",publicKeyMultibase:" << method.publicKeyMultibase << "}";
    return os;
}
