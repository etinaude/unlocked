# 🔑 Unlocked 🔑 Mechanical

## Files

Everything was designed in Fusion 360

All the files needed are here. The STEP was too big to upload to Git Hub without being zipped and the f3z is massive so if you use Fusion360 and want that DM me. Otherwise, you can use the STEP, 3MF or STLs

### Print Settings

FDM - Doesn't matter too much, these parts have loose tolerances, 0.12mm layer height is recommended \
DLP - As small a layer height as possible, as little support as possible, it should be designed to not need much support \
DMLS - Either printed vertically or horizontally, as fine detail as possible. 

## BOM

All costs in GBP as of Sept 2024 \
The total cost is about £200


### Electronics

| Part             | Model            | Count | Cost per unit | Total Cost | URL                                                              |
| ---------------- | ---------------- | ----- | ------------- | ---------- | ---------------------------------------------------------------- |
| Servo Motor      | xl330-m288       | 5     | 26.30         | 131.5      | https://emanual.robotis.com/docs/en/dxl/x/xl330-m288/            |
| Motor controller | openrb-150       | 1     | 28.30         | 28.30      | https://emanual.robotis.com/docs/en/parts/controller/openrb-150/ |
| USB cable        | USB C data cable | 1     | 2             | 2          | NA                                                               |

### Mechanical

Always have lots of spare wire and screws

| Part                    | Notes              | Count |
| ----------------------- | ------------------ | ----- |
| Wire                    | 0.4 mm copper wire | 100   |
| Aluminium extrusion     | 2020 profile       | 1     |
| m3x8 countersunk screw  |                    | 29    |
| m2x10 countersunk screw |                    | 65    |
| m3x60 screw             |                    | 1     |

### 3D Printed Parts

FDM for bigger parts
DLP (resin) parts are used for low-friction and high-precision
DMLS (Metal powder bed) for strong parts (JLCPCB can print this for you)

| Part              | Material | Count | Notes                      |
| ----------------- | -------- | ----- | -------------------------- |
| hub               | DLP      | 1     |                            |
| internal gear     | FDM      | 1     |                            |
| key               | DMLS     | 1     | Make spare if using DLP    |
|                   |          |       |                            |
| **Motor modules** |          | 5     | Parts below are per module |
| rail              | DLP      | 1     |                            |
| carriage          | DLP      | 1     |                            |
| motor mount       | FDM      | 1     |                            |
| linkage           | FDM      | 1     |                            |
| circle            | FDM      | 1     |                            |
|                   |          |       |                            |
| **lock Holder**   | FDM      | 1     | Parts below are per module |
| lock holder       | FDM      | 1     |                            |
| end cap           | FDM      | 1     |                            |
|                   |          |       |                            |
| **Mech Holder**   | FDM      | 1     | Parts below are per module |
| base              | FDM      | 1     |                            |
| end cap           | FDM      | 1     |                            |
| top               | FDM      | 1     |                            |
|                   |          |       |                            |
