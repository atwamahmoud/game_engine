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

float square(vec2 r, vec2 bottomLeft, float side) {
    vec2 p = r - bottomLeft;
    return ( p.x > 0.0 && p.x < side && p.y>0.0 && p.y < side ) ? 1.0 : 0.0;
}

float character(vec2 r, vec2 bottomLeft, float charCode, float squareSide) {
    vec2 p = r - bottomLeft;
    float ret = 0.0;
    float num, quotient, remainder, divider;
    float x, y;
    num = charCode;
    for(int i=0; i<20; i++) {
        float boxNo = float(19-i);
        divider = pow(2., boxNo);
        quotient = floor(num / divider);
        remainder = num - quotient*divider;
        num = remainder;

        y = floor(boxNo/4.0);
        x = boxNo - y*4.0;
        if(quotient == 1.) {
            ret += square( p, squareSide*vec2(x, y), squareSide );
        }
    }
    return ret;
}
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
float characterG(vec2 r, vec2 MiddleLeft, float Diameter) {
    float x, y;
    x = r.x;
    y = r.y;
    float radius = Diameter/2.;
    vec2 center = MiddleLeft.xy + vec2(radius, 0);

    //vec2 a = vec2(radius/pow(2.,0.5), -radius/pow(2.,0.5)) ;
    vec2 a = vec2(radius/pow(1.64,0.5), -radius/pow(1.64,0.5) * 0.8) ;
    vec2 b = a.xy - vec2((radius*0.45)/pow(2.,0.5), -(radius*0.45)/pow(2.,0.5));

    if(x-center.x < a.x && x-center.x > b.x && y-center.y > a.y && y-center.y < 0. )
    {
        return 1.;
    }
    else if(x-center.x < b.x && x-center.x > 0. && y-center.y > b.y && y-center.y < 0.)
    {
        return 1.;
    }
    if(pow(x-center.x, 2.) + pow(y-center.y, 2.) < pow(radius, 2.) && pow(x-center.x, 2.) + pow(y-center.y, 2.) > pow((radius) * 0.65, 2.))
    {

        if(x-center.x > 0. && y-center.y > 0.)
        {
            if((y-center.y) > (x-center.x))
            return 1.;
        }
        else if(x-center.x > 0. && y-center.y < 0.)
        {

            //if((y-center.y) / (x-center.x) < -0.9) In case of 45 Degrees
            //    return 1.;
            if((y-center.y) / (x-center.x) < -0.8)
            return 1.;
        }
        else
        return 1.;
    }
    return 0.;
}


void main() {
    if(shape == 1) {
        vec2 uv= (gl_FragCoord.xy-iResolution.xy*.5)/iResolution.xy;//(mouse/255)*

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
        vec2 uv= (gl_FragCoord.xy-iResolution.xy*.5)/iResolution.xy;
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

        vec2 center = (gl_FragCoord.xy-iResolution.xy*.5)/iResolution.xy;
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
    } else if(shape == 4) {

        vec2 r = (gl_FragCoord.xy - 0.5*iResolution.xy) / iResolution.y;

        float xMax = 0.5*iResolution.x/iResolution.y;
        float yMax = 1.;


        float side = 0.5 * yMax;

        //float maskG = character(r, vec2((iMouse.x-0.5*iResolution.x)/iResolution.y, (iMouse.y-0.5*iResolution.y)/iResolution.y), G, side);
        float maskG = characterG(r, vec2((mouse.x-0.5*iResolution.x)/iResolution.y, -(mouse.y-0.5*iResolution.y)/iResolution.y), side);

        vec3 pixel = vec3(0., 0., 0.);
        vec3 col = vec3(255., 255., 255.);

        pixel = mix(pixel, col, maskG);

        frag_color = vec4(pixel, 1.0);
    }
}
