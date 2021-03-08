#include "Order.h"

void Order::cconsumption(double a, int b, double c) {
	consumption = consumption + a * b * c;//多单叠加计算
}

void Order::setConsumption(double a) {
	consumption += a;
}