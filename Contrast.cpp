#include "Contrast.h"
using namespace cv;
using namespace std;

Contrast::Contrast(Mat& src, Mat& dst) {
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Contrast::process(void) 
{
    int h, w, temp = 0;
    int minWaarde = 2;
    int maxWaarde = 90;

    // vind de minimale waarde.
    // kan niet max waarde vinden op deze manier, want dat is dan 255 waardoor het niet werkt :(
    // Misschien een max zetten voor het aantal pixels dat bij een waarde mag zitten.
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp = src.at<uchar>(h, w);
            if (temp < minWaarde)
                minWaarde = temp;

        }
    }

    // trekt de minimale waarde van alle pixels af.
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp = src.at<uchar>(h, w);
            // min voor het stoppen van overflow
            // rotformule werkt niet zonder float... Heeft weer veel te veel tijd gekost
            dst.at<uchar>(h, w) = min((int)(((float)(temp - minWaarde) / (maxWaarde - minWaarde)) * 255),255);
        }
    }
}