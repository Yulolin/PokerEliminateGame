#include "GameView.h"

GameView* GameView::createScene()
{
    return GameView::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
// 加载背景
void GameView::loadBackground() {
    if (!Scene::init())
    {
        return;
    }
    // 获取屏幕尺寸
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    // --------------------------------------------------
    // 上半部分红色背景
    // --------------------------------------------------
    // 创建颜色层（RGBA: 255,0,0,255 红色）
    playerField = cocos2d::LayerColor::create(
        cocos2d::Color4B(255, 100, 100, 255),
        visibleSize.width,
        visibleSize.height * 2/3
    );

    // 设置位置到屏幕上半部分
    playerField->setPosition(0, visibleSize.height * 1 / 3); // 锚点默认左下角
    this->addChild(playerField);

    // --------------------------------------------------
    // 下半部分蓝色背景
    // --------------------------------------------------
    stackField = cocos2d::LayerColor::create(
        cocos2d::Color4B(100, 100, 255, 255),
        visibleSize.width,
        visibleSize.height / 3
    );

    // 位置默认在左下角
    this->addChild(stackField);

    return;
}
// 设置撤销按钮
void GameView::setUndoButton(GlobalCardController* globalCardController) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    // 添加回退按钮
    auto button = ui::Button::create();
    // 2. 设置按钮属性
    button->setPosition(Vec2(visibleSize.width * 5.3 / 6, visibleSize.height / 6)); // 居中
    button->setTitleText("Undo"); // 设置按钮文字
    button->setTitleFontSize(50); // 字体大小
    button->setTitleColor(Color3B::BLACK); // 字体颜色

    // 3. 设置按钮状态纹理（必须设置）
    button->loadTextureNormal("Button_Normal.png"); // 默认状态
    button->loadTexturePressed("Button_Pressed.png"); // 按下状态
    button->loadTextureDisabled("button_disabled.png"); // 禁用状态

    // 4. 添加点击事件
    button->addClickEventListener([globalCardController](Ref* sender) {
        globalCardController->undoAction();
        // 在这里添加点击逻辑
        });
    // 5. 添加到场景
    this->addChild(button, 50);
}
bool GameView::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    loadBackground();
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(GameView::menuCloseCallback, this));
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }
    this->addChild(closeItem);
    
    return true;
}


void GameView::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}