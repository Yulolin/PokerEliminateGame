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
// ���ر���
void GameView::loadBackground() {
    if (!Scene::init())
    {
        return;
    }
    // ��ȡ��Ļ�ߴ�
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    // --------------------------------------------------
    // �ϰ벿�ֺ�ɫ����
    // --------------------------------------------------
    // ������ɫ�㣨RGBA: 255,0,0,255 ��ɫ��
    playerField = cocos2d::LayerColor::create(
        cocos2d::Color4B(255, 100, 100, 255),
        visibleSize.width,
        visibleSize.height * 2/3
    );

    // ����λ�õ���Ļ�ϰ벿��
    playerField->setPosition(0, visibleSize.height * 1 / 3); // ê��Ĭ�����½�
    this->addChild(playerField);

    // --------------------------------------------------
    // �°벿����ɫ����
    // --------------------------------------------------
    stackField = cocos2d::LayerColor::create(
        cocos2d::Color4B(100, 100, 255, 255),
        visibleSize.width,
        visibleSize.height / 3
    );

    // λ��Ĭ�������½�
    this->addChild(stackField);

    return;
}
// ���ó�����ť
void GameView::setUndoButton(GlobalCardController* globalCardController) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    // ��ӻ��˰�ť
    auto button = ui::Button::create();
    // 2. ���ð�ť����
    button->setPosition(Vec2(visibleSize.width * 5.3 / 6, visibleSize.height / 6)); // ����
    button->setTitleText("Undo"); // ���ð�ť����
    button->setTitleFontSize(50); // �����С
    button->setTitleColor(Color3B::BLACK); // ������ɫ

    // 3. ���ð�ť״̬�����������ã�
    button->loadTextureNormal("Button_Normal.png"); // Ĭ��״̬
    button->loadTexturePressed("Button_Pressed.png"); // ����״̬
    button->loadTextureDisabled("button_disabled.png"); // ����״̬

    // 4. ��ӵ���¼�
    button->addClickEventListener([globalCardController](Ref* sender) {
        globalCardController->undoAction();
        // ��������ӵ���߼�
        });
    // 5. ��ӵ�����
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