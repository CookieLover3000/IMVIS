#include "Mier.h"

using namespace cv;
using namespace std;

Mier::Mier(Mat& src1, Mat& src2, Mat& dst)
{
    this->src1 = src1;
    this->src2 = src2;
    this->dst = dst;
    HEIGHT = src1.rows;
    WIDTH = src1.cols;
}

void Mier::process(void)
{
    int h, w, temp1 = 0, temp2 = 0;
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp1 = src1.at<uchar>(h, w);
            temp2 = src2.at<uchar>(h, w);
            dst.at<uchar>(h, w) = temp1 ^ temp2;
        }
    }
}

// dilate en erode enzo nog.