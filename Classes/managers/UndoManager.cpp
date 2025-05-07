#include "UndoManager.h"

Operation::Operation(CardController* card) {
	this->card = card;
	this->preFieldType = card->cardModel.cardField;
	this->prePosition = card->cardModel.cardPosition;
}
// 记录玩家操作
void UndoManager::recordPlayerAction(CardController* card) {
	Operation operation = Operation(card);
	_operationStack.push(operation);
}
// 撤销操作
Operation UndoManager::undoOperation() {
	if (_operationStack.size() == 0) {
		Operation o = Operation();
		o.card = nullptr;
		return o;
	}
	Operation operation = _operationStack.top();
	_operationStack.pop();
	return operation;
}