#version 330 core
out vec4 fragColor;
uniform vec4 point_color;
void main() {
    fragColor = point_color; // Red point
}