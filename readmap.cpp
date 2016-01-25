#include <iostream>
#include <fstream>
#include <vector>
#define sea_level 5
using namespace std;
class AQUACOP
{
private:
	vector<short> map;
	float x_collner;
	float y_collner;
	short row;
	short col;
public:
	void read_map(const char* pathfile);
	void process_map();
	short get_val(short i, short j);
	void set_val(short i, short j, short minus);
	void set_zero(short i, short j);
};
void AQUACOP::read_map(const char* pathfile)
{
	ifstream file;
	short i,j;
	file.open(pathfile);
	if(file.is_open())
	{
		file>>row;
		file>>col;
		map.resize(row*col);
		int i;
		for(i=0;i<row*col;i++)
			file>>map[i];
		file.close();
	}
	else
	{
		cout<<"Read map error"<<endl;
	}
}
short AQUACOP::get_val(short i,short j)
{
	return map[i*col+j];
}
void AQUACOP::set_val(short i, short j,short minus)
{
	map[i*col+j] -= minus; 
}
void AQUACOP::set_zero(short i, short j)
{
	map[i*col+j] = 0;
}
void AQUACOP::process_map()
{
	short i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			if(get_val(i,j)<sea_level)
			{
				if(i==0)
				{
					if(j==0)
					{
						if(!(get_val(i,j+1)>sea_level && get_val(i+1,j)>sea_level))
							set_zero(i,j);
					}
					else
					{
						if(j==col-1)
						{
							if(!(get_val(i,j-1)>sea_level && get_val(i+1,j)>sea_level))
								set_zero(i,j);
						}
						else
						{
							if(!(get_val(i,j-1)>sea_level && get_val(i+1,j)>sea_level && get_val(i,j+1)>sea_level))
								set_zero(i,j);

						}
					}
						
				}
				else
				{
					if(i==row-1)
					{
						if(j==0)
						{
							if(!(get_val(i-1,j)>sea_level && get_val(i,j+1)>sea_level))
								set_zero(i,j);
						}
						else
						{
							if(j==col-1)
							{
								if(!(get_val(i-1,j)>sea_level && get_val(i,j-1)>sea_level))
									set_zero(i,j);
							}
							else
							{
								if(!(get_val(i,j-1)>sea_level && get_val(i-1,j)>sea_level && get_val(i,j+1)>sea_level))
									set_zero(i,j);
							}
						}
					}
					else
					{
						if(j==0)
						{
							if(!(get_val(i-1,j)>sea_level && get_val(i,j+1)>sea_level && get_val(i+1,j)>sea_level))
								set_zero(i,j);
						}
						else
						{
							if(j==col-1)
							{
								if(!(get_val(i-1,j)>sea_level && get_val(i,j-1)>sea_level && get_val(i+1,j)>sea_level))
									set_zero(i,j);
							}
						}
					}

				}

			}
			else
			{
				set_val(i,j,sea_level);
			}
		}
}
int main()
{
	AQUACOP france;
	france.read_map("test.ASC");
	france.process_map();
	return 0;
}
