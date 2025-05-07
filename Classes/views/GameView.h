#pragma once
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CardController.h"
#include <memory>
#include "GlobalCardController.h"
#include "ui/CocosGUI.h" // ����UI���ͷ�ļ�

// ��Ϸ��ͼ�࣬�����������ƣ��������رհ�ťʵ��
class GameView : public cocos2d::Scene
{
public:
    cocos2d::LayerColor* playerField;// ������������
    cocos2d::LayerColor* stackField; // ������������

    static GameView* createScene();

    virtual bool init();
    // ���ر�����
    void GameView::loadBackground();
    // ���ó�����ť
    void setUndoButton(GlobalCardController* globalCardController);
    // �رհ�ť
    void GameView::menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameView);
};

#endif // __HELLOWORLD_SCENE_H__
