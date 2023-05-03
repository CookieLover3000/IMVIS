#include "Zoom.h"
using namespace cv;
using namespace std;

Zoom::Zoom(Mat& src, Mat& dst) {
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Zoom::process(float z, int x, int y)
{
    // Derde van a en b is om plaatje in het midden te krijgen met uitzoomen.
    float a[3] = { 1 / z, 0, y - HEIGHT / z / 2  };
    float b[3] = { 0, 1 / z, x - WIDTH / z / 2 };

    int h, w, temp = 0;

    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp = src.at<uchar>(h, w);

            float v1 = (a[0] * h) + (a[1] * w) + (a[2] * 1);
            float v2 = (b[0] * h) + (b[1] * w) + (b[2] * 1);
            dst.at<uchar>(h, w) = getPixel(src, v1, v2);
        }
    }
}

// voorkomt overflow en zorgt dat je mag uitzoomen.
int Zoom::getPixel(Mat& i, int y, int x)
{
    if (y < HEIGHT && y >= 0 && x < WIDTH && x >= 0)
    {
        return i.at<uchar>(y, x);
    }
    else
        return 255;
}