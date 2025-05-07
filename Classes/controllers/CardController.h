#pragma once
#include "views/CardView.h"
#include <memory>
#include "configs/LevelConfigLoader.h"

// ��Ƭ�����࣬����cardModel���ݺ�cardView��ʾUI
// ��Ϊ��Ƭ�߼���������Ϸ�����б�����
class CardController 
{
public:
	CardModel cardModel;// ��Ƭ����
	CardView* cardView;//  ��ƬUI

	CardController();
	CardController(CardModel cardModel, cocos2d::Scene* scene);
	// ��ʼ�����ÿ�Ƭλ��
	void setCardPosition(cocos2d::Vec2 position);
	// ���õ���ص�����
	void setClickCallback(const std::function<void(Ref*)>& callback);	
	// �ÿ�Ƭ�ƶ�
	void setCardMove(cocos2d::Vec2 position);
	// ����CardView��z�㼶
	void setViewZOrder(int ZOrder);
};

