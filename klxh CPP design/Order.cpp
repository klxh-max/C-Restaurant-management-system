#include "Order.h"

void Order::cconsumption(double a, int b, double c) {
	consumption = consumption + a * b * c;//�൥���Ӽ���
}

void Order::setConsumption(double a) {
	consumption += a;
}