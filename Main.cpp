#include "edges.h"




int main(int argc, char** argv)
{
    unsigned char edgewidth;
    sscanf(argv[2], "%d", &edgewidth);
    
    unsigned char r, g, b;
    
    sscanf(argv[3], "%d", &r);
    sscanf(argv[4], "%d", &g);
    sscanf(argv[5], "%d", &b);
    
    
    cv::Vec3b* edgecolor = new cv::Vec3b(b, g, r);
    
    cv::Mat img = cv::imread(argv[1]);
    
    show(img);
    
    show( drawEdges(img, edgewidth, *edgecolor) );
    
    cv::waitKey(0);
    return 0;
}

