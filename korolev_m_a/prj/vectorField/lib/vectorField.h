#ifndef VECTORFIELD_VECTORFIELD_H
#define VECTORFIELD_VECTORFIELD_H

#include <iosfwd>
#include "style.h"

class VectorField {
public:
    VectorField() = default;
    const cv::Mat plotByArrows(cv::Mat x, cv::Mat y, const Style& currentStyle, int cellSize = 20);
    const cv::Mat plotByColors(cv::Mat angles, cv::Mat lengths, int cellSize = 1);
};


#endif //VECTORFIELD_VECTORFIELD_H
