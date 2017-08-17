#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>

struct State{
  std::string name;
  std::vector<std::string> neighbors;
  State(std::string n) :name(n) { }
};

//int bfs
int main(){

  std::map<std::string, State *> Nodes;
  std::map<std::string, State *>::iterator it;
  std::string a, b;
  while(std::cin >>a >> b ){
   if(Nodes.find(a) == Nodes.end() ) 
     Nodes[a] = new State(a);
  
   if(Nodes.find(b) == Nodes.end() ) 
     Nodes[b] = new State(b);

    Nodes[a]->neighbors.push_back(b); 
    Nodes[b]->neighbors.push_back(a);
  }

  std::map<std::string, int> dist;
  typedef std::pair<int, std::string> p;
  std::queue<std::string> q;
  std::vector<p> eccentricities;
  for(it = Nodes.begin(); it != Nodes.end(); it++)
  {
    std::string home = it->first;
    int largest;
    for(it = Nodes.begin(); it != Nodes.end(); it++)
    {
      dist[it->first] = 99999; // visit condition in dist map
    }  
    it= Nodes.find(home);
    q.push(it->first);
    dist[it->first] = 0;
    while( !q.empty() ){ /// if queue is empty cant visit any more states
      std::string current= q.front(); // get current state
      q.pop();
      largest = dist[current]; 
      for(int i=0; i< int( Nodes[current]->neighbors.size() ); i++)
      {
        if( dist[Nodes[current]->neighbors[i]] == 99999 ) 
        {
          dist[Nodes[current]->neighbors[i] ] = dist[current] + 1; 
          // visit state add dist to key
          q.push(Nodes[current]->neighbors[i] ); // push state into queue
        }
      }
      
    }
    eccentricities.push_back( p(largest, home) ); 
  
  }
  std::sort(eccentricities.begin(), eccentricities.end() );
  //std::cout<< "\t" << Nodes["DE"]->neighbors[2] << std::endl;
  for(int i=0; i< eccentricities.size(); i++)
    std::cout<< eccentricities[i].second<< ": "<< eccentricities[i].first << std::endl;
  
  return 0;
}

