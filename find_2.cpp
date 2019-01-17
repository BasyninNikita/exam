template <typename Iterator, typename T>
std::pair<bool, std::pair<Iterator, Iterator>> find_two_elements_with_sum(Iterator first, Iterator last, T c)
{
	std::unordered_map<T,Iterator> my_map;
	std::pair<bool, std::pair<Iterator, Iterator>> p;
	Iterator one = last;
	Iterator two = last;
	p = std::make_pair<bool, std::pair<Iterator, Iterator>>(false, std::make_pair<Iterator, Iterator>(one, two));
	for (auto i = first; i != last; ++i)
	{
		auto f = my_map.find(*i);
		if (f != my_map.end())
		{
			p.first = true;
			one = i;
			two = f->second;
			p.second = std::make_pair<Iterator, Iterator>(one, two);
			return p;
		}
		else
		{
			my_map.insert(std::make_pair<T, Iterator>(c - (*i), i));
		}
	}
	return p;
}
