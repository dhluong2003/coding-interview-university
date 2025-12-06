# Arrays

## definition
- contiguous area of memory consisting of equal-size elements (the elements are next to one another); each element indexed by contiguous ints
- constant-time accessing of element(s) ($O(1)$)

> how? simple arithmetic to compute address of any element in array

$$\text{array\_addr} + \text{elem\_size} \times (i - \text{first\_index})$$

where i is the index of interest

## multidimensional arrays
- some languages support 2d and 3d arrays; how the mem addr. for a single element in said arrays is computed is very similar for 1d arrays
- certain languages/compilers have *row-major* indexing where all elements in a row are successively listed; others have *column-major* indexing where successive column elements are listed

## times for common operations
- add
    - at end: $O(1)$
    - at start: $O(n)$ where n is the num. of elements in the array
    - in the middle: $O(n)$
- remove
    - at end: $O(1)$
    - at start: $O(n)$
    - in the middle: $O(n)$