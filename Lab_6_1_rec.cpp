// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву рекурсивним способом
// Варіант 30
 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
// Рекурсивно заповнює масив випадковими числами з діапазону [Low; High].
// a - масив; size - кількість елементів;
// Low, High - межі діапазону значень (параметри-значення);
// i - індекс поточного елемента (початкове значення - 0)
void Create(int* a, const int size, const int Low, const int High, int i)
{
   a[i] = Low + rand() % (High - Low + 1);        // дія, що виконувалася в тілі циклу
   if (i < size - 1)                              // умова продовження рекурсії
       Create(a, size, Low, High, i + 1);         // рекурсивний виклик
}
 
// Рекурсивно виводить елементи масиву в один рядок (кожен елемент - 4 позиції).
// a - масив; size - кількість елементів; i - індекс поточного елемента
void Print(int* a, const int size, int i)
{
   cout << setw(4) << a[i];
   if (i < size - 1)                              // умова продовження рекурсії
       Print(a, size, i + 1);                     // рекурсивний виклик
   else
       cout << endl;                              // дія після циклу: кінець рядка
}
 
// Критерій відбору: число додатне і парне.
// x - значення елемента масиву
bool Criterion(const int x)
{
   return x > 0 && x % 2 == 0;
}
 
// Рекурсивно повертає кількість елементів масиву, що задовольняють критерію.
// a - масив; size - кількість елементів; i - індекс поточного елемента
int Count(int* a, const int size, int i)
{
   if (i < size)
   {
       if (Criterion(a[i]))
           return 1 + Count(a, size, i + 1);      // елемент підходить - додаємо 1
       else
           return Count(a, size, i + 1);
   }
   else
       return 0;                                  // базова задача: елементів більше немає
}
 
// Рекурсивно повертає суму елементів масиву, що задовольняють критерію.
// a - масив; size - кількість елементів; i - індекс поточного елемента
int Sum(int* a, const int size, int i)
{
   if (i < size)
   {
       if (Criterion(a[i]))
           return a[i] + Sum(a, size, i + 1);     // елемент підходить - додаємо його
       else
           return Sum(a, size, i + 1);
   }
   else
       return 0;                                  // базова задача: елементів більше немає
}
 
// Рекурсивно замінює нулями елементи масиву, що задовольняють критерію.
// a - масив (параметр-посилання за суттю); size - кількість елементів;
// i - індекс поточного елемента
void ZeroCriterion(int* a, const int size, int i)
{
   if (Criterion(a[i]))                           // дія, що виконувалася в тілі циклу
       a[i] = 0;
   if (i < size - 1)                              // умова продовження рекурсії
       ZeroCriterion(a, size, i + 1);             // рекурсивний виклик
}
 
int main()
{
   srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
 
   const int n = 25;    // кількість елементів масиву
   const int Low = -20; // нижня межа діапазону значень
   const int High = 30; // верхня межа діапазону значень
   int a[n];
 
   Create(a, n, Low, High, 0);
   cout << "Початковий масив:" << endl;
   Print(a, n, 0);
 
   cout << "Кількість елементів (додатні парні) = " << Count(a, n, 0) << endl;
   cout << "Сума елементів (додатні парні) = " << Sum(a, n, 0) << endl;
 
   ZeroCriterion(a, n, 0);
   cout << "Модифікований масив:" << endl;
   Print(a, n, 0);
 
   return 0;
}
