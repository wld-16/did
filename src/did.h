//
// Created by wld on 05.03.23.
//

#ifndef E_VOTING_DID_H
#define E_VOTING_DID_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ostream>
#include <ranges>
#include <utility>
#include <regex>

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
            if(item.find('\"') == item.size() - 1){
                item.pop_back();
            }
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
        os << "did:" << did.method << ":" << did.methodSpecifierIdentier;
        return os;
    }

    static bool validateDID(std::string input){
        // TODO: Fix slash issue
        //const std::regex did_regex("did:[a-z]+:[a-z|A-Z|0-9]+");
        const std::regex did_regex("did:[a-z]+:.+");
        bool found_match = std::regex_match(input, did_regex);
        return found_match;
    }

    [[nodiscard]] std::string str() const {
        std::stringstream sstringstream;
        sstringstream << this;
        return sstringstream.str();
    }
};

struct escapedDid : did {
    escapedDid(const did &id) {
        this->method = id.method;
        this->methodSpecifierIdentier = id.methodSpecifierIdentier;
    }

    friend std::ostream &operator<<(std::ostream &os, const escapedDid &did) {
        os << "\"" << "did:" << did.method << ":" << did.methodSpecifierIdentier << "\"";
        return os;
    }
};

#endif //E_VOTING_DID_H
