#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
	std::cerr << "Usage: " << argv[0] << " <input_img> <output_img>" << std::endl;
	return -1;
    }
    
    cv::Mat img = cv::imread(argv[1]);
    cv::imwrite(argv[2], img);
    
    return 0;
}
