#include <iostream>
#include <list>
#include <string>
#include <vector>

class Edge {
private:
  int weight, distID;

public:
  Edge(int ID, int w);
  void setValues(int ID, int Iw);
  int getWeight();
  int getID();
  Edge();
  ~Edge();
};

Edge::Edge(int ID, int w) {
  this->distID = ID;
  this->weight = w;
}
void Edge::setValues(int ID, int w) {
  this->distID = ID;
  this->weight = w;
}

int Edge::getID() { return this->distID; }

int Edge::getWeight() { return this->weight; }

Edge::~Edge() {}
Edge::Edge() {}

class Vertex {
private:
  int ID;
  std::string Name;

public:
  std::list<Edge> Edges;
  Vertex(int id, std::string name); // !DANGER DANGER
  void setValues(int id, std::string &name);
  int getID();
  void printEdges();
  void insert(Edge);
  std::string getName();
  std::list<Edge> *getEdges();
  Vertex();
  ~Vertex();
};

Vertex::Vertex(int id, std::string name) {
  this->Name = name;
  this->ID = id;
}
Vertex::Vertex() {
  this->Name = "";
  this->ID = 0;
}
// test
void Vertex::setValues(int id, std::string &name) {
  this->Name = name;
  this->ID = id;
}
int Vertex::getID() { return this->ID; }

std::string Vertex::getName() { return this->Name; }

std::list<Edge> *Vertex::getEdges() { return &this->Edges; }

void Vertex::printEdges() {
  std::cout << " [ \n";
  for (auto &vertex : Edges) {
    std::cout << "  {\n   id: " << vertex.getID()
              << ",   weight:" << vertex.getWeight() << " } , ";
  }
  std::cout << " \n] ,\n";
}
void Vertex::insert(Edge edge) { Edges.push_back(edge); }

Vertex::~Vertex() {}

class Graph {
private:
  std::vector<Vertex> vertices;

public:
  Graph();
  bool vertexExist(int);
  bool edgeExist(int, int);
  void addVertex(Vertex);
  void addEdge(int, int, int);
  void updateEdage(int, int, int);
  void deleteEdge(int, int);
  void deleteVertex(int);
  void printGraph();
  ~Graph();
};

Graph::Graph() {}
Graph::~Graph() {}

void Graph::printGraph() {
  std::cout << "[\n  {\n  ";
  for (auto &v : vertices) {
    std::cout << "  id: " << v.getID() << ",\n    name: " << v.getName()
              << ",\n    Edges: ";
    v.printEdges();
  }
  std::cout << "grap was printed \n";
}
bool Graph::edgeExist(int from, int to) {
  if (vertexExist(from), vertexExist(to)) {
    for (auto &v : vertices) {
      if (v.getID() == from) {
        std::list<Edge> *edges = v.getEdges();
        for (auto e : *edges) {
          if (e.getID() == to)
            return true;
        }
      }
    }
  }
  return false;
}

bool Graph::vertexExist(int id) {

  for (auto &v : vertices) {
    if (v.getID() == id)
      return true;
  }
  return false;
}

void Graph::addVertex(Vertex vertex) {

  if (!vertexExist(vertex.getID())) {
    vertices.push_back(vertex);
    std::cout << "vertex was add \n";
  } else {
    std::cout << "vertex already exist \n";
  }
}

void Graph::addEdge(int from, int to, int weight) {
  if (vertexExist(from) && vertexExist(to) && !edgeExist(from, to)) {
    for (auto &v : vertices) {
      if (v.getID() == from) {
        Edge e(to, weight);
        v.insert(e);
      } else if (v.getID() == to) {
        Edge e(from, weight);
        v.insert(e);
      }
    }
  }
}
void Graph::updateEdage(int from, int to, int weight) {
  if (edgeExist(from, to)) {
    for (auto &v : vertices) {
      if (v.getID() == from) {
        std::list<Edge> *edges = v.getEdges();
        for (auto &e : *edges) {
          if (e.getID() == to)
            e.setValues(to, weight);
        }
      }
      if (v.getID() == to) {
        std::list<Edge> *edges = v.getEdges();
        for (auto &e : *edges) {
          if (e.getID() == from)
            e.setValues(from, weight);
          break;
        }
      }
    }
    std::cout << "edge was updated\n";
    return;
  }
  std::cout << "edge wasn't found\n";
}
void Graph::deleteEdge(int from, int to) {
  if (edgeExist(from, to)) {
    for (auto &v : vertices) {
      if (v.getID() == from) {

        /*         std::list<Edge> *edges = v.getEdges();
                for (auto &e : *edges) {
                  if (e.getID() == to) {
                    v.Edges.remove(e);
                    // edges->erase(e);
                  }

                }
         */
        for (auto e = v.Edges.begin(); e != v.Edges.end(); e++) {
          if (e->getID() == to)
            v.Edges.erase(e);
          break;
        }
      } else if (v.getID() == to) {
        for (auto e = v.Edges.begin(); e != v.Edges.end(); e++) {
          if (e->getID() == from)
            v.Edges.erase(e);
          break;
        }
      }
    }
    std::cout << "edge was deleted\n";
    return;
  }
  std::cout << "edge wasn't found\n";
}

void Graph::deleteVertex(int id) {

  int counter = 0;
  for (auto &v : vertices) {
    if (v.getID() == id) {
      std::list<Edge> *edges = v.getEdges();
      for (auto &e : *edges) {
        if (edges->size())
          deleteEdge(id, e.getID());
        else
          break;
      }
      vertices.erase(vertices.begin() + counter);
      std::cout << "vertex was deleted\n";
      return;
    }
    counter++;
  }
}

int main(int argc, char const *argv[]) {
  Graph graph;
  Vertex vertex;
  std::string name;
  int choice, id, weight, from, to;
  do {
    std::cout << "\n 1 - Add Vertex \n"
              << " 2 - Update Vertex\n"
              << " 3 - Delete Vertex\n"
              << " 4 - Add Edge \n"
              << " 5 - Update Edage \n"
              << " 6 - Delete Edge\n"
              << " 7 - Check if 2 Vertices if they're neighbors\n"
              << " 8 - Print Neighbors of Vertex\n"
              << " 9 - Print Graph\n"
              << " 0 - CLS \n";
    std::cin >> choice;
    switch (choice) {
    case 1:
      std::cout << "enter id , name: ";
      std::cin >> id >> name;
      vertex.setValues(id, name);
      graph.addVertex(vertex);
      break;
    case 2:
      break;
    case 3:
      std::cout << " enter vertex id: ";
      std::cin >> from;
      graph.deleteVertex(from);
      break;
    case 4:
      std::cout << " enter (from --> to , weight)";
      std::cin >> from >> to >> weight;
      graph.addEdge(from, to, weight);
      break;
    case 5:
      std::cout << " enter (from --> to , new weight)";
      std::cin >> from >> to >> weight;
      graph.updateEdage(from, to, weight);
      break;
    case 6:
      std::cout << " enter (from --> to)";
      std::cin >> from >> to;
      graph.deleteEdge(from, to);
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      graph.printGraph();
      break;
    case 10:
      system("cls");
      break;
    }
  } while (choice);

  return 0;
}
