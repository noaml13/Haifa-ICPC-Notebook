#define X 0
#define Y 1
#define Z 2
struct Point{
    double x=0,y=0,z=0;
    double& get(int ind){
        if (ind==0) return x;
        if (ind==1) return y;
        return z;
    }
    void rotate_plane(double al, int d1, int d2){
        ///example: p.rotate_plane(alpha, X, Y) for alpha Radian rotation in XY plane
        double &a= get(d1);
        double &b= get(d2);
        double tmp = a*cos(al) - b*sin(al);
        b = b*cos(al) + a*sin(al);
        a = tmp;
    }
    void print(){
        cout<<"POINT: "<<x<<" "<<y<<" "<<z<<endl;
    }
    double dis(Point& p){
        return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));
    }
};
