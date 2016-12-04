//please fix the code so that it can be passed in compilation
//after you fix the bug, you run it and you will get many print out like ".... GONE--"
//please explain how those lines are shown up


#include <iostream>

//int lineC=0;
class app{
  // static int lineC=0;
public:
  static int lineC;
    int a;
    app(int x):a(x){}
  app(){}
  app operator+(int b) {
    return app(a + b);
  }
};
int app::lineC = 0;

struct woooz{
   int b;
    std::string wz;
    
    woooz(int k, const std::string& kk="WoooZ"):b(k){ wz=kk;}
    woooz() {}
    ~woooz(){
        std::cout << " woooz " << b <<" GONE-- " << ++app::lineC << std::endl;
    }
};

class Handler{
    public:
    app m_a;
    struct woooz m_WZ;
    std::string m_name;
  //Handler(struct app* a, std::string n){
  Handler(app* a, std::string n):m_a(a->a){
      // m_a=*a;
        m_name=n;
        std::cout << "pp caller " << m_name << std::endl;
    }
};

void haha(struct woooz& wz1, struct woooz& wz2){
    struct woooz wA=wz1;
    struct woooz& wB=wz2;
    struct woooz* pWZ=&wB;
    std::cout << __func__ << std::endl;    
}

class chd_handler: public Handler{
    public:
    chd_handler(struct app* a): Handler(a, "i am child"){ }
    chd_handler(struct app* a, std::string n):
               Handler(a, n){      }    
};

int main()
{
app a(1);
app aa=5;
app a3=aa+1;
const app ary[20];


struct woooz wz1(10, "You"); 
struct woooz wz2(10, "Me");
haha(wz1, wz2);

std::cout << "-----------" << std::endl;

//struct app a;
    Handler hb(&a, "base");
    std::cout << hb.m_name << std::endl;
    chd_handler ch(&a);
    std::cout << ch.m_name << std::endl;
    chd_handler ck(&a, "this is child");
    std::cout << ck.m_name << std::endl;        
    std::cout << std::endl;
}
