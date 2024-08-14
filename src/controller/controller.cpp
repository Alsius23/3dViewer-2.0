#include "controller.h"

namespace s21 {

void Controller::setPossition(const glm::vec3 &newPosition) {
  model.setPossition(newPosition);
}

void Controller::setRotation(float angle, glm::vec3 axis) {
  model.rotate(angle, axis);
}

void Controller::setScale(float scale) { model.scale(scale); }

void Controller::loadModel(const std::string &filename) {
  model.read_file(filename.c_str());
}

void Controller::rotateModel(float angle, glm::vec3 axis) {
  model.rotate(angle, axis);
}

void Controller::scaleModel(float scaleFactor) { model.scale(scaleFactor); }

void Controller::translateModel(const glm::vec3 &translation) {
  model.translate(translation);
}

}  // namespace s21
