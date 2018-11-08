#include <iostream>

#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

using namespace std;

string multiply(const string &a, const string &b)
{
  /* initially fill the result string with 0's */
  size_t total_len= a.length() + b.length();
  string result(total_len, '0');

  int num;                                      /* intermediate store */
  int i, j;
  int last_pos_i, last_pos_j, last_pos_k;

  last_pos_i= total_len - 1;

  /* i-loop */
  for (i= b.length() - 1; i >= 0; i --)
  {
    last_pos_j= last_pos_i;

    /* j-loop */
    for (j= a.length() - 1; j >=0; j --)
    {
      last_pos_k= last_pos_j;
      num= INT(a.at(j)) * INT(b.at(i));

      /* k-loop : the actual updation of result string takes place here. */
      while (num)
      {
        num += INT(result.at(last_pos_k));
        result.at(last_pos_k)= CHAR(num % 10);
        /* 'carry' it forward.. -_- */
        num= num / 10;
        last_pos_k --;
      }

      last_pos_j --;
    }

    last_pos_i --;
  }
  return result;
}

int main()
{
  string n1("1000000000000000000000000000000000");
  string n2("999999999999999999999999999999999999999999999999");
  cout << multiply(n1, n2) << endl;
  return 0;
}
