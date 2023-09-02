#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Calc{
	public:
		void assignVector(vector<int>* v);//assigns the values for a 3 length int vector
		float findLength(vector<int> v); //returns length of vector 
		float dotProduct(vector<int> v1, vector<int> v2); //returns the dot product
		vector<int> crossProduct(vector<int> v1, vector<int> v2);//returns the cross product.
		string vectorToString(vector<int> v);
};

int main(){
	Calc calc;
	vector<int> v1(3);
	vector<int> v2(3);
	calc.assignVector(&v1);
	calc.assignVector(&v2);
	//cout << v1.at(0);
	//cout << v2.at(0) << v2.at(1) << v2.at(2);

	/*
	cout << calc.vectorToString(v1);
	cout << calc.vectorToString(v2);
	
	calc.findLength(v1);
	calc.findLength(v2);
	calc.dotProduct(v1, v2);
	calc.crossProduct(v1, v2);
	*/
};

void Calc::assignVector(vector<int>* v){
	int x = 0, y = 0, z = 0;
	//cin >> x >> y >> z;
	//v->assign({x, y, z});
};

float Calc::findLength(vector<int> v){
	double len = sqrt(pow(v.at(0), 2) + pow(v.at(1), 2) + pow(v.at(2), 2));
	return len;
};

float Calc::dotProduct(vector<int> v1, vector<int> v2){
	cout << -1;
	return -1;
};

vector<int> Calc::crossProduct(vector<int> v1, vector<int> v2){
	cout << -1;
	vector<int> v(1,0);
	return v;
};

string Calc::vectorToString(vector<int> v){
	return to_string(v.at(0)) + ' ' + to_string(v.at(1)) + ' ' + to_string(v.at(2));
}	
