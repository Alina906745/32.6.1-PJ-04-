#include "ClassThatUsesDB.h"


ClassThatUsesDB::ClassThatUsesDB(DBconnection* connection) : conn(connection)
{
}

ClassThatUsesDB::~ClassThatUsesDB()
{
	closeConnection();
}

bool ClassThatUsesDB::openConnection()
{
	return conn->open();
}

bool ClassThatUsesDB::useConnection()
{
	return conn->execTestQuery();
}

void ClassThatUsesDB::closeConnection()
{
	conn->close();
}