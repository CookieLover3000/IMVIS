#include "Gaten.h"

using namespace cv;
using namespace std;

Gaten::Gaten(Mat& src, Mat& dst) {
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Gaten::process(void)
{

}