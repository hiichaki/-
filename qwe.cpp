#include <iostream>
#include <vector>
#include <queue>
#include <limits>

int main()
{
   std::locale::global(std::locale(""));
   std::cout << "¬ведите начальную вершину: " << std::endl;
   int start;
   std::cin  >> start;
   std::cout << "¬ведите количeство вершин: " << std::endl;
   int n;
   std::cin  >> n;
   int length;
   std::cout << "¬ведите нужную длинну пути: " << std::endl;
   std::cin  >> length;
   std::cout << "¬ведите матрицу размером "  
             << n << "x" << n << ":" 
             << std::endl;
   std::vector <std::vector <int> > g(n, std::vector<int>(n, 0));
   for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < n; j++)
            std::cin >> g[i][j];
   
   const int infinity = std::numeric_limits<int>::max();
   std::vector <int>  d(n, infinity);
   d[start-1] = 0;
   std::queue <int> bfs;
   bfs.push(start-1);
   while (!bfs.empty())
   {
      int now = bfs.front();
      bfs.pop();
      for (size_t i = 0; i < n; i++)
            if (g[now][i] != 0 && d[now] + g[now][i] < d[i])
            {
                        d[i] = d[now] + g[now][i];
                        bfs.push(i);
            }
   }
   std::cout << "—ледующие вершины расположеные за " 
             << length 
             << " от вершины " 
             << start << ":"
             << std::endl;
 
   for (size_t i = 0; i < n; i++)
      if (d[i] == length) 
            std::cout << i+1 << " ";
   std::cout << std::endl;
 
   return 0;
}
