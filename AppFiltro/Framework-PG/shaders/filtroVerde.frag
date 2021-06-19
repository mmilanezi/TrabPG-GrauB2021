#version 450 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

// Texture sampler
uniform sampler2D ourTexture1;

void main() //alteração no shader no que via ser mapeado nos objetos
{
    color = texture(ourTexture1, TexCoord);// * vec4(ourColor, 1.0);//comentado filtro arco-iris (bem legal)

    //g r b é igual ao x y z e alpha para mapeamento dai usa color.r por exeplo para mapear 
    //float media = color.r * 0.2125 + color.g * 0.7154 + color.b * 0.721; // exemplo de filtro de imagem

    float regulador = 0.3;
    float media = color.r * regulador + color.g * regulador + color.b * regulador;

    
    color = vec4(0.0 , media , 0.0 , 1.0); // filtro verde
    



    //valor final sempre vec4
    //color = vec4(1.0, 1.0 , 0.0 , 1.0); // amarelo
    //color = vec4(1.0, 0.5 , 0.0 , 1.0); // laranja
    //color = vec4(0.0, 0.0 , 1.0 , 1.0);
}