#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_resolution;

uniform vec3 u_colors;

uniform vec2 u_warp;
uniform vec3 u_play;
uniform float u_zoom;
uniform float u_amount;

void main(){
  vec2 coord = gl_FragCoord.xy * u_zoom - u_resolution;
  vec3 color = vec3(u_colors);

  color += abs(cos(coord.x / u_warp.x * u_play.x) + sin(coord.y / u_warp.y * u_play.y) - cos(u_time) / u_play.z);

  gl_FragColor = vec4(color, 1.0);
}