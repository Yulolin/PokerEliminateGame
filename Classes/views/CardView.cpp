#include "CardView.h"

// 初始化显示
void CardView::initDisplay(const CardModel& model) {
    this->loadTexture (CARD_GENERAL_PATH);
    loadSuitAndNum(model);
    updateDisplay(model);
}

void CardView::loadSuitAndNum(const CardModel& model) {
    String suitPath = String(CARD_SUIT_PATH);
    switch (model.cardSuit) {
    case CST_CLUBS:suitPath.append("club.png"); break;
    case CST_SPADES:suitPath.append("spade.png"); break;
    case CST_DIAMONDS:suitPath.append("diamond.png"); break;
    case CST_HEARTS:suitPath.append("heart.png"); break;
    }
    _suit = Sprite::create(suitPath.getCString());
    _suit->setPosition(cocos2d::Vec2(190, 330));
    addChild(_suit);

    String bigNumberPath = String(CARD_NUMBER_PATH);
    String smallNumberPath = String(CARD_NUMBER_PATH);
    if (model.cardSuit == CST_CLUBS || model.cardSuit == CST_SPADES) {
        bigNumberPath.append("big_black_");
        smallNumberPath.append("small_black_");
    }
    else {
        bigNumberPath.append("big_red_");
        smallNumberPath.append("small_red_");
    }
    switch (model.cardFace) {
    case CFT_ACE:bigNumberPath.append("A.png"); smallNumberPath.append("A.png"); break;
    case CFT_TWO:bigNumberPath.append("2.png"); smallNumberPath.append("2.png"); break;
    case CFT_THREE:bigNumberPath.append("3.png"); smallNumberPath.append("3.png"); break;
    case CFT_FOUR:bigNumberPath.append("4.png"); smallNumberPath.append("4.png"); break;
    case CFT_FIVE:bigNumberPath.append("5.png"); smallNumberPath.append("5.png"); break;
    case CFT_SIX:bigNumberPath.append("6.png"); smallNumberPath.append("6.png"); break;
    case CFT_SEVEN:bigNumberPath.append("7.png"); smallNumberPath.append("7.png"); break;
    case CFT_EIGHT:bigNumberPath.append("8.png"); smallNumberPath.append("8.png"); break;
    case CFT_NINE:bigNumberPath.append("9.png"); smallNumberPath.append("9.png"); break;
    case CFT_TEN:bigNumberPath.append("10.png"); smallNumberPath.append("10.png"); break;
    case CFT_JACK:bigNumberPath.append("J.png"); smallNumberPath.append("J.png"); break;
    case CFT_QUEEN:bigNumberPath.append("Q.png"); smallNumberPath.append("Q.png"); break;
    case CFT_KING:bigNumberPath.append("K.png"); smallNumberPath.append("K.png"); break;
    }
    _bigNumber = Sprite::create(bigNumberPath.getCString());
    _bigNumber->setPosition(cocos2d::Vec2(130, 165));
    addChild(_bigNumber);

    _smallNumber = Sprite::create(smallNumberPath.getCString());
    _smallNumber->setPosition(cocos2d::Vec2(50, 330));
    addChild(_smallNumber);
}

void CardView::updateDisplay(const CardModel& model) {
	// 2. 更新位置
	setPosition(model.cardPosition);
}
// 卡牌平移动画
void CardView::playMoveAnimation(const CardModel& model) {
    auto moveAction = MoveTo::create(0.3f, model.cardPosition);
    this->runAction(moveAction);
}
void CardView::setClickCallback(const std::function<void(Ref*)>& callback) {
    // 添加点击事件（需结合 Widget 的触摸监听）
    setTouchEnabled(true);
    setSwallowTouches(true);
    addClickEventListener(callback);
}

void CardView::clearClickCallback() {
    // 移除所有点击事件监听器
    _clickEventListener = nullptr;
    this->setTouchEnabled(false); // 可选：禁用触摸
}
