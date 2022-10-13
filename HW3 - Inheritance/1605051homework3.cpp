#include<iostream>
#include<cstdlib>
#include<math.h>
#include<iomanip>
using namespace std;

typedef enum {UNDEFINED, POINT2D, POINT3D, CIRCLE, SQUARE, RECTANGLE, SPHERE} STYPE;

class Shape
{
	STYPE type;
public:
	Shape();
	Shape(STYPE type);
	virtual void print();
	virtual double area();
	virtual bool contains(const Shape *s);
	//Intentionally made non-virtual
	bool operator==(const Shape &rhs);
	virtual ~Shape(){}
};

Shape::Shape()
{
	type = UNDEFINED;
}

Shape::Shape(STYPE argtype)
{
	type = argtype;
}

double Shape::area()
{
	cout << "I am a dummy Shape"<<endl;
	return 0.0;
}

bool Shape::contains(const Shape *rhs)
{
	cout << "You see this, because appropriate contains function is undefined"<<endl;
	return false;
}

void Shape::print()
{
	cout << "Type: " << type;
}

bool Shape::operator==(const Shape &rhs)
{
	if(type==rhs.type) return true;
	else return false;
}

class Point2D : public Shape
{
protected:
	double x,y;
public:
	Point2D();
	Point2D(STYPE argtype, double argx, double argy);
	void print();
	double area();
	bool contains(Shape *s);
	bool contains(const Point2D * rhs);
	bool operator==(const Point2D &rhs);
	void setxy(double a,double b){x=a;y=b;}
	double getX() const { return x; }
	double getY() const { return y; }
	~Point2D(){}
};

Point2D::Point2D() //calls Base's default constructor
{
	x = 0.0;
	y = 0.0;
}

Point2D::Point2D(STYPE argtype, double argx, double argy) : Shape(argtype)
{
	x = argx;
	y = argy;
}

void Point2D::print()
{
	///Shape::print();
	cout << " (" << x << "," << y << ")"<<endl;
}

double Point2D::area()
{
	return 0.0;
}

bool Point2D::contains(Shape *s)
{
	Point2D * pointType = dynamic_cast<Point2D*>(s);
	if(pointType!=NULL) 
	{
		//Supported
		return contains(pointType);
	}
	//By default, use base
	return Shape::contains(s);
}

bool Point2D::contains(const Point2D * rhs)
{
	if(x==rhs->x && y==rhs->y) return true;
	else return false;
}

bool Point2D::operator==(const Point2D & rhs)
{
	if( !Shape::operator==(rhs) ) return false;
	if( x==rhs.x && y==rhs.y ) return true;
	else return false;
}

class Rectangle : public Shape
{
	Point2D topRight,bottomLeft;
public:
	Rectangle(){topRight.setxy(0,0);bottomLeft.setxy(0,0);}
	Rectangle(STYPE type, Point2D tr, Point2D bl);//implement this
	void print(); //implement this
	double area()const; //implement this
	Point2D gettr()const{ return topRight;}
	Point2D getbl()const{ return bottomLeft;}
	bool contains(Shape *rhs); //implement this to check containment for point2d only
	bool operator==(const Rectangle &rhs); //implement this
	bool contains(Point2D *p);
	~Rectangle(){}
};

Rectangle::Rectangle(STYPE type, Point2D tr, Point2D bl):Shape(type)
{
	topRight=tr;
	bottomLeft=bl;
}

double  Rectangle::area() const
{
	return (topRight.getX()-bottomLeft.getX())*(topRight.getY()-bottomLeft.getY());
}

bool Rectangle::contains(Point2D *p)
{
	double x=p->getX(),y=p->getY();
	if(x>topRight.getX()||x<bottomLeft.getX()||y>topRight.getY()||y<bottomLeft.getY())
		return false;
	return true;
}

bool Rectangle::contains(Shape *s)
{
	Point2D * pointType = dynamic_cast<Point2D*>(s);
	if(pointType!=NULL) 
	{
		//Supported
		return contains(pointType);
	}
	return 0;
}

void Rectangle::print()
{
	topRight.print();
	bottomLeft.print();
}

bool Rectangle::operator==(const Rectangle &rhs)
{
	if(fabs(area()-rhs.area())<=0.000005)
		return 1;
	return 0;
}

class Circle : public Shape
{
	Point2D center;
	double radius;
public:
	Circle();
	Circle(STYPE type, Point2D c, double r); //implement this
	double area(); //implement this
	void print(); //implement this
	bool contains(Shape * s); //implemented partially
	bool contains(const Point2D * p); //implement this
	bool contains(const Circle * rhs); //implement this
	bool contains(const Rectangle * p); //implement this
	bool operator==(const Circle &rhs); //implement this
	~Circle(){}
};

Circle::Circle()
{
	center.setxy(0,0);
	radius=0.00;
}

Circle::Circle(STYPE type, Point2D c, double r):Shape(type)
{
	center =c;
	radius =r;
}

bool Circle::contains(const Point2D *p)
{
	double x1=center.getX(),y1=center.getY(),x2=p->getX(),y2=p->getY();
	double dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	if(dist<=radius*radius) return 1;
	else return 0;
}

bool Circle::contains(const Circle *rhs)
{
	double x1=center.getX(),y1=center.getY(),x2=rhs->center.getX(),y2=rhs->center.getY();
	double dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	
	if((radius-rhs->radius)*(radius-rhs->radius)>=dist) return 1;
	else return 0;
}

bool Circle::contains(const Rectangle *p)
{
	double x=center.getX(),y=center.getY();
	Point2D tr=p->gettr(), bl=p->getbl();
	if((x-tr.getX())*(x-tr.getX())+(y-tr.getY())*(y-tr.getY())>radius*radius)
		return 0;
	if((x-tr.getX())*(x-tr.getX())+(y-bl.getY())*(y-bl.getY())>radius*radius)
		return 0;
	if((x-bl.getX())*(x-bl.getX())+(y-tr.getY())*(y-tr.getY())>radius*radius)
		return 0;
	if((x-bl.getX())*(x-bl.getX())+(y-bl.getY())*(y-bl.getY())>radius*radius)
		return 0;
	return 1;
}

double Circle::area()
{
	return 3.1416*radius*radius;
}

void Circle::print()
{
	cout<<"Center : ("<<center.getX()<<","<<center.getY()<<") ; Radius : "<<radius<<endl;
}

bool Circle::contains(Shape * s)
{
	Point2D * pointType = dynamic_cast<Point2D*>(s);
	if(pointType!=NULL) 
	{
		//Supported
		return contains(pointType);
	}
	Circle * circleType = dynamic_cast<Circle*>(s);
	if(circleType!=NULL) 
	{
		//Supported
		return contains(circleType);
	}
	Rectangle * rectangleType = dynamic_cast<Rectangle*>(s);
	if(rectangleType!=NULL) 
	{
		//Supported
		return contains(rectangleType);
	}
	///By default
	return Shape::contains(s);
}

bool Circle:: operator==(const Circle &rhs)
{
	if((fabs(radius-rhs.radius)<=0.000005))
		return 1;
	return 0;
}

class Shape3D : public Shape
{
public:
	Shape3D();
	Shape3D(STYPE type);
	virtual double volume();
	~Shape3D(){}
};

Shape3D::Shape3D()
{
	
}

Shape3D::Shape3D(STYPE argtype) : Shape(argtype)
{
	
}

double Shape3D::volume()
{
	cout << "You see this, because appropriate function is missing in the derived class";
	return 0.0;
}

class Point3D : public Point2D, public Shape3D
{
    double z;
public:
    Point3D(); //already implemented
    Point3D(STYPE type, double argx, double argy, double argz); //implement this
    void print(); //already implemented
    void setpoint(double a, double b, double c){ z=c;Point2D(SPHERE,0.0,0.0);}
    //double area(); Not needed, base version is sufficient
	bool contains(Shape *rhs); //implement this
	bool contains(Point3D *rhs);  //implement this
	double getZ(){ return z;}
	~Point3D(){}
};

bool Point3D::contains(Point3D *rhs)
{
	if(getX()==rhs->getX()&&getY()==rhs->getY()&&getZ()==rhs->getZ())
		return 1;
	return 0;
}

bool Point3D::contains(Shape *rhs)
{
	Point3D *pointtype= dynamic_cast<Point3D*>(rhs);
	if(pointtype!=NULL)
	{
		return contains(pointtype);
	}
	return 0;
}

Point3D::Point3D()
{
    z = 0;
}

Point3D::Point3D(STYPE type, double argx, double argy, double argz):Point2D(type,argx,argy),Shape3D(type)
{
	z=argz;
}

void Point3D::print()
{
	///Shape::print();
    cout << " (" << getX() << "," << getY() << "," << z << ")";
}

class Sphere : public Shape3D
{
	Point3D center;
	double radius;
public:
	Sphere();//implement this
	Sphere(STYPE type, Point3D c, double r);//implement this
	void print(); //implement this
	double area(); //implement this
	double volume(); //implement this
	bool contains(Shape * rhs); //implement this for checking containgment of Point3D, Sphere inside sphere
	bool contains(Point3D * p); //implement this
	bool contains(Sphere * s); //implement this
	~Sphere(){}
};

bool Sphere::contains(Point3D *p)
{
	double x1=p->getX(),y1=p->getY(),z1=p->getZ();
	double x2=center.getX(),y2=center.getY(),z2=center.getZ();
	
	double dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
	if(dist<=radius*radius)
		return 1;
	else return false;
}

bool Sphere::contains(Sphere *s)
{
	double x1=s->center.getX(),y1=s->center.getY(),z1=s->center.getZ();
	double x2=center.getX(),y2=center.getY(),z2=center.getZ();
	double dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
	if((radius-s->radius)*(radius-s->radius)<dist) return false;
	else return true;
}

bool Sphere::contains(Shape *rhs)
{
	Point3D *pointtype= dynamic_cast<Point3D *>(rhs);
	if(pointtype!=NULL)
	{
		return contains(pointtype);
	}
	Sphere *sp=dynamic_cast<Sphere*> (rhs);
	if(sp!=NULL)
	{
		return contains(sp);
	}
	return 0;
}

Sphere::Sphere()
{
	center.setpoint(0.0,0.0,0.0);
	radius=0.0;
}

Sphere::Sphere(STYPE type, Point3D c, double r):Shape3D(type)
{
	center=c;
	radius=r;
}

void Sphere::print()
{
	center.print();
	cout<<" Radius : "<<radius<<endl;
}

double Sphere::area()
{
	return 4*3.1416*radius*radius;
}

double Sphere::volume()
{
	return 4/3.0*3.1416*radius*radius*radius;
}

int main()
{
	//Write main function to demonstrate your code
	//Create circles, rectanges, point2d,point3d,and sphere objects using base class pointers
	//then call the virtual methods to show that polymorphism works!
	cout << "1. Point2D 2. Rectangle 3. Circle\n";
	cout << "4. Point3D 5. Sphere. 0. Exit\n";
	while(1)
	{
		int choice;
		Shape * shape;
		Shape3D * shape3D;
		cout << "Your choice:";
		cin >> choice;
		switch(choice)
		{
			case 1:{
				shape = new Point2D(POINT2D, 5,10);
				shape->print();
				cout << "\nArea: " << shape->area()<<endl;
				break;
			}
			case 2:{
				Point2D p1(POINT2D,5.0,5.0);
				Point2D p3(POINT2D,15.0,15.0);
				Point2D p2(POINT2D,20.0,20.0);
				cout<<"p1 : ";
				p1.print();
				cout<<"p2 : ";
				p2.print();
				cout<<"p1 contains p2 : "<<boolalpha<<p1.contains(&p2)<<endl;
				cout<<"p1==p2 : "<<boolalpha<<(p2==p1)<<endl;
				Rectangle *shape1 = new Rectangle(RECTANGLE, p1, p2);
				Rectangle *shape2 = new Rectangle(RECTANGLE, p1, p2);
				cout<<"rec1 == rec2 in area : "<<boolalpha<<(*shape1==*shape2)<<endl;
				shape1->print();
				cout << "Area: " << shape1->area()<<endl;
				break;
			}
			
			case 3:
			{
				Point2D p3(POINT2D,10.0,10.0);
				Point2D p4(POINT2D,10.0,20.0);
				shape = new Circle(CIRCLE,p3,10.0);
				Circle *shape2= new Circle(CIRCLE,p4,50.0);
				Circle *shapep= new Circle(CIRCLE,p3,10.0);
				Rectangle *shape1 = new Rectangle(RECTANGLE, p3, p4);
				cout<<"p3 : ";
				p3.print();
				cout<<"p4 : ";
				p4.print();
				cout<<"Circle 1 : ";
				shape2->print();
				cout<<"Circle 2 : ";
				shape->print();
				cout<<"c1 contains c2 : "<<boolalpha<<shape2->contains(shape)<<endl;
				cout<<"c1 contains p3 : "<<boolalpha<<shape2->contains(&p3)<<endl;
				cout<<"c1 contains rectangle1 : "<<boolalpha<<shape2->contains(shape1)<<endl;
				cout<<"c1 == c2 : "<<boolalpha<<(*shape2==*shapep)<<endl;
				cout << "Area 2 : " << shape->area()<<endl;
				break;
			}
			case 4:{
				shape3D = new Point3D(POINT3D,5.0,10.0,20.0);;
				shape3D->print();
				cout << "Area: " << shape3D->area()<<endl;
				cout << "\nVolume: " << shape3D->volume()<<endl;
				break;
			}
			case 5:{
				Point3D p33(POINT3D,0.0,0.0,0.0);
				Point3D p34(POINT3D,10.0,10.0,10.0);
				Sphere *s1=new Sphere(SPHERE,p34,10.0);
				shape3D = new Sphere(SPHERE,p33,10.0);
				cout<<"p33 : ";
				p33.print();
				cout<<endl;
				cout<<"Sphere 1 :";
				shape3D->print();
				cout<<"Sphere 2 :";
				s1->print();
				cout << "Area 1: " << shape3D->area();
				cout << "\nVolume 1: " << shape3D->volume()<<endl;
				cout<<"Sphere 1 contains sphere 2 : "<<boolalpha<<shape3D->contains(s1)<<endl;
				break;
			}
		}
		if(choice==0)break;		
	}
	
	//add other functions for demonstration
	return 0;
}
