#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFile>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Главное окно приложения.
 *
 * Класс MainWindow предоставляет пользовательский интерфейс для взаимодействия
 * с приложением, обработки пользовательского ввода и передачи данных
 * контроллеру.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор главного окна.
   *
   * Создает новое окно и инициализирует пользовательский интерфейс.
   *
   * @param parent Родительский виджет.
   */
  MainWindow(QWidget *parent = nullptr);

  /**
   * @brief Деструктор главного окна.
   *
   * Освобождает ресурсы, связанные с окном.
   */
  ~MainWindow();

 signals:
  /**
   * @brief Сигнал, отправляемый при изменении позиции модели.
   *
   * @param x Координата x новой позиции.
   * @param y Координата y новой позиции.
   * @param z Координата z новой позиции.
   */
  void positionChanged(float x, float y, float z);

 private slots:
  /**
   * @brief Обработчик события нажатия кнопки загрузки файла.
   */
  void on_file_button_clicked();

  /**
   * @brief Обработчик события изменения текста в поле ввода координаты x.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_line_x_textChanged(const QString &arg1);

  /**
   * @brief Обработчик события изменения текста в поле ввода координаты y.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_line_y_textChanged(const QString &arg1);

  /**
   * @brief Обработчик события изменения текста в поле ввода координаты z.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_line_z_textChanged(const QString &arg1);

  /**
   * @brief Обработчик события изменения текста в поле ввода угла поворота по
   * оси x.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_line_x_rotation_textChanged(const QString &arg1);

  /**
   * @brief Обработчик события изменения текста в поле ввода угла поворота по
   * оси y.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_line_y_rotation_textChanged(const QString &arg1);

  /**
   * @brief Обработчик события изменения текста в поле ввода угла поворота по
   * оси z.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_line_z_rotation_textChanged(const QString &arg1);

  /**
   * @brief Обработчик события изменения текста в поле ввода имени файла.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_file_change_name_textEdited(const QString &arg1);

  /**
   * @brief Обработчик события изменения текста в поле ввода коэффициента
   * масштабирования.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_scale_koef_textChanged(const QString &arg1);

  /**
   * @brief Обработчик события нажатия кнопки масштабирования.
   */
  void on_scale_clicked();

  /**
   * @brief Обработчик события изменения индекса выбранного типа проекции.
   *
   * @param index Индекс выбранного типа проекции.
   */
  void on_projection_currentIndexChanged(int index);

  /**
   * @brief Обработчик события изменения индекса выбранного типа линии.
   *
   * @param index Индекс выбранного типа линии.
   */
  void on_linetype_currentIndexChanged(int index);

  /**
   * @brief Обработчик события изменения текста в поле ввода ширины линии.
   *
   * @param arg1 Новый текст в поле ввода.
   */
  void on_edge_size_textChanged(const QString &arg1);

  /**
   * @brief Открывает диалог выбора цвета линии.
   */
  void line_color();

  /**
   * @brief Обработчик события изменения индекса выбранного типа вершины.
   *
   * @param index Индекс выбранного типа вершины.
   */
  void on_vertex_type_currentIndexChanged(int index);

  /**
   * @brief Обработчик события изменения текста в поле ввода размера вершины.
   *
   * @param text Новый текст в поле ввода.
   */
  void on_vertex_size_textChanged(const QString &text);

  /**
   * @brief Открывает диалог выбора цвета вершины.
   */
  void vertex_color();

  /**
   * @brief Открывает диалог выбора цвета фона.
   */
  void background_color();

 private:
  Ui::MainWindow *ui;  // Указатель на объект пользовательского интерфейса
};

#endif  // MAINWINDOW_H
