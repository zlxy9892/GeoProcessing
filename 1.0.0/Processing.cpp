#include "Processing.h"


Processing::Processing(void)
{
}

Processing::Processing(EnvDataset *envDataset, vector<EnvUnit *> sampleEnvUnits)
{
	this->EDS = envDataset;
}

Processing::Processing(EnvDataset *envDataset)
{
	this->EDS = envDataset;
}

Processing::~Processing(void)
{
	if (this->EDS != NULL)
	{
		delete this->EDS;
		this->EDS = NULL;
	}
}

double Processing::CalcSimi_Single(double e1, double e2, double range, DataTypeEnum dataType)
{
	double simi = -1;
	if (dataType == FACTOR)
	{
		if (e1 == e2)
		{
			simi = 1;
		}
		else
		{
			simi = 0;
		}
	}
	else if (dataType == SINGLEVALUE)
	{
		simi = 1 - abs(e1 - e2) / range;
	}
	return simi;
}

double Processing::CalcSimi(EnvUnit *e1, EnvUnit *e2)
{
	double simi = -1;
	if (!e1->IsCal || !e2->IsCal)
	{
		return -1;	// 不参与计算的点
	}
	if (e1->EnvValues.size() == e2->EnvValues.size())
	{
		simi = 1;
		for (int i = 0; i < e1->EnvValues.size(); i++)
		{
			double range = this->EDS->Layers.at(i)->Data_Range;
			DataTypeEnum dataType = e1->DataTypes.at(i);
			double simi_temp = this->CalcSimi_Single(e1->EnvValues.at(i), e2->EnvValues.at(i), range, dataType);
			if (simi_temp < simi)
			{
				simi = simi_temp;
			}
		}
		return simi;
	}
	else
	{
		return -1;
	}
}

double Processing::CalcUncertainty(vector<EnvUnit *> samples, EnvUnit *e)
{
	double simi = 0;
	for (int i = 0; i < samples.size(); ++i)
	{
		EnvUnit *se = samples[i];
		double simi_temp = this->CalcSimi(se, e);
		if (simi < simi_temp)
		{
			simi = simi_temp;
		}
	}
	return 1-simi;
}

int Processing::CalcCanPredictArea(double thred_unc)
{
	int area = 0;
	int count = this->EDS->EnvUnits.size();
	for (int i = 0; i < count; ++i)
	{
		EnvUnit *e = this->EDS->EnvUnits[i];
		if (e->IsCal && e->Uncertainty <= thred_unc)
		{
			area++;
		}
	}
	return area;
}

void Processing::RefreshUncertainty( vector<EnvUnit *> samples )
{
	int count = this->EDS->EnvUnits.size();
	for (int i = 0; i < count; ++i)
	{
		EnvUnit *e = this->EDS->EnvUnits[i];
		if (e->IsCal)
		{
			e->Uncertainty = this->CalcUncertainty(samples, e);
		}
		/*else
		{
			e->Uncertainty = 1;
		}*/
	}
}

double Processing::CalcUncertainty_Sum()
{
	double unc_sum = 0;

	int count = this->EDS->EnvUnits.size();
	for (int i = 0; i < count; ++i)
	{
		EnvUnit *e = this->EDS->EnvUnits[i];
		if (e->IsCal)
		{
			unc_sum += e->Uncertainty;
		}
	}

	return unc_sum;
}

double Processing::ObjectFunction( vector<EnvUnit *> samples )
{
	double o = 0;

	double canPreArea = this->CalcCanPredictArea(0.2);
	double totalArea = this->EDS->CalcArea;

	double unc_sum = this->CalcUncertainty_Sum();

	double o1 = 1.0*canPreArea/totalArea;
	double o2 = 1.0*unc_sum/totalArea;

	cout<<o1<<"\t"<<o2<<"\n";

	return o;
}
