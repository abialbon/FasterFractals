# FasterFractals

## Aim of this project
This project aims to explore ways of generating fractal images in possibly three different languages. (C++, Java and Go)

## Process
Initially the mandlebrot set will be created and saved to disk. This will be done
- Sequentially with one process thread
- Multithreading
- Using SIMD operations
- Using SIMD operations and multithreading

This will be attempted with three different languages (C++, Java and go)
Next, many different fractals will be generated using a command line interface with the ability to select regions and image sizes
Finally, an attempt will be made to render the generated fractal on a GUI and use keyboard events to control pan, zoom etc.