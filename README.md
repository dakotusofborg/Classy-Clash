# Top-Down 2D Fighter (C++ / raylib)

A fast-paced **top-down 2D fighting game** built in C++ with the [raylib](https://www.raylib.com/) game development library.  
This project is both a **game prototype** and a **technical showcase** of modern C++ practices applied to real-time game development.

> ⚡ This game is built as part of a **tutorial lesson from [GameDev.tv](https://www.gamedev.tv/)**.  
> The project has been expanded and documented to highlight programming concepts and good development practices.

---

## 🎮 Features
- **Top-down combat system** with responsive player movement and attack mechanics  
- **Character system** with health management (displayed dynamically on screen)  
- **Simple game loop** demonstrating collision, rendering, and state management  
- **Object-Oriented design** separating player, enemy, and world logic  
- Built entirely with **raylib** for cross-platform rendering and input  

---

## 🚀 Getting Started

### Prerequisites
- C++17 or later  
- [raylib](https://www.raylib.com/) installed on your system  
- CMake (recommended) or a C++ compiler with raylib linked  

### Build & Run
```bash
# Clone the repository
git clone https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git
cd YOUR_REPO_NAME

# If using CMake
mkdir build && cd build
cmake ..
make

# Run the game
./TopDownFighter
```

### Windows (MinGW / MSVC)
1. Install raylib (via [vcpkg](https://github.com/microsoft/vcpkg) or prebuilt binaries)  
2. Open the project in Visual Studio / VSCode  
3. Build and run  

---

## 🛠️ Controls
- **WASD / Arrow keys** → Move character  
- **Space / Enter** → Attack  
- **Esc** → Quit game  

---

## 📚 Learning & Technical Showcase

### 🎮 Game Loop Architecture
- Clear separation between `Update()` and `Draw()` phases  
- Demonstrates fixed vs. variable timestep considerations  

### 🧑‍🤝‍🧑 Entity Management with OOP
- Characters encapsulate their own state (health, position, alive/dead)  
- Extendable base class design for easily adding new fighters or enemies  

### ✍️ Text Rendering & Formatting
- Health values converted to 2-decimal precision using `std::to_string` and appended to UI strings  
- Drawn on screen with `DrawText()` at fixed positions  

### 🛡️ Memory & Resource Safety
- Uses RAII principles for resource handling where applicable  
- Smart pointers and scoped objects to avoid leaks  

### 🌍 Cross-Platform Development with raylib
- Showcases raylib’s simplicity for handling graphics, input, and text in C++  
- Demonstrates how to integrate external C library (`raylib`) with modern C++ design  

### 🧹 Clean Code Practices
- Readable, modular design with clear function responsibilities  
- Demonstrates maintainable structure for expanding gameplay features  

---

## 📸 Screenshots / Demo
*(Insert screenshots or a GIF here if available)*

---

## 🤝 Contributing
Pull requests and suggestions are welcome!  

---

## 📜 License
This project is open-source under the MIT License.  
