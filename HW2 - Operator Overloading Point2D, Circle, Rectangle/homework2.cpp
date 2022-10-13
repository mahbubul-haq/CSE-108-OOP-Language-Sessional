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
	Point2D operator +(Point2D P2);
	Point2D operator * (int n);
	bool operator == (Point2D P2);
	bool operator !=(Point2D P2);
};

Point2D Point2D::operator +( Point2D P2)
{
	Point2D temp;
	temp.x=x+P2.x;
	temp.y=y+P2.y;
	return temp;
}

Point2D Point2D::operator *(int n)
{
	Point2D temp;
	temp.x=x*n;
	temp.y=y*n;
	return temp;
}

bool Point2D:: operator==(Point2D P2)
{
	return (x==P2.x)&&(y==P2.y);
}

bool Point2D::operator !=(Point2D P2)
{
	return (x!=P2.x)||(y!=P2.y);
}

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

class Circle
{
	Point2D center;
	double radius;
public:
	Circle();
	Circle(Point2D c, double r);
	~Circle(){ radius=0.0; center.setX(0);center.setY(0);}
	void setRadius(double r){ radius=r;}
	void setCenter(int i, int j){center.setX(i);center.setY(j);}
	double getRadius(){ return radius;}
	Point2D getCenterXY(){return center; }
	
	double area(); 
	void print(); 
	int intersect(Circle rhs); 
	int contains(Circle rhs); 
	int contains(Point2D p); 
	double perimeter(); 
	
	Circle operator + (Point2D p);
	Circle operator * (int n);
	Circle operator +( Circle c);
	Circle operator -( Circle c);
	bool operator == (Circle c);
	bool operator > (Circle c);
	bool operator >=(Circle c);
	bool operator < (Circle c);
	bool operator <= (Circle c);
	Circle operator ++(int unused);
	Circle operator ++();
};

Circle Circle::operator + (Point2D p)
{
	Circle temp;
	Point2D pp = getCenterXY();
	temp.setRadius(getRadius());
	temp.setCenter((p.getX()+pp.getX()),(p.getY()+pp.getY()));
	return temp;
}

Circle Circle::operator *(int n)
{
	Circle temp;
	Point2D pp = getCenterXY();
	temp.setRadius(getRadius()*n);
	temp.setCenter((pp.getX())*n,n*(pp.getY()));
	return temp;
}

Circle Circle::operator +(Circle c)
{
	Circle temp;
	Point2D pp = getCenterXY(),pp1=c.getCenterXY();
	double r1=getRadius(),r2=c.getRadius();
	double alp=r1/(r1+r2);
	temp.setRadius(r1+r2);
	
	int x=round(pp.getX()*alp+pp1.getX()*(1-alp));
	int y=round(pp.getY()*alp+pp1.getY()*(1-alp));
	temp.setCenter(x,y);
	return temp;
}

Circle Circle::operator -(Circle c)
{
	Circle temp;
	Point2D pp = getCenterXY(),pp1=c.getCenterXY();
	double r1=getRadius(),r2=c.getRadius();
	double alp=r1/(r1+r2);
	temp.setRadius(fabs(r1-r2));
	
	int x=round(pp.getX()*alp+pp1.getX()*(1-alp));
	int y=round(pp.getY()*alp+pp1.getY()*(1-alp));
	temp.setCenter(x,y);
	return temp;
}

bool Circle::operator == (Circle c)
{
	return fabs(area()-(c.area()))<=0.000002;
}

bool Circle::operator > (Circle c)
{
	return area()>c.area();
}

bool Circle::operator >=(Circle c)
{
	return area()>=c.area();
}

bool Circle::operator < (Circle c)
{
	return area()<c.area();
}

bool Circle::operator <= (Circle c)
{
	return area()<=c.area();
}

Circle Circle::operator++(int unused)
{
	double r=getRadius();
	r++;
	setRadius(r);
	return *this;
}

Circle Circle::operator++()
{
	double r=getRadius();
	r++;
	setRadius(r);
	return *this;
}


Circle::Circle()
{
	radius=0.0;
	Point2D(0,0);
}


Circle::Circle(Point2D c, double r)
{
	setCenter(c.getX(),c.getY());
	radius=r;
}

double Circle::area()
{
	return 3.1419*radius*radius;
}

int Circle::intersect(Circle rhs)
{
	//complete this function
}

int Circle::contains(Circle rhs){
	
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius<<endl;
}

class Rectangle
{
	Point2D tr,bl;
public:
	Rectangle(){ tr={0,0}; bl={0,0};}
	Rectangle(Point2D a, Point2D b){ bl=a;tr=b;}
	~Rectangle(){ tr.setX(0);tr.setY(0);bl.setX(0);bl.setY(0);}
	void settr(int i,int y){ tr.setX(i);tr.setY(y);}
	void setbl(int i,int y){bl.setX(i);bl.setY(y);}

	Point2D gettr(){ return tr;}
	Point2D getbl(){ return bl;}

	double area();
	int intersect(Rectangle rhs); 
	int contains(Rectangle rhs); 
	int inside(Circle c); 
	double perimeter();
	Rectangle operator +(Point2D p);
	Rectangle operator *(int n);
};

Rectangle Rectangle::operator *(int n)
{
	Rectangle temp;
	Point2D o=gettr(),t=getbl();
	temp.settr(o.getX()*n,o.getY()*n);
	temp.setbl(t.getX()*n,t.getY()*n);
	return temp;
}

Rectangle Rectangle::operator +(Point2D p)
{
	Rectangle temp;
	Point2D o=gettr(),t=getbl();
	temp.settr(o.getX()+p.getX(),o.getY()+p.getY());
	temp.setbl(t.getX()+p.getX(),t.getY()+p.getY());
	return temp;
}

double Rectangle::area(){
	return (abs((tr.getX()-bl.getX()))*abs((tr.getY()-bl.getY())));
}

double Rectangle::perimeter()
{
}

int Rectangle::inside(Circle c)///inside or touch at the vertex
{
}

int Rectangle::contains(Rectangle rhs)
{
	
}

int Rectangle::intersect(Rectangle rhs)
{
	
}

//Practice: Extend your program to include other geometric objects such as square, ellipse, triangle, etc.


int main(void)
{
	Point2D p1(2,3),p2(5,3),p3;
	p3=p1+p2;
	p3.print();
	cout<<endl;
	p3=p1*5;
	p3.print();
	cout<<endl;
	if(p1==p2)
		cout<<"p1 == P2 is true"<<endl;
	else cout<<"p1 == P2 is false"<<endl;
	if(p1!=p2) cout<<"P1 != P2 is true"<<endl;
	else cout<<"P1 != P2 is false"<<endl;
	
	Circle c1(p1,5),c2(p2,10),c3;
	c3=c1+p1;
	c3.print();
	c3=c1*5;
	c3.print();
	c3=c1+c2;
	c3.print();
	c3=c1-c2;
	c3.print();
	if(c1==c2) cout<<"c1==c2 is true"<<endl;
	else cout<<"c1==c2 is false"<<endl;
	if(c1>c2) cout<<"c1>c2 is true"<<endl;
	else cout<<"c1>c2 is false"<<endl;
	if(c1>=c2) cout<<"c1>=c2 is true"<<endl;
	else cout<<"c1>=c2 is false"<<endl;
	if(c1<c2) cout<<"c1<c2 is true"<<endl;
	else cout<<"c1<c2 is false"<<endl;
	if(c1<=c2) cout<<"c1<=c2 is true"<<endl;
	else cout<<"c1<=c2 is false"<<endl;
	c1++;
	c1.print();
	++c1;
	c1.print();
	
	Rectangle r1(p1,p2),r2;
	r2=r1+p1;
	p1=r2.gettr(),p2=r2.getbl();
	p2.print();
	p1.print();
	r2=r1*5;
	p1=r2.gettr(),p2=r2.getbl();
	p2.print();
	p1.print();
	cout<<endl;
	
	return 0;
}
