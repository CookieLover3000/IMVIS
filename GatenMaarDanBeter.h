#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "Gaten.h"

#include <iostream>

using namespace cv;
using namespace std;
class GatenMaarDanBeter : public Gaten
{
public:
	GatenMaarDanBeter(Mat& src, Mat& dst);
	void process();
private:
	Mat src, src2, dst;
	int HEIGHT, WIDTH;
};

