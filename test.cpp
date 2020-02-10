#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'findBestCity' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER distanceThreshold
 *  2. WEIGHTED_INTEGER_GRAPH city
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int dijkstra(int s, int distanceThreshold, const vector<vector<pair<int, int>>> &adjList) {
    vector<int> d(adjList.size(), numeric_limits<int>::max());
    d[1] = 1;
    set<pair<int, int>> q;
    q.insert({0, s});
    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for(auto edge : adjList[v]) {
            int next = edge.second;
            int dist = edge.first;

            if(d[v] + dist < d[next]) {
                q.erase({d[next], next});
                d[next] = d[v] + dist;
                q.insert({d[next], next});
            }
        }
    }

    return count_if(begin(d), end(d), [distanceThreshold](int elem){ 
        return elem <= distanceThreshold;
    });
}

int findBestCity(int distanceThreshold, int city_nodes, vector<int> city_from, vector<int> city_to, vector<int> city_weight) {
    vector<vector<pair<int, int>>> adjList(city_nodes + 1);
    for(int i = 0; i < city_from.size(); i++) {
        adjList[city_from[i]].push_back({city_weight[i], city_to[i]});
        adjList[city_to[i]].push_back({city_weight[i], city_from[i]});
    }

    int answer = 0, best = city_nodes;
    for(int i = 1; i <= city_nodes; i++) {
        int score = dijkstra(i, distanceThreshold, adjList);
        if(score <= best) {
            best = score;
            answer = i;
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string distanceThreshold_temp;
    getline(cin, distanceThreshold_temp);

    int distanceThreshold = stoi(ltrim(rtrim(distanceThreshold_temp)));

    string city_nodes_edges_temp;
    getline(cin, city_nodes_edges_temp);

    vector<string> city_nodes_edges = split(rtrim(city_nodes_edges_temp));

    int city_nodes = stoi(city_nodes_edges[0]);
    int city_edges = stoi(city_nodes_edges[1]);

    vector<int> city_from(city_edges);
    vector<int> city_to(city_edges);
    vector<int> city_weight(city_edges);

    for (int i = 0; i < city_edges; i++) {
        string city_from_to_weight_temp;
        getline(cin, city_from_to_weight_temp);

        vector<string> city_from_to_weight = split(rtrim(city_from_to_weight_temp));

        int city_from_temp = stoi(city_from_to_weight[0]);
        int city_to_temp = stoi(city_from_to_weight[1]);
        int city_weight_temp = stoi(city_from_to_weight[2]);

        city_from[i] = city_from_temp;
        city_to[i] = city_to_temp;
        city_weight[i] = city_weight_temp;
    }

    int result = findBestCity(distanceThreshold, city_nodes, city_from, city_to, city_weight);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
