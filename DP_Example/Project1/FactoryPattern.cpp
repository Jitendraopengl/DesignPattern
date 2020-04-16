#include <iostream>

using namespace std;
class shape
{
public:
	virtual void draw() = 0;
};
class Line :public shape
{
public:
	Line(){}
	void draw()
	{
		cout << "Draw A Line" << endl;
	}
};
class circle : public shape
{
public:
	circle() {}
	void draw()
	{
		cout << "Draw Circle " << endl;
	}
};

class shapeFactory
{
public:
	shapeFactory(){}
	//shape* GetShape(const char * str)
	static shape* GetShape(const char* str)
	{
		if(str == "Line")
		{
			return new Line();
		}
		else if (str == "Line")
		{
			return new circle();
		}		
	}
	
};

int main()
{
	//shapeFactory *sfobj= new shapeFactory();
	//shape *sObj = sfobj->GetShape("Line");
	shape* sObj = shapeFactory::GetShape("Line");
	sObj->draw();

	return 0;
}