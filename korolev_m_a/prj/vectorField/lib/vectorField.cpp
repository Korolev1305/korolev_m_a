#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc.hpp>
#include "vectorField.h"

const cv::Mat VectorField::plotByArrows(cv::Mat x, cv::Mat y, const Style& currentStyle, int cellSize)
{
    if (x.rows != y.rows || x.cols != y.cols)
    {
        throw std::invalid_argument("Matrix's sizes unequal");
    }

    double imageH{cellSize * x.rows};
    double imageW{cellSize * x.cols};

    cv::Mat image = cv::Mat(imageH, imageW, CV_8UC3, currentStyle.getBackgroundColor());
    cv::Mat res{image};

    double halfCellSize{cellSize /2};
    for (int i = 0; i < x.rows; ++i) {
        for (int j = 0; j < x.cols; ++j) {
            CvPoint begin{2*i*halfCellSize + halfCellSize , 2*j*halfCellSize + halfCellSize};
            CvPoint end{begin.x + x.at<double>(i,j), begin.y + y.at<double>(i,j)};

            cv::arrowedLine(res, begin, end, currentStyle.getArrowColor(), currentStyle.getThickness(),CV_AA,0);
        }
    }


    return res;
}

const cv::Mat VectorField::plotByColors(cv::Mat angles, cv::Mat lengths, std::function<const RGB(double, double, double)> colorTransmitter, int cellSize)
{
    double imageH{cellSize * angles.rows};
    double imageW{cellSize * angles.cols};

    cv::Mat image = cv::Mat(imageH, imageW, CV_8UC3);
    cv::Mat res{image};

    double minLength, maxLength;
    cv::minMaxLoc(lengths, &minLength, &maxLength);

    if(minLength < 0)
    {
        throw std::invalid_argument("Length of vector must not be negative");
    }


    for (int i = 0; i < angles.rows; ++i) {
        for (int j = 0; j < angles.rows; ++j) {
            RGB rgb(colorTransmitter(lengths.at<double>(i, j), angles.at<double>(i, j), maxLength));

            CvPoint begin{i*cellSize , j*cellSize};
            CvPoint end{begin.x + cellSize, begin.y + cellSize};

            cv::rectangle(res, begin, end, CV_RGB(rgb.R, rgb.G, rgb.B), CV_FILLED);
        }
    }

    return res;
}

const cv::Mat VectorField::plotByColors(cv::Mat angles, cv::Mat lengths, int cellSize)
{
    double imageH{cellSize * angles.rows};
    double imageW{cellSize * angles.cols};

    cv::Mat image = cv::Mat(imageH, imageW, CV_8UC3);
    cv::Mat res{image};

    cv::Mat HMat(imageH, imageW, cv::DataType<double >::type);
    cv::Mat SMat(imageH, imageW, cv::DataType<double >::type);
    cv::Mat VMat(imageH, imageW, cv::DataType<double >::type);

    double minLength, maxLength;
    cv::minMaxLoc(lengths, &minLength, &maxLength);

    if(minLength < 0)
    {
        throw std::invalid_argument("Length of vector must not be negative");
    }

    for (int i = 0; i < angles.rows; ++i) {
        for (int j = 0; j < angles.rows; ++j) {
            HMat.at<double>(i, j) = fmod((angles.at<double>(i, j) * 180 / CV_PI), 360);
        }
    }

    for (int i = 0; i < angles.rows; ++i) {
        for (int j = 0; j < angles.rows; ++j) {
            SMat.at<double>(i, j) = (lengths.at<double>(i, j) * cos(angles.at<double>(i, j)) / maxLength) * 100;
            VMat.at<double>(i, j) = (lengths.at<double>(i, j) * sin(angles.at<double>(i, j)) / maxLength) * 100;
        }
    }

    for (int i = 0; i < angles.rows; ++i) {
        for (int j = 0; j < angles.rows; ++j) {
            HSV hsv(HMat.at<double>(i, j), SMat.at<double>(i, j), VMat.at<double>(i, j));
            RGB rgb(HSVToRGB(hsv));

            CvPoint begin{i*cellSize , j*cellSize};
            CvPoint end{begin.x + cellSize, begin.y + cellSize};

            cv::rectangle(res, begin, end, CV_RGB(rgb.R, rgb.G, rgb.B), CV_FILLED);
        }
    }

    return res;
}

const RGB basicColorTransmitter(double lengthOfVector, double angleOfVector, double maxLengthInField)
{
    double H, S, V;
    H = fmod((angleOfVector * 180 / CV_PI), 360);
    S = abs(lengthOfVector * cos(angleOfVector) / maxLengthInField * 100);
    V =  abs((lengthOfVector * sin(angleOfVector)) / maxLengthInField * 100);

    HSV hsv(H, S, V);

    RGB res = HSVToRGB(hsv);
    return res;
}

int showGrayscaledWithAName(const CvMat* inpMat, const char* windowName)
{
    try {
        using namespace cv;

        cv::Mat greyMat;
        cv::Mat colorMat(inpMat);
        std::string winName{windowName};

        cv::cvtColor(colorMat, greyMat, CV_BGR2GRAY);

        namedWindow( winName, WINDOW_AUTOSIZE );
        imshow( winName, greyMat);
        waitKey(0);

        return 0;

    } catch (const std::exception& ex) {
        return -1;
    }
}
