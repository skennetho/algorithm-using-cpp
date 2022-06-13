//https://www.acmicpc.net/problem/1991
// 트리 순회
#include <iostream>

using namespace std;

int tree[91][2];// tree[parent] ={child, child}

void preorder(int parent) {
	if (parent == '.') {
		return;
	}
	printf("%c", (parent));
	preorder(tree[parent][0]);
	preorder(tree[parent][1]);	
}

void inorder(int parent) {
	if (parent == '.') {
		return;
	}
	inorder(tree[parent][0]);
	printf("%c", (parent));
	inorder(tree[parent][1]);
}

void postorder(int parent) {
	if (parent == '.') {
		return;
	}
	postorder(tree[parent][0]);
	postorder(tree[parent][1]);
	printf("%c", (parent));
}


int main() {
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i) {
		char p, c1, c2;//parent, child1, child2
		scanf("%c %c %c\n", &p, &c1, &c2);
		tree[p][0] = c1;
		tree[p][1] = c2;
	}

	preorder('A');
	printf("\n");

	inorder('A');
	printf("\n");

	postorder('A');
	printf("\n");
}
