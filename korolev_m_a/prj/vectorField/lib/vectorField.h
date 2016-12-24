#ifndef VECTORFIELD_VECTORFIELD_H
#define VECTORFIELD_VECTORFIELD_H

#include <iosfwd>
#include <functional>
#include "style.h"
#include "hsv.h"

class VectorField {
public:
    VectorField() = default;
    const cv::Mat plotByArrows(cv::Mat x, cv::Mat y, const Style& currentStyle, int cellSize = 20);
    const cv::Mat plotByColors(cv::Mat angles, cv::Mat lengths, int cellSize = 1);
    const cv::Mat plotByColors(cv::Mat angles, cv::Mat lengths, std::function<const RGB(double, double, double)> colorTransmitter, int cellSize = 1);
};

const RGB basicColorTransmitter(double lengthOfVector, double angleOfVector, double maxLengthInField);

extern "C" int showGrayscaledWithAName(const CvMat* inpMat, const char* windowName);

#endif //VECTORFIELD_VECTORFIELD_H
