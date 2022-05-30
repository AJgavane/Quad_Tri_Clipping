#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <glm/glm.hpp>

using namespace std;

void printVec(const string& str, glm::vec2 v);
void printVec(const string& str, glm::vec3 v);
void printVecList(const string& str, vector<glm::vec2> list);

bool pointInsideEdge(glm::vec2 p, glm::vec2 v1, glm::vec2 v2);
int computeIntersection(glm::vec2 p1, glm::vec2 p2, glm::vec2 v1, glm::vec2 v2, glm::vec2& intersection);
vector<glm::vec2> clippedPolygon(vector<glm::vec2> quad, vector<glm::vec2>clipTriVerts, vector<glm::vec2>clipTriEdges);