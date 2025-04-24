# Hybrid Sorting Algorithm on 3D Arrays

A performance analysis project.  
Implements a custom hybrid sorting algorithm called **"Select 4 – Exchange"** on multidimensional arrays using C.

## 🚀 Objective

Investigate the efficiency of a selection-based hybrid sorting algorithm under different traversal strategies and multidimensional array configurations.

## 📌 Features

- Custom hybrid sort algorithm (`Select 4 – Exchange`)
- Three traversal strategies:
  1. Flattening to 1D array
  2. Index math (`i = k % M; j = k / M`)
  3. Direct 3D iteration
- Works with 3D arrays and vectors
- Performance measurement using `clock()`
- Handles:
  - Ordered arrays
  - Random arrays
  - Reverse-ordered arrays

## 📊 Results

- Time measurements for each sorting method and data type
- Output tables & performance comparison
- Diagrams and conclusions included in report

## 💡 Key Insight

Flattening the 3D slice into a 1D array for sorting yields the best performance across all array sizes and content types.
