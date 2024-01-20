#pragma once
#include "DBconnection.h"
class ClassThatUsesDB
{
public:
    ClassThatUsesDB(DBconnection* connection);
    ~ClassThatUsesDB();
    bool openConnection();
    bool useConnection();
    void closeConnection();
private:
    DBconnection* conn;
};
