#include "Food.h"

Food::Food() {

}

Food::Food(string foodname, double foodprice, double discount){
	foodName = foodname;
	foodPrice = foodprice;
	disCount = discount;
}

void Food::setFoodname(string a) {
	foodName = a;
}

void Food::setFoodprice(double a) {
	foodPrice = a;
}

void Food::setDiscount(double a) {
	disCount = a;
}

string Food::getFoodName() {
	return foodName;
}

double Food::getFoodprice() {
	return foodPrice;
}

double Food::getDiscount() {
	return disCount;
}

void Food::setFoodid(int a){
	foodid = a;
}

int Food::getFoodid() { return foodid; }

void Food::setSale(int a) {
	salenum += a;
}

int Food::getSale() { return salenum; }