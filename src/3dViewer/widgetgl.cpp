#include "widgetgl.h"

#include <iostream>

namespace s21 {
WidgetGL::WidgetGL(QWidget* parent) : QOpenGLWidget(parent) {}
void WidgetGL::initializeGL() {
  vertex_size = 5;
  vertex_color = QColor(0, 255, 255);

  edge_size = 1;
  edge_color = QColor(255, 255, 255);

  projection_type = 0;
  vertex_type = 0;
  line_type = 0;

  glClearColor(0, 0, 0, 1);
  glEnable(GL_DEPTH_TEST);
}

void WidgetGL::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, static_cast<float>(w) / h, 0.01, 100.);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(0, 0, 5, 0, 0, 0, 0.0f, 1.0f, 0.0f);
}

void WidgetGL::paintGL() {
  glClearColor(background_color.redF(), background_color.greenF(),
               background_color.blueF(), 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  switch (projection_type) {
    case 0:
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(45, static_cast<float>(width()) / height(), 0.01, 100.);
      break;
    case 1:
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
      break;
  }

  switch (line_type) {
    case 0:
      glDisable(GL_LINE_STIPPLE);
      glLineWidth(edge_size);
      break;
    case 1:
      glLineWidth(edge_size);
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(4, 0xAAAA);
      break;
  }

  vertices = std::vector<glm::vec3>(controller.getVertices(),
                                    controller.getVerticesEnd());
  faces = std::vector<std::vector<size_t>>(controller.getFaces(),
                                           controller.getFacesEnd());

  glColor3f(edge_color.redF(), edge_color.greenF(), edge_color.blueF());
  glBegin(GL_LINES);
  for (const auto& face : faces) {
    for (size_t i = 0; i < face.size() - 1; i++) {
      glVertex3fv(glm::value_ptr(vertices[face[i] - 1]));
      glVertex3fv(glm::value_ptr(vertices[face[i + 1] - 1]));
    }
  }
  glEnd();

  glColor3f(vertex_color.redF(), vertex_color.greenF(), vertex_color.blueF());
  switch (vertex_type) {
    case 0:
      glPointSize(vertex_size);
      break;
    case 1:
      glPointSize(vertex_size);
      glBegin(GL_POINTS);
      break;
    case 2:
      glPointSize(vertex_size);
      glBegin(GL_POINTS);
      break;
  }

  for (const glm::vec3& vertex : vertices) {
    glVertex3fv(glm::value_ptr(vertex));
  }
  glEnd();
  glFlush();
}

void WidgetGL::loadModel(const std::string& filename) {
  controller.loadModel(filename.c_str());
  this->filename = filename;
  vertex_count = controller.getVerticesSize();
  faces_count = controller.getFacesSize();
  update();
}

void WidgetGL::setModelPosition(float x, float y, float z) {
  controller.setPossition(glm::vec3(x, y, z));
  update();
}

void WidgetGL::setRotation(float angle, glm::vec3 axis) {
  controller.setRotation(angle, axis);
  update();
}

void WidgetGL::setScale(float scale) {
  controller.setScale(scale);
  update();
}

void WidgetGL::setProjection(int index) {
  projection_type = index;
  update();
}

void WidgetGL::setLineType(int index) {
  line_type = index;
  update();
}

void WidgetGL::setLineWidth(float width) {
  edge_size = width;
  update();
}

void WidgetGL::setLineColor(QColor color) {
  edge_color = color;
  update();
}

void WidgetGL::setVertexType(int index) {
  vertex_type = index;
  update();
}

void WidgetGL::setVertexSize(float size) {
  vertex_size = size;
  update();
}

void WidgetGL::setVertexColor(QColor color) {
  vertex_color = color;
  update();
}

void WidgetGL::setBackgroundColor(QColor color) {
  background_color = color;
  update();
}

}  // namespace s21
