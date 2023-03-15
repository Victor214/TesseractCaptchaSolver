#include "Algorithm.hpp"
#include "AlgorithmsParameterEnum.hpp"
#include "Configuration.hpp"

Algorithm::Algorithm(AlgorithmsEnum algoEnum)
	:algorithmEnum{ algoEnum }, successor{nullptr} {

}

void Algorithm::addToHead(std::unique_ptr<Algorithm>& currentHead, std::unique_ptr<Algorithm>& algo) {
	algo->successor = std::move(currentHead);
	currentHead = std::move(algo);
}

void Algorithm::addToTail(std::unique_ptr<Algorithm>& currentHead, std::unique_ptr<Algorithm>& algo) {
	Algorithm* current{ currentHead.get() };
	while (current->successor != nullptr) {
		current = current->successor.get();
	}

	// Current is now last element of linked list
	current->successor = std::move(algo);
}

int Algorithm::getTotalParameterCombinationAmount() const {
	int total{ 1 };
	for (auto const& maxParam : maxParameters) {
		total *= maxParam.second;
	}
	return total;
}

void Algorithm::writeParameters(const int currentParamCount) {
	int divisor{ 1 };
	for (auto const& maxParam : maxParameters) {
		int maxParameterValue{ maxParam.second };
		int parameterValue{ (currentParamCount / divisor) % maxParameterValue };
		parameters.emplace(maxParam.first, parameterValue);
		divisor *= maxParameterValue;
	}
}

std::string Algorithm::getChainDescription() const {
	std::stringstream description;
	const Algorithm* current{ this };
	while (current != nullptr)
	{
		AlgorithmsEnum algoEnum{ current->getAlgorithmEnum() };
		description << algoEnum << ":";
		for (auto param : current->parameters) {
			description << " [" << param.first << ", " << param.second << "]";
		}
		description << "\n";

		current = (current->successor).get();
	}

	return description.str();
}

void Algorithm::process(ImageResolutionQuery& imageResolutionQuery) {
	if (successor != nullptr)
		successor->process(imageResolutionQuery);
}

// Gets & Sets
AlgorithmsEnum Algorithm::getAlgorithmEnum() const {
	return this->algorithmEnum;
}