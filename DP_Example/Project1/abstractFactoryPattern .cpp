#include<iostream>
using namespace std;
//#define main_function_H
class shape
{
public:
	virtual void draw() = 0;
};
class Circle :public shape
{
public:
	Circle() {}
	~Circle() {}
	void draw()
	{
		std::cout << "Draw Circle..!" << endl;
	}

};
class Square :public shape
{
public:
	Square() {}
	~Square() {}
	void draw()
	{
		std::cout << "Draw Square..!" << endl;
	}

};
class Rectangle :public shape
{
public:
	Rectangle() {}
	~Rectangle() {}
	void draw()
	{
		std::cout << "Draw Rectangle..!" << endl;
	}
};
class color
{
public:
	virtual void fill() = 0;
};
class Red :public color
{
public:
	Red() {}
	~Red() {}
	void fill()
	{
		std::cout << "Fill Red color..!" << endl;
	}
};
class Green :public color
{
public:
	Green() {}
	~Green() {}
	void fill()
	{
		std::cout << "Fill Green color..!" << endl;
	}
};
class Blue :public color
{
public:
	Blue() {}
	~Blue() {}
	void fill()
	{
		std::cout << "Fill Blue color..!" << endl;
	}
};
class AbstractFactory
{
public:
	virtual color* getColor(const char* c_Color) = 0;
	virtual shape* getshape(const char* shape) = 0;
};
class ShapFactory :public AbstractFactory
{
public:
	ShapFactory() {}
	shape* getshape(const char *str)
	{
		if (str == "CIRCLE")
		{
			return new Circle();

		}
		else if (str == "RECTANGLE")
		{
			return new Rectangle();
		}
		else if (str == "SQUARE")
		{
			return new Square();
		}
	}
	color* getColor(const char* c_Color)
	{
		return NULL;
	}
};
class ColorFactory :public AbstractFactory
{
public:
	ColorFactory() {}
	color* getColor(const char* c_color)
	{
		if (c_color == NULL)
		{
			return NULL;
		}
		if (c_color == "RED")
		{
			return new Red();
		}
		else if (c_color == "GREEN")
		{
			return new Green();

		}
		else if (c_color == "BLUE")
		{
			return new Blue();
		}
	}

	shape* getshape(const char* shape)
	{
		return NULL;
	}
};
class FactoryProducer
{
public:
	static AbstractFactory *getFactory(const char* choice)
	{
		if (choice == "SHAPE")
		{
			return new ShapFactory();
		}
		else if (choice == "COLOR")
		{
			return new ColorFactory();
		}
	}
};

#ifdef main_function_H
int main()
{
	//get shape factory
	AbstractFactory *shapeFactory = FactoryProducer::getFactory("SHAPE");
	//get an object of Shape Circle
	shape *shape1 = shapeFactory->getshape("CIRCLE");
	//call draw method of Shape Circle
	shape1->draw();

	//get shape factory
	AbstractFactory *colorFactory = FactoryProducer::getFactory("COLOR");
	//get an object of Shape Circle
	color *col = colorFactory->getColor("RED");
	//call draw method of Shape Circle
	col->fill();



	getchar();
	return 0;
}
#endif // main_function_H
