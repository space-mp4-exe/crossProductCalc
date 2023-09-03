#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

//Calculates the length, dot product, and cross product of two vetors in R^3 space
class Calc{
	public:
		vector<float> assignVector(vector<float> v);//assigns the values for a 3 length int vector
		float findLength(vector<float> v); //returns length of vector 
		float dotProduct(vector<float> v1, vector<float> v2); //returns the dot product
		vector<float> crossProduct(vector<float> v1, vector<float> v2);//returns the cross product.
		float* dotProductAngle(vector<float> v1, vector<float> v2);//returns the angle, but like in a weird format
};

int main(){
	Calc calc;
	vector<float> v1(3);
	vector<float> v2(3);
	v1 = calc.assignVector(v1);
	v2 = calc.assignVector(v2);

	cout <<"v1 length: "<< calc.findLength(v1) <<" or sqrt(" << pow(v1.at(0), 2) + pow(v1.at(1), 2) + pow(v1.at(2), 2) << ")" << endl;
	cout <<"v2 length: "<< calc.findLength(v2) <<" or sqrt(" << pow(v2.at(0), 2) + pow(v2.at(1), 2) + pow(v2.at(2), 2) << ")" <<endl;
	cout <<"dot product: " << calc.dotProduct(v1, v2) << endl;
	float* angVector = calc.dotProductAngle(v1, v2);
	float angleVector = (angVector[0] / sqrt(angVector[1])); //* (M_PI / 180);
	cout <<"angle between vectors: " << acos(angleVector) * (180/M_PI)<<" or acos(" << angVector[0] << "/sqrt(" << angVector[1] << "))" << endl;
	vector<float> cpVector = calc.crossProduct(v1, v2);
	cout <<"cross product: < " << cpVector[0] << ", " << cpVector[1] << ", " << cpVector[2] << " >" << endl;
};

vector<float> Calc::assignVector(vector<float> v){
	float x = 0, y = 0, z = 0;
	cin >> x >> y >> z;
	v.assign({x, y, z});
	return v;
};

float Calc::findLength(vector<float> v){
	double len = sqrt(pow(v.at(0), 2) + pow(v.at(1), 2) + pow(v.at(2), 2));
	return len;
};

float Calc::dotProduct(vector<float> v1, vector<float> v2){
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
};

vector<float> Calc::crossProduct(vector<float> v1, vector<float> v2){
	vector<float> v;
	float iCon;
	float jCon;
	float kCon;

	iCon = v1[1] * v2[2] - v1[2] * v2[1];
	jCon = v1[0] * v2[2] - v1[2] * v2[0];
	jCon *= -1;//flip sign of j conponent because that's just what we do
	kCon = v1[0] * v2[1] - v1[1] * v2[0];
	v.assign({iCon, jCon, kCon});
	return v;
};

float* Calc::dotProductAngle(vector<float> v1, vector<float> v2){
	static float result[2];
	result[0] = dotProduct(v1, v2);
	result[1] = (pow(v1.at(0), 2) + pow(v1.at(1), 2) + pow(v1.at(2), 2)) * (pow(v2.at(0), 2) + pow(v2.at(1), 2) + pow(v2.at(2), 2));
	return result;
}
