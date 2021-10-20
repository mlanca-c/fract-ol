# fract-ol

 <small description of project>

[![Intro](https://img.shields.io/badge/Cursus-fract'ol-success?style=for-the-badge&logo=42)](https://github.com/mlanca-c/fract-ol)
 
 [![Stars](https://img.shields.io/github/stars/mlanca-c/fract-ol?color=ffff00&label=Stars&logo=Stars&style=?style=flat)](https://github.com/mlanca-c/fract-ol)
 [![Size](https://img.shields.io/github/repo-size/mlanca-c/fract-ol?color=blue&label=Size&logo=Size&style=?style=flat)](https://github.com/mlanca-c/fract-ol)
 [![Activity](https://img.shields.io/github/last-commit/mlanca-c/fract-ol?color=red&label=Last%20Commit&style=flat)](https://github.com/mlanca-c/fract-ol)
 
# Cloning

 ```
 git clone --recursive git@github.com:mlanca-c/fract-ol.git
 cd fract-ol
 make all
 ```
 
# Compiling
 
 ```./fractol <fractal> [x] [y] [-p <precision>] [-c <color>] ```
  
  The ```<>``` are mandatory and the ```[]``` are optional
 
 **example:**
 ```Shell
 ./fractol Mandelbrot -p 255 -c 2
 ./fractol Julia 1 0 -c 5
 ```
```
COLOR OPTIONS:
	1: black and white
	2: red
	3: green
	4: blue
	5: mix
	other No: trippy
 (If not given any color, default is trippy)

PRECISION OPTIONS:
 (If not given any precision, default is at 85)
```
 
# Intro

 > [subject](subject.pdf)

# Useful Links

 * [ pbielinux/Fract-ol](https://github.com/pbielinux/Fract-ol)
 * [Wiki](https://github.com/mlanca-c/fract-ol/wiki)

