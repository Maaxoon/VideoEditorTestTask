#include <cstdint>
#include <iostream>

class BMPReader
{
public:
	struct BMPHeader
	{
		uint16_t bfType;	  // Cигнатура формата
		uint32_t bfSize;	  // Размер файла в байтах
		uint16_t bfReserved1; // Зарезервированы и должны содержать ноль
		uint16_t bfReserved2; // Зарезервированы и должны содержать ноль
		uint32_t bfOffBits;	  // Положение пиксельных данных относительно начала данной структуры (в байтах)
	};
	struct BMPInfoCore
	{
		uint32_t bcSize;	 // Размер данной структуры в байтах (должно быть 12 для данной структуры)
		uint16_t bcWidth;	 // Ширина растра в пикселях
		uint16_t bcHeight;	 // Высота растра в пикселях
		uint16_t bcPlanes;	 // Количество плоскостей (для BMP всегда 1)
		uint16_t bcBitCount; // Количество бит на пиксель
	};

	struct BMPInfoV3
	{
		uint32_t biSize;		 // Размер данной структуры в байтах (определяет версию структуры)
		int32_t biWidth;		 // Ширина растра в пикселях (целое число со знаком)
		int32_t biHeight;		 // Высота растра в пикселях (целое число со знаком, где знак указывает порядок следования строк)
		uint16_t biPlanes;		 // Количество плоскостей (в BMP всегда равно 1)
		uint16_t biBitCount;	 // Количество бит на пиксель (глубина цвета)
		uint32_t biCompression;	 // Способ сжатия данных изображения (тип компрессии)
		uint32_t biSizeImage;	 // Размер изображения в байтах (может быть 0, если изображение не сжато)
		int32_t biXPelsPerMeter; // Горизонтальное разрешение в пикселях на метр
		int32_t biYPelsPerMeter; // Вертикальное разрешение в пикселях на метр
		uint32_t biClrUsed;		 // Количество используемых цветов в палитре (0 если используется полный набор цветов)
		uint32_t biClrImportant; // Количество важных цветов в изображении (0 если все цвета важны)
	};

	BMPReader(/* args */);
	~BMPReader();

	void ReadBMP(std::istream &in);
	void SaveBMP(std::ostream &out);
	void SaveAsYUV(std::ostream &out);

private:
	BMPHeader * header;
	BMPInfoCore* infoCore;
	BMPInfoV3* infoV3;
	uint8_t * pixelsData;
};
