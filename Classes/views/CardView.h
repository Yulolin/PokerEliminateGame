#pragma once
#include "cocos2d.h"
#include "models/CardModel.h"
#define CARD_GENERAL_PATH "card_General.png"
#define CARD_NUMBER_PATH "number/"
#define CARD_SUIT_PATH "suits/"

USING_NS_CC;
#include "ui/UIImageView.h"

// ��Ƭ��ͼ��
class CardView : public ui::ImageView
{
public:
	CREATE_FUNC(CardView);
	// ��ʼ����ʾ��������ͼ
	void initDisplay(const CardModel& model);
	// ����λ����ʾ
	void updateDisplay(const CardModel& model);
	// �����ƶ�����
	void playMoveAnimation(const CardModel& model);
	// ���õ���ص�����
	void setClickCallback(const std::function<void(Ref*)>& callback);
	// �Ƴ�����ص�����
	void clearClickCallback();

private:
	// �������ֺͻ�ɫ��ͼ
	void loadSuitAndNum(const CardModel& model);

	cocos2d::Sprite* _smallNumber;// С������ͼ���
	cocos2d::Sprite* _bigNumber;  // ��������ͼ���
	cocos2d::Sprite* _suit;		  // ��ɫ���
};

