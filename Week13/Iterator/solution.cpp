#include <iostream>
#include <vector>
#include <stack>
#include <memory>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Forward declaration
class TreeIterator;

// Tree Node class
class TreeNode {
    int value;
    vector<shared_ptr<TreeNode>> neighbors; // Outgoing edges

public:
    explicit TreeNode(int val) : value(val) {}

    int getValue() const { return value; }

    void addNeighbor(shared_ptr<TreeNode> node) {
        neighbors.push_back(node);
    }

    const vector<shared_ptr<TreeNode>>& getNeighbors() const {
        return neighbors;
    }

    // Factory method for creating iterator
    unique_ptr<TreeIterator> createDFSIterator();
};

// Iterator interface
class TreeIterator {
public:
    virtual ~TreeIterator() = default;
    virtual bool hasNext() const = 0;
    virtual TreeNode& next() = 0;
};

// Concrete DFS Iterator
class DFSIterator : public TreeIterator {
    stack<shared_ptr<TreeNode>> nodeStack;
    unordered_map<int, bool> visited;

    void pushIfNotVisited(shared_ptr<TreeNode> node) {
        if (node && !visited[node->getValue()]) {
            nodeStack.push(node);
            visited[node->getValue()] = true;
        }
    }

public:
    explicit DFSIterator(shared_ptr<TreeNode> root) {
        pushIfNotVisited(root);
    }

    bool hasNext() const override {
        return !nodeStack.empty();
    }

    TreeNode& next() override {
        if (!hasNext()) {
            throw out_of_range("No more nodes");
        }

        auto current = nodeStack.top();
        nodeStack.pop();

        // Push neighbors in reverse order to visit them in order
        const auto& neighbors = current->getNeighbors();
        for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
            pushIfNotVisited(*it);
        }

        return *current;
    }
};

// Implement the factory method
unique_ptr<TreeIterator> TreeNode::createDFSIterator() {
    return make_unique<DFSIterator>(shared_ptr<TreeNode>(this, [](TreeNode*){}));
}

// Helper function to build a sample tree
shared_ptr<TreeNode> buildSampleTree() {
    // Build this tree:
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6

    auto node1 = make_shared<TreeNode>(1);
    auto node2 = make_shared<TreeNode>(2);
    auto node3 = make_shared<TreeNode>(3);
    auto node4 = make_shared<TreeNode>(4);
    auto node5 = make_shared<TreeNode>(5);
    auto node6 = make_shared<TreeNode>(6);

    node1->addNeighbor(node2);
    node1->addNeighbor(node3);
    node2->addNeighbor(node4);
    node2->addNeighbor(node5);
    node3->addNeighbor(node6);

    return node1;
}

int main() {
    auto root = buildSampleTree();

    // Create iterator
    auto iterator = root->createDFSIterator();

    // Traverse the tree
    cout << "DFS traversal: ";
    while (iterator->hasNext()) {
        auto& node = iterator->next();
        cout << node.getValue() << " ";
    }
    cout << endl;

    return 0;
}