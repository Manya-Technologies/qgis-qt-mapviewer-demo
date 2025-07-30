# qgis-qt-mapviewer-demo

A minimal Qt C++ demo application showing how to embed a QGIS map canvas and display a shapefile using the QGIS C++ API.

---

## 🧰 Tech Stack

- Qt 5 / Qt 6 (Widgets)
- QGIS C++ API (`qgis_core`, `qgis_gui`)
- GDAL and PROJ dependencies
- Built using **qmake**

---

## 🚀 Features

- Loads and renders a shapefile layer on a `QgsMapCanvas`
- Supports EPSG:4326 coordinate reference system
- Demonstrates integration with:
  - `QgsVectorLayer`
  - `QgsProject`
  - Basic map interaction

---

## 📦 Prerequisites

- **Qt 6** (with `qmake` installed)
- **QGIS-DEV** libraries installed via:
  - OSGeo4W (Windows)
  - System packages (Linux)
- **C++17-compatible** compiler

> ✅ Ensure that the `OSGEO4W_ROOT` path is correctly set in your `.pro` file or your environment.

---

## 🛠️ Build Instructions

### **Step 1: Clone the repository**

```bash
git clone https://github.com/manya-technologies/qgis-qt-mapviewer-demo.git
cd qgis-qt-mapviewer-demo

---

### 🛠️ Step 2: Run `qmake` and build

#### 🔹 On Linux:

```bash
qmake
make
./qgis-qt-mapviewer-demo
```

#### 🔹 On Windows (via Qt command prompt):

```bat
qmake
nmake   (or mingw32-make)
qgis-qt-mapviewer-demo.exe
```

---

## 📂 Sample Shapefile

Place your sample shapefile (`Borders.shp`, `Borders.dbf`, `Borders.shx`) inside the `resources/` directory,  
or update the path in `main.cpp` to point to your custom shapefile.

---

## 🧾 License

This project is licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for more details.

---

## 💬 Contact

**Manya Technologies**  
🌐 [https://manyatechnologies.com](https://manyatechnologies.com)  
📧 business@manyatechnologies.com

