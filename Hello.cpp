/* THINK TWICE .... CODE ONCE */
/* SUKHAM SINGH */
#include <bits/stdc++.h>
#include <iomanip>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define ld long double
#define voi vector<int>
#define voc vector<char>
#define vos vector<string>
#define vovoi vector<vector<int> >
#define vovoc vector<vector<char> >
#define vovos vector<vector<string> >
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pss pair<string,string>
#define piii pair<int,pii>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define setp(n) fixed << setprecision(n)
#define TEST(t) int t; cin>>t; while(t--) 
#define PI 3.141592653589793238462643383279
#define gcd(x,y) __gcd(x,y)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define moii map<int,int>
#define moll map<long long,long long>
#define mocc map<char,char>
#define moic map<int,char>
#define moci map<char,int>
#define mois map<int,string>
#define mosi map<string,int>
#define umoii unordered_map<int,int>
#define umoll unordered_map<long long,long long>
#define umocc unordered_map<char,char>
#define umoic unordered_map<int,char>
#define umoci unordered_map<char,int>
#define umois unordered_map<int,string>
#define umosi unordered_map<string,int>
#define forn(i, k, n) for(int i = k; i < n; i++)
#define fori(a,b) for(int i=a;i<b;i++)
#define f(n) for(int i=0;i<n;i++)
#define fl(n) for(ll i=0;i<(ll)n;i++)
#define si set<int>
#define sc set<char>
#define sst set<string>
#define Si stack<int>
#define Sc stack<char>
#define Sst stack<string>
#define cl(x) cout << x << endl
#define cle() cout << endl
#define c(x) cout << x
#define intarray(n) int* arr = new int[n]
#define llarray(n) ll* arr = new ll[n]
#define inarray(n) f(n) cin >> arr[i]
#define read(n) int n; cin >> n
#define readll(n) ll n; cin >> n
#define readS(str) string str;  cin >> str
using namespace std;
// Use This when I/O is using File*
/* freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);*/

ll countPrime(ll n){
    if(n <= 1)  return 0;
    // Sieve of Eratosthenes 0 to n
    vector<bool> v(n,true);
    v[0] = v[1] = false;
    ll count = 0;
    for(ll i=2;i<n;i++){
        if(v[i]){
            count++;
            ll j = i;
            while(j < n){
                v[j] = false;
                j += i;
            }
        }
    }
    return count;
}
// ll countPrimeFromLowToHighBothInclusive(ll low,ll high){  }
ll gcdIterative(ll a,ll b){
    if(a == 0) return b;
    if(b == 0) return a;
    while(a>0 && b>0){
        if(a > b) a -= b;
        else b -= a;
    }
    return a==0 ? b : a;
}
ll fastExponent(ll a,ll b){  // TC - O(log b)
    ll ans = 1;
    while(b > 0){
        if(b & 1)  ans *= a;   // Means b is odd
        a = a*a;
        b >>= 1;  // Doing left shift by 1 will Half b , b /= 2;
    }
    return ans;
}
bool CompareString(string str1,string str2){
    if(str1.length() < str2.length()) return true;
    else if(str1.length() > str2.length()) return false;
    else{
        for(int i=0;i<str1.length();i++){
            if(str1[i] < str2[i]) return true;
            if(str1[i] > str2[i]) return false;
        }
    }
    return false;
}
string AddString(string str1,string str2){
    // Make sure str2 has larger length Than str1
    if(str1.length() > str2.length()) swap(str1,str2);
    string AnsSum = "";
    int n1 = str1.length(),n2 = str2.length();
    int diff = n2 - n1,carry = 0;
    for(int i=n1-1;i>=0;i--){
        int sum = (str1[i]-'0') + (str2[i+diff]-'0') + carry;
        AnsSum.push_back(sum%10 + '0');
        carry = sum/10;
    }
    // Adding remaining digits of str2
    for(int i=n2-n1-1;i>=0;i--){
        int sum = (str2[i]-'0') + carry;
        AnsSum.push_back(sum%10 + '0');
        carry = sum/10;
    }
    // Add remaining Carry
    if(carry) AnsSum.push_back(carry + '0');
    reverse(all(AnsSum));
    return AnsSum;
}
string SubtractString(string str1,string str2){
    if(CompareString(str1,str2)) swap(str1,str2);
    string AnsDiff = "";
    int n1 = str1.length(),n2 = str2.length();
    int diff = n1 - n2,carry = 0;
    // Traverse From the End of the Strings
    for(int i=n2-1;i>=0;i--){
        int sub = (str1[i+diff]-'0') - (str2[i]-'0') - carry;
        if(sub < 0){ sub += 10;  carry = 1; }
        else carry = 0;
        AnsDiff.push_back(sub+'0');
    }
    // Subtracting remaining digits of str1
    for(int i=n1-n2-1;i>=0;i--){
        if(str1[i]=='0' && carry){
            AnsDiff.push_back('9');
            continue;
        }
        int sub = (str1[i]-'0') - carry;
        // Removing preceding Zeroes
        if(i > 0 || sub > 0)  AnsDiff.push_back(sub + '0');
        carry = 0;
    }
    int last = AnsDiff.length()-1;
    while(AnsDiff[last] == '0'){
        AnsDiff.pop_back();
        last--;
    }
    reverse(all(AnsDiff));
    return AnsDiff;
}
bool CheckPrime(ll n){
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
ll nCr(ll n, ll r){
    ll p = 1, k = 1;
    if(n - r < r) r = n - r;
    while(r){
        p *= n; k *= r; int m = __gcd(p, k); p /= m; k /= m; n--,r--;
    }
    return p;
}
ll DigitSum(ll n){
    ll ans = 0;
    while (n > 0){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
voi PrefixArray(voi& arr){
    int n = arr.size();
    voi Prefix(n);
    Prefix[0] = arr[0];
    for(int i=1;i<n;i++) Prefix[i] = Prefix[i-1] + arr[i];
    return Prefix;
}
voi SuffixArray(voi& arr){
    int n = arr.size();
    voi Suffix(n);
    Suffix[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--) Suffix[i] = Suffix[i+1] + arr[i];
    return Suffix;
}
/*
1. Observe Pattern In Test Cases
2. Implement Brute Force
3. Think Greedy
4. Build the solution in reverse order
5. Check Constraints Carefully & Avoid Overflow
6. Check if Binary Search Can be used
7. Consider DP , No Need to prove Greedy , Sahi lag raha to Laga do bss
6. Time to Build Logic Rather than Code
*/

int main(){
    fastIO;
    TEST(t){
        cout << "Hello" << endl;
    }
    return 0;
}