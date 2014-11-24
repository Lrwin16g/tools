#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
	std::cerr << "Usage: " << argv[0] << " <input_img> <output_img>" << std::endl;
	return -1;
    }
    
    cv::Mat src = cv::imread(argv[1]);
    
    cv::Mat dst;
    cv::cvtColor(src, dst, CV_BGR2GRAY);
    
    cv::imwrite(argv[2], dst);
    
    return 0;
}
