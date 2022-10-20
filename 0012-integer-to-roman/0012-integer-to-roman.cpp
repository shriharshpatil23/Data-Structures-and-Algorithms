class Solution
{
   	// string fun(int dig, int pow, unordered_map<int, string> &mp)
   	// {
   	//     string res;
   	//     if (dig == 9)
   	//     {
   	//         res = mp[(9 *pow)];
   	//     }
   	//     else if (dig >= 5)
   	//     {
   	//         int left = dig - 5;
   	//         res += mp[(5 *pow)];
   	//         while (left--)
   	//         {
   	//             res += mp[pow];
   	//         }
   	//     }
   	//     else if (dig == 4)
   	//         res += mp[(4 *pow)];
   	//     else
   	//     {
   	//         while (dig--)
   	//         {
   	//             res += mp[pow];
   	//         }
   	//     }
   	//     return res;
   	// }

    public:
        string intToRoman(int num)
        {
           	//             unordered_map<int, string> mp;
           	//             mp[1] = "I";
           	//             mp[5] = "V";
           	//             mp[10] = "X";
           	//             mp[50] = "L";
           	//             mp[100] = "C";
           	//             mp[500] = "D";
           	//             mp[1000] = "M";

           	//             mp[4] = "IV";
           	//             mp[9] = "IX";
           	//             mp[40] = "XL";
           	//             mp[90] = "XC";
           	//             mp[400] = "CD";
           	//             mp[900] = "CM";
           	//             int pow = 1;
           	//             string res;
           	//             vector<pair<int, int>> v;
           	//             while (num)
           	//             {
           	//                 int dig = num % 10;
           	//                 if (dig != 0)
           	//                     v.push_back(make_pair(dig, pow));
           	//                 num /= 10;
           	//                 pow *= 10;
           	//             }

           	//             for (auto it = v.rbegin(); it != v.rend(); it++)
           	//             {
           	//                 res += fun(it->first, it->second, mp);
           	//             }

           	//             return res;

            string ones[] = { "",
                "I",
                "II",
                "III",
                "IV",
                "V",
                "VI",
                "VII",
                "VIII",
                "IX" };
            string tens[] = { "",
                "X",
                "XX",
                "XXX",
                "XL",
                "L",
                "LX",
                "LXX",
                "LXXX",
                "XC" };
            string hrns[] = { "",
                "C",
                "CC",
                "CCC",
                "CD",
                "D",
                "DC",
                "DCC",
                "DCCC",
                "CM" };
            string ths[] = { "",
                "M",
                "MM",
                "MMM" };

            return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
        }
};