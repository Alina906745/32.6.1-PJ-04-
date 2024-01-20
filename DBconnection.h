#pragma once
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

constexpr auto SQL_RETURN_CODE_LEN = 1024;
constexpr auto SQL_RESULT_LEN = 240;

class DBconnection
{
public:
	virtual bool open();
	virtual void close();
	virtual SQLRETURN execQuery(SQLWCHAR* StatementText, SQLINTEGER TextLength);
	virtual bool execTestQuery();
private:
	SQLHANDLE sqlConnHandle{ nullptr }; 
	SQLHANDLE sqlEnvHandle{ nullptr }; 
	SQLHANDLE sqlStmtHandle{ nullptr };  
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN]{}; 
	SQLHSTMT hstmt{ SQL_NULL_HSTMT };  
};