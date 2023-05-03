#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <list>
#include <algorithm>
#include <iostream>

using namespace cv;
using namespace std;

class Contrast
{
public:
	Contrast(Mat& src, Mat& dst);
	void process();
private:
	Mat src, dst;
	int HEIGHT, WIDTH;

};

