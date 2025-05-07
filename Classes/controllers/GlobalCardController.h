#pragma once
#include <vector>
#include "CardController.h"
#include "managers/UndoManager.h"
#include "models/GameModel.h"

// ȫ�ֿ��ƿ����࣬�������еĿ��ƣ��������ء������ƶ������Ƴ���
class GlobalCardController
{
public:
	GameModel gameModel;

	GlobalCardController();
	GlobalCardController(float cardY, float handAreaLeftX, float handAreaRightX, float stackX, float playerFieldY) :
		_cardY(cardY), _handAreaLeftX(handAreaLeftX), _handAreaRightX(handAreaRightX), 
		_stackX(stackX), _playerFieldY(playerFieldY), _undoManager(UndoManager()){};

	// ��ʼ�����ؿ���
	void cardsInit(std::vector<CardModel> cardModels, cocos2d::Scene* scene);
	
	// ��ʼ������ӵ�������
	void addToHand(CardController* cardController);
	// �����ƶ�������ջ��
	void handToStack(CardController* cardController);
	// �������ƶ�������ջ��
	void addToStack(CardController* cardController);
	// ��������
	void undoAction();
	
private:
	float _cardY; // ������������Ƭ��Y
	float _handAreaLeftX; // ���������߽�
	float _handAreaRightX; // �������Ҳ�߽�
	float _stackX; // ����ջ����X
	float _playerFieldY; // ��������ƫ��

	UndoManager _undoManager;

	void onCardClicked(Ref* sender, CardController* cardController);
	void setCardClickCallback(CardController* cardController);
	// ��������ջ���Ĳ㼶��ʾ
	void updateStackCardLayer();

};

