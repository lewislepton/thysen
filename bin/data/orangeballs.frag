#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
uniform vec2 u_mouse;
uniform vec2 u_resolution;

uniform vec3 u_colors;
uniform vec3 u_play;
uniform vec2 u_warp;
uniform float u_zoom;
uniform float u_amount;

vec2 random2(vec2 p){
  return fract(sin(vec2(dot(p,vec2(127.1,311.7)),dot(p,vec2(269.5,183.3))))*43758.5453);
}

void main() {
  vec2 st = gl_FragCoord.xy / u_resolution.xy;
  st.x *= u_resolution.x / u_resolution.y;
  vec3 color = vec3(u_colors);
  st *= 10.0;
  vec2 i_st = floor(st / u_warp.x);
  vec2 f_st = fract(st / u_warp.y);
  float m_dist = u_zoom;
  for (int y = -8; y <= 1; y++) {
  for (int x = -1; x <= 1; x++) {
      vec2 neighbor = vec2(float(x),float(y));
      vec2 point = random2(i_st + neighbor);
      point = 0.3 + 0.5 * sin(u_time * 2.0 + 9.0 * point);
      vec2 diff = neighbor + point - f_st;
      float dist = length(diff);
      m_dist = min(m_dist, dist);
    }
  }
  color += m_dist;
  color += 1.0 - step(u_amount, m_dist);
  color -= mod(sin(9.0 * m_dist) * .8, 0.);
  gl_FragColor = vec4(color, 1.0);
}