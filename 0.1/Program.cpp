#include <iostream>
#include "Utility.h"
#include "Processing.h"

using namespace std;

int main(int argc, char *argv[])
{
	// 初始化环境因子数据
	GDALAllRegister();
	EnvDataset *envDataset = new EnvDataset();
	envDataset->Layers.push_back(new EnvLayer(0, "slope", "D:/data/heshan/slp.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(1, "planc", "D:/data/heshan/plan.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(2, "profc", "D:/data/heshan/prof.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(3, "twi", "D:/data/heshan/twi.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->RefreshAll();
	cout<<"read data OK!"<<endl;

	// 开始进行地理处理
	//Processing *processing = new Processing(envDataset);

	for (int i = 0; i < 10; i++)
	{
		cout<<Utility::GetOneRandomEnvUnit(envDataset->EnvUnits)->EnvValues[0];
	}

	//system("pause");
	return 0;
}