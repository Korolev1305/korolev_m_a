#ifndef VECTORFIELD_VECTORFIELD_H
#define VECTORFIELD_VECTORFIELD_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

class VectorField {
public:
    VectorField() = default;
    const cv::Mat VectorPlot(cv::Mat x, cv::Mat y, cv::Mat image);
};


#endif //VECTORFIELD_VECTORFIELD_H
