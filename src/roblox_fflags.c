#include <dlfcn.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

static void* start_routine(void*) {
    void* handle = nullptr;
    while ((handle = dlopen("libroblox.so", RTLD_NOLOAD)) == nullptr) {
        usleep(1000);
    }

    void** start = dlsym(handle, "__start_ls_rbx_fflags");
    void** stop = dlsym(handle, "__stop_ls_rbx_fflags");

    for (void** item = start; item < stop; ++item) {
        void* fflag = *item;
        if (fflag == nullptr) continue;

        const char* name = *(const char**)((unsigned char*) fflag);
        if (name == nullptr) continue;

        void* value = *(void**)((unsigned char*) fflag + 0x10);
        if (value == nullptr) continue;

        if (strcmp(name, "DebugForceAnisoOff") == 0 || strcmp(name, "RenderParticlesOptimizeVisibleSimLocality") == 0) {
            *(bool*) value = true;
        } else if (strcmp(name, "FRMMinGrassDistance") == 0 || strcmp(name, "FRMMaxGrassDistance") == 0) {
            *(int*) value = 0;
        } else if (strcmp(name, "DebugFRMQualityLevelOverride") == 0 || strcmp(name, "DebugForceMSAASamples") == 0 || strcmp(name, "RenderLocalLightUpdatesMin") == 0 || strcmp(name, "RenderLocalLightUpdatesMax") == 0 || strcmp(name, "RenderTextureProcessingBudgetMilliseconds") == 0 || strcmp(name, "RenderMeshBulkUploadMaxTimeMs") == 0) {
            *(int*) value = 1;
        } else if (strcmp(name, "DebugTextureManagerSkipMips") == 0 || strcmp(name, "DebugAdditionalNumberOfMipsToSkipForNonAlbedoTextures") == 0) {
            *(int*) value = 2;
        } else if (strcmp(name, "UITextureMaxRenderTextureSize") == 0 || strcmp(name, "UITextureLowMaxRenderTextureSize") == 0 || strcmp(name, "UITextureMediumMaxRenderTextureSize") == 0 || strcmp(name, "UITextureHighMaxRenderTextureSize") == 0) {
            *(int*) value = 512;
        } else if (strcmp(name, "DebugDynamicRenderKiloPixels") == 0) {
            *(int*) value = 1152; // 720 x 1600
        }
    }

    return nullptr;
}

[[gnu::constructor]]
static void start() {
    pthread_t id;
    if (pthread_create(&id, nullptr, start_routine, nullptr) == 0) {
        pthread_detach(id);
    }
}
