#include <cstdint>
#include <iostream>

class ImageReader
{
public:
	struct Resolution
	{
		explicit Resolution(uint16_t h, uint16_t w) : height(h), width(w) {};
		int16_t height;
		int16_t width;
	};

	

	ImageReader(Resolution res);
	~ImageReader();

	void ReadImage(std::istream& in);
	void SaveImage(std::ostream& out);

private:
	Resolution m_res;
	uint8_t * m_yPart;
	uint8_t * m_uPart;
	uint8_t * m_vPart;
};
