#include <stdio.h>
#define MAX 30
struct {
    char arr[14][7];//9�� �������� 21�� ��������, �����Ϻ��� ����ϱ���.
}column;
struct {

};
int main()
{
    FILE *in;
    int rst=fopen_s(&in, "schedule.txt", "r");
    if(rst==0)//������ �����ϴ� ���.
    {
        char arr[14][7]; 
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                fscanf_s(in, "%s", &arr[j][i]);
            }
        }
    }
    else
    {

    }

}
