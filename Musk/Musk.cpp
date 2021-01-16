#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
#include <vector>
#include <limits>

class Node
{
public:
	int val;
	Node* next;

	Node(int v)
	{
		val = v;
		next = nullptr;
	}

	Node(int v, Node* n)
	{
		val = v;
		next = n;
	}
};

class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v)
	{
		val = v;
		left = nullptr;
		right = nullptr;
	}
};

Node* reverseLinkedList(Node* head)
{
	if (!head)
	{
		return nullptr;
	}

	Node* prev = nullptr;
	Node* curr = head;
	Node* next = nullptr;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

void preOrderTraversal(TreeNode* root)
{
	if (!root)
	{
		return;
	}

	std::cout << root->val << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root)
{
	if (!root)
	{
		return;
	}

	inOrderTraversal(root->left);
	std::cout << root->val << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root)
{
	if (!root)
	{
		return;
	}
	
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	std::cout << root->val << " ";
}

void printLinkedList(Node* head)
{
	Node* curr = head;
	while (curr)
	{
		std::cout << curr->val << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}

void bubbleSort(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void insertionSort(std::vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j > -1 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void selectionSort(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

int partition(std::vector<int>& arr, int l, int r)
{
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;
	return i + 1;
}

void quickSortHelper(std::vector<int>& arr, int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int p = partition(arr, l, r);
	quickSortHelper(arr, l, p - 1);
	quickSortHelper(arr, p + 1, r);
}

void quickSort(std::vector<int>& arr)
{
	quickSortHelper(arr, 0, arr.size() - 1);
}

bool binarySearch(TreeNode* root, int val)
{
	if (!root)
	{
		return false;
	}
	if (root->val == val)
	{
		return true;
	}
	return binarySearch(root->left, val) || binarySearch(root->right, val);
}

bool validBinarySearchTreeHelper(TreeNode* root, int left, int right)
{
	if (!root)
	{
		return true;
	}
	if (left < root->val && root->val < right)
	{
		return validBinarySearchTreeHelper(root->left, left, root->val) && validBinarySearchTreeHelper(root->right, root->val, right);
	}
	else
	{
		return false;
	}
}

bool validBinarySearchTree(TreeNode* root)
{
	return validBinarySearchTreeHelper(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

void printVector(std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

bool canSpell(std::vector<char> magazine, std::string note)
{
	// create the hash map
	std::unordered_map<char, int> dict;
	for (int i = 0; i < magazine.size(); i++)
	{
		dict[magazine[i]]++;
	}

	// check up
	for (int i = 0; i < note.size(); i++)
	{
		if (dict[note[i]] > 0)
		{
			dict[note[i]]--;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	Node* head = new Node(1, new Node(2, new Node(3, new Node(4))));
	printLinkedList(head);
	Node* reversedHead = reverseLinkedList(head);
	printLinkedList(reversedHead);

	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	preOrderTraversal(root);
	std::cout << std::endl;
	inOrderTraversal(root);
	std::cout << std::endl;
	postOrderTraversal(root);
	std::cout << std::endl;

	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	std::cout << s.top() << std::endl;

	std::vector<int> arr;
	arr.push_back(1);
	arr.push_back(7);
	arr.push_back(6);
	arr.push_back(5);
	arr.push_back(9);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(8);
	arr.push_back(2);
	printVector(arr);
	//bubbleSort(arr);
	//insertionSort(arr);
	//selectionSort(arr);
	quickSort(arr);
	printVector(arr);
	std::cout << std::endl;

	// binary search tree
	TreeNode* root2 = new TreeNode(7);
	root2->left = new TreeNode(5);
	root2->left->left = new TreeNode(3);
	root2->left->right = new TreeNode(6);
	root2->right = new TreeNode(10);
	root2->right->left = new TreeNode(9);
	root2->right->right = new TreeNode(13);
	inOrderTraversal(root2);
	std::cout << std::endl;
	std::cout << binarySearch(root2, 13) << std::endl;

	// Valid Binary Search Tree
	std::cout << std::endl;
	std::cout << "Valid Binary Search Tree" << std::endl;
	TreeNode* root3 = new TreeNode(5);
	root3->left = new TreeNode(4);
	root3->right = new TreeNode(7);
	std::cout << validBinarySearchTree(root3) << std::endl;
	root3->right->left = new TreeNode(2);
	std::cout << validBinarySearchTree(root3) << std::endl;

	// Ransom Note
	std::vector<char> magazine;
	magazine.push_back('a');
	magazine.push_back('b');
	magazine.push_back('c');
	magazine.push_back('d');
	magazine.push_back('e');
	magazine.push_back('f');
	std::string note = "bbed";
	std::cout << std::endl;
	std::cout << "Ransom Note" << std::endl;
	std::cout << canSpell(magazine, note) << std::endl;
}