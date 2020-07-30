# TMI Web

>Brochureware Introductory Website


## Dependencies

* [git version control](https://git-scm.com/)
* [docker and docker-compose](https://www.docker.com/)


## Recommended

* [Ubuntu 18.04](http://releases.ubuntu.com/18.04/)


## Installation

Clone the TMI Web repository:

```
git clone https://github.com/AfrikaBurn/TMI-Web.git
```
Install CMS dependencies
```
cd TMI-Web/local
composer install
```

## Running

From within the cloned directory (TMI-Web):

```
docker-compose up -d
```


## Using

While running, visit the following address:
```
http://localhost:8080/
```
