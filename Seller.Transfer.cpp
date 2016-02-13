#include "all.h"

#define INFINITY 999999
#define MAX_VERTEX_NUM 50

typedef struct MGraph
{
	string vexs[MAX_VERTEX_NUM];
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
}MGraph;

int Seller_LocateVex(MGraph G, string u)
{
	for(int i=0; i<G.vexnum; i++)
		if(G.vexs[i]==u)
			return i;
	return -1;
}

void Seller_CreateDN(MGraph &G)
{
    Time time;
    string line;
	G.vexnum = G.arcnum = 0;
	int i, j;

	chdir(time.Show_file_curdir());
	ifstream file("index.txt");
	while(getline(file,line))
    {
        if(line.find("id") != -1)
        {
            for(i = 0; getline(file,line); ++i)
            {
                if(line.find("id") != -1)
                    break;
                ++ G.vexnum;
                G.vexs[i] = line;
            }
            for(i=0; i<G.vexnum; i++)
                for(j=0; j<G.vexnum; j++)
                {
                    if(i == j)
                        G.arcs[i][j] = 0;
                    else
                        G.arcs[i][j]=INFINITY;
                }
        }

        if(line.find("dep_station") != -1)
        {
            i=Seller_LocateVex(G, line.erase(0,14));
            getline(file,line);
            j=Seller_LocateVex(G, line.erase(0,14));
            getline(file,line);
            getline(file,line);
            G.arcs[i][j] = atoi(line.c_str());

            ++G.arcnum;
        }
    }
    file.close();
}

void Seller_ShortestPath_FLOYD(MGraph G, int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM], int D[][MAX_VERTEX_NUM])
{
    int u, v, w, i, j;

	for(v=0; v<G.vexnum; v++)
		for(w=0; w<G.vexnum; w++)
		{
			D[v][w]=G.arcs[v][w];
			for(u=0; u<G.vexnum; u++)
				p[v][w][u]=-1;
			if(D[v][w] < INFINITY)
			{
				p[v][w][0]=v;
				p[v][w][1]=w;
			}
		}

		for(u=0; u<G.vexnum; u++)
			for(v=0; v<G.vexnum; v++)
				for(w=0; w<G.vexnum; w++)
					if(D[v][u] < INFINITY && D[u][w] < INFINITY && D[v][u]+D[u][w] < D[v][w])
					{
						D[v][w]=D[v][u]+D[u][w];
						for(i=0; i<G.vexnum; i++)
						{
							if(p[v][u][i]!=-1)
								p[v][w][i]=p[v][u][i];
							else
								break;
						}
						for(j=1; j<G.vexnum; j++)
						{
							if(p[u][w][j]!=-1)
								p[v][w][i++]=p[u][w][j];
							else
								break;
						}
					}
}

void Seller::Transfer(string dep_station, string arr_station)
{
	MGraph g;
	Time time;
	string route,line;
	int i = 0;
	int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int dis[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

	map <string,int> name_id;
	chdir(time.Show_file_curdir());
	ifstream file("index.txt");
	while(getline(file,line))
    {
        if(line.find("id") != -1)
        {
            for(i = 0; getline(file,line); ++i)
            {
                if(line.find("id") != -1)
                    break;
                name_id[line] = i;
            }
            break;
        }
    }

	Seller_CreateDN(g);
	Seller_ShortestPath_FLOYD(g, path, dis);

	int hour = dis[name_id[dep_station]][name_id[arr_station]] / 3600;
	int minute = (dis[name_id[dep_station]][name_id[arr_station]] % 3600) / 60;
	int second = (dis[name_id[dep_station]][name_id[arr_station]] % 3600) % 60;
	cout<<"The shortest time of "<<g.vexs[name_id[dep_station]]<<" -> "<<g.vexs[name_id[arr_station]];
	cout<<": "<<hour<<" hours "<<minute<<" minutes "<<second<<" seconds"<<endl;
	for(int k=0; k<g.vexnum; k++)
    {
        if(path[name_id[dep_station]][name_id[arr_station]][k]!=-1)
            route = route + g.vexs[path[name_id[dep_station]][name_id[arr_station]][k]] + " -> ";
		else break;
    }
    route.erase(route.end() - 4, route.end());
    cout<<"The transfer program: "<<route<<endl;
}
