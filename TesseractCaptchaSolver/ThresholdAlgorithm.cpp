#include <memory>
#include "ThresholdAlgorithm.hpp"

ThresholdAlgorithm::ThresholdAlgorithm()
	:Algorithm{ AlgorithmsEnum::THRESHOLD } {
	insertMaxParameterConfiguration();
}

void ThresholdAlgorithm::process(ImageResolutionQuery& imageResolutionQuery) {
	//Apply threshold
	cv::Mat& image{ *(imageResolutionQuery.image) };
	double threshold{ rangeCutoff + (this->parameters[AlgorithmsParameterEnum::THRESHOLDVALUE] * (255 - rangeCutoff * 2)) / (this->maxParameters[AlgorithmsParameterEnum::THRESHOLDVALUE] - 1.0) };
	cv::threshold(image, image, threshold, 255, cv::THRESH_BINARY);
	//cv::imshow("Threshold", image);
	//cv::waitKey(0);

	Algorithm::process(imageResolutionQuery);
}