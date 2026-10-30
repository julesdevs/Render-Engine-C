#include "image.h"
#include <stdlib.h>
#include <string.h>

Image* image_create(uint32_t width, uint32_t height, uint32_t channels) {
    Image* img = (Image*)calloc(1, sizeof(Image));
    if (!img) return NULL;

    img->width = width;
    img->height = height;
    img->channels = channels;
    
    // Alignement mémoire sur 32 octets pour la vectorisation (AVX/SSE)
    img->stride = (width * channels + 31) & ~31; 
    
    img->data = (uint8_t*)calloc(1, img->stride * height);
    if (!img->data) {
        free(img);
        return NULL;
    }

    return img;
}

void image_destroy(Image* img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

// Shader logiciel ultra-rapide utilisant l'arithmétique entière
void image_apply_grayscale_fast(Image* img) {
    if (!img || !img->data || img->channels < 3) return;

    for (uint32_t y = 0; y < img->height; ++y) {
        uint8_t* row = img->data + (y * img->stride);
        for (uint32_t x = 0; x < img->width; ++x) {
            uint32_t idx = x * img->channels;
            uint8_t r = row[idx];
            uint8_t g = row[idx + 1];
            uint8_t b = row[idx + 2];
            
            // Approximation de luminance par décalage binaire (évite les floats)
            // (R*77 + G*150 + B*29) / 256
            uint8_t gray = (uint8_t)(((uint16_t)r * 77 + (uint16_t)g * 150 + (uint16_t)b * 29) >> 8);
            
            row[idx] = gray;
            row[idx + 1] = gray;
            row[idx + 2] = gray;
        }
    }
}
