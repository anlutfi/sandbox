#include "edges.h"

void show(cv::Mat image)
{
    cv::namedWindow("TESTE", cv::WINDOW_NORMAL);
    cv::imshow("TESTE", image);
    
    cv::waitKey(0);
}

cv::Mat drawEdges(cv::Mat image, unsigned char edgewidth, cv::Vec3b edgecolor)
{
    edgewidth = edgewidth % 2 != 1 ? edgewidth : edgewidth - 1;
    cv::Mat result = image.clone();
    
    for(unsigned int i = 0; i < image.rows; i++)
    {
        for(unsigned int j = 0; j < image.cols; j++)
        {
            cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
            
            if(( i > 0 && (image.at<cv::Vec3b>(i - 1, j) != pixel) ) ||
               ( i > 0 && j > 0 &&
                 (image.at<cv::Vec3b>(i - 1, j - 1) != pixel)
               ) ||
               (i > 0 && j < image.cols - 1 &&
                (image.at<cv::Vec3b>(i - 1, j + 1) != pixel)
               ) ||
               ( j > 0 && (image.at<cv::Vec3b>(i, j - 1) != pixel) ) ||
               ( i < image.rows - 1 && j > 0 &&
                 (image.at<cv::Vec3b>(i + 1, j - 1) != pixel)
               ) ||
               ( i < image.rows - 1 && (image.at<cv::Vec3b>(i + 1, j) != pixel) ) ||
               ( i < image.rows - 1 && j < image.cols - 1 &&
                 (image.at<cv::Vec3b>(i + 1, j + 1) != pixel)
               ) ||
               ( j < image.cols - 1 && (image.at<cv::Vec3b>(i, j + 1) != pixel) )
              )
            {
                unsigned int half = edgewidth / 2;
                for(unsigned int ni = ( (i - half) >= 0 ? i - half : 0 );
                    ni <= ( (i + half) <= image.rows - 1 ? i + half : image.rows - 1 );
                    ni++
                   )
                {
                    for(unsigned int nj = ( (j - half) >= 0 ? j - half : 0 );
                        nj <= ( (j + half) <= image.cols - 1 ? j + half : image.cols - 1 );
                        nj++
                       )
                    {
                        result.at<cv::Vec3b>(ni, nj) = edgecolor;
                    }
                }
            }
        }
    }
    
    return result;
}
