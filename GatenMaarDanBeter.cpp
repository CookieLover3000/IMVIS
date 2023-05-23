#include "GatenMaarDanBeter.h"

int label;

GatenMaarDanBeter::GatenMaarDanBeter(Mat& src, Mat& dst) : Gaten(src, dst) {}

void GatenMaarDanBeter::process(void)
{
    Gaten::process();
}