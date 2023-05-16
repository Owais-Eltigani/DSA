#include <iostream>

class Node {
private:
public:
  int data;
  Node *right, *left;
  Node(int, Node *, Node *);
  Node();
  ~Node();
};

Node::Node(int data, Node *left, Node *right) {
  this->data = data;
  this->left = left;
  this->right = right;
}
Node::Node() {
  this->data = 0;
  this->left = this->right = NULL;
}

Node::~Node() {}

class BST {

public:
  Node *root;
  BST(Node *);
  ~BST();
  bool isEmpty();
  void insertNode(Node *);
  Node *insertB(Node *, Node *);
  void print2D(Node *, int);
  void NLR(Node *);
  void LNR(Node *);
  void LRN(Node *);
  void BFS(Node *);
  void levels(Node *, int);
  Node *search(int);
  Node *min(Node *);
  Node *deleteNode(Node *, int);
  Node *deleteB(Node *, int);
  Node *lRotation(Node *);
  Node *rRotation(Node *);
  int height(Node *);
  int BF(Node *);
};
BST::BST(Node *node = NULL) { this->root = node; }
BST::~BST() { this->root = NULL; }

int main(int argc, char const *argv[]) {
  int opt, height, val;
  Node *node;
  BST Tree;
  do {
    node = new Node;
    std::cout << "1- insertNode node\n"
              << " 2- NLR\n"
              << " 3- LNR\n"
              << " 4- LRN\n"
              << " 5- Search A value \n"
              << " 6- Height of the Tree \n"
              << " 7- Breadth-First-Search \n"
              << " 8- Delete Node\n"
              << " 9- print tree\n"
              << " 10- Clear Screen\n"
              << " 11- Balance insert\n"
              << "enter operation:  ";
    std::cin >> opt;
    switch (opt) {
    case 1:
      std::cout << "enter data: ";
      std::cin >> node->data;
      Tree.insertNode(node);
      break;
    case 2:
      Tree.NLR(Tree.root);
      std::cout << "\n";
      break;
    case 3:
      Tree.LNR(Tree.root);
      std::cout << "\n";
      break;
    case 4:
      Tree.LRN(Tree.root);
      std::cout << "\n";
      break;
    case 5:
      std::cout << "enter value:  ";
      std::cin >> val;
      (Tree.search(val)) ? std::cout << "Node found with value " << val << "\n"
                         : std::cout << "Node not found\n";
      break;
    case 6:
      height = Tree.height(Tree.root);
      std::cout << "Tree height:  " << height << "\n";
      break;
    case 7:
      Tree.BFS(Tree.root);
      break;
    case 8:
      std::cout << "enter node to be deleted:  ";
      std::cin >> val;
      std::cout << Tree.deleteNode(Tree.root, val)->data << "\n";
      break;
    case 10:
      system("cls");
      break;
    case 9:
      Tree.print2D(Tree.root, 5);
      std::cout << "\n\n";
      break;
    case 11:
      std::cout << "enter data: ";
      std::cin >> node->data;
      Tree.root = Tree.insertB(Tree.root, node);
      break;

    default:
      break;
    }

  } while (opt);

  delete node;
  return 0;
}

bool BST::isEmpty() { return (!root); }
void BST::insertNode(Node *node) {
  if (root) {
    Node *temp = root;
    while (temp) {
      if (node->data < temp->data && !temp->left) {
        temp->left = node;
        return;
      } else if (node->data < temp->data && temp->left)
        temp = temp->left;
      else if (node->data > temp->data && !temp->right) {
        temp->right = node;
        return;
      } else if (node->data > temp->data && temp->right)
        temp = temp->right;
      else {
        std::cout << "No Duplication\n";
        return;
      }
    }
  } else {
    root = node;
    std::cout << "root appointed\n";
  }
}
void BST::print2D(Node *node, int space) {
  if (node == NULL)
    return;
  space += space;
  print2D(node->right, space);
  std::cout << "\n";
  for (size_t i = 10; i < space; i++)
    std::cout << " ";
  std::cout << node->data << "\n";
  print2D(node->left, space);
}
void BST::NLR(Node *node) {
  if (!node)
    return;
  std::cout << node->data << "  ";
  NLR(node->left);
  NLR(node->right);
}
void BST::LNR(Node *node) {
  if (!node)
    return;
  LNR(node->left);
  std::cout << node->data << "  ";
  LNR(node->right);
}
void BST::LRN(Node *node) {
  if (!node)
    return;
  LRN(node->left);
  LRN(node->right);
  std::cout << node->data << "  ";
}

Node *BST::search(int data) {
  if (!root)
    return root;
  Node *temp = root;
  while (temp) {
    if (data == temp->data)
      break;
    else if (data < temp->data)
      temp = temp->left;
    else
      temp = temp->right;
  }
  return temp;
}

int BST::height(Node *node) {
  if (!node)
    return -1;
  int Lheight = height(node->left);
  int Rheight = height(node->right);
  if (Lheight > Rheight)
    return Lheight + 1;
  else
    return Rheight + 1;
}

void BST::BFS(Node *node) {
  int height = this->height(root);
  for (size_t i = 0; i <= height; i++) {
    levels(root, i);
    std::cout << "\n";
  }
}

void BST::levels(Node *node, int level) {
  if (!node) {
    return;
  } else if (level == 0) {
    std::cout << node->data << "  ";
  } else {
    levels(node->left, level - 1);
    levels(node->right, level - 1);
  }
}

Node *BST::min(Node *node) {
  Node *temp = node;
  while (temp->left)
    temp = temp->left;
  return temp;
}

Node *BST::deleteNode(Node *node, int data) {
  if (!node)
    return node;
  if (data > node->data)
    node->right = deleteNode(node->right, data);
  else if (data < node->data)
    node->left = deleteNode(node->left, data);
  else {
    Node *temp = NULL;
    if (!node->left) {
      temp = node->right;
      delete node;
      return temp;
    } else if (!node->right) {
      temp = node->left;
      delete node;
      return temp;
    } else {
      temp = min(node->right);
      node->data = temp->data;
      node->right = deleteNode(node->right, temp->data);
    }
  }
  return node;
}

Node *BST::insertB(Node *root, Node *node) {
  if (!root)
    root = node;
  else if (node->data > root->data)
    root->right = insertB(root->right, node);
  else if (node->data < root->data)
    root->left = insertB(root->left, node);
  else
    std::cout << "No Duplication\n";
  if (BF(root) > 1 && node->data < root->left->data)
    root = rRotation(root);
  else if (BF(root) < -1 && node->data > root->right->data)
    root = lRotation(root);
  if (BF(root) > 1 && node->data > root->left->data) {
    root->left = lRotation(root->left);
    this->print2D(this->root, 5);
    return rRotation(root);
  } else if (BF(root) < -1 && node->data > root->right->data) {
    root->right = rRotation(root->left);
    return lRotation(root);
  }
  return root;
}

Node *BST::rRotation(Node *node) {
  Node *temp = node->left;
  Node *Rtemp = temp->right;
  temp->right = node;
  node->left = Rtemp;
  return temp;
}

Node *BST::lRotation(Node *node) {
  Node *temp = node->right;
  Node *ltemp = temp->left;
  temp->left = node;
  node->right = ltemp;
  return temp;
}
int BST::BF(Node *node) {
  return (!node) ? -1 : height(node->left) - height(node->right);
  // return height(node->left) - height(node->right);
}

Node *BST::deleteB(Node *node, int data) {
  if (!node)
    return node;
  if (data > node->data)
    node->right = deleteNode(node->right, data);
  else if (data < node->data)
    node->left = deleteNode(node->left, data);
  else {
    Node *temp = NULL;
    if (!node->left) {
      temp = node->right;
      delete node;
      return temp;
    } else if (!node->right) {
      temp = node->left;
      delete node;
      return temp;
    } else {
      temp = min(node->right);
      node->data = temp->data;
      node->right = deleteNode(node->right, temp->data);
    }
  }
  if (BF(node) > 1 && BF(node->left) >= 0)
    return rRotation(node);
  else if (BF(node) > 1 && BF(node->left) == -1) {
    node->left = lRotation(node->left);
    return rRotation(node);
  }
  if (BF(node) < -1 && BF(node->right) <= 0)
    return lRotation(node);
  else if (BF(node) < -1 && BF(node->right) == 1) {
    node->right = rRotation(node->left);
    return lRotation(node);
  }

  return node;
}