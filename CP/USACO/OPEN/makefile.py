import argparse


def get_par():
    """Parse program argument."""
    parser = argparse.ArgumentParser(description='simple example of argparse')
    parser.add_argument('file_name', help='file name', type=str)
    my_arg = parser.parse_args()
    return my_arg.file_name


def create():
    name = get_par()
    text = '/*\nID: licht.n1\nPROG: ' + name + '\nLANG: C++14          \n*/\n#include <iostream>\n#include <fstream>\n#include <string>\n#include <vector>\n#include <map>\n#include <set>\n#include <algorithm>\n#define int int64_t\n#define vi vector<int>\n#define ii pair<int,int>\n#define vb vector<bool>\n#define vvi vector<vi>\n#define vvb vector<vb>\n#define vvvb vector<vvb>\n#define vii vector<ii>\n#define vvii vector<vii>\n#define x first\n#define y second\n#define pb push_back\n#define mp make_pair\n#define loop(i,s,e) for(int i=s;i<e;i++)\n#define chkmax(a,b) a = max((a),(b))\n#define chkmin(a,b) a=min(a,b)\n#define all(x) x.begin(),x.end()\nusing namespace std;\nconst int INF = 1e9;\n\n\nint32_t main() {\n    //ofstream cout("' + name + '.out");\n    //ifstream cin("' + name + '.in");\n    int n; cin>>n;\n    return 0;\n}\n/*\ncolor a\ncls\ng++ ' + name + '.cpp -o a & a\n\n*/\n'
    with open("{}.cpp".format(name), 'w') as f:
        f.write(text)


if __name__ == "__main__":
    create()
