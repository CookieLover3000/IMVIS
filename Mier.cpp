#include "Mier.h"
using namespace cv;
using namespace std;

Mier::Mier(Mat& src, Mat& src2, Mat& dst) {
    this->src = src;
    this->src2 = src2;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Mier::process(void)
{
    Mat tdst = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;
    Mat tdst2 = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;
    Mat tdst3 = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;
    Mat tdst4 = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;
    src = threshold(src);
    src2 = threshold(src2);
    tdst = vindMier(tdst);
    tdst2 = erosie(tdst, tdst2);
    tdst3 = erosie(tdst2, tdst3);
    tdst4 = dilatie(tdst3, tdst4);
    dst = dilatie(tdst4, dst);
}

Mat Mier::threshold(Mat tempsrc)
{
    int h, w, temp = 0;
    for (h = 0; h < HEIGHT; h++) {
        for (w = 0; w < WIDTH; w++) {
            temp = tempsrc.at<uchar>(h, w);
            if (temp > 97) { // 97 is de gekozen drempelwaarde
                temp = 0;
            }
            else
                temp = 255;
            tempsrc.at<uchar>(h, w) = temp;
        }
    }
    return tempsrc;
}

Mat Mier::vindMier(Mat tempMier)
{
    int h, w, temp1 = 0, temp2 = 0;
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp1 = src.at<uchar>(h, w);
            temp2 = src2.at<uchar>(h, w);
            tempMier.at<uchar>(h, w) = temp1 ^ temp2;
        }
    }
    return tempMier;
}

Mat Mier::erosie(Mat temp, Mat tempMier)
{
    int pixels[5] = { 0 };
    for (int h = 1; h < HEIGHT - 1; h++)
    {
        for (int w = 1; w < WIDTH - 1; w++)
        {
            pixels[0] = temp.at<uchar>(h, w);
            pixels[1] = temp.at<uchar>(h + 1, w);
            pixels[2] = temp.at<uchar>(h - 1, w);
            pixels[3] = temp.at<uchar>(h, w - 1);
            pixels[4] = temp.at<uchar>(h, w + 1);

            if (pixels[0] == 0 || pixels[1] == 0 || pixels[2] == 0 || pixels[3] == 0 || pixels[4] == 0)
                tempMier.at<uchar>(h, w) = 0;
            else
                tempMier.at<uchar>(h, w) = 255;
        }
    }
    return tempMier;
}

Mat Mier::dilatie(Mat temp, Mat tempMier)
{
    int pixels[5] = { 0 };
    for (int h = 1; h < HEIGHT - 1; h++)
    {
        for (int w = 1; w < WIDTH - 1; w++)
        {
            pixels[0] = temp.at<uchar>(h, w);
            pixels[1] = temp.at<uchar>(h + 1, w);
            pixels[2] = temp.at<uchar>(h - 1, w);
            pixels[3] = temp.at<uchar>(h, w - 1);
            pixels[4] = temp.at<uchar>(h, w + 1);

            if (pixels[0] == 255 || pixels[1] == 255 || pixels[2] == 255 || pixels[3] == 255 || pixels[4] == 255)
                tempMier.at<uchar>(h, w) = 255;
            else
                tempMier.at<uchar>(h, w) = 0;
        }
    }
    return tempMier;
}
