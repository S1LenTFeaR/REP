//������� ������� ���. ��������� ������� ������
//� ������� �������� ��������
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

#define N 50
void glavelem( int k, double mas[] [N + 1], int n, int otv[] );

int main( )
{
	
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
  
  double mas[N] [N + 1];
  double x[N]; //����� �������
  int otv[N]; //�������� �� ������� ������
  int i, j, k, n;
  //���� ������
  system("cls");
  do
  {
    printf( "������� ����� ��������� �������: " );
    scanf_s( "%d", & n );
    if ( N < n )
      printf( "������� ������� ����� ���������. ��������� ����\n" );
  }
  while ( N < n );
  printf( "������� �������:\n" );
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n + 1; j++ )
      scanf_s( "%lf", & mas[i] [j] );
  //����� ��������� �������
 system("cls");
  printf( "�������:\n" );
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n + 1; j++ )
      printf( "%7.2f ", mas[i] [j] );
    printf( "\n" );
  }
  //������� ��� ����� �� �������
  for ( i = 0; i < n + 1; i++ )
    otv[i] = i;
  //������ ��� ������ ������
  for ( k = 0; k < n; k++ )
  { //�� ����� ������� ������ ������ ������� �������
    glavelem( k, mas, n, otv ); //��������� �������� ��������
    if ( fabs( mas[k] [k] ) < 0.0001 )
    {
      printf( "������� �� ����� ������������� �������" );
      return ( 0 );
    }
    for ( j = n; j >= k; j-- )
      mas[k] [j] /= mas[k] [k];
    for ( i = k + 1; i < n; i++ )
      for ( j = n; j >= k; j-- )
        mas[i] [j] -= mas[k] [j] * mas[i] [k];
  }
  //�������� ���
  for ( i = 0; i < n; i++ )
    x[i] = mas[i] [n];
  for ( i = n - 2; i >= 0; i-- )
    for ( j = i + 1; j < n; j++ )
      x[i] -= x[j] * mas[i] [j];
  //����� ����������
  printf( "�����:\n" );
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ )
      if ( i == otv[j] )
      { //����������� ����� �� �������
        printf( "%f\n", x[j] );
        break;
      }

	  system ("pause"); //����� ����� �� ��������� ����
  return ( 0 );
}
//----------------------------------------------
//��������  �������
//----------------------------------------------
void glavelem( int k, double mas[] [N + 1], int n, int otv[] )
{
  int i, j, i_max = k, j_max = k;
  double temp;
  //���� ������������ �� ������ �������
  for ( i = k; i < n; i++ )
    for ( j = k; j < n; j++ )
      if ( fabs( mas[i_max] [j_max] ) < fabs( mas[i] [j] ) )
      {
        i_max = i;
        j_max = j;
      }
  //������������ ������
  for ( j = k; j < n + 1; j++ )
  {
    temp = mas[k] [j];
    mas[k] [j] = mas[i_max] [j];
    mas[i_max] [j] = temp;
  }
  //������������ �������
  for ( i = 0; i < n; i++ )
  {
    temp = mas[i] [k];
    mas[i] [k] = mas[i] [j_max];
    mas[i] [j_max] = temp;
  }
  //��������� ��������� ������� ������
  i = otv[k];
  otv[k] = otv[j_max];
  otv[j_max] = i;
  
}

for (int k = 0; k < n - 1; k++)
{
    if (a1[k][k] == 0) //�� ������ ������� i-� ������ � k-�� �������
    {
        for (int i = k + 1; i < n; i++)
        {
            if (a1[i][k] != 0)
            {
                swap(a1[k], a1[i]);
                break;
            }
        }
    }
}
for (int k = 0; k < n - 1; k++) //��������� � ������ 1.2
{
    for (int i = k + 1; i < n; i++)
    {
        eps[i] = (-a1[i][k]) / a1[k][k];
        b[i] = b1[i] + eps[i] * b1[k];
        for (int j = k + 1; j < n; j++)
            a[i][j] = a1[i][j] + eps[i] * a1[k][j];
    }
}

cout << "���������� �������: " << endl;
vivod(a1);
cout << "���������� ������� 2: " << endl;
vivod(a);
//�������� ���
x[n - 1] = b[n - 1] / a[n - 1][n - 1];
cout << x[n - 1] << endl;
for (int i = n - 2; i > 0; i--)
{
    for (int j = n - 2; j > 0; j--)
        sum += a[i][i + j] * x[i + j];
    x[i] = 1 / (a[i][i]) * (b[i] - sum);
    cout << x[i] << endl;
}