#ifndef _UTILITY_H_
#define _UTILITY_H_


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "EnvUnit.h"
#include "EnvDataset.h"
#include "boost/random.hpp"

using namespace std;


static boost::random::mt19937 rng(time(0));	// 随机种子

class Utility
{
public:

	Utility(void);
	~Utility(void);

	static string ConvertToString(double value);
	static void ParseStr(string str, char c, vector<string>& tokens);	// 解析以c为分隔符的数据
	static vector<EnvUnit *> ReadCSV(string filename, EnvDataset *envDataset);
	static vector<EnvUnit *> ReadCSV(string filename, EnvDataset *envDataset, string targetV, string idName);	// 包含读取目标土壤属性信息和ID号
	static void WriteCSV(string filename, vector<EnvUnit *> envUnits);
	static void WriteCSV2(string filename, vector<EnvUnit *> envUnits, vector<int> predictedAreaList);

	static void WriteCSV_Temp(string filename, vector<EnvUnit *> envUnits);

	static EnvUnit* GetOneRandomEnvUnit(vector<EnvUnit *> envUnits);		// 获取一个随机的环境单元(栅格)
};

#endif