<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="https://github.com/iel-amra/So_long/blob/main/img/So_long.png?raw=true" alt="Logo" width="400" height="400">
  </a>

  <h3 align="center">So Long - The game</h3>

  <p align="center">
    A hard, fun and somewhat frustrating plateformer !
  </p>
</div>



<!-- ABOUT THE PROJECT -->
## About The Project

So long is a 2D platformer developed for linux with a library called Minilibx.

The goal of the game is to pick up all the potions before exiting through the plant.

![Product Name Screen Shot][product-screenshot]

The game is purposely designed to be hard and frustrating.

It's possible to create custom maps by creating a file with a .ber extension (see below)

Since the subject only allowed Minilibx, all the physices and frame management is manually implemented. The collisions, animations and map building are manually implemented.The physics and display aer optimized so the game can be rendered using the processor only, on one core (Imposed by the subject).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

So_long was developed and tested only on ubuntu, but should work well on other debian based distribution

### Prerequisites

<p>MiniLibX for Linux requires <code class="language-plaintext highlighter-rouge">xorg</code>, <code class="language-plaintext highlighter-rouge">x11</code> and <code class="language-plaintext highlighter-rouge">zlib</code>, therefore you will need to install the following dependencies: <code class="language-plaintext highlighter-rouge">xorg</code>, <code class="language-plaintext highlighter-rouge">libxext-dev</code> and <code class="language-plaintext highlighter-rouge">zlib1g-dev</code>. Installing these dependencies on Ubuntu can be done as follows:</p>

```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Installation

1. Clone the repo
   ```sh
   git clone git@github.com:iel-amra/So_long.git
   ```
2. Enter the So_long folder and compile
   ```
   cd So_long && make
   ```

That's it ! So_long is now installed on your machine.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

To start the first map of the game, enter the following command in your terminal :
```
./so_long map/map1.ber
```

You can launch any map you want with the following syntax :
```
./so_long [map_name].ber
```

For example to 

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Ihab El amrani - [Linkedin](www.linkedin.com/in/ihab-el-amrani) - iel-amra@student.42lyon.fr

Project Link: [https://github.com/iel-amra/So_long](https://github.com/iel-amra/So_long)

My github : [https://github.com/iel-amra](https://github.com/iel-amra)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: www.linkedin.com/in/ihab-el-amrani
[product-screenshot]: https://github.com/iel-amra/So_long/blob/main/img/screenshot.png?raw=true
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 