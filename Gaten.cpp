#include "Gaten.h"

Gaten::Gaten(Mat& src, Mat& dst) {
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Gaten::process(void)
{
    int binnenTeller = 0;
    int buitenTeller = 0;
    int pixels[4] = { 0 };
    for (int h = 1; h < HEIGHT - 1; h++)
    {
        for (int w = 1; w < WIDTH - 1; w++)
        {
            dst.at<uchar>(h, w) = 255 - src.at<uchar>(h, w);
            int tempTeller = 0;
            pixels[0] = src.at<uchar>(h, w);
            pixels[1] = src.at<uchar>(h + 1, w);
            pixels[2] = src.at<uchar>(h + 1, w + 1);
            pixels[3] = src.at<uchar>(h, w + 1);
            for (int i = 0; i < 4; i++)
            {
                if (pixels[i] == 255)
                    tempTeller++;
            }
            if (tempTeller == 3)
                binnenTeller++;
            if (tempTeller == 1)
                buitenTeller++;            
        }
    }
    cout << (buitenTeller - binnenTeller) / 4 << endl;
}