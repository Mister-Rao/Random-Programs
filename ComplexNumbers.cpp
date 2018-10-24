#include<iostream>
#include<stdlib.h>
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
      complex t(*this);
      t.rl++; 
      t.img++;
      return t;
    }

//operator ++ [post-increment] Overloading
    complex operator++(int)
    {
      complex temp(*this);
      ++(temp);
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
        int ch, count;
        cout<<"Enter the First complex number: \t";
        cin>>num1;
        cout<<"\nEnter the Second complex number: \t";
        cin>>num2;

        complex num3, num4;

        top:
        cout<<"\n\nSelect the operation you want to perform:\n";
        cout<<"\t1.addition\n\t2.subtraction\n\t3.multiplication\n\t4.Division\n";
        cout<<"\t5.scalarMultiplication\n\t6.preIncrement\n\t7.postIncrement\n";
        cout<<"\t8.Add and Assign\n\t9.Equality Check\n\n\n";

        count = 0;
        here:
        while (1)
       {
        cout<<"\t\tEnter the choice: ";
        cin>>ch;
        count++;

        //Selection of operation
        switch (ch) {

          case 1://addition
                  num3 = num1 + num2;
                  cout<<"\t\t\t\t\t:sum is: "<<endl;
                  cout<<"\t\t\t\t( "<<num1<<" ) + ( "<<num2<<" ) = "<<num3<<endl;
                  cout<<"\n\n"<<endl;
                  break;

          case 2://subtraction
                  num3 = num1 - num2;
                  cout<<"\t\t\t\t\t:difference is: "<<endl;
                  cout<<"\t\t\t\t( "<<num1<<" ) - ( "<<num2<<" ) = "<<num3<<endl;
                  cout<<"\n\n"<<endl;
                  break;

          case 3://multiplication
                  num3 = num1 * num2;
                  cout<<"\t\t\t\t\t:product is: "<<endl;
                  cout<<"\t\t\t\t( "<<num1<<" ) * ( "<<num2<<" ) = "<<num3<<endl;
                  cout<<"\n\n"<<endl;
                  break;

          case 4://Division
                  num3 = num1 / num2;
                  cout<<"\t\t\t\t\t:quotient is: "<<endl;
                  cout<<"\t\t\t\t( "<<num1<<" ) / ( "<<num2<<" ) = "<<num3<<endl;
                  cout<<"\n\n"<<endl;
                  break;//end Division

          case 5://scalarMultiplication
                  int s, c;
                  cout<<"Which complex number do you want to multiply?"<<endl;
                  cout<<"1.] "<<num1<<"\t2.] "<<num2<<endl;
                  cin>>c;
                  cout<<"Enter the scalar multiplication factor: "<<endl;
                  cin>>s;
                  switch (c) {
                    case 1:
                            num3 = num1 * s;
                            cout<<"\t\t\t\t\t:Result is: "<<endl;
                            cout<<"\t\t\t\t"<<num1<<" * "<<s<<" = "<<num3<<endl;
                            cout<<"\n\n"<<endl;
                            break;

                    case 2:
                            num3 = num2 * s;
                            cout<<"\t\t\t\t\t:Result is: "<<endl;
                            cout<<"\t\t\t\t"<<num2<<" * "<<s<<" = "<<num3<<endl;
                            cout<<"\n\n"<<endl;
                            break;

                    default:
                            cout<<"Enter a valid choice!"<<endl;
                  }
                  break;//end scalarMultiplication

          case 6://preIncrement
                  int c_1;
                  cout<<"Which complex number do you want to preIncrement?"<<endl;
                  cout<<"1.] "<<num1<<"\t2.] "<<num2<<endl;
                  cin>>c_1;
                  switch (c_1) {
                    case 1:
                            num3 = ++num1;
                            cout<<"\t\t\t\t\t:Result is: "<<endl;
                            cout<<"\t\t\t\t++( "<<num1<<" )  = "<<num3<<endl;
                            cout<<"\n\n"<<endl;
                            break;

                    case 2:
                            num3 = num2++;
                            cout<<"\t\t\t\t\t:Result is: "<<endl;
                            cout<<"\t\t\t\t++( "<<num2<<" ) = "<<num3<<endl;
                            cout<<"\n\n"<<endl;
                            break;

                    default:
                            cout<<"Enter a valid choice!"<<endl;
                  }
                  break;//end preIncrement

          case 7://postIncrement
                  int c_2;
                  cout<<"Which complex number do you want to postIncrement?"<<endl;
                  cout<<"1.] "<<num1<<"\t2.] "<<num2<<endl;
                  cin>>c_2;
                  switch (c_2) {
                    case 1:
                            ++num1;
                            cout<<"\t\t\t\t\t:Result is: "<<endl;
                            cout<<"\t\t\t\t( "<<num1<<" )++  = "<<num1<<endl;
                            cout<<"\n\n"<<endl;
                            break;

                    case 2:
                            ++num2;
                            cout<<"\t\t\t\t\t:Result is: "<<endl;
                            cout<<"\t\t\t\t( "<<num2<<" )++ = "<<num2<<endl;
                            cout<<"\n\n"<<endl;
                            break;

                    default:
                            cout<<"Enter a valid choice!"<<endl;
                  }
                  break;//end postIncrement
          
          default://Choice handler
                  cout<<"Enter a valid choice!"<<endl;
                  
         }//end switch

         if(count == 5){//clear screen handler
           cin.get();
           system("clear");
           count = 0;
           goto top;}
      
      }//end while
}//end main
