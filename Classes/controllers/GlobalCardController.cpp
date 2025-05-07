#include "GlobalCardController.h"

GlobalCardController::GlobalCardController() {
	_undoManager = UndoManager();
}

void GlobalCardController::cardsInit(std::vector<CardModel> cardModels, cocos2d::Scene* scene) {
	
	// �����һ�ż�������ջ��
	CardModel stackModel = cardModels.back();
	cardModels.pop_back();
	stackModel.cardField = CFT_STACK;
	stackModel.cardPosition = cocos2d::Vec2(_stackX, _cardY);

	CardController* firstStackCard = new CardController(stackModel, scene);
	setCardClickCallback(firstStackCard);
	// ����gameModel��ջ��
	gameModel.stackCards.push(firstStackCard);
	// ������������
	for (CardModel cardModel : cardModels) {

		// ����CardController���󶨻ص�����
		if (cardModel.cardField == CFT_PLAYERFIELD) {
			cardModel.cardPosition += cocos2d::Vec2(0, _playerFieldY);
			CardController* card = new CardController(cardModel, scene);
			setCardClickCallback(card);
			gameModel.playerFieldCards.insert(card);
		}
		else {
			CardController* card = new CardController(cardModel, scene);
			setCardClickCallback(card);
			addToHand(card);
		}
	}
}

void GlobalCardController::addToHand(CardController* cardController) {
	if (cardController == nullptr) {
		return;
	}

	gameModel.handCards.insert(cardController);
	cardController->cardView->setZOrder(gameModel.handCards.size());
	float deltaX = (_handAreaRightX - _handAreaLeftX) / (gameModel.handCards.size() + 1);
	int i = 0;
	for (auto it:gameModel.handCards)
	{
		i++;
		cocos2d::Vec2 pos = cocos2d::Vec2(_handAreaLeftX + deltaX * (i + 1), _cardY);
		it->setCardPosition(pos);
	}
}

void GlobalCardController::handToStack(CardController* cardController) {
	std::set<CardController*>::iterator handCard = gameModel.handCards.find(cardController);
	if (handCard == gameModel.handCards.end()) {
		return;
	}
	gameModel.handCards.erase(handCard);
	gameModel.stackCards.push(cardController);
	cardController->cardModel.cardField = CFT_STACK;
	cocos2d::Vec2 pos = cocos2d::Vec2(_stackX, _cardY);
	cardController->setCardMove(pos);
	updateStackCardLayer();
}

void GlobalCardController::addToStack(CardController* cardController) {
	cocos2d::Vec2 pos = cocos2d::Vec2(_stackX, _cardY);
	cardController->setCardMove(pos);
	gameModel.stackCards.push(cardController);
	cardController->cardModel.cardField = CFT_STACK;
	updateStackCardLayer();
}

void GlobalCardController::setCardClickCallback(CardController* cardController) {
	// �󶨻ص������� Cocos2d-x �� Ref* ������
	cardController->setClickCallback([this, cardController](Ref* sender) {
		this->onCardClicked(sender, cardController);
		});
}

void GlobalCardController::onCardClicked(Ref* sender, CardController* cardController) {
	if (cardController->cardModel.cardField == CFT_PLAYERFIELD) {
		int clickCard = cardController->cardModel.cardFace;
		int stackCard = gameModel.stackCards.top()->cardModel.cardFace;
		if (clickCard == stackCard + 1 || clickCard == stackCard - 1) {
			_undoManager.recordPlayerAction(cardController);
			addToStack(cardController);
		}
	}
	else if (cardController->cardModel.cardField == CFT_STACK) {

	}
	else if (cardController->cardModel.cardField == CFT_HAND) {
		_undoManager.recordPlayerAction(cardController);
		handToStack(cardController);
	}
	//cardController->cardModel.cardPosition.x = 800;
	//cardController->cardView->updateDisplay(cardController->cardModel);
}

void GlobalCardController::updateStackCardLayer() {
	if (gameModel.stackCards.size() == 0) {
		return;
	}
	gameModel.stackCards.top()->cardView->setZOrder(gameModel.stackCards.size());
}

void GlobalCardController::undoAction() {
	Operation operation = _undoManager.undoOperation();
	CardController* card = operation.card;
	if (card == nullptr) {
		return;
	}
	gameModel.stackCards.pop();
	if (operation.preFieldType == CFT_HAND) {
		gameModel.handCards.insert(card);
		card->cardModel.cardField = CFT_HAND;
		card->setCardMove(operation.prePosition);
	}
	else if (operation.preFieldType == CFT_PLAYERFIELD) {
		gameModel.playerFieldCards.insert(card);
		card->cardModel.cardField = CFT_PLAYERFIELD;
		card->setCardMove(operation.prePosition);
	}
}