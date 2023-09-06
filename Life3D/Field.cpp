#include "Field.h"


Field::Field()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->width = 2;
	this->pixelLineWidth = 1;
	this->cellWidth = 0.1;
	GLdouble arr[3]{ 1, 1, 1 };
	this->color = arr;

	this->cellsLength = this->width * this->width * this->width;


	// field Data creating
	for (int i = 0; i < this->cellsLength; i++)
	{
		this->vertCells.push_back(std::vector<GLdouble>(3));
	}

	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			for (int k = 0; k < this->width; k++)
			{
				int index = i * this->width * this->width + j * this->width + k;
				this->vertCells[index][0] = x + (i * this->cellWidth);
				this->vertCells[index][1] = y + (j * this->cellWidth);
				this->vertCells[index][2] = z + (k * this->cellWidth);
			}
		}
	}
}
Field::Field(GLdouble x, GLdouble y, GLdouble z, GLint width, GLdouble pixelLineWidth, GLdouble cellWidth, GLdouble color[3])
{
	// init data
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->pixelLineWidth = pixelLineWidth;
	this->cellWidth = cellWidth;
	this->color = color;

	this->cellsLength = width * width * width;


	// field Data creating
	for (int i = 0; i < this->cellsLength; i++)
	{
		this->vertCells.push_back(std::vector<GLdouble>(3));
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < width; k++)
			{
				int index = i * width * width + j * width + k;
				this->vertCells[index][0] = x + (i * cellWidth);
				this->vertCells[index][1] = y + (j * cellWidth);
				this->vertCells[index][2] = z + (k * cellWidth);
			}
		}
	}
}


void Field::FillPixel(GLint x, GLint y, GLint z, GLdouble side, std::vector<GLdouble> color) {
	GLdouble delta = ((this->cellWidth - side) / 2);
	Pixel(this->x + (x * this->cellWidth) + delta, this->y + (y * this->cellWidth) + delta, this->z + (z * this->cellWidth) + delta, side, color);
}

bool Field::HavePixel(GLint x, GLint y, GLint z)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < width; k++)
			{
				int index = i * width * width + j * width + k;
				if ((this->vertCells[index][0] = x + (i * this->cellWidth)) &&
					(this->vertCells[index][1] = y + (j * this->cellWidth)) &&
					(this->vertCells[index][2] = z + (k * this->cellWidth)))
				{
					return true;
					break;
				}
			}
		}
	}
	return false;
}

void Field::Init()
{
	for (int i = 0; i < this->cellsLength; i++)
	{
		StrokePixel(this->vertCells[i][0], this->vertCells[i][1], this->vertCells[i][2], cellWidth, pixelLineWidth, color);
	}
	//glutPostRedisplay();
}