#ifndef TRIM_WHITESPACE_ALGORITHM_HPP
#define TRIM_WHITESPACE_ALGORITHM_HPP

#include "Algorithm.hpp"

class TrimWhitespaceAlgorithm : public Algorithm {
	public:
		TrimWhitespaceAlgorithm();
		virtual void process(ImageResolutionQuery& imageResolutionQuery) override;
		virtual ~TrimWhitespaceAlgorithm() = default;

	private:
		void insertMaxParameterConfiguration() {

		}
};


#endif