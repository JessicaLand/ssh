#include<iostream>
using namespace std;
const int maxsize = 10;
class MGraph {
public:
	MGraph(char a[], int n, int e);
	~MGraph(){}
	void DESTraverse(int v);
	void BESTraverse(int v);
	void Print();
private:
	char vertex[maxsize];
	int arc[maxsize][maxsize];
	int vertexNum, arcNum;
	int front, rear;
	int visited[maxsize];
	int Q[maxsize];
};
MGraph::MGraph(char a[], int n, int e)
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0; i < vertexNum; i++)
		vertex[i] = a[i];
	for (int i = 0; i < vertexNum; i++)
		visited[i] = 0;
	
	for (int i = 0; i < vertexNum; i++)
		for (int j = 0; j < vertexNum; j++)
			arc[i][j] = 0;
	for (int k = 0; k < arcNum; k++)
	{   
		int i,j;
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;
	}
}
void MGraph::DESTraverse(int v) {
	if(visited[v]==0)
	cout << vertex[v];
	visited[v] = 1;
	for (int j = 0; j < vertexNum; j++)
		if (arc[v][j] == 1 && visited[j] == 0)
			DESTraverse(j);
}
void MGraph::BESTraverse(int v) {
	front = rear = - 1;
	cout << vertex[v]<<" ";
	visited[v] = 1;
	Q[++rear] = v;
	while (front != rear)
	{
		v = Q[++front];
		for (int j = 0; j < vertexNum; j++)
			if (arc[v][j] == 1 && visited[j] == 0) {
				cout << vertex[j];
				visited[j] = 1;
				Q[++rear] = j;
			}

	}
}
void MGraph::Print() {
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << arc[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int n, e;
	char vertex[maxsize];
	cin >> n >> e;
	char *a = new char[maxsize];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	MGraph m(a, n, e);
	m.Print();
	for (int i = 0; i < n; i++)
	{
		m.DESTraverse(i);
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		m.BESTraverse(i);
	}
	cout << endl;
	return 0;
	
	}
