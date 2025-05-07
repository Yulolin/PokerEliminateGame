#pragma once
#include "configs/CardResConfig.h"
#include "cocos2d.h"
#include "CardController.h"
#include<vector>

struct Operation {
	CardController* card;
	CardFieldType preFieldType;
	cocos2d::Vec2 prePosition;
	Operation(CardController* card);
	Operation() {};
};
class UndoManager
{
public:
	// ��¼��Ҳ���
	void recordPlayerAction(CardController* card);
	// ��������
	Operation undoOperation();

private:
	std::stack<Operation> _operationStack;
};

