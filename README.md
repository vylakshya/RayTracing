🌌 Physically-Based Ray Tracing & Celestial Mechanics
A C++ simulation engine that combines Whitted-style ray tracing with Newtonian gravitational dynamics.

Core Features :
Dynamic Light Transport: Real-time calculation of light attenuation from a moving stellar source.

Mathematical Precision: Solves ray-geometry intersections using algebraic methods (quadratic solvers) rather than mesh heuristics.

N-Body Dynamics: Real-time gravitational interaction between multiple celestial bodies using integration.

Development Roadmap
-> CPU-based intersection logic (SDL2).

 -> Dynamic source-to-surface intensity calculation.

In Progress :
-> CUDA Kernel Migration: Offloading pixel-shading to GPU.

-> Implementing BVH (Bounding Volume Hierarchy) for spatial optimization.

Update : Shifting the progress completely to new repo : https://github.com/vylakshya/RayTracing2.0
