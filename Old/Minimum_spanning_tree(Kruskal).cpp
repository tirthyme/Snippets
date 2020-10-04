vector< vector<int> >conn; // Stores weight , node1 , node2

//DSU BEGIN

vector< int >point;
vector< set<int> >connected;

void pre(int n)
{
	point.resize(n+1);
	connected.resize(n+1);
	for(int i=1;i<=n;i++) point[i]=i;
	for(int i=1;i<=n;i++) connected[i].insert(i);
}

void merge(int x, int y)
{
	for(auto node:connected[y])
	{
		point[node]=x;
	}
	connected[x].insert(connected[y].begin(),connected[y].end());
	connected[y].clear();
}

bool same(int x, int y) 
{
	return point[x]==point[y];
}

void add(int x, int y)
{
	if(same(x,y)) return;
	if(connected[point[x]].size()<=connected[point[y]].size())
	{
		merge(point[y],point[x]);
	}
	else
	{
		merge(point[x],point[y]);
	}
}

//DSU OVER

void mst(int n)
{
	vector< bool >done(n+1,0);
	sort(conn.begin(),conn.end());
	vector< vector< int > >edges;
	pre(n);
	for(auto x:conn)
	{
		if(!same(x[1],x[2]))
		{
			edges.push_back(x);
			merge(x[1],x[2]);
		}
	}
	conn.clear();
	conn.resize(edges.size());
	copy(edges.begin(),edges.end(),conn.begin());
}