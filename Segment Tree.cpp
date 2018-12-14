Min Query (Point Update):

int st[4*N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=1e9;
		return;
	}
	int M=(L+R)/2;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=min(st[node*2], st[node*2+1]);
}

int query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return 1e9;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)/2;
	int left=query(node*2, L, M, i, j);
	int right=query(node*2 + 1, M+1, R, i, j);
	return min(left, right);
}

void update(int node, int L, int R, int pos, int val)
{
	if(L==R)
	{
		st[node]=val;
		return;
	}
	int M=(L+R)/2;
	if(pos<=M)
		update(node*2, L, M, pos, val);
	else
		update(node*2 + 1, M+1, R, pos, val);
	st[node]=min(st[node*2], st[node*2 + 1]);
}