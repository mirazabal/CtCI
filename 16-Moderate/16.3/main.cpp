#include <iostream>
#include <exception>

using namespace std;

struct Point{
	
	Point(double x_, double y_) : x{x_}, y{y_}
	{

	}	

	double x;
	double y;
};

struct Line{
	
	Line(Point p1, Point p2 ) : p1_{p1}, p2_{p2}
	{
	}

	Point p1_;
	Point p2_;
	double getMalda()
	{
		return (p2_.x-p1_.x) / (p2_.y-p1_.y);
	}

	double offset(){
		return p1_.y - getMalda()*p1_.x;
	}
};

Point intersectionPoint(Line& l1, Line& l2 ){
	
	if( l1.getMalda() == l2.getMalda())
		throw std::runtime_error("they never intersect");  

	auto x = (l1.offset() - l2.offset()) / (l2.getMalda() - l1.getMalda()) ;
	auto y = l1.getMalda()*x + l1.offset();
	return Point(x,y);
}

int main(){
	Line l1(Point(0,1), Point(1,2) )  ;
	Line l2( Point(1,3 ), Point(3,0));

	auto p = intersectionPoint(l1,l2);

	cout << "x = " << p.x << " y = " <<  p.y << endl;

}

