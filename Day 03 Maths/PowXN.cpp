class Solution
{
public:
    double calcPow(double x, long n)
    {
        if (n == 0)
            return 1;

        if (n & 1)
            return x * calcPow(x, n - 1);
        else
        {
            double y = calcPow(x, n / 2);
            return y * y;
        }
    }
    double myPow(double x, int n)
    {
        long nn = n; //to avoid int overflow
        if (n > 0)
            return calcPow(x, nn);
        else
            return 1 / calcPow(x, -1 * nn);
    }
};