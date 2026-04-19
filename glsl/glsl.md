## frag中
变量
* u_resolution  
    屏幕坐标？

* u_position  
    原点在中心？

* uv = gl_FragCoord.xy / u_resolution.xy  
    原点在左下角


`clamp`函数
```glsl
clamp(n, min, max);

min(max(x, minVal), maxVal)?
```

`step`函数
```glsl
step(edge, n);

if(n < edge) return 0
if(n >= edge) return 1
```

`smoothstep`函数
```glsl
smoothstep(edge0, edge1, n);

if n > edge0 and n < edge1 then
float smoothstep(edge0, edge1, n){
    float t = clamp((n - edge0) / (edge1 - edge0), 0.0, 1.0);
    return t * t * (3.0 - 2.0 * t);
}
```

circle 抗锯齿圆形
```glsl
//抗锯齿圆形
float inCircle = 1.0 - smoothstep(0.5, 0.51, length(v_position.xy));
vec3 color = vec3(1.0, 1.0, 0.0) * inCircle;
```

square 方形
```glsl
float rect(vec2 pt, vec2 center, vec2 size) {
    vec2 p = pt - center;
    vec2 halfSize = size * 0.5;

    float horz = step(-halfSize.x, p.x) - step(halfSize.x, p.x);
    float vert = step(-halfSize.y, p.y) - step(halfSize.y, p.y);
    return horz * vert;
}

float inRect = rect(v_position.xy, vec2(0.0), vec2(0.5));
vec3 color = vec3(1.0, 1.0, 0.0) * inRect;
```

rotation 旋转
```glsl
mat2 rotate2d(float angle) {
    return mat2(cos(angle), -sin(angle),
                sin(angle), cos(angle));
}

float inRect = rect(v_position.xy * rotate2d(u_time), vec2(0.0), vec2(0.5));
```

tile 平铺？
```glsl
float tilecount = 16.0;
vec2 center = vec2(0.5, 0.5);
vec2 p = fract(v_uv * tilecount);
float inTileRect = rect((p-center) * rotate2d(u_time) + center, vec2(1.0, 1.), vec2(0.4, 0.4), vec2(0.5,0.5));
color += vec3(p.x, p.y, 1.0) * inTileRect;
```