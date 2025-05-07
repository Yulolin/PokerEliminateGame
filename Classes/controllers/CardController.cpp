#include "CardController.h"

CardController::CardController() {

}

CardController::CardController(CardModel cardModel, cocos2d::Scene* scene) {
	this->cardModel = cardModel;
	cardView = CardView::create();
	scene->addChild(cardView);
	cardView->initDisplay(this->cardModel);
}

void CardController::setClickCallback(const std::function<void(Ref*)>& callback) {
	cardView->setClickCallback(callback);
}

void CardController::setCardMove(cocos2d::Vec2 position) {
	cardModel.cardPosition = position;
	cardView->playMoveAnimation(cardModel);
}

// ÉèÖÃ¿¨Æ¬Î»ÖÃ
void CardController::setCardPosition(cocos2d::Vec2 position) {
	cardModel.cardPosition = position;
	cardView->updateDisplay(cardModel);
}

void CardController::setViewZOrder(int ZOrder) {
	cardView->setZOrder(ZOrder);
}
