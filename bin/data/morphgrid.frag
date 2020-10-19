#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

uniform vec3 u_colors;
uniform vec2 u_warp;
uniform float u_zoom;
uniform float u_amount;
uniform vec3 u_play;

void main(){
	vec2 coord = 4.0 * (gl_FragCoord.xy - u_resolution / u_zoom) / min(u_resolution.y, u_resolution.x) / u_play.z;

	float len;

	for (int i = 0; i < u_amount; i++){
		len = length(vec2(coord.x / u_warp.x, coord.y / u_warp.y));

		coord.x = coord.x - cos(coord.y + sin(len / u_play.x)) + cos(u_time / u_warp.x / 60.0);
		coord.y = coord.y + sin(coord.x + cos(len / u_play.y)) + sin(u_time / u_warp.y / 60.0);
	}

	vec3 color = vec3(cos(len * u_colors.x), cos(len * u_colors.y), cos(len * u_colors.z));
	gl_FragColor = vec4(color, 1.0);
}