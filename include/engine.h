// Structures du moteur.
#ifndef ENGINE_H
#define ENGINE_H

#include "image.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    uint32_t version;
    bool is_initialized;
} RenderEngine;

static inline RenderEngine* engine_init(void) {
    RenderEngine* engine = (RenderEngine*)calloc(1, sizeof(RenderEngine));
    if (engine) {
        engine->version = 100; // v1.0.0
        engine->is_initialized = true;
    }
    return engine;
}

static inline void engine_shutdown(RenderEngine* engine) {
    if (engine) free(engine);
}

static inline bool engine_process_image(RenderEngine* engine, Image* img) {
    if (!engine || !engine->is_initialized || !img) return false;
    image_apply_grayscale_fast(img);
    return true;
}

#endif // ENGINE_H
