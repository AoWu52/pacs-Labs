#include <map>
#include <unordered_map>
#include <iostream>
#include <chrono>

int main ()
{
	std::map<int, int> m;
auto start = std::chrono::high_resolution_clock::now();
for (int i = 0; i < (1 << 20); ++i) //2^20 ~= 10^6
    m[i] = i;
auto end = std::chrono::high_resolution_clock::now();
auto delta_m = std::chrono::duration_cast<
std::chrono::microseconds>(end - start).count ();

std::unordered_map<int, int> u; 
u.reserve(1 << 20); //prevents repeated rehashing: try to comment this
start = std::chrono::high_resolution_clock::now();
for (int i = 0; i < (1 << 20); ++i) 
    u[i] = i;
end = std::chrono::high_resolution_clock::now();
auto delta_u = std::chrono::duration_cast<
std::chrono::microseconds>(end - start).count ();

std::cout << "speed-up: " << (static_cast<double>(delta_m)
/static_cast<double>(delta_u)) << std::endl;

	return 0;
}
