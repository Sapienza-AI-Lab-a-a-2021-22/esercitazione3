# esercitazione3

## Italiano

## Utilizzo di diverse normalizzazioni per il filtro gaussiano

Normalizzazione L2
possiamo utilizzare diverse tecniche di normalizzazione per i filtri gaussiani. Ognuna di queste normalizzazioni varia nel modo in cui calcolano il gradiente.

La norma l^2 (scritta anche "l^2 norm") |x| è una norma vettoriale definita per un vettore complesso

x=[x_1; x_2; |; x_n]

di

|x|=sqrt(somma_(k=1)^n|x_k|^2)

La normalizzazione L2 può essere trovata in `filter_image.cpp` con la funzione `l2_normalize`

## Rilevamento di Canny Edge
Il rilevatore di bordi Canny è un operatore di rilevamento dei bordi che utilizza un algoritmo a più stadi per rilevare un'ampia gamma di bordi nelle immagini.
È stato sviluppato da John F. Canny nel 1986. Canny ha anche prodotto una teoria computazionale del rilevamento dei bordi che spiega perché la tecnica funziona.

Di seguito sono riportati i passaggi per implementare il rilevamento del bordo astuto su un'immagine

### 1. Filtra l'immagine con la derivata di gaussiana

Le funzioni di supporto per questa implementazione possono essere trovate in `edge_detection.cpp` sotto la funzione `gaussianKernal` e `gaussian_derivative`


### 2. Trova la grandezza e l'orientamento del gradiente
Le funzioni di aiuto sono implementate in `filter_image` per `make_gx_filter` e `make_gy_filter`. Queste funzioni possono essere utilizzate per trovare la magnitudine
e orientamento.


### 3. Soppressione non massima

Le funzioni di supporto per questa implementazione possono essere trovate in `edge_detection.cpp` sotto la funzione `nonMaxSuppression`

### 4. Collegamento e soglia (isteresi):
Definire due soglie: bassa e alta

Le funzioni di supporto per questa implementazione possono essere trovate in `edge_detection.cpp` sotto le funzioni `performThreshold` e `performDoubleThreshold`

Utilizzare la soglia alta per iniziare le curve di bordo e la soglia bassa per continuarle

## Inglese

## Using different Normalisations for Gaussian filter

L2 Normalization
we can use different normalization techniques for the gaussian filters. Each of these normalizations vary in how they compute the gradient.

The l^2-norm (also written "l^2-norm") |x| is a vector norm defined for a complex vector

x=[x_1; x_2; |; x_n]

by

|x|=sqrt(sum_(k=1)^n|x_k|^2)

The L2 Normalisation can be found in `filter_image.cpp` with the function `l2_normalize`

## Canny Edge detection
The Canny edge detector is an edge detection operator that uses a multi-stage algorithm to detect a wide range of edges in images. 
It was developed by John F. Canny in 1986. Canny also produced a computational theory of edge detection explaining why the technique works.

The following are the steps in implementing the canny edge detection on an image

### 1. Filter image with derivative of Gaussian

   The supporting functions for this implementation  can be found in `edge_detection.cpp` under the function `gaussianKernal` and `gaussian_derivative`


### 2. Find magnitude and orientation of gradient
   The helping functions are implemented in `filter_image` for `make_gx_filter` and `make_gy_filter`. These functions can be used for finding the magnitude
   and orientation.


### 3. Non-maximum suppression
   
   The supporting functions for this implementation  can be found in `edge_detection.cpp` under the function `nonMaxSuppression`

### 4. Linking and thresholding (hysteresis):
   Define two thresholds: low and high

   The supporting functions for this implementation  can be found in `edge_detection.cpp` under the functions `performThreshold` and `performDoubleThreshold`

   Use the high threshold to start edge curves and the low threshold to continue them
