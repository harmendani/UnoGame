/* Visão dos jogos são contagens, predições e verificações em relação as cartas e
** são utilizados para que o motor de IA do jogo tome as melhores decisões.
*/

// TIPOS DEFINIDOS
typedef struct VisaoContagem
{
    int i_quantMesa;
    int i_quantMontante;

} st_Contagem;

typedef struct VisaoMesa
{
    carta c_cartaMesa;

} st_Mesa;

typedef struct VisaoJogador
{
    int i_quantJogador;
    int i_quantadversario;

} st_Jogador;

typedef struct VisaoTotal
{
    st_Contagem contagem;
    st_Mesa mesa;
    st_Jogador jogador;
} vision;

/* Procedimentos para a visão Contagem */
int v_QuantMesa();
int v_QuantMontante();
/* Procedimentos para a visão Mesa */
carta v_VerificarCartaMesa();
/* Procedimento para a visão Jogador */
int v_QuantJogador();
int v_QuantAdversario();
