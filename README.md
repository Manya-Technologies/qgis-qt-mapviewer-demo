# qgis-qt-mapviewer-demo

A minimal Qt C++ demo application showing how to embed a QGIS map canvas and display a shapefile using the QGIS C++ API.

---

## 🧰 Tech Stack

- Qt 5 / Qt 6 (Widgets)
- QGIS C++ API (qgis_core, qgis_gui)
- GDAL and PROJ dependencies
- Built using **qmake**

---

## 🚀 Features

- Loads and renders a shapefile layer on a `QgsMapCanvas`
- EPSG:4326 support for coordinate systems
- Demonstrates integration with `QgsVectorLayer`, `QgsProject`, and basic map interaction

---

## 📦 Prerequisites

- Qt6 (with qmake installed)
- QGIS-DEV libraries installed via OSGeo4W (Windows) or system packages (Linux)
- C++17-compatible compiler

Make sure `OSGEO4W_ROOT` is set correctly in your `.pro` file or environment.

---

## 🛠️ Build Instructions

### Step 1: Clone the repository

```bash
git clone https://github.com/manya-technologies/qgis-qt-mapviewer-demo.git
cd qgis-qt-mapviewer-demo

### Step 2: Run qmake and build

On Linux
bash
Copy
Edit
qmake
make
./qgis-qt-mapviewer-demo

On Windows (via Qt command prompt)
bat
Copy
Edit
qmake
nmake   (or mingw32-make)
qgis-qt-mapviewer-demo.exe

📂 Sample Shapefile
Place your sample shapefile (e.g., Borders.shp, .dbf, .shx) inside the resources/ directory or adjust the layer path in main.cpp.

🧾 License
This project is licensed under the MIT License. See the LICENSE file for more info.

💬 Contact
Manya Technologies
🌐 https://manyatechnologies.com
📧 business@manyatechnologies.com

