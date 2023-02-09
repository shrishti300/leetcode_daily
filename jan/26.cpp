/* 787. Cheapest Flights Within K Stops*/

/* APPROACH 1- USING BFS TRAVERSAL  - POOR TIME MANAGEMENT */\
class Solution {
public:
  int findCheapestPrice( int n, vector<vector<int>>& flights, int src, int dst, int K ) { 
	// Create adjList
	unordered_map<int, vector< pair<int,int> > > adjList;
	for( auto flight : flights )
		adjList[flight[0]].push_back( { flight[1], flight[2] } );

	/* BFS starting from src */
	queue< pair<int,int> > q; // < node, dist_from_src > pair
	q.push( { src, 0 } );
	int srcToTgtDist = INT_MAX; // result

	while( !q.empty() && K-- >= 0 ) {
		int size = q.size();
		for( int i = 0; i < size; i++ ) {
			auto curr = q.front(); q.pop();         
			for( auto nbr : adjList[curr.first] ) {
				if( srcToTgtDist < curr.second + nbr.second ) continue;

				q.push( { nbr.first, curr.second + nbr.second } );

				// update distance from src to dst
				if( dst == nbr.first ) 
					srcToTgtDist = min( srcToTgtDist, curr.second + nbr.second );
				}
		}
	}
	return srcToTgtDist == INT_MAX ? -1 : srcToTgtDist;
  }
};

/* BELLMAN FORD ALGORITHM*/


class Solution {
public:
  int findCheapestPrice( int n, vector<vector<int>>& flights, int src, int dst, int K ) { 
	vector<int>dist(n,INT_MAX);
    dist[src]=0;
    for(int i=0;i<=K;i++){
        vector<int>tmp(dist);
        for(auto flight:flights){
            if(dist[flight[0]] != INT_MAX){
                tmp[flight[1]]=min(tmp[flight[1]],             dist[flight[0]]+flight[2]);
            }
        }
        dist=tmp;
    }
    return dist[dst]==INT_MAX ? -1: dist[dst];
  }
};