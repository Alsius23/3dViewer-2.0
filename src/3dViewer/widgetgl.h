#ifndef WIDGETGL_H
#define WIDGETGL_H

#include <GL/glut.h>

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QWidget>
#include <glm/ext.hpp>

#include "../controller/controller.h"
#include "../model/model.h"

namespace s21 {

/**
 * @brief Класс для визуализации 3D модели в OpenGL.
 *
 * Класс WidgetGL наследует от QOpenGLWidget и предоставляет функциональность
 * для отображения 3D модели, а также взаимодействия с пользователем для
 * изменения параметров отображения.
 */
class WidgetGL : public QOpenGLWidget {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор класса WidgetGL.
   *
   * Создает новый объект WidgetGL.
   *
   * @param parent Родительский виджет.
   */
  WidgetGL(QWidget* parent = nullptr);

  /**
   * @brief Возвращает имя загруженного файла модели.
   *
   * @return Имя загруженного файла модели.
   */
  std::string getFileName() { return filename; }

  /**
   * @brief Возвращает количество вершин модели.
   *
   * @return Количество вершин модели.
   */
  size_t getVertexCount() { return vertex_count; }

  /**
   * @brief Возвращает количество граней модели.
   *
   * @return Количество граней модели.
   */
  size_t getFacesCount() { return faces_count; }

 public slots:
  /**
   * @brief Загружает модель из указанного файла.
   *
   * @param filename Путь к файлу с моделью.
   */
  void loadModel(const std::string& filename);

  /**
   * @brief Устанавливает позицию модели.
   *
   * @param x Координата x позиции.
   * @param y Координата y позиции.
   * @param z Координата z позиции.
   */
  void setModelPosition(float x, float y, float z);

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
   * @brief Устанавливает тип линии для отображения модели.
   *
   * @param index Индекс типа линии.
   */
  void setLineType(int index);

  /**
   * @brief Устанавливает тип проекции для отображения модели.
   *
   * @param index Индекс типа проекции.
   */
  void setProjection(int index);

  /**
   * @brief Устанавливает ширину линии для отображения модели.
   *
   * @param width Ширина линии.
   */
  void setLineWidth(float width);

  /**
   * @brief Устанавливает цвет линии для отображения модели.
   *
   * @param color Цвет линии.
   */
  void setLineColor(QColor color);

  /**
   * @brief Устанавливает тип отображения вершин модели.
   *
   * @param index Индекс типа отображения вершин.
   */
  void setVertexType(int index);

  /**
   * @brief Устанавливает размер вершин модели.
   *
   * @param size Размер вершин.
   */
  void setVertexSize(float size);

  /**
   * @brief Устанавливает цвет вершин модели.
   *
   * @param color Цвет вершин.
   */
  void setVertexColor(QColor color);

  /**
   * @brief Устанавливает цвет фона.
   *
   * @param color Цвет фона.
   */
  void setBackgroundColor(QColor color);

 protected:
  /**
   * @brief Инициализация OpenGL контекста.
   */
  virtual void initializeGL() override;

  /**
   * @brief Изменение размеров OpenGL окна.
   *
   * @param w Ширина окна.
   * @param h Высота окна.
   */
  virtual void resizeGL(int w, int h) override;

  /**
   * @brief Отрисовка сцены.
   */
  virtual void paintGL() override;

 private:
  std::string filename;  // Имя загруженного файла модели

  size_t vertex_count;      // Количество вершин модели
  size_t faces_count;       // Количество граней модели
  float vertex_size;        // Размер вершин
  QColor vertex_color;      // Цвет вершин
  float edge_size;          // Ширина линий
  QColor edge_color;        // Цвет линий
  QColor background_color;  // Цвет фона

  int projection_type;  // Тип проекции
  int line_type;        // Тип линии
  int vertex_type;      // Тип отображения вершин

  s21::Controller controller;  // Контроллер модели

  std::vector<glm::vec3> vertices;  // Векторы вершин
  std::vector<std::vector<size_t>> faces;  // Индексы вершин в гранях
};

}  // namespace s21

#endif  // WIDGETGL_H
