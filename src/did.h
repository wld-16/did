//
// Created by wld on 05.03.23.
//

#ifndef E_VOTING_DID_H
#define E_VOTING_DID_H

#include <sstream>
#include <string>
#include <vector>
#include <ostream>
#include <ranges>
#include <utility>

//TODO: Implement Syntax rules

struct did {
    std::string method;
    std::string methodSpecifierIdentier;

    did()= default;

    did(std::string method, std::string methodSpecifierIdentier) : method(std::move(method)),
                                                                                 methodSpecifierIdentier(std::move(
                                                                                         methodSpecifierIdentier)) {}

    explicit did(const std::string& did_str) {
        std::vector<std::string> result;
        std::stringstream ss (did_str);
        std::string item;

        while (getline (ss, item, ':')) {
            result.push_back (item);
        }
        method = result[1];
        methodSpecifierIdentier = result[2];
    }

    bool operator==(const did &rhs) const {
        return method == rhs.method &&
               methodSpecifierIdentier == rhs.methodSpecifierIdentier;
    }

    bool operator!=(const did &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const did &rhs) const {
        if (method < rhs.method)
            return true;
        if (rhs.method < method)
            return false;
        return methodSpecifierIdentier < rhs.methodSpecifierIdentier;
    }

    bool operator>(const did &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const did &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const did &rhs) const {
        return !(*this < rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const did &did) {
        os << "\"did:" << did.method << ":" << did.methodSpecifierIdentier << "\"";
        return os;
    }
};

#endif //E_VOTING_DID_H
