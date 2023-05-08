#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;

class Filter
{
public:
	Filter(Mat& src, Mat& dst);
	void process(void);
	void smoothing();
	void mediaan();
private:
	void insertionSort(int arr[], int n);
	Mat src, dst;
	int HEIGHT, WIDTH;
};

