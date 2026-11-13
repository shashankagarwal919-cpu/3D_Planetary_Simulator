🌌 3D Planetary Simulator

A real-time 3D planetary orbit simulator built using C and Raylib, featuring eight planets revolving around the Sun, circular orbital paths, and a procedurally generated starfield.

The project explores the fundamentals of 3D graphics programming, mathematical modelling, and real-time animation using the C programming language.

🚀 Features

* 3D Solar System: Visual representation of the Sun and eight planets.
* Planetary Revolution: Each planet revolves around the Sun at its own orbital speed.
* Orbital Paths: Circular orbital paths visualised around the Sun.
* Dynamic Starfield: 400 procedurally generated stars scattered throughout 3D space.
* Interactive Camera: Explore the simulation using Raylib’s orbital camera controls.
* Real-Time Animation: Smooth planetary movement using frame-independent time updates.

🛠️ Technologies Used

* C - Core programming language.
* Raylib - 3D graphics, rendering, and camera controls.
* Math Library (math.h) - Trigonometric calculations for planetary positioning.

🪐 How It Works

The simulation uses mathematical calculations to determine the position of each planet at any given time.

The position of a planet is calculated using:

x = orbitRadius * cos(angle);
z = orbitRadius * sin(angle);

The orbital angle is continuously updated using the planet's angular speed and the time elapsed between frames:

angle += speed * deltaTime;

This ensures smooth and frame-independent planetary motion.

The starfield is generated using random 3D coordinates, which are normalised and distributed across a spherical region surrounding the solar system.

⚙️ Installation & Setup

Prerequisites

* GCC compiler
* Raylib library
* Git

Clone the Repository

git clone https://github.com/shashankagarwal919-cpu/3D_Planetary_Simulator.git
cd 3D_Planetary_Simulator

Compile and Run

On macOS with Raylib installed:

gcc main.c -o simulator -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -lm

Run the executable:

./simulator

🎮 Controls

* Mouse: Orbit around the solar system using the orbital camera controls.
* Mouse Wheel: Zoom in and out.

📌 Future Improvements

* Planetary textures and surface details.
* Saturn's rings.
* Moons and their orbital movements.
* Planet labels and additional information.
* Improved lighting and visual effects.
* More realistic planetary proportions and orbital mechanics.

👨‍💻 Author

SHASHANK AGARWAL

Developed as a personal project to explore C programming, 3D graphics, mathematical modelling, and real-time simulation.

⸻

⭐ If you find this project interesting, consider giving the repository a star!
