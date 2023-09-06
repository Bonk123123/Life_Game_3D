#include "Life.h"

Life::Life(Field field, int quantity, std::vector<GLdouble> color)
{
	std::srand(std::time(nullptr));
	this->field = field;
	this->quantity = quantity;
	this->Generation = 0;
	this->color = color;

	if (quantity > field.cellsLength)
	{
		throw "слишком большое кол-во ячеек жизни";
	}



	for (int i = 0; i < quantity; i++)
	{
		double r;
		double g;
		double b;
		if (color[0] == 1 && color[1] == 1 && color[2] == 1)
		{
			r = ((double)rand() / (RAND_MAX));
			g = ((double)rand() / (RAND_MAX));
			b = ((double)rand() / (RAND_MAX));
		}
		else
		{
			r = color[0];
			g = color[1];
			b = color[2];
		}


		GLint x = rand() % field.width;
		GLint y = rand() % field.width;
		GLint z = rand() % field.width;

		while (this->isContain(x, y, z, this->Cells))
		{
			x = rand() % field.width;
			y = rand() % field.width;
			z = rand() % field.width;
		}

		this->Cells.push_back(std::vector<GLint>{ x, y, z });
		this->Colors.push_back(std::vector<GLdouble>{ r, g, b });
	}
}

Life::Life(Field field, int quantity, int AppearingCubeWidth, std::vector<GLdouble> color)
{
	std::srand(std::time(nullptr));
	this->field = field;
	this->quantity = quantity;
	this->Generation = 0;
	this->color = color;

	if (quantity > AppearingCubeWidth * AppearingCubeWidth * AppearingCubeWidth)
	{
		throw "слишком большое кол-во ячеек жизни";
	}



	for (int i = 0; i < quantity; i++)
	{
		double r;
		double g;
		double b;
		if (color[0] == 1 && color[1] == 1 && color[2] == 1)
		{
			r = ((double)rand() / (RAND_MAX));
			g = ((double)rand() / (RAND_MAX));
			b = ((double)rand() / (RAND_MAX));
		}
		else
		{
			r = color[0];
			g = color[1];
			b = color[2];
		}

		int center = ((field.width / 2) - AppearingCubeWidth / 2);

		GLint x = rand() % AppearingCubeWidth + center;
		GLint y = rand() % AppearingCubeWidth + center;
		GLint z = rand() % AppearingCubeWidth + center;

		while (this->isContain(x, y, z, this->Cells))
		{
			x = rand() % AppearingCubeWidth + center;
			y = rand() % AppearingCubeWidth + center;
			z = rand() % AppearingCubeWidth + center;
		}

		this->Cells.push_back(std::vector<GLint>{ x, y, z });
		this->Colors.push_back(std::vector<GLdouble>{ r, g, b });
	}
}

Life::Life(Field field, int x, int y, int z, int width, std::vector<GLdouble> color)
{
	this->field = field;
	this->quantity = width * width * width;
	this->Generation = 0;
	this->color = color;

	if (quantity > field.cellsLength)
	{
		throw "слишком большое кол-во ячеек жизни";
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < width; k++)
			{
				double r;
				double g;
				double b;
				if (color[0] == 1 && color[1] == 1 && color[2] == 1)
				{
					r = ((double)rand() / (RAND_MAX));
					g = ((double)rand() / (RAND_MAX));
					b = ((double)rand() / (RAND_MAX));
				}
				else
				{
					r = color[0];
					g = color[1];
					b = color[2];
				}

				GLint x1 = x + i;
				GLint y1 = y + j;
				GLint z1 = z + k;

				this->Cells.push_back(std::vector<GLint>{ x1, y1, z1 });
				this->Colors.push_back(std::vector<GLdouble>{ r, g, b });
			}
		}
	}
}

Life::Life(Field field, int x, int y, int z, std::vector<GLdouble> color)
{
	this->field = field;
	this->quantity = 12;
	this->Generation = 0;
	this->color = color;

	if (quantity > field.cellsLength)
	{
		throw "слишком большое кол-во ячеек жизни";
	}

	this->Cells.push_back(std::vector<GLint>{ x + 1, y, z });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x + 2, y, z });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x, y + 1, z });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x, y + 2, z });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x + 3, y + 1, z });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x + 3, y + 2, z });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x + 1, y + 3, z });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x + 2, y + 3, z });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x, y, z + 1 });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x + 3, y, z + 1 });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x, y + 3, z + 1 });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
	this->Cells.push_back(std::vector<GLint>{ x + 3, y + 3, z + 1 });
	this->Colors.push_back(std::vector<GLdouble>{ 0.1, 0.5, 0.5 });
}

void Life::LifeInit()
{
	std::srand(std::time(nullptr));
	for (int i = 0; i < this->quantity; i++)
	{
		this->field.FillPixel(this->Cells[i][0], this->Cells[i][1], this->Cells[i][2], this->field.cellWidth, this->Colors[i]);
	}
}

void Life::NextGeneration()
{
	std::srand(std::time(nullptr));

	int index = 0;
	int maxI = 0, maxJ = 0, maxK = 0;
	int minI = this->field.width, minJ = this->field.width, minK = this->field.width;
	std::vector<std::vector<GLint>> OldCellsTrue = {};
	int oldCellsQuantity = 0;
	std::vector<std::vector<GLint>> OldCells = {};
#pragma omp parallel sections
	{
	#pragma omp section
		{
			for (int i = 0; i < this->quantity; i++)
			{
				if (this->Cells[i][0] > maxI) maxI = this->Cells[i][0];
				if (this->Cells[i][1] > maxJ) maxJ = this->Cells[i][1];
				if (this->Cells[i][2] > maxK) maxK = this->Cells[i][2];

				if (this->Cells[i][0] < minI) minI = this->Cells[i][0];
				if (this->Cells[i][1] < minJ) minJ = this->Cells[i][1];
				if (this->Cells[i][2] < minK) minK = this->Cells[i][2];
			}


			for (int i = this->quantity - 1; i >= 0; i--)
			{
				OldCellsTrue.push_back(std::vector<GLint>{ this->Cells[i][0], this->Cells[i][1], this->Cells[i][2] });
			}
		}
	#pragma omp section
		{
			for (int i = minI - 1; i <= maxI + 1; i++)
			{
				for (int j = minJ - 1; j <= maxJ + 1; j++)
				{
					for (int k = minK - 1; k <= maxK + 1; k++)
					{
						oldCellsQuantity++;
						OldCells.push_back(std::vector<GLint>{ i, j, k });
					}
				}
			}
		}
	#pragma omp section
		{
			for (int i = 0; i < oldCellsQuantity; i++)
			{
				// остаются живы
				if ((this->quantityNeighbour(OldCells[i][0], OldCells[i][1], OldCells[i][2], OldCellsTrue) == 2 ||
					this->quantityNeighbour(OldCells[i][0], OldCells[i][1], OldCells[i][2], OldCellsTrue) == 3) &&
					this->isContain(OldCells[i][0], OldCells[i][1], OldCells[i][2], OldCellsTrue) == true)
				{
					continue;
				}

				// новая жизнь
				if ((this->quantityNeighbour(OldCells[i][0], OldCells[i][1], OldCells[i][2], OldCellsTrue) == 5) &&
					this->isContain(OldCells[i][0], OldCells[i][1], OldCells[i][2], OldCellsTrue) == false)
				{
					double r;
					double g;
					double b;
					if (this->color[0] == 1 && this->color[1] == 1 && this->color[2] == 1)
					{
						r = ((double)rand() / (RAND_MAX));
						g = ((double)rand() / (RAND_MAX));
						b = ((double)rand() / (RAND_MAX));
					}
					else
					{
						r = color[0];
						g = color[1];
						b = color[2];
					}
					this->Cells.push_back(std::vector<GLint>{ OldCells[i][0], OldCells[i][1], OldCells[i][2] });
					this->Colors.push_back(std::vector<GLdouble>{ r, g, b });
					this->quantity += 1;
					continue;
				}

				// умирает

				if (this->isContain(OldCells[i][0], OldCells[i][1], OldCells[i][2], OldCellsTrue) == true)
				{


					for (int z = 0; z < OldCellsTrue.size(); z++)
					{
						if (this->Cells[z][0] == OldCells[i][0] &&
							this->Cells[z][1] == OldCells[i][1] &&
							this->Cells[z][2] == OldCells[i][2])
						{
							index = z;
							break;
						}
					}

					this->Colors.erase(std::next(this->Colors.begin(), index));
					this->Cells.erase(std::next(this->Cells.begin(), index));
					this->quantity -= 1;
				}
			}
		}
	} // omp sections

	



	// другая реализация
	/*
	std::vector<std::vector<GLint>> OldCells;
	for (int i = this->Cells.size() - 1; i >= 0; i--)
	{
		OldCells.push_back(std::vector<GLint>{ this->Cells[i][0], this->Cells[i][1], this->Cells[i][2] });
	}

	for (int i = 0; i < this->field.width; i++)
	{
		for (int j = 0; j < this->field.width; j++)
		{
			for (int k = 0; k < this->field.width; k++)
			{
				// варианты: 2,3/5  5,7/6

				int index = 0;
				if ((this->quantityNeighbour(i, j, k, OldCells) < 5 ||
					this->quantityNeighbour(i, j, k, OldCells) > 7) &&
					this->isContain(i, j, k, OldCells) == false)
				{
					continue;
				}


				// остаются живы
				if ((this->quantityNeighbour(i, j, k, OldCells) == 5 ||
					this->quantityNeighbour(i, j, k, OldCells) == 7) &&
					this->isContain(i, j, k, OldCells) == true)
				{
					continue;
				}

				// рождаются
				if ((this->quantityNeighbour(i, j, k, OldCells) == 6) &&
					this->isContain(i, j, k, OldCells) == false)
				{
					double r;
					double g;
					double b;
					if (this->color[0] == 1 && this->color[1] == 1 && this->color[2] == 1)
					{
						r = ((double)rand() / (RAND_MAX));
						g = ((double)rand() / (RAND_MAX));
						b = ((double)rand() / (RAND_MAX));
					}
					else
					{
						r = color[0];
						g = color[1];
						b = color[2];
					}
					this->Cells.push_back(std::vector<GLint>{ i, j, k });
					this->Colors.push_back(std::vector<GLdouble>{ r, g, b });
					this->quantity += 1;
					continue;
				}


				// умирают
				if (this->isContain(i, j, k, OldCells) == true)
				{
					for (int z = 0; z < OldCells.size(); z++)
					{
						if (this->Cells[z][0] == i &&
							this->Cells[z][1] == j &&
							this->Cells[z][2] == k)
						{
							index = z;
							break;
						}
					}
					this->Colors.erase(std::next(this->Colors.begin(), index));
					this->Cells.erase(std::next(this->Cells.begin(), index));
					this->quantity -= 1;
				}
			}
		}
	}
	*/
	if (this->Cells.size() > 0)
	{
		this->Generation += 1;
	}
}

void Life::glaider(int x, int y, int z)
{
	this->Cells.push_back(std::vector<GLint>{ x + 1, y, z });
	this->Cells.push_back(std::vector<GLint>{ x + 2, y, z });
	this->Cells.push_back(std::vector<GLint>{ x, y + 1, z });
	this->Cells.push_back(std::vector<GLint>{ x, y + 2, z });
	this->Cells.push_back(std::vector<GLint>{ x + 3, y + 1, z });
	this->Cells.push_back(std::vector<GLint>{ x + 3, y + 2, z });
	this->Cells.push_back(std::vector<GLint>{ x + 1, y + 3, z });
	this->Cells.push_back(std::vector<GLint>{ x + 2, y + 3, z });
	this->Cells.push_back(std::vector<GLint>{ x, y, z + 1 });
	this->Cells.push_back(std::vector<GLint>{ x + 2, y, z + 1 });
	this->Cells.push_back(std::vector<GLint>{ x, y + 2, z + 1 });
	this->Cells.push_back(std::vector<GLint>{ x + 2, y + 2, z + 1 });
}

void Life::displayGeneration(double WIDTH, double HEIGHT) 
{
	glDisable(GL_TEXTURE_2D); //added this
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(10, 10);
	std::string str = std::string("Generation: ") + std::to_string(this->Generation);
	int j = str.size();

	glColor3f(0, 0, 0);
	glRasterPos2f(1, 0);
	void* font = GLUT_BITMAP_9_BY_15;
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	glMatrixMode(GL_PROJECTION); //swapped this with...
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW); //...this
	glPopMatrix();
	//added this
	glEnable(GL_TEXTURE_2D);
}

void Life::console()
{
	for (int i = 0; i < this->quantity; i++)
	{

		std::cout << '[' << this->Cells[i][0] << ' ' << this->Cells[i][1] << ' ' << this->Cells[i][2] << ']' << '\n';

	}
	std::cout << "quantity: " << this->quantity << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

int Life::quantityNeighbour(GLint x, GLint y, GLint z, std::vector<std::vector<GLint>> OldCells)
{
	int quantity = 0;
	for (int i = 0; i < OldCells.size(); i++)
	{
		if (abs(OldCells[i][0] - x) == 0 && abs(OldCells[i][1] - y) == 0 && abs(OldCells[i][2] - z) == 0)
		{
			continue;
		}
		if (abs(OldCells[i][0] - x) < 2 && abs(OldCells[i][1] - y) < 2 && abs(OldCells[i][2] - z) < 2) quantity += 1;
	}
	return quantity;
}

bool Life::isContain(GLint x, GLint y, GLint z, std::vector<std::vector<GLint>> OldCells)
{
	for (int i = 0; i < OldCells.size(); i++)
	{
		if (OldCells[i][0] == x &&
			OldCells[i][1] == y &&
			OldCells[i][2] == z)
		{
			return true;
		}
	}
	return false;
}