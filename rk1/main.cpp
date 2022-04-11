#include <iostream>
#include <string>
#include <QList>
#include <QFile>
#include <QCoreApplication>


using namespace std;

///Task1
void ReadFromFile(const char* filename)
{
    QFile f(filename);
    f.open(QIODevice::ReadOnly);

    fileData=f.readAll();

    f.close();
}
void task1()
{
    ReadFromFile("text");
    int arr[256];
    memset(&arr[0],0x00,sizeof(int)*256);
    for (int i = 0; i < fileData.size(); ++i) {
        arr[fileData[i]]++;
    }
}

void WriteToFile (const int* arr)
{
    QFile f(filename);
    f.open(QIODevice::ReadOnly);

    fileData=f.write(arr);

    f.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void task2 (const int num, string& snum) {
    if (num % 2 == 0)
        snum += "0";
    else snum += "1";
    if ((num / 2) != 0) dec(num / 2, snum);
    else return;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///Task5
QList<float> getAverStr(int *Arr,int N,int M)
{
    QList<float> averstr;
    for (int i = 0; i < N; ++i) {
        float aStr_temp=0;
        for (int j = 0; j < M; ++j) {
            aStr_temp+=Arr[i*N+j]/M;
        }
        averstr.push_back(aStr_temp);
    }
    return averstr
}
void task5(int *Arr,int N,int M){
    QList<float> b= getAverStr(Arr,N,M);
    cout<<b<<endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Task6()
{
    adress *p = head;
    FILE *output;
    if (head == NULL)
    {
        system("cls");
        cout << "Список  пуст!" << endl;
    }
    else
    {
        output = fopen_s("Output.txt", "wb");
        if (output != NULL)
        {
            while (p != NULL)
            {
                fwrite(p, sizeof(city), 1, output);
                p = p->next;
            }
            cout << "Информация успешно сохранена" << endl;
            fclose(output);
        }
        else
            cout << endl << "\tНе удалось создать файл" << endl;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Double_List* Task7 (Double_List* Head,int Number, int DataItem){
    Number--;
    Double_List *NewItem=new(Double_List);
    NewItem->Data=DataItem;
    NewItem->Prior=NULL;
    NewItem->Next = NULL;
    if (Head == NULL) {
        Head = NewItem;
    }
    else {
        Double_List *Current=Head;
        for(int i=1; i < Number && Current->Next!=NULL; i++)
            Current=Current->Next;
        if (Number == 0){

            NewItem->Next = Head;
            Head->Prior = NewItem;
            Head = NewItem;
        }
        else {
            if (Current->Next != NULL) Current->Next->Prior = NewItem;
            NewItem->Next = Current->Next;
            Current->Next = NewItem;
            NewItem->Prior = Current;
            Current = NewItem;
        }
    }
    return Head;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///Task8
class Student{
private:
    int age;
    char *name;
    char *surname;
    char *Subject;
    int id_subject;
    int mark[];
public:
    void SetScores (int Scores[])
    {
        for (int i = 0; i < 5; ++i) {
            cin>>Scores[i];
            mark[i]=Scores[i];
        }
    }
    int averageMark(int n)
    {
        int sum=0;
        for (int i = 0; i < n; ++i) {
            sum+= mark[i];
        }
        float averageMark=sum/n;
        return averageMark;
    }

    void PrintStud()
    {
        cout << "ФИО студента: " << surname << " " << name << endl;
        cout << "Оценки студента: "<<endl;
        for (int i = 0; i < n; i++)
        {
            cout << this->uspev.at(i) << " ";
        }
        cout << "\nСредний балл студента: " << averageMark(5) << endl;
    }
    void addSubject(const char* subjName, int idSubj = 0) {
        listSubjMark.push_back(new SubjMark(subjName, idSubj));
    }

    int addMarkToSubj(const char* subjName /*int _idSubj*/, int mark) {
        int numSubj = lookForSub(subjName);

        listSubjMark[numSubj]->marks_list.push_back(mark);

        return 0;
    }
    int lookForSubj(const char* subjName) {
        for (int i = 0; i < listSubjMark.size(); i++)
        {
            if (strcmp(listSubjMark[i]->subj, subjName) == 0)
            {
                return i;
            }
        }
        listSubjMark.push_back(new SubjMark(subjName));
        return listSubjMark.size() - 1;
    }
    void set_name(string Name)
    {
        name=Name;
    }
    string get_name(string Name)
    {
        return Name;
    }
    void set_surname(string SurName)
    {
        surname=SurName;
    }
    string get_surname(string SurName)
    {
        return SurName;
    }
};

int main()
{

    return 0;
}

