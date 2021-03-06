#include<iostream>

using namespace std;

class complex
{

//Variables rl and img parts
  public:
    int rl; //rl
    int img; //img

  public:
    complex(){}; // constructor

//Parameterized constructor
    complex(int r, int i)
    {
      rl = r;
      img = i;
    }

//copy constructor
    complex (const complex &ob)
    {
      rl = ob.rl;
      img = ob.img;
    }

//operator + Overloading
    complex operator+(const complex&ob)
    {
      complex t;
      t.rl = rl + ob.rl;
      t.img = img + ob.img;
      return(t);
    }

//operator - Overloading
    complex operator-(complex ob)
    {
      complex t;
      t.rl = rl - ob.rl;
      t.img = img - ob.img;
      return(t);
    }

//operator * Overloading
    complex operator*(complex ob)
    {
      complex t;
      t.rl = ob.rl*rl - ob.img*img;
      t.img = ob.rl*img + ob.img*rl;
      return(t);
    }

//operator / Overloading
    complex operator/(complex ob)
    {
      complex t;
      float tmp;
      tmp=ob.rl * ob.rl + ob.img * ob.img;
      t.rl=(ob.rl*rl+ob.img*img)/tmp;
      t.img=(ob.rl*img-ob.img*rl)/tmp;
      return(t);
    }

//operator * for scalar multiplication
    complex operator*(int a)
    {
      complex t;
      t.rl = rl*a;
      t.img = img*a;
      return(t);
    }

//operator = Overloading
    complex operator=(complex ob)
    {
      rl = ob.rl;
      img = ob.img;
      return *this;
    }

//operator ++ [pre-increment] Overloading
    complex operator++()
    {
      ++rl;
      ++img;
      return *this;
    }

//operator ++ [post-increment] Overloading
    complex operator++(int)
    {
      complex temp(*this);
      ++(*this);
      return temp;
    }


//operator += adding a complex number
    complex operator+=(complex ob)
    {
      rl = rl + ob.rl;
      img = img + ob.img;
      return *this;
    }

//operator == Overloading
    bool operator==(complex ob)
    {
      if(rl == ob.rl)
        if(img == ob.img)
          return true;
      return false;
    }
//operator << Overloading
    friend ostream &operator<<(ostream &dout, complex &c)
    {
      if(c.img>=0)
        dout<<c.rl<<"+"<<c.img<<"i";
      else
        dout<<c.rl<<c.img<<"i";
      return (dout);
    }

//operator >> Overloading
    friend istream &operator>>(istream &din,complex &c)
    {
      din>>c.rl>>c.img;
      return (din);
    }

};

int main()
{
        complex num1, num2;
        int ch;
        cout<<"Enter the First complex number: \n";
        cin>>num1;
        cout<<"Enter the Second complex number: \n";
        cin>>num2;

        complex num3, num4;

        while (1) {
        cout<<"Select the operation you want to perform:\n";
        cout<<"\t1.addition\n\t2.subtraction\n\t3.multiplication\n\t4.Division\n";
        cout<<"\t5.scalarMultiplication\n\t6.preIncrement\n\t7.postIncrement\n";
        cout<<"\t8.Add and Assign\n\t9.Equality Check\n";
        cout<<"\t\tEnter the choice: ";
        cin>>ch;

//Selection of operation
        switch (ch) {
          case 1:
                  num3 = num1 + num2;
                  cout<<"\t\t\t\t\t:sum is: "<<endl;
                  cout<<"\t\t\t\t( "<<num1<<" ) + ( "<<num2<<" ) = "<<num3<<endl;
                  break;

          case 2:
                  num3 = num1 - num2;
                  cout<<"\t\t\t\t\t:difference is: "<<endl;
                  cout<<"\t\t\t\t( "<<num1<<" ) - ( "<<num2<<" ) = "<<num3<<endl;
                  break;

          case 3:
                  num3 = num1 * num2;
                  cout<<"\t\t\t\t\t:product is: "<<endl;
                  cout<<"\t\t\t\t( "<<num1<<" ) * ( "<<num2<<" ) = "<<num3<<endl;
                  break;

          case 4:
                  num3 = num1 / num2;
                  cout<<"\t\t\t\t\t:quotient is: "<<num3<<endl;
                  cout<<"\t\t\t\t( "<<num1<<" ) / ( "<<num2<<" ) = "<<num3<<endl;
                  break;
        }
      }
}
