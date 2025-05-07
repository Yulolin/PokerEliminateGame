#pragma once
#include <vector>
#include "CardController.h"
#include "managers/UndoManager.h"
#include "models/GameModel.h"

// 全局卡牌控制类，管理所有的卡牌，包括加载、卡牌移动、卡牌撤销
class GlobalCardController
{
public:
	GameModel gameModel;

	GlobalCardController();
	GlobalCardController(float cardY, float handAreaLeftX, float handAreaRightX, float stackX, float playerFieldY) :
		_cardY(cardY), _handAreaLeftX(handAreaLeftX), _handAreaRightX(handAreaRightX), 
		_stackX(stackX), _playerFieldY(playerFieldY), _undoManager(UndoManager()){};

	// 初始化加载卡牌
	void cardsInit(std::vector<CardModel> cardModels, cocos2d::Scene* scene);
	
	// 初始加载添加到手牌区
	void addToHand(CardController* cardController);
	// 手牌移动到手牌栈区
	void handToStack(CardController* cardController);
	// 桌面牌移动到手牌栈区
	void addToStack(CardController* cardController);
	// 撤销操作
	void undoAction();
	
private:
	float _cardY; // 所有手牌区卡片的Y
	float _handAreaLeftX; // 手牌区左侧边界
	float _handAreaRightX; // 手牌区右侧边界
	float _stackX; // 手牌栈区的X
	float _playerFieldY; // 桌面区的偏移

	UndoManager _undoManager;

	void onCardClicked(Ref* sender, CardController* cardController);
	void setCardClickCallback(CardController* cardController);
	// 更新手牌栈区的层级显示
	void updateStackCardLayer();

};

