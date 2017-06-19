#include <iostream>
#include "Utility.h"
#include "Processing.h"
#include "Windows.h"

using namespace std;

int main(int argc, char *argv[])
{
	LARGE_INTEGER freq, start, end;
	QueryPerformanceFrequency(&freq);

	// 初始化环境因子数据
	GDALAllRegister();
	string dataDir = "../data/heshan/";
	EnvDataset *envDataset = new EnvDataset();
	envDataset->Layers.push_back(new EnvLayer(0, "slope", dataDir + "slp.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(1, "planc", dataDir + "plan.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(2, "profc", dataDir + "prof.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(3, "twi", dataDir + "twi.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->RefreshAll();
	cout<<"read data OK!"<<endl;

	// 开始进行地理处理
	Processing *processing = new Processing(envDataset);

	processing->RefreshDensity(0.8);
	processing->RefreshDSimi();

	Utility::WriteCSV_Temp("E:/output.csv", envDataset->EnvUnits);


	// final handle
	delete processing;
	processing = NULL;

	//system("pause");
	return 0;
}