//
// Created by Максим on 12.12.2016.
//

#ifndef VECTORFIELD_STYLE_H
#define VECTORFIELD_STYLE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class Style {
public:
    Style() = default;

    Style(int thickness, const cv::Scalar &arrowColor, const cv::Scalar &backgroundColor, float celSize) :
            thickness(thickness),
            arrowColor(arrowColor),
            backgroundColor(backgroundColor){}

    int getThickness() const {
        return thickness;
    }

    void setThickness(int thickness) {
        Style::thickness = thickness;
    }

    const cv::Scalar &getArrowColor() const {
        return arrowColor;
    }

    void setArrowColor(const cv::Scalar &arrowColor) {
        Style::arrowColor = arrowColor;
    }

    const cv::Scalar &getBackgroundColor() const {
        return backgroundColor;
    }

    void setBackgroundColor(const cv::Scalar &backgroundColor) {
        Style::backgroundColor = backgroundColor;
    }

private:
    int thickness{1};
    cv::Scalar arrowColor{CV_RGB(0,0,0)};
    cv::Scalar backgroundColor{CV_RGB(0xFF, 0xFF, 0xFF)};

};


#endif //VECTORFIELD_STYLE_H
