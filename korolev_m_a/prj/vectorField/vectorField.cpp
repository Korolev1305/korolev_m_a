#include "vectorField.h"

const cv::Mat VectorField::VectorPlot(cv::Mat x, cv::Mat y, cv::Mat image)
{
    cv::Mat res{image};
    int cellLength{(image.rows / x.rows > image.cols / x.cols) ? (image.rows / x.rows) : (image.cols / x.cols)};


    float cellSize{cellLength /2};
    for (int i = 0; i < x.rows; ++i) {
        for (int j = 0; j < x.cols; ++j) {
            CvPoint begin{2*i*cellSize + cellSize , 2*j*cellSize + cellSize};
            CvPoint end{begin.x + x.at<float>(i,j), begin.y + y.at<float>(i,j)};

            cv::arrowedLine(res, begin, end,CV_RGB(0,0,0),1,CV_AA,0);
        }
    }

    return res;
}