# miniRT - Ray Tracing Engine with Advanced Features

## About

**miniRT** is an advanced computer graphics project at École 42 that involves implementing a ray tracing engine capable of rendering photorealistic 3D scenes. The project explores advanced rendering techniques, mathematical modeling of light behavior, and optimization strategies for computationally intensive graphics algorithms.

This project demonstrates mastery of 3D graphics programming, vector mathematics, and advanced rendering techniques while creating a functional ray tracer that produces high-quality, realistic images with complex lighting, shadows, reflections, and material properties.

![miniRT_bonus_scene0](https://github.com/user-attachments/assets/c002dbc8-4116-44e9-a531-fe5889b30fc9)
![miniRT_bonus_scene1](https://github.com/user-attachments/assets/8303fd79-a97f-48c6-8e0e-d7c396d41979)

## Learning Objectives

- **Ray Tracing Fundamentals**: Understanding the ray tracing algorithm and light simulation
- **Vector Mathematics**: Advanced 3D vector operations and geometric calculations
- **Light Physics**: Simulating realistic light behavior and material interactions
- **Intersection Algorithms**: Computing ray-object intersection points
- **Scene Management**: Parsing and organizing complex 3D scene descriptions
- **Color Theory**: Implementing realistic color mixing and lighting models
- **Performance Optimization**: Accelerating computationally expensive rendering operations
- **Advanced Rendering**: Implementing sophisticated visual effects and material properties

## Core Features (Mandatory)

### Geometric Primitives
- **Spheres**: Perfect spheres with center point and radius
- **Planes**: Infinite planes defined by point and normal vector
- **Cylinders**: Finite cylinders with position, orientation, diameter, and height
- **Cones**: Conical shapes with apex, axis, and angle

### Light Sources
- **Ambient Light**: Global illumination with adjustable intensity
- **Point Lights**: Omnidirectional light sources with position and intensity

### Camera System
- **Configurable Position**: Camera location in 3D space
- **Orientation**: View direction using normal vector
- **Field of View**: Adjustable viewing angle

### Material Properties
- **Diffuse Color**: Base color of objects
- **Ambient Reflection**: Object visibility in ambient light
- **Specular Highlights**: Shiny surface reflections
- **Texture**: Set object texture with xmp image

## Advanced Features

### Enhanced Lighting Models

#### Phong Reflection Model
Complete implementation of the Phong lighting equation:
- **Ambient Component**: Constant base illumination
- **Specular Component**: Shininess and specular highlights
- **Combined Model**: Realistic material appearance

#### Advanced Shadows
- **Hard Shadows**: Sharp shadow boundaries from point lights
- **Shadow Rays**: Accurate occlusion testing for realistic shadows
- **Multiple Light Sources**: Combined shadow effects from multiple lights

### Reflection and Refraction

#### Mirror Reflections
- **Recursive Ray Tracing**: Simulating perfect mirror surfaces
- **Reflection Depth Control**: Limiting recursion for performance

### Texture Mapping

#### 2D Textures
- **Image Mapping**: Applying bitmap images to surfaces
- **UV Coordinates**: Proper texture coordinate calculation

#### Procedural Textures
- **Checkerboard Pattern**: Algorithmic pattern generation
- **Bump Mapping**: Normal perturbation for surface detail

### Anti-Aliasing Techniques
- **Supersampling**: Multiple rays per pixel for smooth edges
- **Jittered Sampling**: Reducing aliasing artifacts

## Usage Examples

### Basic Scene Rendering
```bash
# Render simple scene
./miniRT scene/scene.rt

# Enable all bonus features
./miniRT_bonus scene/advanced_scene.rt
```

## Performance Optimizations

### Multi-threading
- **Parallel Rendering**: Multiple threads rendering image tiles
- **Lock-free Operations**: Minimizing synchronization overhead

## Key Challenges & Solutions

### Mathematical Precision
- **Challenge**: Accurate vector mathematics and floating-point calculations
- **Solution**: Robust numerical methods

### Performance Optimization
- **Challenge**: Optimize rendering of complex scenes
- **Solution**: Multi-threaded rendering

### Realistic Materials
- **Challenge**: Implementing physically accurate light-material interactions
- **Solution**: Phong model with recursive reflection and refraction

### Complex Scene Management
- **Challenge**: Parsing and organizing scenes with many objects and lights
- **Solution**: Efficient data structures and scene graph implementation

## Skills Demonstrated

- **Advanced Graphics Programming**: Ray tracing algorithm implementation and optimization
- **3D Mathematics**: Vector operations, matrix transformations, geometric calculations
- **Physics Simulation**: Realistic light behavior and material properties
- **Algorithm Optimization**: Acceleration structures and performance tuning
- **Parallel Programming**: Multi-threaded rendering implementation
- **File Parsing**: Complex scene description parsing and validation
- **Software Architecture**: Clean, modular code for complex rendering pipeline
- **Visual Computing**: Understanding of color theory and image generation

## Real-World Applications

Ray tracing concepts are fundamental to numerous professional fields:
- **Game Development**: Real-time ray tracing in modern games (RTX)
- **Computer Vision**: Understanding 3D scene reconstruction

## Related Technologies

The miniRT project provides foundation knowledge for:
- **OpenGL/Vulkan**: Modern graphics APIs and GPU programming
- **Path Tracing**: Advanced Monte Carlo light transport simulation
- **GPU Ray Tracing**: Hardware-accelerated ray tracing (NVIDIA RTX, AMD RDNA)
- **Game Engines**: Unity, Unreal Engine rendering systems

## Notes

The miniRT project represents a significant achievement in computer graphics programming, demonstrating the ability to implement complex rendering algorithms that produce photorealistic images. The bonus features showcase advanced understanding of light physics, material properties, and optimization techniques.

The recursive nature of ray tracing with reflections and refractions demonstrates sophisticated algorithm design, while the performance optimizations show practical software engineering skills essential for graphics programming.

---

*Developed as part of the École 42 curriculum - mastering advanced computer graphics through physically-based ray tracing implementation.*
