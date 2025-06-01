
# 🎮 Dự án Game Cờ Caro Console bằng C++

> Tác giả: [Tên bạn]  
> Ngôn ngữ: C++  
> IDE khuyến nghị: CLion, Visual Studio, hoặc Code::Blocks  
> Nền tảng: Windows (sử dụng WinAPI)

---

## 🧠 Giới thiệu

Đây là một trò chơi **Cờ Caro (Gomoku)** trên nền **console Windows**, được viết bằng ngôn ngữ **C++** theo phong cách **lập trình hướng đối tượng (OOP)**. Chương trình cho phép **2 người chơi** thi đấu với nhau bằng cách điều khiển con trỏ và đánh dấu các ô trên bàn cờ. Ai đạt **5 ký hiệu liên tiếp (ngang/dọc/chéo)** trước sẽ giành chiến thắng.

---

## 🚀 Tính năng chính

- ✅ Giao diện khung bàn cờ linh hoạt (tuỳ chọn kích thước)
- ✅ Cho phép người chơi nhập tên và ký hiệu riêng
- ✅ Hỗ trợ điều khiển bằng phím `W`, `A`, `S`, `D` hoặc mũi tên
- ✅ Kiểm tra thắng theo cả 4 hướng
- ✅ In kết quả người thắng rõ ràng
- ✅ Có thể mở rộng dễ dàng về sau (AI, GUI, lưu ván...)

---

## 🛠️ Công nghệ sử dụng

- Ngôn ngữ: **C++17**
- Hệ điều hành: **Windows**
- Thư viện: **WinAPI** (con trỏ, màu sắc, bàn phím...)
- Build system: **CMake** (nếu dùng CLion)
- IDE: CLion / Visual Studio / Code::Blocks

---

## 📂 Cấu trúc dự án

```bash
CaroGame/
├── include/              # Header files (.h)
│   ├── Game.h
│   ├── Board.h
│   ├── Player.h
│   └── Utils.h
├── src/                  # Source files (.cpp)
│   ├── Game.cpp
│   ├── Board.cpp
│   ├── Player.cpp
│   └── Utils.cpp
├── main.cpp              # Entry point
├── CMakeLists.txt        # CMake build configuration
└── README.md             # Mô tả dự án
```

---

## ⚙️ Hướng dẫn Build & Chạy Dự Án

### ✅ Cách 1: Dùng CLion (Khuyến nghị)

1. Mở CLion → `File` → `Open Folder` → trỏ vào thư mục dự án
2. Nhấn **Build** hoặc **Run**
3. Chương trình sẽ khởi chạy và yêu cầu nhập tên, ký hiệu người chơi, v.v.

### ✅ Cách 2: Dùng dòng lệnh (Windows)

```bash
g++ main.cpp src/*.cpp -I include -o CaroGame.exe
.\CaroGame.exe
```

> 🔔 Lưu ý: chương trình chỉ chạy trên Windows vì sử dụng WinAPI.

---

## 🎮 Hướng dẫn chơi

1. Khi khởi động, nhập **kích thước bàn cờ** (ví dụ: 20 x 30)
2. Nhập **tên** và **ký hiệu** của 2 người chơi
3. Dùng các phím:
    - `W` / `↑` : đi lên
    - `S` / `↓` : đi xuống
    - `A` / `←` : sang trái
    - `D` / `→` : sang phải
4. Nhấn `ENTER` để đánh dấu
5. Ai có 5 ký hiệu liên tiếp là người chiến thắng
6. Nhấn `ESC` để thoát bất cứ lúc nào

---

## 📌 Ghi chú

- Dự án dành cho mục tiêu **học tập và rèn luyện lập trình C++**
- Có thể nâng cấp để:
    - Thêm AI (bot)
    - Lưu ván chơi (log file)
    - Hiển thị giao diện đồ hoạ bằng SDL hoặc Qt
- Mã nguồn viết rõ ràng, dễ hiểu, tách biệt theo hướng OOP

---

## 📫 Liên hệ

> Mọi thắc mắc, góp ý hoặc cải tiến, xin vui lòng liên hệ:  
> 📧 Email: xuansontrannguyen06@gmail.com  
> 💬 GitHub: https://github.com/lovell112/CaroGame
