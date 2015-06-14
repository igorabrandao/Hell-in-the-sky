using namespace std;

// modifica a e b baseado no destino e velocidade
void ponto_entre_pontos( float origem_x, float origem_y, float destino_x, float destino_y, float distancia, float &x, float &y )
{
    //cout << "ponto_entre_pontos(" << origem_x << ", " << origem_y << ", " << destino_x << ", " << destino_y << ", " << distancia << ", " << x << ", " << y << endl;
    // calculate distance between the two points
    float DT = sqrt( pow(origem_x - destino_x, 2) + pow(origem_y - destino_y, 2) );

    //cout << "DT=" << DT << endl;

    //float DT = Math.sqrt(Math.pow((destino_a - origem_a), 2) + Math.pow((destino_b - origem_b), 2));

    float D = distancia; // distance to point C

    if( distancia >= DT ) 
    {
        // nesse caso quero caminhar mais que precisa. Cap
        x = destino_x;
        y = destino_y;
        return;
    }
 
    float T = distancia / DT;
  
    // finding point C coordinate
    x = (1 - T) * origem_x + T * destino_x;
    y = (1 - T) * origem_y + T * destino_y;

    //cout << "calculado (x,y): " << x << "," << y << endl;
}
    
// testa se dois circulos colidem
bool colide_circle_circle( float x1, float y1, float r1, float x2, float y2, float r2 )
{
    float distancia = sqrt( pow( x1 - x2, 2 ) + pow( y1 - y2, 2 ) );
    return ( distancia < ( r1 + r2 ));
}

// Testa se um circulo colide com um retangulo.
bool colide_circle_rectangle(float circ_x, float circ_y, float circ_r, float rec_x1, float rec_y1, float rec_x2, float rec_y2) {
    float rec_width = abs(rec_x2 - rec_x1);
    float rec_height = abs(rec_y2 - rec_y1);
    float rec_x = (rec_x1 + rec_x2) / 2;
    float rec_y = (rec_y1 + rec_y2) / 2;

    float circleDistance_x = abs(circ_x - rec_x);
    float circleDistance_y = abs(circ_y - rec_y);
    
    if( circleDistance_x > ( rec_width/2 + circ_r )) { return false; }
    if( circleDistance_y > ( rec_height/2 + circ_r )) { return false; }

    if (circleDistance_x <= (rec_width/2)) { return true; } 
    if (circleDistance_y <= (rec_height/2)) { return true; }

    float cornerDistance_sq = pow((circleDistance_x - rec_width/2), 2) +
                         pow((circleDistance_y - rec_height/2), 2);

    return (cornerDistance_sq <= (pow(circ_r, 2)));
}