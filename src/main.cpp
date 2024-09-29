#include <fstream>
#include "ImageReader.h"
int main()
{
	std::ifstream in{"sample.yuv"};
	if (in.is_open())
	{
		ImageReader reader(ImageReader::Resolution{176, 144});
		reader.ReadImage(in);
		std::ofstream out{"generated_sample.yuv"};
		reader.SaveImage(out);
	}
}
