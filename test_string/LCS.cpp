#include <string>
#include <iostream>
using namespace std;

string longestCommonSubstring(string* string1, string* string2)
{
  int l1 = string1->length();
  int l2 = string2->length();
  int dp[l1 + 1][l2 + 1];
  for (int i = 0; i <= l1; ++i) 
  {
    for (int j = 0; j <= l2; ++j)
    {
      dp[i][j] = 0;
    }     
  }
  
  for (int i = 1; i <= l1; ++i) 
  {
    for (int j = 1; j <= l2; ++j)
    {
      if (string1->at(i - 1) == string2->at(j - 1)) 
      {
	dp[i][j] = dp[i - 1][j - 1] + 1;
      }
    }     
  }
  int start = 0;
  int max = 0;
  for (int i = 1; i <= l1; i++)
  {
    for (int j = 1; j <= l2; j++)
    {
      if (dp[i][j] > max)
      {
	max = dp[i][j];
	start = i -  max;
      }
    }
  }
  return string1->substr(start, max);
}

int main() {
  string s1;
  string s2;
  cout << "Please input the two strings with enter" << endl;
  cin >> s1;
  cin >> s2;
  string s = longestCommonSubstring(&s1, &s2);
  cout << "The longest common substring is: " << endl;
  cout << s << endl;
  return 0;
}
