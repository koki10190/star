#include "star_texture.hpp"
#include <stb_image/stb_image.h>
#include <glad/include/glad/glad.h>
#include <GLFW/glfw3.h>

star_texture::star_texture(const char *img_path, bool nearest) : path(img_path) {
    // This loads the texture upside down, it's necessary so that the texture won't be displayed upside down
    stbi_set_flip_vertically_on_load(true);
    // Load the pixels
    unsigned char *data = stbi_load(img_path, &this->width, &this->height, &this->nr_channels, 0);

    // Generate texture
    glGenTextures(1, &this->m_id);
    glBindTexture(GL_TEXTURE_2D, this->m_id);

    // Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, nearest ? GL_NEAREST_MIPMAP_NEAREST : GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, nearest ? GL_NEAREST : GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Check the color channels and accordingly to that make the images
    if (this->nr_channels >= 4)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    else if (this->nr_channels == 3)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    else if (this->nr_channels == 1)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
    else
        return;

    // Generate a mipmap of the texture
    glGenerateMipmap(GL_TEXTURE_2D);

    // We do not need the pixels anymore so we delete it
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void star_texture::bind(uint32_t slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void star_texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}