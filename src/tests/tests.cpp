#include "../model/model.h"
#include "gtest/gtest.h"

TEST(Model, read_file) {
  s21::Model md;
  int code = 0;
  md.read_file("object_files/cube.obj");
  if (md.vertices_size() == 0 || md.faces_size() == 0) code = 1;
  md.clear_data();
  EXPECT_EQ(0, code);
}

TEST(Model, normalization) {
  s21::Model md;
  int code = 0;
  md.read_file("object_files/cube.obj");
  if (md.vertices_size() == 0 || md.faces_size() == 0) code = 1;
  md.normalization();
  if (md.vertices_size() != 8 || md.faces_size() != 12) code = 1;
  md.clear_data();
  EXPECT_EQ(0, code);
}

TEST(Model, rotate) {
  s21::Model md;
  int code = 0;
  md.read_file("object_files/cube.obj");
  if (md.vertices_size() == 0 || md.faces_size() == 0) code = 1;
  md.normalization();
  if (md.vertices_size() != 8 || md.faces_size() != 12) code = 1;
  md.rotate(0.5, glm::vec3(0.0f, 1.0f, 0.0f));
  EXPECT_EQ(0, code);
  md.clear_data();
}

TEST(Model, translate) {
  s21::Model md;
  int code = 0;
  md.read_file("object_files/cube.obj");
  if (md.vertices_size() != 8 || md.faces_size() != 12) code = 1;
  md.translate(glm::vec3(0.0f, 1.0f, 0.0f));
  EXPECT_EQ(0, code);
  md.clear_data();
}

TEST(Model, setPosition) {
  s21::Model md;
  int code = 0;
  md.read_file("object_files/cube.obj");
  if (md.vertices_size() != 8 || md.faces_size() != 12) code = 1;
  md.setPossition(glm::vec3(0.0f, 1.0f, 0.0f));
  EXPECT_EQ(0, code);
  md.clear_data();
}

TEST(Model, scale) {
  s21::Model md;
  int code = 0;
  md.read_file("object_files/cube.obj");
  md.scale(1.1);
  if (md.vertices_size() != 8 || md.faces_size() != 12) code = 1;
  EXPECT_EQ(0, code);
  md.clear_data();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
