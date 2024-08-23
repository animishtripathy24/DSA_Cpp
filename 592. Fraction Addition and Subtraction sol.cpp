class Solution {
public:
    string fractionAddition(string expr) {
        int numerator = 0;
        int denominator = 1;

        int i = 0;
        int n = expr.length();
        while (i < n) {
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');

            if (expr[i] == '+' || expr[i] == '-') {
                i++;
            }

            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currNume = (currNume * 10) + val;
                i++;
            }

            i++; // for '/'

            if (isNeg == true) {
                currNume *= -1;
            }
            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            numerator = numerator * currDeno + currNume * denominator;
            denominator = denominator * currDeno;
        }

        int GCD = abs(__gcd(numerator, denominator)); // 3

        numerator /= GCD;   //-1
        denominator /= GCD; // 2

        return to_string(numerator) + "/" + to_string(denominator); //"-1/2"
    }
};
