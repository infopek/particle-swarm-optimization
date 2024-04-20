#include "../stdafx.h"
#include <pso/function_approximation.h>
#include <fstream>

namespace core
{
	FunctionApproximation::FunctionApproximation(const std::vector<ValuePair>& pairs)
		: m_knownValues{ pairs }
	{
	}

	//
	// Basic IO
	//
	void FunctionApproximation::loadKnownValuesFromFile(const std::string& fileName)
	{
		std::ifstream fvalues(fileName);
		ValuePair valuePair{};
		while (fvalues >> valuePair.input >> valuePair.output)
		{
			m_knownValues.push_back(valuePair);
		}
		fvalues.close();
	}

	//
	// Objective functions
	//
	float FunctionApproximation::objective(const std::vector<float>& coefficients) const
	{
		float totalDiff = 0;
		for (const auto& valuepair : m_knownValues)
		{
			float x = valuepair.input;
			float y = coefficients[0] * pow(x - coefficients[1], 3) +
				coefficients[2] * pow(x - coefficients[3], 2) +
				coefficients[4] * x;

			float diff = (float)pow(y - valuepair.output, 2);
			totalDiff += diff;
		}
		return totalDiff;
	}
}
