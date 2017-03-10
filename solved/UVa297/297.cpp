#include <bits/stdc++.h>
using namespace std;

enum node_types { GRAY, WHITE, BLACK };

typedef struct node_t {
	int type;
	int sz;
	node_t *chld[4];
} node_t;

node_t* mk_node ()
{
	node_t* root = (node_t *) calloc (1, sizeof (node_t));
	return root;
}

node_t* build_tree (char **s, int sz)
{
	if (sz <= 0 || !s || !(*s) || !(**s))
		return NULL;

	//printf ("s = [%s], ", *s);
	//printf ("sz = %d\n", sz);
	
	node_t *root = mk_node ();
	assert (sz != 1 || **s != 'p');

	if (sz == 1 || **s != 'p') {
		if (**s == 'e')
			root->type = WHITE;
		else
			root->type = BLACK;

		root->sz = sz;
		
		(*s)++;
		return root;
	}

	if (**s == 'p') {
		root->type = GRAY;
		root->sz = sz;

		(*s)++;
		for (int i = 0; i < 4; i++)
			root->chld[i] = build_tree (s, sz/2);
	}

	return root;
}

node_t *union_tree (node_t *A, node_t *B)
{
	if (!A) return B;
	if (!B) return A;

	if (A->type == BLACK) 
		return A;
	
	if (B->type == BLACK)
		return B;
	
	if (A->type == WHITE && B->type == WHITE)
		return A;
	
	for (int i = 0; i < 4; i++)
		A->chld[i] = union_tree (A->chld[i], B->chld[i]);

	return A;
}

int ct_blacks (node_t *root)
{
	if (root == NULL)
		return 0;

	if (root->type == WHITE)
		return 0;
	else if (root->type == BLACK)
		return (root->sz * root->sz);
	else {
		int sum  = 0;
		for (int i = 0; i < 4; i++)
			sum += ct_blacks (root->chld[i]);

		return sum;
	}
}

int ct_union_tree (node_t *A, node_t *B)
{
	if (!A) return ct_blacks (B);
	if (!B) return ct_blacks (A);

	if (A->type == BLACK) 
		return ct_blacks (A);
	
	if (B->type == BLACK)
		return ct_blacks (B);
	
	if (A->type == WHITE && B->type == WHITE)
		return 0;
	
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += ct_union_tree (A->chld[i], B->chld[i]);

	return sum;
}

void free_tree (node_t *root)
{
	if (root != NULL) {
		for (int i = 0; i < 4; i++) {
			free_tree (root->chld[i]);
			root->chld[i] = NULL;
		}

		free (root);
	}
}

#define MAXLLEN 3000

int
main ()
{
	int T;
	scanf ("%d", &T);
	scanf ("%*[^\n]");
	getchar ();

	while (T--) {
		char s1[MAXLLEN], s2[MAXLLEN];

		fgets (s1, MAXLLEN, stdin);
		s1[ strcspn (s1, "\n") ] = 0;

		fgets (s2, MAXLLEN, stdin);
		s2[ strcspn (s2, "\n") ] = 0;

		node_t *A, *B, *res;
		A = B = res = NULL;

		char *sa = s1;
		char *sb = s2;

		A = build_tree (&sa, 32);
		B = build_tree (&sb, 32);

		//res = union_tree (A, B);
		printf ("There are %d black pixels.\n", ct_union_tree (A, B));
		free_tree (A);
		free_tree (B);
	}

	return 0;
}
