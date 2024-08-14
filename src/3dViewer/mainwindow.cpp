#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("3dViewer");

  connect(ui->file_button, &QPushButton::clicked, this,
          &MainWindow::on_file_button_clicked);
  connect(ui->line_x, &QLineEdit::textChanged, this,
          &MainWindow::on_line_x_textChanged);
  connect(ui->line_y, &QLineEdit::textChanged, this,
          &MainWindow::on_line_y_textChanged);
  connect(ui->line_z, &QLineEdit::textChanged, this,
          &MainWindow::on_line_z_textChanged);
  connect(ui->line_x_rotation, &QLineEdit::textChanged, this,
          &MainWindow::on_line_x_rotation_textChanged);
  connect(ui->line_y_rotation, &QLineEdit::textChanged, this,
          &MainWindow::on_line_y_rotation_textChanged);
  connect(ui->line_z_rotation, &QLineEdit::textChanged, this,
          &MainWindow::on_line_z_rotation_textChanged);
  connect(ui->file_change_name, &QLineEdit::textEdited, this,
          &MainWindow::on_file_change_name_textEdited);
  connect(ui->scale_koef, &QLineEdit::textEdited, this,
          &MainWindow::on_scale_koef_textChanged);
  connect(ui->scale, &QPushButton::clicked, this,
          &MainWindow::on_scale_clicked);
  connect(ui->projection, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MainWindow::on_projection_currentIndexChanged);
  connect(ui->linetype, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MainWindow::on_linetype_currentIndexChanged);
  connect(ui->edge_size, &QLineEdit::textChanged, this,
          &MainWindow::on_edge_size_textChanged);
  connect(ui->line_color, &QPushButton::clicked, this, &MainWindow::line_color);
  connect(ui->vertex_type, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MainWindow::on_vertex_type_currentIndexChanged);
  connect(ui->vertex_size, &QLineEdit::textChanged, this,
          &MainWindow::on_vertex_size_textChanged);
  connect(ui->vertex_color, &QPushButton::clicked, this,
          &MainWindow::vertex_color);
  connect(ui->background_color, &QPushButton::clicked, this,
          &MainWindow::background_color);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_file_button_clicked() {
  std::string file = ui->file_change_name->text().toStdString();
  ui->openGLWidget->loadModel(file);
  ui->file_name->setText(
      QString().fromStdString(ui->openGLWidget->getFileName()));
  ui->vertex_count->setText(
      QString::number(ui->openGLWidget->getVertexCount()));
  ui->face_count->setText(QString::number(ui->openGLWidget->getFacesCount()));
  ui->line_x->setText("0");
  ui->line_y->setText("0");
  ui->line_z->setText("0");
  ui->line_x_rotation->setText("0");
  ui->line_y_rotation->setText("0");
  ui->line_z_rotation->setText("0");
}

void MainWindow::on_line_x_textChanged(const QString &text) {
  bool ok;
  float x = text.toFloat(&ok);
  if (ok) {
    float y = ui->line_y->text().toFloat();
    float z = ui->line_z->text().toFloat();
    ui->openGLWidget->setModelPosition(x, y, z);
  }
}

void MainWindow::on_line_y_textChanged(const QString &text) {
  bool ok;
  float y = text.toFloat(&ok);
  if (ok) {
    float x = ui->line_x->text().toFloat();
    float z = ui->line_z->text().toFloat();
    ui->openGLWidget->setModelPosition(x, y, z);
  }
}

void MainWindow::on_line_z_textChanged(const QString &text) {
  bool ok;
  float z = text.toFloat(&ok);
  if (ok) {
    float x = ui->line_x->text().toFloat();
    float y = ui->line_y->text().toFloat();
    ui->openGLWidget->setModelPosition(x, y, z);
  }
}

void MainWindow::on_line_x_rotation_textChanged(const QString &text) {
  bool ok;
  float angle = text.toFloat(&ok);
  if (ok) {
    ui->openGLWidget->setRotation(angle, glm::vec3(1, 0, 0));
  }
}

void MainWindow::on_line_y_rotation_textChanged(const QString &text) {
  bool ok;
  float angle = text.toFloat(&ok);
  if (ok) {
    ui->openGLWidget->setRotation(angle, glm::vec3(0, 1, 0));
  }
}

void MainWindow::on_line_z_rotation_textChanged(const QString &text) {
  bool ok;
  float angle = text.toFloat(&ok);
  if (ok) {
    ui->openGLWidget->setRotation(angle, glm::vec3(0, 0, 1));
  }
}

void MainWindow::on_file_change_name_textEdited(const QString &text) {
  QFile file(text.toStdString().c_str());
  if (file.open(QIODevice::ReadOnly)) {
    ui->file_button->setEnabled(true);
    file.close();
  } else {
    ui->file_button->setEnabled(false);
  }
}

void MainWindow::on_scale_koef_textChanged(const QString &text) {
  bool ok;
  text.toFloat(&ok);
  if (ok) {
    ui->scale->setEnabled(true);
  } else {
    ui->scale->setEnabled(false);
  }
}

void MainWindow::on_scale_clicked() {
  float scale = ui->scale_koef->text().toFloat();
  ui->openGLWidget->setScale(scale);
}

void MainWindow::on_projection_currentIndexChanged(int index) {
  ui->openGLWidget->setProjection(index);
}

void MainWindow::on_linetype_currentIndexChanged(int index) {
  ui->openGLWidget->setLineType(index);
}

void MainWindow::on_edge_size_textChanged(const QString &text) {
  bool ok;
  float size = text.toFloat(&ok);
  if (ok) {
    ui->openGLWidget->setLineWidth(size);
  }
}

void MainWindow::line_color() {
  QColorDialog dialog;
  if (dialog.exec()) {
    QColor color = dialog.selectedColor();
    ui->openGLWidget->setLineColor(color);
  }
}

void MainWindow::on_vertex_type_currentIndexChanged(int index) {
  ui->openGLWidget->setVertexType(index);
}

void MainWindow::on_vertex_size_textChanged(const QString &text) {
  bool ok;
  float size = text.toFloat(&ok);
  if (ok) {
    ui->openGLWidget->setVertexSize(size);
  }
}

void MainWindow::vertex_color() {
  QColorDialog dialog;
  if (dialog.exec()) {
    QColor color = dialog.selectedColor();
    ui->openGLWidget->setVertexColor(color);
  }
}

void MainWindow::background_color() {
  QColorDialog dialog;
  if (dialog.exec()) {
    QColor color = dialog.selectedColor();
    ui->openGLWidget->setBackgroundColor(color);
  }
}
