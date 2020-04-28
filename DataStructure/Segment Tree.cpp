const int MAX = 1e5 + 2, mod = 998244353, shift = 1000;
int a[MAX], ans[MAX], n;

struct Node
{
	vector < int > v;

	void merge(const Node &left, const Node &right)
	{
		::merge(all(left.v), all(right.v), back_inserter(v));
	}
};

struct SegTree
{
	private:
		Node node[4 * MAX];

		bool query(int p, int s, int e, int qs, int qe, int val)
		{
			if(qs > e || qe < s) return false;
			else if(qs <= s && e <= qe)
			{
				auto it = lower_bound(all(node[p].v), val);
				return it == node[p].v.begin() ? false : true;
			}
			else
			{
				int mid = (s + e) >> 1;
				return query(2 * p + 2, mid + 1, e, qs, qe, val) || query(2 * p + 1, s, mid, qs, qe, val);
			}
		}

		void build(int p, int s, int e)
		{
			if(s > e) return;
			else if(s == e) node[p].v.push_back(a[s]);
			else
			{
				int mid = (s + e) >> 1;
				build(2 * p + 1, s, mid);
				build(2 * p + 2, mid + 1, e);
				node[p].merge(node[2 * p + 1], node[2 * p + 2]);
			}
		}

	public:
		void build()
		{
			build(0, 0, n - 1);
		}

		bool query(int qs, int qe, int val)
		{
			return query(0, 0, n - 1, qs, qe, val);
		}
};
