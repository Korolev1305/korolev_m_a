#include "../lib/vectorField.h"

using namespace cv;
using namespace std;


const RGB anotherColorTransmitter(double lengthOfVector, double angleOfVector, double maxLengthInField)
{
    double H, S, V;
    H = 240;
    S = (lengthOfVector * cos(angleOfVector) / maxLengthInField * 100);
    V =  (lengthOfVector * sin(angleOfVector)) / maxLengthInField * 100;

    HSV hsv(H, S, V);

    RGB res = HSVToRGB(hsv);
    return res;
}

int main()
{
    VectorField vectorField;
    const int xSizeArrows{45};
    const int ySizeArrows{xSizeArrows};

    const int xSizeColor{900};
    const int ySizeColor{xSizeColor};


    Mat arrX(xSizeArrows, ySizeArrows, DataType<double >::type);
    Mat arrY(xSizeArrows, ySizeArrows, DataType<double>::type);

    Mat colorL(xSizeColor, ySizeColor, DataType<double >::type);
    Mat colorFi(xSizeColor, ySizeColor, DataType<double>::type);

    Style myStyle;

    myStyle.setArrowColor(CV_RGB(144, 123, 187));

    for (int i = 0; i < xSizeArrows; ++i) {
        for (int j = 0; j < ySizeArrows; ++j) {
            double x = (i-xSizeArrows/2);
            double y = (j-ySizeArrows/2);

            arrX.at<double>(i,j) = abs(x);
            arrY.at<double>(i,j) = y;
        }
    }

    for (int i = 0; i < ySizeColor; ++i) {
        for (int j = 0; j < ySizeColor; ++j) {
            double x = (i-xSizeColor/2);
            double y = (j-ySizeColor/2);

            double l = (sqrt(x*x + y*y));
            double fi = atan(y/x);

            colorL.at<double>(i,j) = l;
            colorFi.at<double>(i,j) = 2*fi + CV_PI;
        }
    }

    namedWindow( "Arrows window", WINDOW_AUTOSIZE );
    imshow( "Arrows window", vectorField.plotByArrows(arrY, arrX, myStyle) );

    namedWindow( "Basic color transmittion", WINDOW_AUTOSIZE );
    imshow( "Basic color transmittion", vectorField.plotByColors(colorFi, colorL) );

    namedWindow( "Another color transmittion", WINDOW_AUTOSIZE );
    imshow( "Another color transmittion", vectorField.plotByColors(colorFi, colorL, &anotherColorTransmitter) );

    bool externFResul = saveExampleVectorFieldMap("C:\\out.jpeg", 900);

    waitKey(0);
    return 0;
}

