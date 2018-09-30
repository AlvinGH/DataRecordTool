/************************************
 *@File: dataRecord.cc
 *@Brief: Main Module For Data Record
 *@Author: Alvin
 *@Date: Sep-29-2018
 *************************************/
#include "dataRecord.h"

using namespace dR;


DataRecord* DataRecord::m_instance = NULL;

DataRecord::DataRecord()
{

}



DataRecord* DataRecord::getInstance()
{
	if ( !m_instance ) m_instance = new DataRecord();

	return m_instance;
}

STATUS DataRecord::init()
{
	return ERROR;
}

STATUS DataRecord::saveData(string& section, string& name, string& val)
{return ERROR;}
STATUS DataRecord::saveData(string& section, string& name, INT32 val)
{return ERROR;}

STATUS DataRecord::saveData(string& section, string& name, UINT32 val)
{return ERROR;}

STATUS DataRecord::saveData(string& section, string& name, double val)
{return ERROR;}



STATUS DataRecord::getData(string& section, string& name, string& val)
{return ERROR;}

STATUS DataRecord::getData(string& section, string& name, INT32& val)
{return ERROR;}

STATUS DataRecord::getData(string& section, string& name, UINT32& val)
{return ERROR;}

STATUS DataRecord::getData(string& section, string& name, double& val)
{return ERROR;}


