//#include <iostream>	
//#include <vector>	
//#include <queue>
//1. 출발 노드 설정
//2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장
//3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드 선택
//4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신
//5. 위 과정 3~4번 반복

//const int number = 6; //노드의 개수
//int INF = 100000000;
//
//using namespace std;

//전체 그래프 초기화
//int a[number][number] = {
//	{0,2,5,1,INF,INF},
//	{2,0,3,2,INF,INF},
//	{5,3,0,3,1,5},
//	{1,2,3,0,1,INF},
//	{INF,INF,1,1,0,2},
//	{INF,INF,5,INF,2,0},
//};
//
//bool v[number];//Visitied node;
//int d[number];//Minimum distance
//
//int getSmallIndex()
//{
//	int min = INF;
//	int index = 0;
//	for (int i = 0; i < number; i++)
//	{
//		if (d[i] < min && !v[i])//방문하지 않은 노드 중에서 현재 최소값 보다 더 작은 값이 가져오면 갱신
//		{
//			min = d[i];
//			index = i;
//		}
//	}
//	//최소 거리를 반환
//	return index;
//}
//
//void dijkstra(int start)
//{
//	for (int i = 0; i < number; i++)
//	{
//		d[i] = a[start][i];//시작점으로부터 출발했을 때, 모든 경로값 비용을 저장
//	}
//	v[start] = true;//시작점 방문 체크
//	for (int i = 0; i < number - 2; i++)
//	{
//		int current = getSmallIndex();
//		v[current] = true;//방문 노드 체크
//		for (int j = 0; j < number; j++)
//		{
//			if (!v[j])//방문하지 않은 노드에서
//			{
//				if (d[current] + a[current][j] < d[j])//최단 거리 경로값이 현재 값보다 작으면
//				{
//					d[j] = d[current] + a[current][j];//최단거리 경로값 갱신
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	int start = 1;//출발점
//	dijkstra(start-1);
//	//출발점->각 노드로의 최소비용을 출력
//	for (int i = 0; i < number; i++)
//	{
//		cout << start<<"->"<<i+1<<" : "<<d[i] << endl;
//	}
//}


#include <iostream>	
#include <vector>	
#include <queue>
using namespace std;

const int number = 8;
int INF = 1000000000;

vector<pair<int, int>> a[number+1];//간선 정보
int d[number+1];//최소 비용 정보

void dijkstra(int start)
{
	d[start] = 0;//시작점 비용 0
	
	priority_queue<pair<int, int>> pq;//힙 구조(우선순위 큐)
	pq.push(make_pair(start, 0));//pair에 값을 할당 -> {start, 자기자신 코스트}
	//가까운 순서대로 처리하므로 큐를 사용
	while (!pq.empty())
	{
		int current = pq.top().first;//가장 작은 비용을 가지는 노드 비용
		
		//top은 가장 큰 값이 오기 때문에 음수화(-) 해서 반대로 정렬
		int distance = -pq.top().second;

		pq.pop();

		//최단 거리가 아닌 경우 패스
		if (d[current] < distance)continue;

		for (int i = 0; i < a[current].size(); i++)
		{
			//선택된 노드의 인접 노드
			int next = a[current][i].first;

			//선택된 노드 거쳐서 인접 노드로 가는 비용
			int nextDistance = distance + a[current][i].second;
			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void)
{
	//기본적으로 연결되지 않은 경우 비용은 무한

	for (int i = 1; i <= number; i++)//배열 INF 초기화
	{
		d[i] = INF;
	}

	//간선정보 생성, pair(출발노드, 코스트)
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(6, 3));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 4));
	a[2].push_back(make_pair(4, 1));

	a[3].push_back(make_pair(2, 4));
	a[3].push_back(make_pair(5, 3));

	a[4].push_back(make_pair(2, 1));
	a[4].push_back(make_pair(5, 3));
	a[4].push_back(make_pair(7, 2));

	a[5].push_back(make_pair(4, 3));
	a[5].push_back(make_pair(8, 4));

	a[6].push_back(make_pair(1, 3));
	a[6].push_back(make_pair(7, 6));
	
	a[7].push_back(make_pair(4, 2));
	a[7].push_back(make_pair(6, 6));
	a[7].push_back(make_pair(8, 4));

	a[8].push_back(make_pair(5, 4));
	a[8].push_back(make_pair(7, 4));

	int start = 1;
	dijkstra(start);//출발노드 다익스트라 except 0

	//결과 출력

	for (int i =1; i <= number; i++)
	{
		cout << start << " -> " << i << "\nMinimum cost : " << d[i] << endl;
	}
}