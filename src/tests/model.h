#ifndef SRC_MODEL_H
#define SRC_MODEL_H
#include <fstream>
#include <glm/ext.hpp>
#include <regex>
#include <string>
#include <vector>

namespace s21 {
/**
 * @brief Класс для представления и обработки 3D модели.
 *
 * Класс Model используется для хранения информации о геометрии 3D модели,
 * а также для выполнения различных операций над ней, таких как вращение,
 * масштабирование и перемещение.
 */
class Model {
 public:
  /**
   * @brief Конструктор по умолчанию.
   *
   * Создает пустой объект модели.
   */
  Model() = default;

  /**
   * @brief Деструктор по умолчанию.
   *
   * Освобождает ресурсы, связанные с моделью.
   */
  ~Model() = default;

  /**
   * @brief Очищает данные модели.
   *
   * Удаляет все вершины и грани из модели.
   */
  void clear_data();

  /**
   * @brief Загружает модель из файла.
   *
   * Читает данные о вершинах и гранях из указанного файла и заполняет ими
   * модель.
   *
   * @param filename Путь к файлу с моделью.
   */
  void read_file(const char* filename);

  /**
   * @brief Вращает модель вокруг заданной оси на указанный угол.
   *
   * @param angle Угол вращения в радианах.
   * @param axis Ось вращения.
   */
  void rotate(float angle, glm::vec3 axis);

  /**
   * @brief Масштабирует модель.
   *
   * Увеличивает или уменьшает размеры модели в соответствии с указанным
   * коэффициентом.
   *
   * @param scale Коэффициент масштабирования.
   */
  void scale(float scale);

  /**
   * @brief Перемещает модель на указанный вектор.
   *
   * @param translation Вектор смещения.
   */
  void translate(const glm::vec3& translation);

  /**
   * @brief Нормализует модель.
   *
   * Приводит модель к стандартному положению с центром в начале координат.
   */
  void normalization();

  /**
   * @brief Устанавливает позицию центра модели.
   *
   * @param newPossition Новая позиция центра модели.
   */
  void setPossition(const glm::vec3& newPossition);

  /**
   * @brief Возвращает итератор на начало списка вершин.
   *
   * @return Итератор на начало списка вершин.
   */
  auto vertices_begin() const { return vertices.begin(); }

  /**
   * @brief Возвращает итератор на конец списка вершин.
   *
   * @return Итератор на конец списка вершин.
   */
  auto vertices_end() const { return vertices.end(); }

  /**
   * @brief Возвращает количество вершин в модели.
   *
   * @return Количество вершин.
   */
  size_t vertices_size() const { return vertices.size(); }

  /**
   * @brief Возвращает итератор на начало списка граней.
   *
   * @return Итератор на начало списка граней.
   */
  auto faces_begin() const { return faces.begin(); }

  /**
   * @brief Возвращает итератор на конец списка граней.
   *
   * @return Итератор на конец списка граней.
   */
  auto faces_end() const { return faces.end(); }

  /**
   * @brief Возвращает количество граней в модели.
   *
   * @return Количество граней.
   */
  size_t faces_size() const { return faces.size(); }

 private:
  /**
   * @brief Вычисляет центр модели.
   *
   * @param vertices Список вершин модели.
   * @return Координаты центра модели.
   */
  glm::vec3 calculate_center(const std::vector<glm::vec3>& vertices);

  glm::vec3 center;                 // Центр модели
  glm::vec3 current_rotation;       // Текущий угол вращения
  glm::mat4 modelMatrix;            // Матрица модели
  std::vector<glm::vec3> vertices;  // Векторы вершин
  std::vector<std::vector<size_t>> faces;  // Индексы вершин в гранях
};
}  // namespace s21
#endif
