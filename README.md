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
