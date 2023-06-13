Pattern-1:
/*
******
******
******
******
******
******
*/
#include<iostream>
using namespace std;


int main()
{
    int n;
    cout<<"enter the numbers of rows"<<endl;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n)
        {
            cout<<"*";
            j=j+1;
        }
        cout<<"\n";
        i=i+1;
    }

}


Pattern-2:
/*
*
* *
* * *
* * * *
* * * * *
* * * * * *
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout << "*" << " ";
            j+=1;
        }
        i+=1;
        cout << endl;
    }

    return 0;
}


Pattern-3:
/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int x=1;
        int j=1;
        while(j<=i)
        {
            cout << x << " ";
            x++;
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}


Pattern-4:
/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
6 6 6 6 6 6
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    int x=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout << x << " ";
            j++;
        }
        i++;
        x++;
        cout << endl;
    }
    return 0;
}


Pattern-5:
/*
* * * * * *
* * * * *
* * * *
* * *
* *
*
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int stars=n-i+1;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        i++;
        cout << endl;
    }
}


Pattern-6:
/*
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int x=1;
        int numbers=n-i+1;
        while(numbers)
        {
            cout<< x << " ";
            x++;
            numbers--;
        }
        i++;
        cout << endl;
    }
}


Pattern-7:
/*
              *
            * * *
          * * * * *
        * * * * * * *
      * * * * * * * * *
    * * * * * * * * * * *
  * * * * * * * * * * * * *
* * * * * * * * * * * * * * *
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        //printing spaces
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int j=1;
        while(j<=i)
        {
            cout << "*" << " ";
            j++;
        }
        int stars=i-1;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        i++;
        cout << endl;
    }
}


Pattern-8:
/*
* * * * * * * * * * *
  * * * * * * * * *
    * * * * * * *
      * * * * *
        * * *
          *
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        //printing spaces
        int spaces=i-1;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        //printing stars..
        int stars=n-i+1;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        int stars2=n-i;
        while(stars2)
        {

            cout << "*" << " ";
            stars2--;
        }
        i++;
        cout << endl;
    }
}


Pattern-9:
/*
*
* *
* * *
* * * *
* * * * *
* * * * * *
* * * * * * *
* * * * * * * *
* * * * * * * * *
* * * * * * * *
* * * * * * *
* * * * * *
* * * * *
* * * *
* * *
* *
*
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    int rows=(2*n-1);
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout << "*" << " ";
            j++;
        }

        i++;
        cout << endl;
    }
    int left=n-1;
    while(left<=rows)
    {
        int stars=rows-left+1;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        left++;
        cout << endl;
    }
    return 0;

}


Pattern-10:
/*
          *
        * * *
      * * * * *
    * * * * * * *
  * * * * * * * * *
* * * * * * * * * * *
* * * * * * * * * * *
  * * * * * * * * *
    * * * * * * *
      * * * * *
        * * *
          *
*/
#include<iostream>
using namespace std;
void print7(int n)
{
    int i=1;
    while(i<=n)
    {
        //printing spaces
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int j=1;
        while(j<=i)
        {
            cout << "*" << " ";
            j++;
        }
        int stars=i-1;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        i++;
        cout << endl;
    }
}
void print8(int n)
{
    int i=1;
    while(i<=n)
    {
        //printing spaces
        int spaces=i-1;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        //printing stars..
        int stars=n-i+1;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        int stars2=n-i;
        while(stars2)
        {

            cout << "*" << " ";
            stars2--;
        }
        i++;
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    print7(n);
    print8(n);
    return 0;
}


Pattern-11:
/*
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
0 1 0 1 0 1
1 0 1 0 1 0 1
*/
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i&1)
			{
				if(j&1)
				{
					cout << 1 << " ";
				}
				else
				{
					cout << 0 << " ";
				}
			}
			else
			{
				if(j&1)
				{
					cout << 0 << " ";
				}
				else
				{
					cout << 1 << " ";
				}
			}

		}
		cout << endl;
	}
}


Pattern-12:
/*
1                     1
1 2                 2 1
1 2 3             3 2 1
1 2 3 4         4 3 2 1
1 2 3 4 5     5 4 3 2 1
1 2 3 4 5 6 6 5 4 3 2 1
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int x=1;
        int x2=1;
        int j=1;
        while(j<=i)
        {
            cout << x << " ";
            x++;
            j++;
        }
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int spaces2=n-i;
        while(spaces2)
        {
            cout << " " << " ";
            spaces2--;
        }
        int number=i;
        while(number)
        {
            cout << number << " ";
            number--;

        }
        i++;
        cout << endl;
    }
}


Pattern-13:
/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x=1;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout << x << " ";
            x++;
            j++;
        }
        i++;
        cout << endl;
    }
}


Pattern-14:
/*
A
A B
A B C
A B C D
A B C D E
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        char ch=65;
        int j=1;
        while(j<=i)
        {
            cout << ch << " ";
            ch++;
            j++;
        }
        i++;
        cout << endl;
    }
}


Pattern-15:
/*
A B C D E
A B C D
A B C
A B
A
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int c=n-i+1;
        char ch=65;
        while(c)
        {
            cout << ch << " ";
            ch++;
            c--;
        }
        i++;
        cout << endl;
    }
}


Pattern-16:
/*
A
B B
C C C
D D D D
E E E E E
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    char ch=65;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout << ch << " ";
            j++;
        }
        ch++;
        i++;
        cout << endl;

    }
}


Pattern-17:
/*
      A
    A B A
  A B C B A
A B C D C B A
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        char co='A'+i-2;
        char ch=65;
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int c=i;
        while(c)
        {
            cout << ch << " ";
            ch++;
            c--;
        }
        int ci=i-1;
        while(ci)
        {
            ci--;
            cout << co << " ";
            co-=1;

        }
        i++;
        cout << endl;

    }
}


Pattern-18:
/*
E
D E
C D E
B C D E
A B C D E
*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        char ch='A'+n-i;
        int j=1;
        while(j<=i)
        {
            cout << ch << " ";
            ch=ch+1;
            j=j+1;
        }
        i=i+1;
        cout << endl;
    }
}


Pattern-19:
/*
* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *
*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
*/
#include<iostream>
using namespace std;
void print_first_part(int n)
{
    int i=1;
    while(i<=n)
    {
        int stars=n-i+1;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        int spaces=i-1;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int spaces2=i-1;
        while(spaces2)
        {
            cout << " " << " ";
            spaces2--;
        }
        int stars2=n-i+1;
        while(stars2)
        {
            cout << "*" << " ";
            stars2--;
        }
        i++;
        cout << endl;
    }
}
void print_second_part(int n)
{
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout << "*" << " ";
            j++;
        }
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int spaces2=n-i;
        while(spaces2)
        {
            cout << " " << " ";
            spaces2--;
        }
        int number=i;
        while(number)
        {
            cout << "*" << " ";
            number--;

        }
        i++;
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    print_first_part(n);
    print_second_part(n);
    return 0;

}


Pattern-20:




/*
*                 * 
* *             * * 
* * *         * * * 
* * * *     * * * * 
* * * * * * * * * * 
* * * *     * * * * 
* * *         * * * 
* *             * * 
*                 *
*/
#include<iostream>
using namespace std;

void upper_part(int n)
{
    int i=1;
    while(i<=n)
    {
        int stars=i;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int spaces2=n-i;
        while(spaces2)
        {
            cout << " " << " ";
            spaces2--;
        }
        int stars2=i;
        while(stars2)
        {
            cout << "*" << " ";
            stars2--;
        }
        i++;
        cout << endl;
    }
}
void lower_part(int n)
{
    int i=1;
    while(i<=n)
    {
        int stars=n-i+1;
        while(stars)
        {
            cout << "*" << " ";
            stars--;
        }
        int spaces=i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int spaces2=i;
        while(spaces2)
        {
            cout << " " << " ";
            spaces2--;
        }
        int stars2=n-i+1;
        while(stars2)
        {
            cout << "*" << " ";
            stars2--;
        }
        i++;
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    upper_part(n);
    lower_part(n-1);
    return 0;
}


Pattern-21:
/*
* * * * *
*       	   *
*           *
*           *
* * * * *
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n)
        {
            if(i==1 || i==n)
            {
                cout << "*" << " ";
                j+=1;
            }
            else
            {
                if(j==1 || j==n)
                {
                    cout << "*" << " ";
                    j++;
                }
                else
                {
                    cout << " " << " ";
                    j++;
                }
            }

        }
        i++;
        cout << endl;
    }

}


Pattern-22:
/*
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    int rows=(2*n-1);
    int i=0;
    while(i<rows)
    {
        int j=0;
        while(j<rows)
        {
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int down=(2*n-2)-i;
            cout << (n-min(min(top,down),min(left,right))) << " ";
            j++;
        }
        i++;
        cout << endl;
    }
}


Pattern-23:

/*
         11
    11 10 11
  11 10 9 10 11
11 10 9 8 9 10 11
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    int x2=12;
    while(i<=n)
    {
        int x=11;
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int numbers=i;
        int var=x;
        while(numbers)
        {
            cout << var << " ";
            var--;
            numbers--;
        }
        int number2=i-1;
        int var2=x2;
        while(number2)
        {
            cout << var2 << " ";
            var2++;
            number2--;
        }
        i++;
        x2--;
        cout << endl;
    }
}


Pattern-24:
/*
1 2 3 4 5 6 7 8 9 10 10 9 8 7 6 5 4 3 2 1 
1 2 3 4 5 6 7 8 9 * * 9 8 7 6 5 4 3 2 1 
1 2 3 4 5 6 7 8 * * * * 8 7 6 5 4 3 2 1 
1 2 3 4 5 6 7 * * * * * * 7 6 5 4 3 2 1 
1 2 3 4 5 6 * * * * * * * * 6 5 4 3 2 1 
1 2 3 4 5 * * * * * * * * * * 5 4 3 2 1 
1 2 3 4 * * * * * * * * * * * * 4 3 2 1 
1 2 3 * * * * * * * * * * * * * * 3 2 1 
1 2 * * * * * * * * * * * * * * * * 2 1 
1 * * * * * * * * * * * * * * * * * * 1
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int x=1;
        int loop=n-i+1;
        while(loop)
        {
            cout<<x << " ";
            x=x+1;
            loop--;

        }
        int stars=i-1;
        while(stars)
        {
            cout<<"*" << " ";
            stars--;
        }
        // int j=2;
        // while(j<=i)
        // {
        //     cout<<"*";
        //     j=j+1;
        // }
        int stars2=i-1;
        while(stars2)
        {
            cout << "*" << " ";
            stars2--;
        }
        int start=n-i+1;
        while(start)
        {
            cout<<start << " ";
            start--;
        }

        cout<<endl;
        i=i+1;

    }
}


Pattern-25:
/*
        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    int x=1;
    int x2=0;
    while(i<=n)
    {
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
       int j=1;
       int number=x;
       while(j<=i)
       {
           cout << number << " ";
           number++;
           j++;
       }
       int x1=i-1;
       int number2=x2;
       while(x1)
       {
           cout << number2 << " ";
           number2--;
           x1--;
       }
       x2+=2;

       i++;
       x++;
       cout << endl;
    }
}


Pattern-26:
/*
        A
      A B C
    A B C D E
  A B C D E F G
A B C D E F G H I
  A B C D E F G
    A B C D E
      A B C
        A
*/

#include<iostream>
using namespace std;
void upper_part(int n)
{
    int i=1;
    while(i<=n)
    {
        char ch=65;
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int j=1;
        while(j<=i)
        {
            cout << ch << " ";
            ch++;
            j++;
        }
        char ch1='A'+i;
        int rows=i-1;
        while(rows)
        {
            cout << ch1 << " ";
            ch1++;
            rows--;
        }
        i++;
        cout << endl;

    }
}
void lower_part(int n)
{
    int i=1;
    while(i<=n)
    {
        char ch=65;
        int spaces=i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
        int rows=n-i+1;
        while(rows)
        {
            cout << ch << " ";
            ch++;
            rows--;
        }
        char ch1='A'+n-i+1;
        int rows2=n-i;
        while(rows2)
        {
            cout << ch1 << " ";
            ch1++;
            rows2--;
        }
        i++;
        cout << endl;


    }
}

int main()
{
    int n;
    cin >> n;
    upper_part(n);
    lower_part(n-1);

    return 0;
}

Pattern-27:
/*
        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    int x=1;
    int x2=0;
    while(i<=n)
    {
        int spaces=n-i;
        while(spaces)
        {
            cout << " " << " ";
            spaces--;
        }
       int j=1;
       int number=x;
       while(j<=i)
       {
           cout << number << " ";
           number++;
           j++;
       }
       int x1=i-1;
       int number2=x2;
       while(x1)
       {
           cout << number2 << " ";
           number2--;
           x1--;
       }
       x2+=2;

       i++;
       x++;
       cout << endl;
    }
}

Pattern-28:
/*
            * 
          *   * 
        *   *   * 
      *   *   *   * 
    *   *   *   *   * 
  *   *   *   *   *   * 
  *   *   *   *   *   * 
    *   *   *   *   * 
      *   *   *   * 
        *   *   * 
          *   * 
            * 
*/
#include<iostream>
using namespace std;

void first_part(int n)
{
	int i=1;
	while(i<=n)
	{
		int spaces=n-i;
		while(spaces)
		{
			cout << " " << " ";
			spaces--;
		}
		int stars=i;
		while(stars)
		{
			cout << "  " << "*" << " ";
			stars--;
		}
		i++;
		cout << endl;
	}
}

void second_part(int n)
{
	int i=1;
	while(i<=n)
	{
	int spaces2=i-1;
	while(spaces2)
	{
		cout << " " << " ";
		spaces2--;
	}
	int stars=n-i+1;
	while(stars)
	{
		cout << "  " << "*" << " ";
		stars--;
	}
	i++;
	cout << endl;	
	}

}

int main()
{
	int n;
	cin >> n;
	first_part(n);
	second_part(n);
}




