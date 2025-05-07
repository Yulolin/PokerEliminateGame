#include "UndoManager.h"

Operation::Operation(CardController* card) {
	this->card = card;
	this->preFieldType = card->cardModel.cardField;
	this->prePosition = card->cardModel.cardPosition;
}
// ��¼��Ҳ���
void UndoManager::recordPlayerAction(CardController* card) {
	Operation operation = Operation(card);
	_operationStack.push(operation);
}
// ��������
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