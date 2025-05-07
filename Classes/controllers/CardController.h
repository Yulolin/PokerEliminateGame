#pragma once
#include "views/CardView.h"
#include <memory>
#include "configs/LevelConfigLoader.h"

// 卡片控制类，持有cardModel数据和cardView显示UI
// 作为卡片逻辑主体在游戏运行中被控制
class CardController 
{
public:
	CardModel cardModel;// 卡片数据
	CardView* cardView;//  卡片UI

	CardController();
	CardController(CardModel cardModel, cocos2d::Scene* scene);
	// 初始化设置卡片位置
	void setCardPosition(cocos2d::Vec2 position);
	// 设置点击回调函数
	void setClickCallback(const std::function<void(Ref*)>& callback);	
	// 让卡片移动
	void setCardMove(cocos2d::Vec2 position);
	// 设置CardView的z层级
	void setViewZOrder(int ZOrder);
};

