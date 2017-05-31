// ��������

#pragma once

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include "DataTypeEnum.h"
#include "Location.h"
#include "EnvUnit.h"
#include "BasicSetting.h"
#include "Location.h"
#include "EnvDataset.h"
#include "Utility.h"

using namespace std;

class Processing
{
public:
	EnvDataset *EDS;
	//vector<EnvUnit *> SampleEnvUnits;

public:
	Processing(void);
	~Processing(void);
	Processing(EnvDataset *envDataset, vector<EnvUnit *> sampleEnvUnits);
	Processing(EnvDataset *envDataset);

	double CalcSimi_Single(double e1, double e2, double range, DataTypeEnum dataType);
	double CalcSimi(EnvUnit *e1, EnvUnit *e2);											// ��������������Ԫ֮����ۺ����ƶ�
	double CalcUncertainty(vector<EnvUnit *> samples, EnvUnit *e);						// ����ĳһ����Ʋⲻȷ����
	int CalcCanPredictArea(vector<EnvUnit *> samples, double thred_unc);				// ������Ʋ����������ȷ��������ֵ���ڵ�դ������

	void RefreshUncertainty(vector<EnvUnit *> samples);									// ����ÿ�����Ʋ��Ĳ�ȷ����

	EnvUnit* GetLargestGapFillingSample(double threshold_uncertainty);					// �������Ʋ����

};
