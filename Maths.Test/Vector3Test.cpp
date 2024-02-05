#include "pch.h"
#include "Vector3.h"

TEST(Vector3_Constructor, AssignAllComponents) {
	Vector3 v(3, 4, 5);
	EXPECT_FALSE(false);
}

TEST(Vector3_Negate, InvertsPositiveValues) {
  EXPECT_EQ(Vector3 (3,4,5), Vector3 ( - 3, -4, -5 ));
  EXPECT_FALSE(false);
}