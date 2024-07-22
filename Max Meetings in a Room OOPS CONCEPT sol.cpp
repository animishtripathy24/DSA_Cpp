/* This is the Meeting class definition
class Meeting {
public:
    int start, end;
    Meeting(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
*/
bool static cmp(Meeting* &a,Meeting* &b)
{
	return a->end < b->end;
}
int getMaxMeetings(vector<Meeting*> &meetings) {
	sort(begin(meetings),end(meetings),cmp);
	vector<Meeting*>intervals;
	for(int i=0;i<meetings.size();i++)
	{
		if(intervals.empty() || meetings[i]->start >=intervals.back()->end)
		{
			intervals.push_back(meetings[i]);
		}
		else
		{
			continue;
		}
	}
	return intervals.size();
}
