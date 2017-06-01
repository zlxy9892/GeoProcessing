#include <iostream>
#include "Utility.h"
#include "Processing.h"


using namespace std;

int main(int argc, char *argv[])
{
	// ��ʼ��������������
	GDALAllRegister();
	string dataDir = "E:/data/heshan/";
	EnvDataset *envDataset = new EnvDataset();
	envDataset->Layers.push_back(new EnvLayer(0, "slope", dataDir + "slp.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(1, "planc", dataDir + "plan.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(2, "profc", dataDir + "prof.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->Layers.push_back(new EnvLayer(3, "twi", dataDir + "twi.tif", DataTypeEnum::SINGLEVALUE));
	envDataset->RefreshAll();
	cout<<"read data OK!"<<endl;

	// ��ʼ���е�����
	//Processing *processing = new Processing(envDataset);

	for (int i = 0; i < 10; i++)
	{
		cout<<Utility::GetOneRandomEnvUnit(envDataset->EnvUnits)->EnvValues[1]<<endl;
		//Utility::GetOneRandomEnvUnit(envDataset->EnvUnits);
	}


	// final handle
	delete envDataset;
	envDataset = NULL;

	//system("pause");
	return 0;
}