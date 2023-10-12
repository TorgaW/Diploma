#version 330 core
out vec4 fragColor;
uniform vec4 line_color;
void main() {
    fragColor = line_color; // Red point
}