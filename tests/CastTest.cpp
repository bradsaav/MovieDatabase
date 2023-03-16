#include "gtest/gtest.h"
#include "../header/CastList.hpp"
#include "../header/CastMember.hpp"
#include <sstream>

TEST (CastTests, testCastMemberConstructor) {
	 CastMember m = CastMember("John Doe", 25);
     EXPECT_TRUE(m.get_name() == "John Doe");
     EXPECT_EQ(m.get_age() , 25);
}

TEST(CastTests, testCastListConstructor) {
    CastList cast; 
    EXPECT_TRUE(cast.getCastList().empty());
}

TEST(CastTests, testAddMembers) {
    CastList my_cast;
    CastMember member1("Morgan Freeman" , 56);
    CastMember member2("James Bond" , 67);
    my_cast.addCastMember(member1);
    my_cast.addCastMember(member2);

    std::stringstream output;
    std::streambuf* old_cout_buf = std::cout.rdbuf(output.rdbuf());
    my_cast.print_cast();
    std::cout.rdbuf(old_cout_buf);

    std::string expected_output = "Morgan Freeman\nJames Bond\n";
    EXPECT_EQ(expected_output, output.str());
}

TEST(CastTests, testGetSize) {
    CastList my_cast;
    CastMember member1("Actor1" , 36);
    CastMember member2("Actor2" , 35);
    my_cast.addCastMember(member1);
    my_cast.addCastMember(member2);

    EXPECT_EQ(my_cast.get_size(), 2);
}

TEST(CastListTest, DeleteCastMember) {
    CastList my_cast;
    CastMember member1("Actor1" , 27);
    CastMember member2("Actor2" , 24);
    my_cast.addCastMember(member1);
    my_cast.addCastMember(member2);

    my_cast.deleteCastMember("Actor1");

    bool found_member1 = false;
    bool found_member2 = false;

    for (auto& member : my_cast.getCastList()) {
        if (member.get_name() == "Actor1") {
            found_member1 = true;
        } else if (member.get_name() == "Actor2") {
            found_member2 = true;
        }
    }

    EXPECT_FALSE(found_member1);
    EXPECT_TRUE(found_member2);
}

TEST(CastTests, testGetCastMember) {
    CastList my_cast;
    CastMember member1("Dave Chapel" , 36);
    CastMember member2("Mat Franco" , 17);
    my_cast.addCastMember(member1);
    my_cast.addCastMember(member2);

    CastMember retrieved_member = my_cast.get_CastMember(1);
    EXPECT_EQ(retrieved_member.get_name(), "Mat Franco");
}