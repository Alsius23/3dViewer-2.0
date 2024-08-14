#include "model.h"

namespace s21 {

    void Model::read_file(const char* filename){
        std::ifstream file(filename);
        if(file.is_open()){
            clear_data();
            std::string line;
            
            while(getline(file, line)){
                if(line.empty()){
                    continue;
                }
                if (line[0] == 'v' && line[1] == ' '){
                    line = line.substr(2);
                    std::stringstream ss(line);
                    float x, y, z;
                    ss >> x >> y >> z;
                    vertices.emplace_back(x, y, z);
                } else if (line[0] == 'f'){
                    std::vector<size_t> cur_vec;
                    char* pars_str = strtok((char*)line.c_str(), "f ");
                    while(pars_str != nullptr){
                        int cur;
                        sscanf(pars_str, "%d", &cur);
                        cur_vec.push_back(cur);
                        pars_str = strtok(nullptr, " ");
                    }
                    faces.push_back(cur_vec);
                } 
            }
            normalization();
            center = calculate_center(vertices);
            modelMatrix = glm::mat4(1.0f);
            current_rotation = glm::vec3(0.0f);
            file.close();
        }
    }

    void Model::clear_data(){
        vertices.clear();
        faces.clear();
    }

    void Model::normalization(){
        glm::vec3 min_values = glm::vec3(std::numeric_limits<float>::max());
        glm::vec3 max_values = glm::vec3(std::numeric_limits<float>::min());
        for(const glm::vec3& vertex : vertices){
            min_values = glm::min(min_values, vertex);
            max_values = glm::max(max_values, vertex);
        }
        glm::vec3 range = max_values - min_values;
        float scale = 2.0 / std::max(range.x, glm::max(range.y, range.z));

        for (auto& vertex : vertices) {
            vertex = (vertex - min_values) * scale - glm::vec3(1.0f);
        }

        glm::vec3 center = calculate_center(vertices);
        for(glm::vec3& vertex : vertices){
            vertex -= center;
        }
        center = calculate_center(vertices);
    }

    void Model::setPossition(const glm::vec3 &newPossition){
        glm::vec3 delta = newPossition - center;
        for(auto& vertex: vertices){
            vertex += delta;
        }
        center = newPossition;
    }

    void Model::rotate(float angle, glm::vec3 axis){
        glm::vec3 diff_r = current_rotation * axis;
        float diff = angle - diff_r.x - diff_r.y - diff_r.z;
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(diff), axis);
        current_rotation += diff * axis;

        modelMatrix *= rotationMatrix;

        for(auto &vertex : vertices){
            vertex -= center;
        }

        for(auto &vertex : vertices){
            vertex = rotationMatrix * glm::vec4(vertex, 1.0f);
        }

        for(auto &vertex : vertices){
            vertex += center;
        }
    }

    glm::vec3 Model::calculate_center(const std::vector<glm::vec3>& vertices){
        glm::vec3 center(0.0f);
        for(const glm::vec3& vertex : vertices){
            center += vertex;
        }
        return center / static_cast<float>(vertices.size());
    }

    void Model::scale(float scale_factor){
        for(glm::vec3& vertex : vertices){
            vertex *= scale_factor;
        }
    }

    void Model::translate(const glm::vec3& translation){
        for(glm::vec3& vertex : vertices){
            vertex += translation;
        }
    }
}
