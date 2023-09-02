#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Calculates the length, dot product, and cross product of two vetors in R^3 space
//don't ask me why it changes from a int vector to a float vector halfway thru
class Calc{
	public:
		vector<int> assignVector(vector<int> v);//assigns the values for a 3 length int vector
		float findLength(vector<int> v); //returns length of vector 
		float dotProduct(vector<int> v1, vector<int> v2); //returns the dot product
		vector<float> crossProduct(vector<int> v1, vector<int> v2);//returns the cross product.
		string vectorToString(vector<int> v);
};

int main(){
	Calc calc;
	vector<int> v1(3);
	vector<int> v2(3);
	v1 = calc.assignVector(v1);
	v2 = calc.assignVector(v2);

	cout <<"v1 length: "<< calc.findLength(v1) <<" or sqrt(" << pow(v1.at(0), 2) + pow(v1.at(1), 2) + pow(v1.at(2), 2) << ")" << endl;
	cout <<"v2 length: "<< calc.findLength(v2) <<" or sqrt(" << pow(v2.at(0), 2) + pow(v2.at(1), 2) + pow(v2.at(2), 2) << ")" <<endl;
	cout <<"dot product: " << calc.dotProduct(v1, v2) << endl;
	vector<float> cpVector = calc.crossProduct(v1, v2);
	cout <<"cross product: < " << cpVector[0] << ", " << cpVector[1] << ", " << cpVector[2] << " >" << endl;
};

vector<int> Calc::assignVector(vector<int> v){
	int x = 0, y = 0, z = 0;
	cin >> x >> y >> z;
	v.assign({x, y, z});
	return v;
};

float Calc::findLength(vector<int> v){
	double len = sqrt(pow(v.at(0), 2) + pow(v.at(1), 2) + pow(v.at(2), 2));
	return len;
};

float Calc::dotProduct(vector<int> v1, vector<int> v2){
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
};

vector<float> Calc::crossProduct(vector<int> v1, vector<int> v2){
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

string Calc::vectorToString(vector<int> v){
	return to_string(v.at(0)) + ' ' + to_string(v.at(1)) + ' ' + to_string(v.at(2));
}	
