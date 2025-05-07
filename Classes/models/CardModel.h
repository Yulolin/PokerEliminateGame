#pragma once
#include "configs/CardResConfig.h"
#include "cocos2d.h"

// ��Ƭ������
struct CardModel
{
	CardFieldType cardField;// �������ͣ���������������
	CardFaceType cardFace;// ��������
	CardSuitType cardSuit;// ��ɫ����
	cocos2d::Vec2 cardPosition;// λ��

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

