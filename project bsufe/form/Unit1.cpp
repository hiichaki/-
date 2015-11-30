//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
      StringGrid1->Cells[0][0]="h";
      StringGrid1->Cells[1][0]="m";
      StringGrid1->Cells[2][0]="s";
      StringGrid1->Cells[3][0]="t";
      TStringList *LL = new TStringList;
      LL->LoadFromFile("1.txt");
      int i;
      for (i=1;i<LL->Count;i++)
        StringGrid1->Rows[i]->CommaText=LL->Strings[i];

      StringGrid1->RowCount=i;

        for(int j=1;j<StringGrid1->RowCount-1;++j)
                Series1->AddY( StrToInt(StringGrid1->Cells[3][j]), clRed);

}
//---------------------------------------------------------------------------
