#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>

using namespace cv;


int main()
{

    // 加载图像
    Mat src = imread("../getAffineTransform/env_10.png",1);

    Mat warp_dst = Mat::zeros(src.rows,src.cols,src.type());

    Point2f srcTri[3]{Point2f(0,0), Point2f(src.cols-1,0),Point2f(0,src.rows-1)};
    Point2f dstTri[3]{Point2f(src.cols*0.0,src.rows*0.33),Point2f(src.cols*0.85,src.rows*0.25),Point2f(src.cols*0.1,src.rows*0.35)};

    Mat warp_mat(2,3,CV_32F);

    warp_mat = getAffineTransform(srcTri,dstTri);

    warpAffine(src,warp_dst,warp_dst,warp_dst.size());

    imshow("origin",src);

    imshow("after",warp_dst);

    waitKey(0);







}