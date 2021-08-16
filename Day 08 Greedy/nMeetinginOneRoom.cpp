struct meeting
{
    int start, end, pos;
};
bool comparator(struct meeting m1, meeting m2)
{
    return (m1.end != m2.end) ? m1.end < m2.end : m1.pos < m2.pos;
}
void maxMeetings(int s[], int e[], int n)
{
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
    }

    sort(meet, meet + n, comparator);

    int limit = meet[0].end, answer = 1;

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            answer++;
        }
    }
    return answer;
}