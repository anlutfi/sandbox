#ifndef __EDGES__
#define __EDGES__

#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/**takes an image and draws edges separating the different regions.
Opposite to canny edge detection,
this function is more strict on what it considers an edge:
any color difference between neighbouring pixels.
*/
cv::Mat drawEdges(cv::Mat image, unsigned char edgewidth, cv::Vec3b edgecolor);

void show(cv::Mat image);

#endif
