ofxHomography
=============

![ofxHomography](https://github.com/paulobarcelos/ofxHomography/raw/master/screenshots/example.png)

`ofxHomography` is a small openFrameworks addon for finding the homography matrix between two sets of four points. It is useful for perspective warps, projection mapping helpers, screen-to-surface coordinate transforms, and other quad-to-quad mapping tasks.

The addon is header-only and has no external dependencies beyond openFrameworks' bundled math/GLM support.

Installation
------------

Clone or copy this repository into your openFrameworks `addons/` folder:

```sh
cd /path/to/openFrameworks/addons
git clone https://github.com/paulobarcelos/ofxHomography.git
```

Add `ofxHomography` to your project's `addons.make`, or include it through the openFrameworks Project Generator.

The example also includes an `of.yml` recipe for ofWorks/ofGen users.

Quick Start
-----------

```cpp
#include "ofxHomography.h"

std::array<glm::vec2, 4> source = {{
	{ 0.0f, 0.0f },
	{ 100.0f, 0.0f },
	{ 100.0f, 100.0f },
	{ 0.0f, 100.0f }
}};

std::array<glm::vec2, 4> destination = {{
	{ 20.0f, 30.0f },
	{ 420.0f, 10.0f },
	{ 390.0f, 360.0f },
	{ 30.0f, 410.0f }
}};

glm::mat4 homography = ofxHomography::findHomography(source, destination);

ofPushMatrix();
ofMultMatrix(homography);
ofDrawRectangle(0, 0, 100, 100);
ofPopMatrix();

glm::vec2 localPoint(80, 80);
glm::vec2 screenPoint = ofxHomography::toScreenCoordinates(localPoint, homography);
```

API
---

- `ofxHomography::findHomography(src, dst, float homography[16])` fills an OpenGL-style 4x4 float matrix.
- `ofxHomography::findHomography(src, dst)` returns a `glm::mat4`.
- `ofxHomography::toScreenCoordinates(point, homography)` transforms a `glm::vec2` or `glm::vec3` through a homography.

For official openFrameworks builds that still expose the legacy math classes, `toScreenCoordinates(const ofPoint&, const ofMatrix4x4&)` is also available for compatibility.

Compatibility
-------------

Current `master` is tested with:

- openFrameworks 0.12.1 on macOS using the official addon Makefile workflow.
- ofWorks/ofGen 1.0.8 on macOS using the included `of.yml` and Chalet template.

Version `1.1.0` remains the last tagged release documented as tested with openFrameworks 0.11.2.

Development
-----------

Official openFrameworks:

```sh
cd /path/to/openFrameworks/addons/ofxHomography/example
make Debug -j8
make RunDebug
```

ofWorks/ofGen:

```sh
cd /path/to/ofworks/addons/ofxHomography/example
/path/to/ofworks/ofGen/dist/ofgen build
```

License
-------

MIT

Version History
---------------

### Version 2.0.0

- Modernized the example from `testApp` to `ofApp`.
- Moved the primary matrix/point API to `glm`.
- Added an ofWorks/ofGen `of.yml` recipe.
- Kept the official openFrameworks Makefile project files for the example.
- Verified builds with openFrameworks 0.12.1 and ofWorks/ofGen 1.0.8 on macOS.

### Version 1.1.0 (2021.03.31)

- Adapted to the official addon template.
- Cleanup.
