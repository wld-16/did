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

TEST(did, test_validateFormat) {
    bool resultTrue = did::validateDID("did:pvote:123controller");
    bool resultFalse = did::validateDID("did:123");
    bool resultFalse2 = did::validateDID("\"did:pvote:123BUZBLWG6V/FAy8ViyB7YP7G4quJrV7sawA1e3ceYrA8=/Wd5H6/xXeXhqTp/3zptVO3f+s55O2O4UKwQ4R08nPg=k4B0rGVAHowi6ga12b3MnERQsxGwgMkpruMuBHY/a/Q=\"");
    bool resultTrue2 = did::validateDID("did:pvote:123BUZBLWG6V/FAy8ViyB7YP7G4quJrV7sawA1e3ceYrA8=/Wd5H6/xXeXhqTp/3zptVO3f+s55O2O4UKwQ4R08nPg=k4B0rGVAHowi6ga12b3MnERQsxGwgMkpruMuBHY/a/Q=");
    ASSERT_TRUE(resultTrue);
    ASSERT_TRUE(resultTrue2);
    ASSERT_FALSE(resultFalse);
    ASSERT_FALSE(resultFalse2);
}