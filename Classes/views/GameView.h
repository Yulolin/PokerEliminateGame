#pragma once
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CardController.h"
#include <memory>
#include "GlobalCardController.h"
#include "ui/CocosGUI.h" // 包含UI组件头文件

// 游戏视图类，包含背景绘制，撤销、关闭按钮实现
class GameView : public cocos2d::Scene
{
public:
    cocos2d::LayerColor* playerField;// 桌面区背景板
    cocos2d::LayerColor* stackField; // 手牌区背景板

    static GameView* createScene();

    virtual bool init();
    // 加载背景板
    void GameView::loadBackground();
    // 设置撤销按钮
    void setUndoButton(GlobalCardController* globalCardController);
    // 关闭按钮
    void GameView::menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameView);
};

#endif // __HELLOWORLD_SCENE_H__
