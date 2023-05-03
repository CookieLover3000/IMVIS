#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;

class Zoom
{
public:
	Zoom(Mat& src, Mat& dst);
	void process(float, int, int);
private:
	Mat src, dst;
	int HEIGHT, WIDTH;
	int getPixel(Mat&, int, int);
};

