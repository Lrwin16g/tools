#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    if(argc != 5)
    {
	std::cerr << "Usage: " << argv[0] << " <input_img> <output_img> <mean> <stddev>" << std::endl;
	return -1;
    }
    
    double mean = atof(argv[3]);
    double stddev = atof(argv[4]);
    
    cv::Mat src = cv::imread(argv[1]);
    
    cv::RNG gen(cv::getTickCount());
    cv::Mat noise(src.size(), src.type());
    gen.fill(noise, cv::RNG::NORMAL, cv::Scalar(0, 0, 0), cv::Scalar(40, 40, 40));
    
    cv::Mat result = src + noise;
    cv::Mat dst;
    result.convertTo(dst, src.type());
        
    cv::imwrite(argv[2], dst);
    
    return 0;
}
