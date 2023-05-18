#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class Mier
{
public:
	Mier(Mat& src, Mat& src2, Mat& dst);
	void process();
private:
	Mat src, src2, dst;
	int HEIGHT, WIDTH;
	Mat threshold(Mat);
	Mat vindMier(Mat);
	Mat erosie(Mat, Mat);
	Mat dilatie(Mat, Mat);
};

