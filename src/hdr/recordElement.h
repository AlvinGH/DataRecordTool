/************************************
 *@File: recordElemnet.h
 *@Brief: Data Base For Data Record 
 *@Author: Alvin
 *@Date: Sep-30-2018
 *************************************/

#ifndef _DR_RECORD_ELEMENT_BASE_H
#define _DR_RECORD_ELEMENT_BASE_H

#include <string>
#include <map>
#include "recordDataBase"

using namespace std;

namespace dR{

class RecordItem
{

public:
	RecordItem(string name);
	RecordItem(string name, string value);

	virtual ~RecordItem();

private:
	string m_name;
	string m_value;

};

typedef map< string, RecordItem* > RecordItemMap;
typedef RecordItemMap::iterator  RecordItemItr;

class RecordSection
{

public:
	         RecordSection(string name);
	virtual ~RecordSection();

	STATUS addRecord(string name, string value);
	STATUS getRecord(string name, string& value);
	STATUS addItem(RecordSection* section);
	STATUS getItem(string name, RecordSection& RecordSection);

	
private:
	string m_name;
	RecordItemMap m_itemMap;
};

typedef map< string, RecordSection* > RecordSectionMap;
typedef RecordItemMap::iterator  RecordSectionItr;

class RecordTable
{

public:
	 RecordTable(string name);
	~RecordTable();

	  bool isSectionExist(string section);
	STATUS getRecord(string section, string item, string& value);
    STATUS insertRecord(string section, string item, string value);  


protected:
	           string m_name;
	RecordSectionMap  m_sectionMap;
	  recordDataBase* m_dataBase;

	  STATUS insertSection( string section );
};


}


#endif


