// string contains '1', '2', '3' only
int sliding_window(string &str) 
{
	int c = 3; // number of chars need to be found
	int l = 0, r = 0, ans = -1;
	map < char, int > counter;

	while(l < str.size())
	{
		const auto ch = str[l++];

		if(counter[ch] == 0)
		{
			c--;
		}

		counter[ch]++;

		if(c == 0)
		{
			while(r < l)
			{
				if(ans > l - r || ans == -1)
				{
					ans = l - r;
				}

				const auto ch = str[r++];
				counter[ch]--;

				if(counter[ch] == 0)
				{
					c++;
					break;
				}
			}
		}
	}

	return ans;
}
