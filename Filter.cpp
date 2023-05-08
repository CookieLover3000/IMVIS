#include "Filter.h"
using namespace cv;
using namespace std;

Filter::Filter(Mat& src, Mat& dst) {
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Filter::process(void) 
{
    int h, w, temp = 0;
    int kernel[3][3] = { {-1, -1, -1},
                         {-1, 9, -1},
                         {-1, -1, -1} };
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            int som = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int x = w + j - 1;
                    int y = h + i - 1;

                    if (x < 0)
                        x = 0;
                    else if (x >= WIDTH)
                        x = WIDTH - 1;
                    if (y < 0)
                        y = 0;
                    else if (y >= HEIGHT)
                        y = HEIGHT - 1;


                    som += kernel[i][j] * src.at<uchar>(y, x);
                }
            }
            if (som > 255)
                som = 255;
            if (som < 0)
                som = 0;

            dst.at<uchar>(h, w) = som;
        }
    }
}

void Filter::smoothing()
{
    int h, w, temp = 0;
    int kernel[3][3] = { {1, 1, 1},
                         {1, 1, 1},
                         {1, 1, 1} };
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            int som = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int x = w + j - 1;
                    int y = h + i - 1;

                    if (x < 0)
                        x = 0;
                    else if (x >= WIDTH)
                        x = WIDTH - 1;
                    if (y < 0)
                        y = 0;
                    else if (y >= HEIGHT)
                        y = HEIGHT - 1;


                    som += kernel[i][j] * src.at<uchar>(y, x);
                }
            }


            som /= 9;

            if (som > 255)
                som = 255;
            if (som < 0)
                som = 0;

            dst.at<uchar>(h, w) = som;
        }
    }
}

// https://www.geeksforgeeks.org/noise-removal-using-median-filter-in-c/
void Filter::mediaan()
{
    int window[9] = {0};

    for (int h = 1; h < HEIGHT-1; h++)
    {
        for (int w = 1; w < WIDTH-1; w++)
        {
            //neighbor pixel values are stored in window including this pixel
            window[0] = src.at<uchar>(h - 1, w - 1);
            window[1] = src.at<uchar>(h - 1, w);
            window[2] = src.at<uchar>(h - 1, w + 1);
            window[3] = src.at<uchar>(h, w - 1);
            window[4] = src.at<uchar>(h, w);
            window[5] = src.at<uchar>(h, w + 1);
            window[6] = src.at<uchar>(h + 1, w - 1);
            window[7] = src.at<uchar>(h + 1, w);
            window[8] = src.at<uchar>(h + 1, w + 1);

            //sort window array
            insertionSort(window, 9);
            //put the median to the pixel
            dst.at<uchar>(h, w) = window[4];
        }
    }
}

void Filter::insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

