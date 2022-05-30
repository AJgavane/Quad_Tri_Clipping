#include "pch.h"
#include "Tests.h"
#include "utils.h"

void Test1()
{
	vector<glm::vec2> quad;
	quad.push_back(glm::vec2(-1, 1));
	quad.push_back(glm::vec2(1, 1));
	quad.push_back(glm::vec2(1, -1));
	quad.push_back(glm::vec2(-1, -1));

	vector<glm::vec2> tri;
	tri.push_back(glm::vec2(-2, 0));
	tri.push_back(glm::vec2(0, 2));
	tri.push_back(glm::vec2(2, 0));


	vector<glm::vec2> edges;
	edges.emplace_back(0, 1);
	edges.push_back(glm::vec2(1, 2));
	edges.push_back(glm::vec2(2, 0));

	vector<glm::vec2> outputList = clippedPolygon(quad, tri, edges);

	printVecList("clipped Poly: ", outputList);
}

void Test2()
{
	vector<glm::vec2> quad;
	quad.push_back(glm::vec2(-1, 2));
	quad.push_back(glm::vec2(1, 2));
	quad.push_back(glm::vec2(1, 0));
	quad.push_back(glm::vec2(-1, 0));

	vector<glm::vec2> tri;
	tri.push_back(glm::vec2(-2, 0));
	tri.push_back(glm::vec2(0, 2));
	tri.push_back(glm::vec2(2, 0));


	vector<glm::vec2> edges;
	edges.push_back(glm::vec2(0, 1));
	edges.push_back(glm::vec2(1, 2));
	edges.push_back(glm::vec2(2, 0));

	vector<glm::vec2> outputList = clippedPolygon(quad, tri, edges);

	printVecList("clipped Poly: ", outputList);
}