/************************************
 *@File: recordElemnet.cc
 *@Brief: Data Base For Data Record 
 *@Author: Alvin
 *@Date: Sep-30-2018
 *************************************/

#include "recordElement.h"

using namespace dR;


RecordTable::RecordTable(string name):m_name(name)
{

}

RecordTable::~RecordTable()
{
	RecordSectionItr itr = m_sectionMap.begin();

	for (; itr != m_sectionMap.end(); itr++){
		if ( itr->second ){
			delete itr->second;
			itr->second = NULL;
		}

	}

	m_sectionMap.clear();
}

bool RecordTable::isSectionExist(string section)
{
	bool isExist = false;
	RecordItemItr itr = m_sectionMap.find( section );

	if ( itr == m_sectionMap.end() ) isExist = false;

	else if ( NULL == itr->second ) isExist = false;

	else isExist = true;

	return isExist;
}

STATUS RecordTable::insertSection( string section )
{
	if (isSectionExist(section)){
		traceForce("ERR[%s]: section %s is Exist!\n", __func__, section.c_str());
		return ERROR;
	}

	RecordSection* tmpSct = new RecordSection(section);

	if ( !tmpSct ){
		traceForce("ERR[%s]: new section %s Failed!\n", __func__, section.c_str());
		return ERROR;
	}

	m_sectionMap[section] = tmpSct;

	return OK;

	
}


STATUS RecordTable::insertRecord(string section, string item, string value)
{
	if ( isSectionExist( section ) ){
		return	m_sectionMap[section]->addRecord(item, value);
	}
	else{
		
		if( OK != insertSection(string section) ){
			traceForce("ERR[%s]: insert Setction %s Failed!\n", __func__, section);
			return ERROR;
		}

		return	m_sectionMap[section]->addRecord(item, value);
	}
}


STATUS RecordTable::getRecord(string section, string item, string& value)
{
	if ( isSectionExist( section ) )
		return	m_sectionMap[section]->getItem(item, value);
	else{
		trace(TRACE_5, "WARN[%s]: get record failed!, %s.%s\n", __func__, section.c_str(), item.c_str());
		return ERROR;
	}
}





