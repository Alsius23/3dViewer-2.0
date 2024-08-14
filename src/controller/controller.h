#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H
#include "../model/model.h"
namespace s21 {
/**
 * @brief Класс контроллера для управления 3D моделью.
 *
 * Класс Controller предоставляет интерфейс для доступа и модификации данных 3D
 * модели,
 *
 */
class Controller {
 public: /**
          * @brief Конструктор по умолчанию.
          *
          *
          * Создает объект контроллера с пустой моделью.
          */
  Controller() = default;
  /**
   * @brief Возвращает итератор на начало списка вершин модели.
   *
   * @return Итератор на начало списка вершин модели.
   */
  auto getVertices() const { return model.vertices_begin(); }
  /**
   * @brief Возвращает итератор на конец списка вершин модели.
   *
   * @return Итератор на конец списка вершин модели.
   */
  auto getVerticesEnd() const { return model.vertices_end(); }
  /**
   * @brief Возвращает количество вершин в модели.
   *
   * @return Количество вершин в модели.
   */
  size_t getVerticesSize() const { return model.vertices_size(); }
  /**
   * @brief Возвращает итератор на начало списка граней модели.
   *
   * @return Итератор на начало списка граней модели.
   */
  auto getFaces() const { return model.faces_begin(); }
  /**
   * @brief Возвращает итератор на конец списка граней модели.
   *
   * @return Итератор на конец списка граней модели.
   */
  auto getFacesEnd() const { return model.faces_end(); }
  /**
   * @brief Возвращает количество граней в модели.
   *
   * @return Количество граней в модели.
   */
  size_t getFacesSize() const { return model.faces_size(); }
  /**
   * @brief Устанавливает позицию модели.
   *
   * @param newPosition Новая позиция модели.
   */
  void setPossition(const glm::vec3& newPosition);
  /**
   * @brief Устанавливает вращение модели.
   *
   * @param angle Угол вращения в радианах.
   * @param axis Ось вращения.
   */
  void setRotation(float angle, glm::vec3 axis);
  /**
   * @brief Устанавливает масштаб модели.
   *
   * @param scale Коэффициент масштабирования.
   */
  void setScale(float scale);
  /**
   * @brief Загружает модель из файла.
   *
   * @param filename Путь к файлу с моделью.
   */
  void loadModel(const std::string& filename);
  /**
   * @brief Вращает модель вокруг заданной оси на указанный угол.
   *
   * @param angle Угол вращения в радианах.
   * @param axis Ось вращения.
   */
  void rotateModel(float angle, glm::vec3 axis);
  /**
   * @brief Масштабирует модель.
   *
   * @param scaleFactor Коэффициент масштабирования.
   */
  void scaleModel(float scaleFactor);
  /**
   * @brief Перемещает модель на указанный вектор.
   *
   * @param translation Вектор смещения.
   */
  void translateModel(const glm::vec3& translation);
  /**
   * @brief Нормализует модель.
   */
  void normalize() { model.normalization(); };
  /**
   * @brief Возвращает текущую модель.
   *
   * @return Текущая модель.
   */
  s21::Model getModel();

 private:
  s21::Model model;  // Модель данных
};
}  // namespace s21
#endif  // SRC_CONTROLLER_H
