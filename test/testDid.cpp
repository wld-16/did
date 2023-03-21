//
// Created by wld on 14.03.23.
//

#include "gtest/gtest.h"
#include "../src/did.h"

TEST(did, constructorFromString) {
    std::string didUrl = "did:pvote:abyye";
    did id = did(didUrl);
    std::cout << id.method << std::endl;
    std::cout << id.methodSpecifierIdentier << std::endl;

    ASSERT_EQ(id.method, "pvote");
    ASSERT_EQ(id.methodSpecifierIdentier, "abyye");
}