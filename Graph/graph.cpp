#include <iostream>
#include <queue>
using namespace std;

// Forward Declaration
struct Node;

// Edge Node
struct Edge {
    Node* vertex;
    Edge* next;
};

// Vertex Node
struct Node {
    char data;
    Edge* edgeList;
    Node* next;
    bool visited;
};

Node* head = NULL;

// 🔹 Find Vertex
Node* findVertex(char value) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// 🔹 Add Vertex
void addVertex(char value) {
    Node* temp = new Node();
    temp->data = value;
    temp->edgeList = NULL;
    temp->next = head;
    temp->visited = false;
    head = temp;
}

// 🔹 Add Edge (Undirected)
void addEdge(char a, char b) {
    Node* v1 = findVertex(a);
    Node* v2 = findVertex(b);

    if (!v1 || !v2) {
        cout << "Vertex not found\n";
        return;
    }

    Edge* e1 = new Edge();
    e1->vertex = v2;
    e1->next = v1->edgeList;
    v1->edgeList = e1;

    Edge* e2 = new Edge();
    e2->vertex = v1;
    e2->next = v2->edgeList;
    v2->edgeList = e2;
}

// 🔹 Display Graph
void display() {
    Node* temp = head;

    cout << "\nGraph:\n";

    while (temp != NULL) {
        cout << temp->data << " -> ";

        Edge* e = temp->edgeList;

        while (e != NULL) {
            cout << e->vertex->data << " ";
            e = e->next;
        }

        cout << endl;
        temp = temp->next;
    }
}

// 🔹 Find Degree
int findDegree(char value) {
    Node* v = findVertex(value);

    if (!v) {
        cout << "Vertex not found\n";
        return -1;
    }

    int count = 0;
    Edge* temp = v->edgeList;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// 🔹 BFS
void BFS(char start) {
    Node* v = findVertex(start);

    if (!v) {
        cout << "Start not found\n";
        return;
    }

    queue<Node*> q;

    Node* temp = head;
    while (temp != NULL) {
        temp->visited = false;
        temp = temp->next;
    }

    v->visited = true;
    q.push(v);

    cout << "BFS: ";

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        Edge* e = current->edgeList;

        while (e != NULL) {
            if (!e->vertex->visited) {
                e->vertex->visited = true;
                q.push(e->vertex);
            }
            e = e->next;
        }
    }

    cout << endl;
}

// 🔹 DFS
void DFS(Node* v) {
    if (!v) return;

    v->visited = true;
    cout << v->data << " ";

    Edge* e = v->edgeList;

    while (e != NULL) {
        if (!e->vertex->visited) {
            DFS(e->vertex);
        }
        e = e->next;
    }
}

// 🔹 Cycle Detection
bool detectCycle(Node* v, Node* parent) {
    v->visited = true;

    Edge* e = v->edgeList;

    while (e != NULL) {
        Node* nextNode = e->vertex;

        if (!nextNode->visited) {
            if (detectCycle(nextNode, v))
                return true;
        }
        else if (nextNode != parent) {
            return true;
        }

        e = e->next;
    }

    return false;
}

// 🔹 Path Detection
bool isPath(char start, char end) {
    Node* v1 = findVertex(start);
    Node* v2 = findVertex(end);

    if (!v1 || !v2) {
        cout << "Vertex not found\n";
        return false;
    }

    Node* temp = head;
    while (temp != NULL) {
        temp->visited = false;
        temp = temp->next;
    }

    queue<Node*> q;

    v1->visited = true;
    q.push(v1);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current == v2)
            return true;

        Edge* e = current->edgeList;

        while (e != NULL) {
            if (!e->vertex->visited) {
                e->vertex->visited = true;
                q.push(e->vertex);
            }
            e = e->next;
        }
    }

    return false;
}

// 🔹 MAIN
int main() {
    addVertex('1');
    addVertex('2');
    addVertex('3');
    addVertex('4');

    addEdge('1', '2');
    addEdge('1', '3');
    addEdge('2', '4');

    display();

    cout << "\nDegree of 1: " << findDegree('1') << endl;

    BFS('1');

    Node* temp = head;
    while (temp != NULL) {
        temp->visited = false;
        temp = temp->next;
    }

    cout << "DFS: ";
    DFS(findVertex('1'));
    cout << endl;

    temp = head;
    while (temp != NULL) {
        temp->visited = false;
        temp = temp->next;
    }

    if (detectCycle(findVertex('1'), NULL))
        cout << "Cycle exists\n";
    else
        cout << "No cycle\n";

    if (isPath('1', '4'))
        cout << "Path exists\n";
    else
        cout << "No path\n";

    return 0;
}