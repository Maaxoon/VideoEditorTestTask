#include "BMPReader.h"

BMPReader::BMPReader(/* args */)
	: header(nullptr),
	  infoCore(nullptr),
	  infoV3(nullptr),
	  pixelsData(nullptr)
{
}

BMPReader::~BMPReader()
{
	delete header;
	delete infoCore;
	delete infoV3;
	delete pixelsData;
}

void BMPReader::ReadBMP(std::istream &in)
{
	in.read(reinterpret_cast<char *>(header), sizeof(BMPHeader));
	uint32_t infoSize = in.peek();
	if (infoSize == 0xC)
	{
		in.read(reinterpret_cast<char *>(infoCore), sizeof(BMPInfoCore));
		in.seekg(header->bfOffBits);
		in.read(reinterpret_cast<char *>(pixelsData), infoCore->bcWidth * infoCore->bcHeight * infoCore->bcBitCount / 3);
	}
	else
	{
		in.read(reinterpret_cast<char *>(&infoV3), sizeof(BMPInfoV3));
		in.seekg(header->bfOffBits);
		in.read(reinterpret_cast<char *>(pixelsData), infoV3->biWidth * infoV3->biHeight * infoV3->biBitCount / 3);
	}
}

void BMPReader::SaveAsYUV(std::ostream &out)
{
	constexpr double kR = 1.0 / 3.0;
	constexpr double kG = kR;
	constexpr double kB = kR;

	const auto toY = [this](auto R, auto G, auto B){
		return kR * R + kG * G + kB * B;
	};
	const auto toU = [this](auto B, auto Y){
		return 1 / 2 * (B - Y) / (1 - kB);
	};
	const auto toV = [this](auto R, auto Y){
		return 1 / 2 * (R - Y) / (1 - kR);
	};

	
}
