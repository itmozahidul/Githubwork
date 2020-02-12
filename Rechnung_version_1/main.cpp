#include <iostream>

using namespace std;




class Article{
private:
    string model;
    double netPrice;
    double taxRate;
public:
    Article(string a,double b,double c=19):model(a),netPrice(b),taxRate(c){}
    virtual ~Article(){cout<<"~Article()";}

   /*functions*/
    void set_Model(string a){model=a;}
    void set_netPrice(double b){netPrice=b;}
    string get_model(){return model;}
    double get_netPrice(){return netPrice;}
    double get_grossPrice(){return (netPrice+((netPrice*taxRate)/100));}
    void virtual print()=0;
};

class Accessory:public Article{
private:
    bool original;
public:
    Accessory(string name, double netPrice, bool is_Original=true):Article(name,netPrice),original(is_Original){}
    virtual  ~Accessory(){cout<<" ~Accessory() ";}
    virtual  void print(){
        cout<<Article::get_model();
        if(original){cout<<" original accessory ";}
    }

};

enum OperatingSystem{unknown,android,iOS,macOS,linux,proprietary,unix,windows};
ostream& operator<< (ostream& o,OperatingSystem& os){
  switch (os){
      case unknown:o<<"unknown";break;
      case android:o<<"android";break;
      case iOS:o<<"ios";break;
      case macOS:o<<"macIos";break;
      case linux:o<<"linux";break;
      case proprietary:o<<"proprietary";break;
      case unix:o<<"unix";break;
      case windows:o<<"windows";break;

  }
return o;
}
class Device:public Article{
private:
    int main_memory;
    OperatingSystem OS;
public:
    Device(string name,double netPrice,int mainmemorysize,OperatingSystem oss=unknown):Article(name,netPrice),main_memory(mainmemorysize),OS(oss){}
    virtual ~Device(){cout<<"~Device()";}
    OperatingSystem get_os(){ return  OS;}
    virtual void print(){
        cout<<Article::get_model()<<" RAM "<<main_memory<<" GB "<<OS;
    }
};

class Notebook:public Device{
private:
    string drive;
    bool convertible;
public:
    Notebook(string name,double netPrice,int mainmemorysize,string driv,OperatingSystem os=linux,bool con=false):Device(name,netPrice,mainmemorysize,os),drive(driv),convertible(con){}
    virtual  ~Notebook(){cout<<" ~Notebook() ";}
    bool is_a_convertible(){return convertible;}
    virtual void print(){
        Device::print();
        if(convertible){cout<<" convertible ";}
    }

};

class Phone:  public Device{
public:
    Phone(string name,double netPrice,int memorysize=4,OperatingSystem os=android):Device(name,netPrice,memorysize,os){}
    virtual  ~Phone(){cout<<" ~Phone() ";}
    virtual  void print(){
        Device::print();cout<<" phone ";

    }
};
class InCart{
private:
    Article *article;
    int amount;
    InCart *next;
public:
    InCart(Article *a,int b=0, InCart *c= nullptr):article(a),amount(b),next(c){}
    virtual  ~InCart(){
        cout<<" ~InCart() "<<amount;
        delete article;
    }

    InCart* get_next(){
        return next;
    }

    virtual  void print(){
        cout<<amount<<" ";
        article->print();cout<<endl<<"              "<<article->get_grossPrice()<<"            "<<amount*(article->get_grossPrice())<<endl;

    }
};

class ShoppingCart{
private:
    InCart *articles;
    double minFreeShipping;
    double sumNetPrice;
    double sumGrossPrice;
public:
    ShoppingCart(InCart *x=nullptr,double a=1000.0,double b=0.0,double c=0.0):articles(x),minFreeShipping(a),sumNetPrice(b),sumGrossPrice(c){}
    ~ShoppingCart(){cout<<"~ShoppingCart()";
                    cout<<endl;
                     while(articles!=nullptr)
                     {
                      cout<<"delete article:";
                      delete articles;
                      cout<<endl;
                      articles=articles->get_next();
                     }
                    }

    void set_minFreeShipping(double x)
                                     {
                                         minFreeShipping=x;
                                     }
    void add_article(Article *x,int amount){
                                             if(articles==nullptr){
                                                                   articles=new InCart(x,amount);
                                                                   sumNetPrice=sumNetPrice+(x->get_netPrice()*amount);
                                                                   sumGrossPrice=sumGrossPrice+(x->get_grossPrice()*amount);
                                                                  }else
                                                                       {articles=new InCart(x,amount,articles);
                                                                        sumNetPrice=sumNetPrice+(x->get_netPrice()*amount);
                                                                        sumGrossPrice=sumGrossPrice+(x->get_grossPrice()*amount);
                                                                       }
                                           }


virtual void print(){
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"+           P R O T O  - T E C  -  S H O P            +"<<endl;
        cout<<"+          Y O U R   S H O P P I N G C A R T          +"<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
       InCart *temp_article;
       temp_article=articles;
        while(temp_article!=nullptr)
           {  temp_article->print();
              temp_article=temp_article->get_next();
           }
           cout<<"                                                -------------"<<endl;
           cout<<"                            sum net price:  "<<sumNetPrice<<endl;
           cout<<"                                      tax:  "<<(sumGrossPrice-sumNetPrice)<<endl;
           cout<<"                          sum gross price:  "<<sumGrossPrice<<endl;
           cout<<"                                                -------------"<<endl;
if(sumGrossPrice>=minFreeShipping)
          {cout<<"                                 shipping:                0.00    "<<endl;
           cout<<"                                    total:  "<<sumGrossPrice <<endl;}else
          {cout<<"                                 shipping:                5.90    "<<endl;
           cout<<"                                    total:  "<<(sumGrossPrice+5.90)<<endl;}
           cout<<"                                                =================="<<endl;
}
};

void Show_What_U_Want_To_See()
{
    ShoppingCart shoppingcart;
    shoppingcart.set_minFreeShipping(500);
    Article *firstArticle= new Accessory("YOOLOX 10k Wireless Powerbank Qi",31.08,false);
    shoppingcart.add_article(firstArticle,3);

     shoppingcart.print();

    Article *seceondArticle=new Phone("Samsung s10 + SM-G975F/DS Dual SIM",661.67,8);
    shoppingcart.add_article(seceondArticle,1);
    Article *thirdArticle=new Phone("Apple iPhone 11 pro 256GB",1097.47,4,iOS);
    shoppingcart.add_article(thirdArticle,2);
    Article *fourthArticle=new Notebook("ASUS ROG Strix Scar III G731",1586.55,16,"512GB SSD + 1TB SSHD",windows);
    shoppingcart.add_article(fourthArticle,1);

     shoppingcart.print();
   cout<<"******************************************************************************"<<endl;
   cout<<"*         here we will check if original and convertible works               *"<<endl;
   cout<<"*                                                                            *"<<endl;
   cout<<"******************************************************************************"<<endl;
      Article *fifthArticle=new Phone("Samsung s6 edge Plus + SM-N905F/DS Single SIM",250.00,8);
    shoppingcart.add_article(fifthArticle,2);
    Article *sixthArticle= new Accessory("Intenso USB-Stick Basic Line 64 GB",9.39,true);
    shoppingcart.add_article(sixthArticle,1);
    Article *seventhArticle=new Notebook("Apple MacBook Air (2019) MVFL2D/A 33,8 cm (13,3 Zoll)",2000.09,16,"512GB SSD + 1TB SSHD",macOS,true);
    shoppingcart.add_article(seventhArticle,1);

    shoppingcart.print();


}
void headLine(){
   cout<<"******************************************************************************"<<endl;
   cout<<"*                                                                            *"<<endl;
   cout<<"*                       Welcome To ProtoTechShop                             *"<<endl;
   cout<<"*                                                                            *"<<endl;
   cout<<"******************************************************************************"<<endl;
   cout<<"                                                                              "<<endl;
}
void EndLine(){
   cout<<"******************************************************************************"<<endl;
   cout<<"*                                                                            *"<<endl;
   cout<<"*                          Good Buy                                          *"<<endl;
   cout<<"*                     dont forget to pay                                     *"<<endl;
   cout<<"******************************************************************************"<<endl;
   cout<<"                                                                              "<<endl;
}
   int main(){
   headLine();
   cout<<"Your automatic rechnung"<<endl;
   Show_What_U_Want_To_See();
   EndLine();
   return 0;}
