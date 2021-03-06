#include "Test_Evaluator.h"

Test_Evaluator::Test_Evaluator() {
	Test_Spaces();
//	Test_No_Spaces();
//	Test_Errors();
}

void Test_Evaluator::Test_Spaces() {
	//Test_Prefix_Operators_Spaces();
	Test_Combo_Operators_Spaces();
	//Test_Boolean_Operators_Spaces();

	return;
}

void Test_Evaluator::Test_Prefix_Operators_Spaces() {

	// !
	assert(evaluator.eval("! 1"), false);
	// ++
	assert(evaluator.eval("++ 2"), 3);
	// --
	assert(evaluator.eval("-- 1"), 1);
	// - (negative)
	assert(evaluator.eval("- 1"), -1);

	return;
}

void Test_Evaluator::Test_Combo_Operators_Spaces() {
	// ^
//	assert(evaluator.eval("2 ^ 3"), 8);
	// *
	assert(evaluator.eval("6 * 2"), 12);
	// /
	assert(evaluator.eval("6 / 2"), 3);
	// %
	assert(evaluator.eval("5 % 2"), 1);
	// +
	assert(evaluator.eval("2 + 2"), 4);
	// -
	assert(evaluator.eval("6 - 2"), 4);

	return;
}

void Test_Evaluator::Test_Boolean_Operators_Spaces() {
	// >
	assert(evaluator.eval("6 > 5"), true);
	// >
	assert(evaluator.eval("6 >= 5"), true);
	// <
	assert(evaluator.eval("6 < 5"), false);
	// <=
	assert(evaluator.eval("6 <= 5"), false);
	// ==
	assert(evaluator.eval("6 == 5"), false);
	// !=
	assert(evaluator.eval("6 != 5"), true);
	// &&
	assert(evaluator.eval("6 > 5 && 4 > 5"), false);
	// ||
	assert(evaluator.eval("1 || 0"), true);

	return;
}

void Test_Evaluator::Test_No_Spaces() {
	Test_Prefix_Operators_No_Spaces();
	Test_Combo_Operators_No_Spaces();
	Test_Boolean_Operators_No_Spaces();

	return;
}

void Test_Evaluator::Test_Prefix_Operators_No_Spaces() {

	// !
	assert(evaluator.eval("!1"), false);
	// ++
	assert(evaluator.eval("++2"), 3);
	// --
	assert(evaluator.eval("--1"), 1);
	// - (negative)
	assert(evaluator.eval("-1"), -1);

	return;
}

void Test_Evaluator::Test_Combo_Operators_No_Spaces() {
	// ^
//	assert(evaluator.eval("2^3"), 8);
	// *
	assert(evaluator.eval("6*2"), 12);
	// /
	assert(evaluator.eval("6/2"), 3);
	// %
	assert(evaluator.eval("5%2"), 1);
	// +
	assert(evaluator.eval("2+2"), 4);
	// -
	assert(evaluator.eval("6-2"), 4);

	return;
}

void Test_Evaluator::Test_Boolean_Operators_No_Spaces() {
	// >
	assert(evaluator.eval("6>5"), true);
	// >
	assert(evaluator.eval("6>=5"), true);
	// <
	assert(evaluator.eval("6<5"), false);
	// <=
	assert(evaluator.eval("6<=5"), false);
	// ==
	assert(evaluator.eval("6==5"), false);
	// !=
	assert(evaluator.eval("6!=5"), true);
	// &&
	assert(evaluator.eval("6>5&&4>5"), false);
	// ||
	assert(evaluator.eval("1||0"), true);

	return;
}

void Test_Evaluator::Test_Errors() {
	// TODO: I'm unsure if this is how you assert check an error thrown, but the test cases are still useful
	// to have around

	// Starting w/ Closing Parentheses
	assert(evaluator.eval(")3+2"), "Expression can't start with a closing parenthesis @ char: 0");
	// Starting w/ Binary Operator
	assert(evaluator.eval("<3+2"), "Expression can't start with a binary operator @ char: 0");
	// Two binary operators in a row
	assert(evaluator.eval("3&&&& 5"), "Two binary operators in a row @ char: 3");
	// Two operands in a row
	assert(evaluator.eval("15+3 2"), "Two operands in a row @ char: 5");
	// A unary operand followed by a binary operator
	assert(evaluator.eval("10+ ++<3"), "A unary operator can't be followed by a binary operator @ char: 6");
	// Division by zero
	assert(evaluator.eval("1/0"), "Division by zero @ char: 2");
}