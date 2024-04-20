#pragma once

#include <string>
#include <vector>

namespace core
{
	class ValuePair
	{
	public:
		float input;
		float output;
	};

	class FunctionApproximation
	{
	public:
		FunctionApproximation(const std::vector<ValuePair>& pairs);

		float objective(const std::vector<float>& coefficients) const;
		void loadKnownValuesFromFile(const std::string& fileName);

		inline const std::vector<ValuePair>& getData() const { return m_knownValues; }

	private:
		std::vector<ValuePair> m_knownValues{};
	};
}
