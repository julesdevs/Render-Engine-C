#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include <stddef.h>

// Structure d'image optimisée pour le traitement en rafale (SIMD)
typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t channels;
    size_t stride; // Padding pour alignement mémoire
    uint8_t* data;
} Image;

Image* image_create(uint32_t width, uint32_t height, uint32_t channels);
void image_destroy(Image* img);
void image_apply_grayscale_fast(Image* img);

#endif // IMAGE_H
