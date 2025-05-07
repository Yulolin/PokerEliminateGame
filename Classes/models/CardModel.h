#pragma once
#include "configs/CardResConfig.h"
#include "cocos2d.h"

// 卡片数据类
struct CardModel
{
	CardFieldType cardField;// 属性类型，手牌区和桌面牌
	CardFaceType cardFace;// 数字类型
	CardSuitType cardSuit;// 花色类型
	cocos2d::Vec2 cardPosition;// 位置

	CardModel() {};
	
	CardModel(const CardModel& other) :cardField(other.cardField), 
		cardFace(other.cardFace), cardSuit(other.cardSuit), cardPosition(other.cardPosition) {};
	
	CardModel(CardFaceType cardFace, CardSuitType cardSuit, cocos2d::Vec2 position, CardFieldType cardField) :
		cardFace(cardFace), cardSuit(cardSuit), cardPosition(position), cardField(cardField){};
	
	CardModel(int cardFace, int cardSuit, cocos2d::Vec2 position, CardFieldType cardField) {
		this->cardFace = static_cast<CardFaceType>(cardFace);
		this->cardSuit = static_cast<CardSuitType>(cardSuit);
		this->cardPosition = position;
		this->cardField = cardField;
	}

};

