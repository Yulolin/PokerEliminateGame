#pragma once
#include "cocos2d.h"
#include "models/CardModel.h"
#define CARD_GENERAL_PATH "card_General.png"
#define CARD_NUMBER_PATH "number/"
#define CARD_SUIT_PATH "suits/"

USING_NS_CC;
#include "ui/UIImageView.h"

// 卡片视图类
class CardView : public ui::ImageView
{
public:
	CREATE_FUNC(CardView);
	// 初始化显示，加载贴图
	void initDisplay(const CardModel& model);
	// 更新位置显示
	void updateDisplay(const CardModel& model);
	// 播放移动动画
	void playMoveAnimation(const CardModel& model);
	// 设置点击回调函数
	void setClickCallback(const std::function<void(Ref*)>& callback);
	// 移除点击回调函数
	void clearClickCallback();

private:
	// 加载数字和花色贴图
	void loadSuitAndNum(const CardModel& model);

	cocos2d::Sprite* _smallNumber;// 小数字贴图组件
	cocos2d::Sprite* _bigNumber;  // 大数字贴图组件
	cocos2d::Sprite* _suit;		  // 花色组件
};

