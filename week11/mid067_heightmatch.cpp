#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // ปรับปรุงประสิทธิภาพของ I/O ใน C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    // รับค่าจำนวนคน N และระยะความยาวไม้ L
    if (!(cin >> n >> l)) return 0;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // ใช้ Hash Map เก็บว่า ความสูงนี้ (Key) ถูกพบครั้งล่าสุดที่ตำแหน่งไหน (Value)
    unordered_map<int, int> last_seen;
    int count = 0;

    // วนลูปจากคนขวาสุดไปซ้ายสุด
    for (int i = n - 1; i >= 0; --i) {
        // เงื่อนไข: เคยเจอคนความสูงเท่ากัน และระยะห่างไม่อยู่ไกลเกินความยาวไม้ L
        if (last_seen.count(h[i]) && last_seen[h[i]] - i <= l) {
            count++;
        }
        
        // อัปเดตตำแหน่งล่าสุดที่เจอความสูงนี้เป็นตำแหน่งปัจจุบัน
        last_seen[h[i]] = i;
    }

    // แสดงผลลัพธ์จำนวนคนที่สามารถหาคู่ได้
    cout << count << "\n";

    return 0;
}