#include <header.h>
#include <globalVariable.h>

int grapH[MAX][MAX];
int v, edges;

int selectMinVertex (vector<int>& value, vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;
	
	for (int i = 0; i < v; i++)
	{
		if (setMST[i] == false && value[i] < minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	
	return vertex;
}

int findMST (int grapH[MAX][MAX])
{
	int parent[v], sum = 0;
	vector<int> value (v, INT_MAX); //used edged relaxation
	vector<bool> setMST (v, false); //TRUE -> vertex is included in MST
	
	//Assuming start point as Node -> 0
	parent[0] = -1; // start node has no parent
	value[0] = 0; // start node has value = 0 to get picked 1st
	
	//from MST with (v-1) edges
	for (int i = 0; i < v-1; i++)
	{
		//select best vertex applying greedy method
		int u = selectMinVertex (value, setMST);
        
		setMST[u] = true; //include new vertex in MST
		
		//relax adjacent vertices (noy yet included in MST)
		for (int j = 0; j < v; j++)
		{
			
			if (grapH[u][j] != 0 && setMST[j] == false && grapH[u][j] < value[j])
			{
				value[j] = grapH[u][j];
				parent[j] = u;
			}
		}
	}
	
	//print MST
	for (int i = 1; i < v; i++)
	{
		cout << "u -> v : " << parent[i] << "->" << i << ", weight = " << grapH[parent[i]][i] << endl;
		graphConnection(parent[i], i);
		nodeColor_1(parent[i]);
        nodeColor_1(i);

		delay(1000);
	}

	for (int i = 1; i < v; i++)
	{
		sum += grapH[parent[i]][i];
	}

	return sum;
	
}

void MST_Prims_Algorithm ()
{
	// settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    // outtextxy(400, 30, "Prims");

	// Graph_FixedNodesAndEdges();

	setfillstyle(SOLID_FILL, BLACK); // to erase the line "Please press any key to continue"
    bar(230, 500, 230 + 500, 500 + 600); // draws a rectangle over the text

	freopen("graph_input.txt", "r", stdin);

    cout << "Enter the number of nodes: ";
	//outtextxy(20, 20, "Enter the number of nodes: ");
    cin >> v;
	//std::string label_1 = std::to_string(v);

    cout << "Enter the number of edges: ";
	//outtextxy(20, 40, "Enter the number of edges: ");
    cin >> edges;
	//std::string label_2 = std::to_string(edges);


    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            grapH[i][j] = 0;
        }
    }

	int u1, u2, weight;

	cout << "Enter edges (u v) and it's weight:\n";
    for (int i = 0; i < edges; i++) 
	{
        cin >> u1 >> u2 >> weight;
        grapH[u1][u2] = weight;
		grapH[u2][u1] = weight;
    }

	cout << "MST cost is : " << findMST(grapH) << endl;
	
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(300, 550, "Successfully ended...");

}

//time complexity : O(V^2)
//if we use adjacency list : O(E log V)
/*
9
14
0 1 4
1 2 8
2 3 7 
3 4 9
4 5 10
5 6 2
6 7 1
7 8 7
0 7 8
1 7 11
2 8 2
6 8 6
2 5 4
3 5 14
*/