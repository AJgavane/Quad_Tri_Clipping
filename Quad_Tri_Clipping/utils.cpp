#include "pch.h"
#include "utils.h"


vector<glm::vec2> clippedPolygon(vector<glm::vec2> quad, vector<glm::vec2>clipTri, vector<glm::vec2>clipTriEdges)
{
	vector<glm::vec2> outputList = quad;
	printVecList("quad: ", outputList);
	for (glm::vec2 e : clipTriEdges)
	{
		vector<glm::vec2> inputList = outputList;
		outputList.clear();
		cout << "\nedge: " << endl;
		int listSize = inputList.size();
		for (int i = 0; i < listSize; i++)
		{
			glm::vec2 curr_point = inputList[i];
			int prevIdx = (i == 0) ? (listSize - 1) : (i - 1);
			glm::vec2 prev_point = inputList[prevIdx];
			glm::vec2 intersection = glm::vec2(0);
			if (pointInsideEdge(curr_point, clipTri[e.x], clipTri[e.y]))
			{
				if (!pointInsideEdge(prev_point, clipTri[e.x], clipTri[e.y]))
				{
					int intersected = computeIntersection(curr_point, prev_point, clipTri[e.x], clipTri[e.y], intersection);
					if (intersected == 1)
						outputList.push_back(intersection);
				}
				outputList.push_back(curr_point);
			}
			else if (pointInsideEdge(prev_point, clipTri[e.x], clipTri[e.y]))
			{
				int intersected = computeIntersection(curr_point, prev_point, clipTri[e.x], clipTri[e.y], intersection);
				if (intersected == 1)
					outputList.push_back(intersection);
			}
		}
		printVecList("list: ", outputList);
	}
	return outputList;
}

int computeIntersection(glm::vec2 p1, glm::vec2 p2, glm::vec2 v1, glm::vec2 v2, glm::vec2& intersection)
{
	// segments p1 + s*(p2-p1), v1 + t*(v2 - v1)
	glm::vec2 d0 = p2 - p1;
	glm::vec2 d1 = v2 - v1;

	glm::vec2 E = v1 - p1;

	float kross = d0.x * d1.y - d0.y * d1.x;
	float sqKross = kross * kross;

	float sqLen0 = glm::dot(d0, d0);
	float sqLen1 = glm::dot(d1, d1);

	if(sqKross > FLT_MIN * sqLen0 * sqLen1 )
	{
		// lines are not parallel
		float s = (E.x *d1.y - E.y * d1.x) / kross;
		if(s <0 || s > 1)
		{
			// not a point on segment
			return 0;
		}

		float t = (E.x * d0.y - E.y * d0.x) / kross;
		if(t < 0 || t > 1)
		{
			// not a point on seg
			return 0;
		}
		// intersects
		intersection = p1 + s * d0;
		return 1;
	}
	// lines are parallel
	return 0;
}

bool pointInsideEdge(glm::vec2 p, glm::vec2 v1, glm::vec2 v2)
{

	float val = (v2.x - v1.x) * (p.y - v1.y) - (v2.y - v1.y) * (p.x - v1.x);
	cout << "val: " << val << endl;
	return (val <= 0) ? true : false;
}


void printVec(const string& str, glm::vec2 v)
{
	cout << str << ": [" << v.x << ", " << v.y <<  "]" << endl;
}

void printVec(const string& str, glm::vec3 v)
{
	cout << str << ": [" << v.x << ", " << v.y << ", " << v.z << "]" << endl;
}

void printVecList(const string& str, vector<glm::vec2> list)
{
	cout << str << endl;
	if (list.size() == 0)
		cout << "EMPTY" << endl;
	int i = 0;
	for(glm::vec2 v: list)
	{
		printVec(to_string(i), v);
		i++;
	}
}