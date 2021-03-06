#include "ViewModel.h"
#include <utility>

StarMapVM::StarMapVM() {}

void StarMapVM::attachNotification(std::function<void(int)> _notification_func) {
	sendNotification = _notification_func;
}

void StarMapVM::detachNotification() {
	sendNotification = std::function<void(int)>();
}

std::function<void(int)> StarMapVM::getNotification() {
	return [this](int uID) {
		if (uID == 0) {
			this->sendNotification(uID);
		}
	};
}

void StarMapVM::attachModel(const std::shared_ptr<StarMap>& refModel) {
	m_refModel = refModel;
}

std::shared_ptr<StarMap> StarMapVM::detachModel() {
	return std::shared_ptr<StarMap>(std::move(m_refModel));
}

std::shared_ptr<Starmat> StarMapVM::getStarmat() {
	return m_refModel->getStarmat();
}