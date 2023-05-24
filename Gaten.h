#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;

class Gaten
{
public:
	Gaten(Mat& src, Mat& dst);
	void process();
	int label;
private:
	Mat src, src2, dst;
	int HEIGHT, WIDTH;
};

