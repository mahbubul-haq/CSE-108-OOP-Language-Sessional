#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Point2D
{
	int x,y;
public:
	Point2D(){ x = 0; y = 0; } 
	Point2D(int argx, int argy);
	void setX(int argx);
	void setY(int argy);
	int getX();
	int getY();
	void print();
	~Point2D(){ x = 0; y = 0; } 
};

Point2D::Point2D(int argx,int argy)
{
	x = argx;
	y = argy;
}

void Point2D::setX(int argx)
{
	x=argx;
}

void Point2D::setY(int argy)
{
	y = argy;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}
void Point2D::print()
{
	cout << "(" << x << "," << y << ")";
}
///***************************************Circle***********************************
class Circle
{
	Point2D center;
	double radius;
public:
	Circle();
	Circle(Point2D c, double r);
	~Circle(){ radius=0.0; center.setX(0);center.setY(0);}
	void setRadius(double r){ radius=r;}
	void setCenter(int i, int j){center.setX(i);center.setY(j); }
	double getRadius(){ return radius;}
	Point2D getCenterXY(){return center; }
	
	double area(); 
	void print(); 
	int intersect(Circle rhs); 
	int contains(Circle rhs); 
	int contains(Point2D p); 
	double perimeter(); 
};

Circle::Circle()
{
	radius=0.0;
	Point2D(0,0);
}

Circle::Circle(Point2D c, double r)
{
	radius=r;
	center.setX(c.getX());
	center.setY(c.getY());
}

double Circle::area()
{
	return 3.1419*radius*radius;
}

int Circle::intersect(Circle rhs)
{
	double  i,k;
	k=radius+rhs.radius;
	Point2D pp=getCenterXY(),pprhs=getCenterXY();
	
	double x1=pp.getX(),y1=pp.getY(),x2=pprhs.getX(),y2=pprhs.getY();
	
	i=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);

	if(fabs((k*k)-i)<=0.000005)
		return 1;
	else if(k*k>i)
		return 1;
	else return 0;
}

int Circle::contains(Circle rhs)
{
	double  i,k;
	k=radius-rhs.radius;
	Point2D pp=getCenterXY(),pprhs=rhs.getCenterXY();
	
	double x1=pp.getX(),y1=pp.getY(),x2=pprhs.getX(),y2=pprhs.getY();
	i=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);

	if(fabs((k*k)-i)<=0.000005)
	{
		return 1;
	}
	else if(k*k>i)
		return 1;
	else return 0;
}

int Circle::contains(Point2D p)///inside or on the circle
{
	if((radius*radius)>=(((double)p.getX()-center.getX())*((double)p.getX()-center.getX())+((double)p.getY()-center.getY())*((double)p.getY()-center.getY())))
		return 1;
	else return 0;
}

double Circle::perimeter()
{
	double k=2*acos(0.0);
	return 2*k*radius;
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << endl<<"Radius: " << radius;
	cout<<endl<<"Area : "<<area()<<endl;
}
///********************************************Rectangle********************************
class Rectangle
{
	Point2D tr,bl;
public:
	Rectangle(){ tr={0,0}; bl={0,0};}
	Rectangle(Point2D a,Point2D b){ bl=a;tr=b;}
	~Rectangle(){ tr.setX(0);tr.setY(0);bl.setX(0);bl.setY(0);}
	void settr(int i,int y){ tr.setX(i);tr.setY(y);}///point could be used in place of i and j
	void setbl(int i,int y){bl.setX(i);bl.setY(y);}

	Point2D gettr(){ return tr;}
	Point2D getbl(){ return bl;}

	double area();
	int intersect(Rectangle rhs); 
	int contains(Rectangle rhs); 
	int inside(Circle c); 
	double perimeter();
};

double Rectangle::area(){
	return (abs((tr.getX()-bl.getX()))*abs((tr.getY()-bl.getY())));
}

double Rectangle::perimeter()
{
	return 2*(abs((tr.getX()-bl.getX()))+abs((tr.getY()-bl.getY())));
}

int Rectangle::inside(Circle c)///inside or touch at the vertex
{
	double r=c.getRadius();
	Point2D pp=c.getCenterXY();
	double x=pp.getX(), y=pp.getY();
	
	if(r*r<((x-tr.getX())*(x-tr.getX())+(y-tr.getY())*(y-tr.getY())))
		return 0;
	else if(r*r<((x-bl.getX())*(x-bl.getX())+(y-bl.getY())*(y-bl.getY())))
		return 0;
	else if(r*r<((x-bl.getX())*(x-bl.getX())+(y-tr.getY())*(y-tr.getY())))
		return 0;
	else if(r*r<((x-tr.getX())*(x-tr.getX())+(y-bl.getY())*(y-bl.getY())))
		return 0;
	else return 1;
}

int Rectangle::contains(Rectangle rhs)
{
	Point2D ppbl=rhs.tr,ppytr=rhs.bl;
	
	if(ppbl.getX()>bl.getX()&&ppytr.getX()<tr.getX()&&ppbl.getY()>bl.getY()&&ppytr.getY()<tr.getY())
	{
		return 1;
	}
	return 0;
}

int Rectangle::intersect(Rectangle rhs)
{
	if(bl.getX()>rhs.tr.getX()||rhs.bl.getX()>tr.getX())
		return 0;
	if(bl.getY()>rhs.tr.getY()||rhs.tr.getY()>tr.getY())
		return 0;
	if(contains(rhs))
		return 0;
	else return 1;
	
}
//Practice: Extend your program to include other geometric objects such as square, ellipse, triangle, etc.

int main(void)
{
//Demonstrate your circle class
	Point2D ob2(4,6),ob3(20,6),ob5(5,5);
	Circle ob1(ob2,10.0),ob4(ob3,10.0),ob6(ob5,5.0);
	//Demonstrate your area funciton showing that it successfully prints area of a circle
	cout<<"Circle ob1 :"<<endl;
	ob1.print();
	cout<<endl;
	//Demonstrate intersect(Circle) function by creating appropriate circles and showing that they intersect
	cout<<"Circle ob4 : "<<endl;
	ob4.print();
	if(ob1.intersect(ob4))
		cout<<"Circle ob1 & ob4 intersect each other"<<endl;
	else cout<<"Cirlce ob1 & ob4 don't intersect"<<endl;
	cout<<endl;
	//Demonstrate contains(Circle) function by creating appropriate circles and showing that one circle
	//contains another circle
	cout<<"Circle ob6 : "<<endl;
	ob6.print();
	if(ob1.contains(ob6))
		cout<<"ob1 contains ob6"<<endl;
	else cout<<" ob1 does't contain ob6"<<endl;
	cout<<endl;
	
//Demonstrate your Rectangle class	
	Rectangle rec1(ob2,ob5),rec2(ob5,ob3),rec3;
	
	//Demonstrate your area funciton showing that it successfully prints area of a rectangle
	cout<<"Area : "<<rec1.area()<<endl;
	//Demonstrate intersect(Rectangle) function by creating appropriate circles and showing that 
	//they intersect
	
	if(rec1.intersect(rec2))
		cout<<"rec1 & rec2 intersect each other"<<endl;
	else cout<<"rec1 & rec2 don't intersect"<<endl<<endl;
	
	//Demonstrate contains(Rectangle) function by creating appropriate circles and showing that 
	
	//one rectangle contains another rectangle
	if(rec1.contains(rec2))
		cout<<"rec2 is inside rec1 "<<endl;
	else cout<<"rec1 doesn't contain rec2"<<endl<<endl;
	//Demonstrate inside(Circle) function by creating appropriate rectangle and circle and showing that 
	//a rectange is completely inside a circle
	if(rec1.inside(ob1))
		cout<<"rec1 is inside the circle ob1"<<endl;
	else cout<<"rec1 is not inside the circle ob1"<<endl<<endl;

	return 0;
}
