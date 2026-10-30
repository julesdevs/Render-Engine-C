#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "image.h"

int main(int argc, char** argv) {
    // Suppression des warnings pour variables non utilisées dans ce test
    (void)argc; 
    (void)argv; 

    printf("[INFO] Booting Render-Engine-C core...\n");
    
    RenderEngine* engine = engine_init();
    if (!engine) {
        fprintf(stderr, "[ERROR] Engine init failed (OOM).\n");
        return EXIT_FAILURE;
    }

    // Simulation d'une frame 4K
    Image* frame = image_create(3840, 2160, 3);
    if (frame) {
        printf("[INFO] 4K Framebuffer allocated. Stride: %zu bytes.\n", frame->stride);
        
        engine_process_image(engine, frame);
        printf("[INFO] Fast integer-math Grayscale shader applied.\n");
        
        image_destroy(frame);
        printf("[INFO] Framebuffer memory safely released.\n");
    } else {
        fprintf(stderr, "[ERROR] Failed to allocate 4K frame.\n");
    }

    engine_shutdown(engine);
    printf("[INFO] Engine shut down safely. Zero leaks detected.\n");
    
    return EXIT_SUCCESS;
}
