#declare FALSE 0
#declare TRUE 1

void ebnfIf(bool (*boolExpression)(), void (*block)(), int isWhile){
	if (boolExpression()){
		block();
		
		if (is_while)
			ebnfIf(boolExpression, block, isWhile);
	}
}