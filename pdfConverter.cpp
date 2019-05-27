#include<iostream>
#include<graphics.h>
#include<stack>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>

#define Begin_Text "BT"
#define End_Text "ET"
#define Header "%PDF-"
#define Rectangel "re"
#define StartGraphics "stream"
#define StopGraphics "endstream"

using namespace std ;

ofstream oFile;
ifstream iFile;
string inputFile,outputFile;

void FileNameInput()
{
    cout << "Enter Your Input File Name" << endl ;
    cin >> inputFile;
    cout << "Enter Your Output File Name" << endl ;
    cin >> outputFile;

}

bool checkPdf()
{
    iFile.open(inputFile.c_str());
    if(iFile.is_open())
    {
        string s,t;
        getline(iFile,s);
        for(int i=0;i<5;i++)
        {
            t=t+s[i];
        }
        if(t==Header)
         {
             iFile.close();
            return true;
         }
        else
            return false;
    }
    else
    {
        cout << "Khule Nai" << endl;
        return false;
    }

}

void PdfToTextExtracsion()
{
    iFile.open(inputFile.c_str());
    if(iFile.is_open())
    {
        oFile.open(outputFile.c_str());
        if(oFile.is_open())
        {
            bool flag=false;
            int count=0;
            string getWord;
            while(getline(iFile,getWord))
            {

                if(getWord==Begin_Text)
                {
                    flag=true;
                }
                if(getWord==End_Text)
                {
                    flag=false;
                    count=0;
                }
                if(flag==true)
                {
                    count++;
                }
            if(count==4 || count==5)
            {
                string s=getWord;
                int n=s.length();
                int fmarker=-1,lmarker=-1;
                for(int i=0;i<n;i++)
                {
                    if(s[i]=='(')
                    {
                         fmarker=i;
                         break;
                    }

                }

                for(int j=n-1;j>0;j--)
                {
                    if(s[j]==')')
                    {
                         lmarker=j;
                         break;
                    }

                }
                if(fmarker!=-1 && lmarker!=-1)
                {
                    for(int i=fmarker+1;i<lmarker-1;i++)
                    {
                        oFile<<s[i];
                    }
                    oFile<<endl;
                }

            }
        }
        oFile.close();
        }
        iFile.close();
    }
}

int stringToint(string s)
{
      stringstream value(s);

    int x = 0;
   value >> x;

    return x;
}

void drawRectangel(int *arr)
{
    int gd = DETECT, gm;

   initgraph(&gd, &gm, " ");

   rectangle(arr[0],arr[1],arr[2],arr[3]);

   getch();
   closegraph();
}

void drawLine(int *arr)
{
     int gd = DETECT, gm;

   initgraph(&gd, &gm, " ");

   line(arr[0],arr[1],arr[2],arr[3]);

   getch();
   closegraph();

}

double factorialCounter(int i)
{
    if (i==0)
    {
      return (1);
    }
    else
     return (i*factorialCounter(i-1));

}
double pixelCounter(int *arr,int n,double t)
{
    double pixel=0;
    int p=n-1;
    for(int i=0;i<n;i++)
    {
        pixel=pixel+((factorialCounter(p)/factorialCounter(p-i))*(pow(t,i))*(pow((1-t),(p-i)))*arr[i]);
    }
    return pixel;
}
void BeizerCurve(int *arr,int n)
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, " ");
    int x[n],y[n],px,py,i;
    //cout<< "Enter four control points of bezier curve: " ;
    for(i=0;i<n;i++)
    {
        x[i]=arr[i*2];
        y[i]=arr[i*2+1];
    }
    double t;
    for(int i=0;i<n;i++)

    for(t=0.0;t<=1.0;t+=0.001){
            px=pixelCounter(x,n,t);
            py=pixelCounter(y,n,t);
    //px=(1-t)*(1-t)*x[0]+2*t*(1-t)*x[1]+t*t*x[2];
    //py=(1-t)*(1-t)*y[0]+2*t*(1-t)*y[1]+t*t*y[2];
    putpixel(px,py,RED);
    //delay(2);
    line(x[0],y[0],x[n-1],y[n-1]);
    }
    getch();
    closegraph();
}
void GraphicsDrawer()
{
    iFile.open(inputFile.c_str());
    if(iFile.is_open())
    {
        string line;
        while(getline(iFile,line))
        {
            if(line==StartGraphics)
            {
                while(true)
                {
                    getline(iFile,line);
                    if(line==StopGraphics)break;
                        string s,t;
                        int n;
                        s=line;
                        n=s.length();
                        //cout << n << endl;
                        for(int i=n-1;i>=0;i--)
                        {
                            int count=0;
                            if(s[i]>='a' && s[i] <='z' && s[i]=='e' && s[i-1]=='r' && count==0)
                            {
                               //cout << "Yes" << endl;
                               t=s[i-1]+s[i];
                               break;

                            }
                        }
                        if(t==Rectangel)
                        {
                            string arr[4];
                            int count=0;
                            for(int i=0;i<n;i++)
                            {
                                if(count==0)
                                {
                                    if(s[i]==' ')
                                    {
                                        count++;
                                        continue;
                                    }
                                    arr[0]=arr[0]+s[i];
                                }
                                if(count==1)
                                {
                                    if(s[i]==' ')
                                    {
                                        count++;
                                        continue;
                                    }
                                    arr[1]=arr[1]+s[i];
                                }
                                if(count==2)
                                {
                                    if(s[i]==' ')
                                    {
                                        count++;
                                        continue;
                                    }
                                    arr[2]=arr[2]+s[i];
                                }
                                if(count==3)
                                {
                                    if(s[i]==' ')
                                    {
                                        count++;
                                        continue;
                                    }
                                    arr[3]=arr[3]+s[i];
                                }
                                if(count==4)
                                {
                                    break;
                                }
                            }
                            int coOrdinate[4];
                            for(int i=0;i<4;i++)
                            {
                                coOrdinate[i]= stringToint(arr[i]);
                            }
                            drawRectangel(coOrdinate);

                        }

                        t.clear();
                }
            }

        }
        iFile.close();
    }
    iFile.open(inputFile.c_str());
    if(iFile.is_open())
    {
        string line;
        string arr[4];
        int count=0;
        while(getline(iFile,line))
        {
            if(line==StartGraphics)
            {
                while(true)
                {
                    getline(iFile,line);
                    if(line==StopGraphics)break;
                        string s,t;
                        int n;
                        s=line;
                        n=s.length();
                        for(int i=n-1; i>=0;i--)
                        {
                            if(s[i]=='m' && count==0)
                            {
                                int bount=0;
                                for(int i=0;i<n;i++)
                                {
                                if(bount==0)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[0]=arr[1]+s[i];
                                }
                                if(bount==1)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[1]=arr[1]+s[i];
                                }

                                if(bount==2)
                                {
                                    break;
                                }
                                count=1;
                            }
                            }
                            if(s[i]=='l' && count==1)
                            {
                                int bount=0;
                                for(int i=0;i<n;i++)
                                {
                                if(bount==0)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[2]=arr[2]+s[i];
                                }
                                if(bount==1)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[3]=arr[3]+s[i];
                                }

                                if(bount==2)
                                {
                                    break;
                                }
                                count=2;
                            }
                            }

                        }
                            int coOrdinate[4];
                            for(int i=0;i<4;i++)
                            {
                                coOrdinate[i]= stringToint(arr[i]);
                            }
                            drawLine(coOrdinate);


                }

            }

        }
        iFile.close();
    }

    iFile.open(inputFile.c_str());
    if(iFile.is_open())
    {
        string line;
        string arr[8];
        int count=0;
        while(getline(iFile,line))
        {
            if(line==StartGraphics)
            {
                while(true)
                {
                    getline(iFile,line);
                    if(line==StopGraphics)break;
                        string s,t;
                        int n;
                        s=line;
                        n=s.length();
                        for(int i=n-1; i>=0;i--)
                        {
                            if(s[i]=='m' && count==0)
                            {
                                int bount=0;
                                for(int i=0;i<n;i++)
                                {
                                if(bount==0)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[0]=arr[1]+s[i];
                                }
                                if(bount==1)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[1]=arr[1]+s[i];
                                }

                                if(bount==2)
                                {
                                    break;
                                }
                                count=1;
                            }
                            }
                            if(s[i]=='c' && count==1)
                            {
                                int bount=0;
                                for(int i=0;i<n;i++)
                                {
                                if(bount==0)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[2]=arr[2]+s[i];
                                }
                                if(bount==1)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[3]=arr[3]+s[i];
                                }

                                if(bount==2)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[4]=arr[4]+s[i];
                                }
                                if(bount==3)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[5]=arr[5]+s[i];
                                }
                                if(bount==4)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[6]=arr[6]+s[i];
                                }
                                if(bount==5)
                                {
                                    if(s[i]==' ')
                                    {
                                        bount++;
                                        continue;
                                    }
                                    arr[7]=arr[7]+s[i];
                                }

                                if(bount==6)
                                {
                                    break;
                                }
                                count=2;
                            }
                            }

                        }
                            int coOrdinate[8];
                            for(int i=0;i<8;i++)
                            {
                                coOrdinate[i]= stringToint(arr[i]);
                            }
                            BeizerCurve(coOrdinate,4);

                }
            }

        }
        iFile.close();
    }

}


int main (void)
{
    FileNameInput();
    bool checkPdfFile=false;
    checkPdfFile=checkPdf();
    if(checkPdfFile==true)PdfToTextExtracsion();
    GraphicsDrawer();
    return 0;
}
