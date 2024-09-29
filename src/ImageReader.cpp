#include "ImageReader.h"

ImageReader::ImageReader(Resolution res)
	: m_yPart(new uint8_t[res.height * res.width]),
	  m_uPart(new uint8_t[res.height * res.width / 4]),
	  m_vPart(new uint8_t[res.height * res.width / 4]),
	  m_res(res)
{
}

ImageReader::~ImageReader()
{
	delete[] m_yPart;
	delete[] m_uPart;
	delete[] m_vPart;
}

void ImageReader::ReadImage(std::istream &in)
{
	const int pixelCount = m_res.height * m_res.width;
	in.read(reinterpret_cast<char *>(m_yPart), pixelCount);
	in.read(reinterpret_cast<char *>(m_uPart), pixelCount / 4);
	in.read(reinterpret_cast<char *>(m_vPart), pixelCount / 4);
}

void ImageReader::SaveImage(std::ostream &out)
{
	const int pixelCount = m_res.height * m_res.width;
	out.write(reinterpret_cast<char *>(m_yPart), pixelCount);
	out.write(reinterpret_cast<char *>(m_uPart), pixelCount / 4);
	out.write(reinterpret_cast<char *>(m_vPart), pixelCount / 4);
}
