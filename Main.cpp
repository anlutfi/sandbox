#include "edges.h"



/**
./[executable_name] [imagepath] [line thickness] [r][g][b]
*/
int main(int argc, char** argv)
{
    if(argc != 6)
    {
        std::cout << "usage: " << argv[0] << " [imagepath] [line thickness] [r][g][b]\n";
        return -1;
    }
    
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

