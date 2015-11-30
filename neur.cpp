#include <math.h>
#include <windows.h>
#include <cstdlib> 
#include <ctime>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>
#define E 2.7182818284590452354
 
using namespace std;
class neur{
public:
    double input_v[5];
    int in_v_size;
    double input_w[5];
    double input_w_old;
    double act_f;
    double pr_act_f;
    double summ;
    long err_n;
 
    neur(int Size_in_v){
        summ=0;
        err_n=0;
        pr_act_f=0;
        act_f=0;
        input_w_old=0;
        in_v_size=Size_in_v;
        /*double **input_v=new double*[Size_in_v];
        double **input_w=new double*[Size_in_v];
        for(int i=0;i<Size_in_v;i++){
        input_v[i]=new double[Size_in_v];
        input_w[i]=new double[Size_in_v];
        }*/
    }
    neur(){
        summ=0;
        err_n=0;
        pr_act_f=0;
        act_f=0;
        in_v_size=0;
        input_w_old=0;
    }
    ~neur(){};
    /*  ~neur(){
    for(int i=0;i<in_v_size;i++){
    delete[](input_v[i]);
    delete[](input_w[i]);
    }
    delete[](input_v);
    delete[](input_w);
    }*/
    double Sum_n(){
        summ=0;
        for(int i=0;i<in_v_size;i++){
            summ=summ+(input_v[i])*(input_w[i]);
        }
        return summ;
    }
    double Activ_f(){
        act_f=1./(1+exp((-1)*summ));
        return act_f;
    }
 
    void pr_activ_f(){
        pr_act_f=act_f*(1.-act_f);
        //pr_act_f =pow(E, -summ)/pow( ( 1 + pow(E, -summ)), 2);
    }
 
    double err_count_y(double z){
        err_n=(z-summ)*1.0;
        return err_n;
    }
 
 
    void weight_correct(double h){
        for(int i=0;i<in_v_size;i++){
            input_w[i]=(input_w[i])+h*(err_n)*(pr_act_f)*(input_v[i]);
        }
    }
    void close_enough(double h){
        input_w_old=0;
        for(int i=0;i<in_v_size;i++){
            input_w_old=pow(input_w[i],2)+input_w_old;
        }
        input_w_old=sqrt(input_w_old);
    }
    /*  void def_to_dinamic(int Size_in_v){
    in_v_size=Size_in_v;
    double **input_v=new double*[Size_in_v];
    double **input_w=new double*[Size_in_v];
    for(int i=0;i<Size_in_v;i++){
    input_v[i]=new double[Size_in_v];
    input_w[i]=new double[Size_in_v];
    }
    }*/
};
 
neur neur_h[5];
neur Y;
 
void err_count(neur W){
    for(int i=0;i<5;i++){
        neur_h[i].err_n=W.err_n*(W.input_w[i]);
    }
}
 
double random(double min,double max){
    return (double)(rand())/RAND_MAX*(max-min)+min;
}
 
int main()
{
    float b=0.7*pow(5,1/2);
    srand((unsigned int)time(NULL));
    double **mass = new double* [9];
    for (int count = 0; count < 9; count++)
        mass[count] = new double [9]; 
    int k=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            mass[i][j]=(i+1)*(j+1);
 
    for (int i=0;i<5;i++){
        neur_h[i]=*new neur(2);
        for(int j=0;j<2;j++){
        neur_h[i].input_w[j]=(rand()%100)/(100*1.0)-0.5;
        }
    }
 
    Y=*new neur(5);
 
    for(int i=0;i<5;i++){
        Y.input_w[i]=(rand()%100)/(100*1.0)-0.5;
    }
    double **mass_r = new double* [9];
    for (int count = 0; count < 9; count++)
        mass_r[count] = new double [9]; 
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            mass_r[i][j]=0;
    double step=1;
 
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int sch=0;
            while (1){
 
                for (int k = 0; k < 5; k++)
                {
                    if (sch==0){
                        neur_h[k].input_v[0]=i+1;
                        neur_h[k].input_v[1]=j+1;
                //      for (int s = 0; s  < 2; s ++)
            //          {
 
            //              neur_h[k].input_w[s]=(b*neur_h[k].input_w[s])/neur_h[k].input_w_old;
            //          }
                        
                    }
 
                    neur_h[k].Sum_n();
                    neur_h[k].Activ_f();
                    neur_h[k].pr_activ_f();
                    Y.Activ_f();
                    Y.pr_activ_f();
                    Y.input_v[k]=neur_h[k].act_f;
                }
 
                Y.Sum_n();
 
                Y.err_count_y(mass[i][j]);
                err_count(Y);
                    Y.weight_correct(step);
 
                for (int q = 0; q < 5; q++)
                {
                    neur_h[q].weight_correct(step);
                }
                //Y.weight_correct(step);
 
                for (int k = 0; k < 5; k++)
                {
                    neur_h[k].Sum_n();
                    neur_h[k].Activ_f();
                    neur_h[k].pr_activ_f();
                    Y.input_v[k]=neur_h[k].act_f;
                    //  cout<<"Second Input r_weight_"<<k<<" "<<Y.input_w[k]<<" "<<Y.input_v[k]<<endl;
                }
                Y.Sum_n();
                //if((step<1)||(step>0))
                //step=0.1;
                if (Y.summ>mass[i][j])
                {
                step=step-0.1;
                }
                if (Y.summ<mass[i][j])
                {
                step=step+0.1;
                }
 
            //  getchar();
                Y.err_count_y(mass[i][j]);
                cout<<i+1<<"*"<<j+1<<"="<<Y.summ<<" "<<Y.err_n<<" "<<mass[i][j]<<" "<<Y.summ<<" "<<step<<endl;
            //  for (int i = 0; i < 5; i++)
            //  {
                //  for (int j = 0; j < 2; j++)
                //  {
                //      cout<<" Input neur_"<<i<<" Input weight_"<<j<<" "<<neur_h[i].input_w[j]<<endl;
                //  }
 
                //  cout<<" Input r_weight_"<<i<<" "<<Y.input_w[i];
                //  cout<<" Input r_value_"<<i<<" "<<Y.input_v[i];
                //  cout<<endl;
            //  }
                if(abs(Y.err_n)<0.1){
                    //cout<<i+1<<"*"<<j+1<<"="<<Y.summ<<" "<<Y.err_n<<" "<<mass[i][j]<<" "<<Y.summ<<" "<<step<<endl;
                    mass_r[i][j]=Y.summ;
                    //getchar();
                    step=1;
                    sch=0;
                for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 2; j++)
                        {
                            neur_h[i].input_w[j]=(rand()%100)/(100*1.0)-0.5;
                        }
 
                        Y.input_w[i]=(rand()%100)/(100*1.0)-0.5;
                }
 
                    break;
                }
 
 
            }   
        }
    }
    system("pause");
    return 0;
}
