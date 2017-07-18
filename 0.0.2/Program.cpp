#include <iostream>
#include "Utility.h"
#include "Processing.h"

using namespace std;

void LoadData_heshan(string dataDir, EnvDataset *envDataset)
{
	envDataset->Layers.push_back(new EnvLayer(0, "slope", dataDir + "slp.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(1, "planc", dataDir + "plan.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(2, "profc", dataDir + "prof.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(3, "twi", dataDir + "twi.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->RefreshAll();
}

void LoadData_raffelson(string dataDir, EnvDataset *envDataset)
{
	envDataset->Layers.push_back(new EnvLayer(0, "bedrock", dataDir + "Bedrock.asc", DataTypeEnum::FACTOR));
	envDataset->Layers.push_back(new EnvLayer(1, "elev", dataDir + "Elevation.asc", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(2, "slope", dataDir + "Slope.asc", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(3, "planc", dataDir + "PlanformCurve.asc", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(4, "profc", dataDir + "ProfileCurve.asc", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(5, "wet", dataDir + "Wet.asc", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(6, "pctg", dataDir + "Pctglmult.asc", DataTypeEnum::SINGLEVALUE));
	envDataset->RefreshAll();
}

int main(int argc, char *argv[])
{
	cout<<"Start!\n";

	// 初始化环境因子数据
	cout<<"\nLoading data ...";
	GDALAllRegister();
	EnvDataset *envDataset = new EnvDataset();
	string dataDir = "../data/heshan/";
	//string dataDir = "../data/raffelson/";
	//LoadData_raffelson(dataDir, envDataset);
	LoadData_heshan(dataDir, envDataset);
	cout<<"\nRead data OK!\n";

	// 开始进行地理处理
	Processing *processing = new Processing(envDataset);


	// final handle
	delete processing;
	processing = NULL;


	cout<<"\n\n----- DONE! -----\n";
	//system("pause");
	return 0;
}