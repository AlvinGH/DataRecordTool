/************************************
 *@File: dataRecord.h
 *@Brief: Main Module of Data Record
 		  Module
 *@Author: Alvin
 *@Date: Sep-29-2018
 *************************************/
#ifndef _DR_DATA_RECORD_H
#define _DR_DATA_RECORD_H

#include <stdio.h>
#include <string>

using namespace std;

/*
 *Data Record Module saves data in dataBase (based on readable file).
 *And Recover Data at Start-up. 
 *
 *Data Format:
 * [sectionName]
 *        recordName1 = recordValue1
 *        recordName2 = recordValue2
 * [sectionName2]
 *        recordName3 = recordValue3
 */
#define _DR_OFF_BOARD

typedef bool STATUS;
typedef int INT32;
typedef unsigned int UINT32;

const static STATUS OK = true;
const static STATUS ERROR = false;



namespace dR{

#ifdef _DR_OFF_BOARD

typedef enum level{
	TRACE_0,
	TRACE_5,
	TRACE_10,
};

#define bci_printf(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define trace(level, fmt, ...) printf(fmt, ##__VA_ARGS__)
#define traceForce(fmt, ...) printf(fmt, ##__VA_ARGS__)


#endif

class DataRecord
{
public:
		static DataRecord* m_instance;
		static DataRecord* getInstance();

		STATUS init();

		STATUS saveData(string section, string name, string val);
		STATUS saveData(string section, string name, INT32 val);
		STATUS saveData(string section, string name, UINT32 val);
		STATUS saveData(string section, string name, double val);


		STATUS getData(string section, string name, string& val);
		STATUS getData(string section, string name, INT32& val);
		STATUS getData(string section, string name, UINT32& val);
		STATUS getData(string section, string name, double& val);

	
private:
	DataRecord();
	~DataRecord(){}

	DataRecord(const DataRecord& other);
	DataRecord& operator =(const DataRecord& other);

	
};


}


#endif

