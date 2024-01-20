#include "task.h"
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "DBconnection.h"
#include "ClassThatUsesDB.h"

using namespace std;

const char* testQuery = "SELECT * FROM users";

class MockDBConnection :
    public DBconnection
{
public:
    MOCK_METHOD(bool, open, (), (override)) {};
    MOCK_METHOD(void, close, (), (override)) {};
    MOCK_METHOD(SQLRETURN, execQuery, (SQLWCHAR* StatementText, SQLINTEGER TextLength), (override)) {};
};

TEST(ClassThatUsesDB, testOpenning)
{
    MockDBConnection connection;
    EXPECT_CALL(connection, open).Times(::testing::AtLeast(1));
    EXPECT_CALL(connection, close).Times(::testing::AtLeast(1));
    ClassThatUsesDB userDB(&connection);
    userDB.openConnection();
}

TEST(ClassThatUsesDB, testUsing)
{
    EXPECT_STRCASEEQ(testQuery, "select * from users");
    MockDBConnection connection;
    EXPECT_CALL(connection, execQuery).Times(::testing::AtLeast(1));
    EXPECT_CALL(connection, close).Times(::testing::AtLeast(1));
    ClassThatUsesDB userDB(&connection);
    userDB.useConnection();
}

TEST(ClassThatUsesDB, testClosing)
{
    MockDBConnection connection;
    EXPECT_CALL(connection, close).Times(::testing::AtLeast(2));
    ClassThatUsesDB userDB(&connection);
    userDB.closeConnection();
}

int main(int argc, char* argv[])
{
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}