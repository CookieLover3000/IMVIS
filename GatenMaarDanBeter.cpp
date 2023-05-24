#include "GatenMaarDanBeter.h"

int label;

GatenMaarDanBeter::GatenMaarDanBeter(Mat& src, Mat& dst)
{
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void GatenMaarDanBeter::process(void)
{
    int h, w;
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            dst.at<uchar>(h, w) = 0;
        }
    }
    label = 1;
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            if ((labelPixel(h, w) != 255) && (label < 254))
            {
                label++;
            }
        }
    }
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            dst.at<uchar>(h, w) = src.at<uchar>(h, w);
        }
    }
    cout << "Aantal Gaten: " << label - 1 << endl;
}

int GatenMaarDanBeter::labelPixel(int h, int w)
{
    int16_t i, j;
    if ((src.at<uchar>(h, w) == 255) && (dst.at<uchar>(h, w) == 0))
    {
        dst.at<uchar>(h, w) = label;
        for (i = -1; i < 2; i++)
        {
            for (j = -1; j < 2; j++)
            {
                if (((i != 0) || (j != 0)) && (h + i >= 0) && (h + i < HEIGHT) && (w + j >= 0) && (w + j < WIDTH))
                    labelPixel(h + i, w + j);
            }
        }
        return 0;
    }
    return 255;
}