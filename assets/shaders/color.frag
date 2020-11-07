#version 330 core
// Here we will define Uniform Variable
// they are called uniform because every run of the shader (under the same draw call) will see the same value
// so it is uniform across all executions of the shader
uniform vec3 color;
uniform float time;
uniform bool flicker;
uniform vec2 mouse;
uniform vec2 iResolution;
uniform int shape;
// The output that goes to the frame buffer
out vec4 frag_color;

float Circle (vec2 uv, vec2 p, float r, float blur) {
    float c = smoothstep(r, r-blur , length(uv-p));
    return c;
}

float Smiley(vec2 uv, vec2 p, float size) {

    uv -= p;

    float mask = Circle(uv, vec2(0.), .4, .01);

    mask -= Circle(uv, vec2(-.13, .2), .06, .01);
    mask -= Circle(uv, vec2(.13, .2), .06, .01);

    float mouth = Circle(uv, vec2(0., 0.), .3, .01);
    mouth -= Circle(uv, vec2(0., 0.1), .3, .01);

    mask -= mouth;

    return mask;
}


    // Just a constant
    #define PI 3.1415926535897932384626433832795


float drawCircle(vec2 position, float radius) {
    return step(length(position - 0.5), radius);
}
float inverseDrawCircle(vec2 pos, float radius) {
    return step(radius, length(pos - 0.5));
}
float inverseDrawArc(vec2 pos, float radius) {
    //convert to polar coordinates
    float r = sqrt(
        (pos.x - 0.5) * (pos.x - 0.5) +
        (pos.y - 0.5) * (pos.y - 0.5)
    );
    float a = atan(pos.y - 0.5, pos.x - 0.5);
    if(a < 0) {
        a += 2 * PI;
    }

    //starting angle = 45 deg = 0.25 * pi
    float startingAngle = 0.25 * PI;
    float endingAngle = 2 * PI - startingAngle;
    if(r > radius) return 1.0;
    if(r <= radius && (a >= endingAngle || a <= startingAngle)) return 0.0;
    return 1.0;
}


void main() {
    if(shape == 1) {
        vec2 uv= (gl_FragCoord.xy-iResolution.xy*.5)/iResolution.y;//(mouse/255)*

        uv -= .5;
        uv.x *= iResolution.x/iResolution.y;
        uv.x -= (mouse.x/iResolution.x-1.5f);
        uv.y += (mouse.y/iResolution.y);
        vec3 col = vec3(0.);

        float mask = Smiley(uv, vec2(0.), 1.);


        col = vec3(1., 1., 1.)* mask;
        frag_color = vec4(col, 1.0);
    } else if (shape == 2) {
        frag_color = vec4(color, 1.0);
        // If flickering, multiply it with a sinusoidal wave that oscillates over time
        vec2 uv= (gl_FragCoord.xy-iResolution.xy*.5)/iResolution.y;//(mouse/255)*
        uv.x -= (mouse.x/iResolution.x-0.6f);
        uv.y += (mouse.y/iResolution.y-0.4f);
        vec3 col= vec3(0);
        uv.x *=.7;
        uv.y -=sqrt(abs(uv.x))*.6;
        float r=.3;
        float b=.01;
        float d = length(uv);
        float c= smoothstep(r,r-b,d);
        col= vec3(c);
        frag_color=vec4(col,1.0);
    } else if(shape == 3) {

        vec2 center = (gl_FragCoord.xy-iResolution.xy*.5)/iResolution.y;;
        center.x -= (mouse.x/iResolution.x - 1);
        center.y += (mouse.y/iResolution.y);



        float mastershape = drawCircle(center, 0.3);

        float inverseEye = inverseDrawCircle(
            vec2(center.x , center.y - 0.17),
            0.05
        );

        float inverseMouth = inverseDrawArc(
            center,
            0.3
        );

        vec4 pacmanColor = vec4(vec3(mastershape), 1.0);
        vec4 inverseEyeColor = vec4(vec3(inverseEye), 1.0);
        vec4 inverseMouthColor = vec4(vec3(inverseMouth), 1.0);
//        frag_color = pacmanColor * inverseEyeColor;
        frag_color = pacmanColor * inverseEyeColor * inverseMouthColor * vec4(color, 1.0);
    } else {
        //@Hessuin Ehab
    }
    // Convert RGB to RGBA (in other words, add an alpha value).


}