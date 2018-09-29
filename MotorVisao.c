static void inicializarMotorVisao(player *p)
{

    // Visão Contagem
    p->visaoPlayer.contagem.i_quantMesa = 0;
    p->visaoPlayer.contagem.i_quantMontante = 0;

    // Visão Mesa
    p->visaoPlayer.mesa.c_cartaMesa = NULL;

    p->visaoPlayer.mesa.historico.i_amarelo = 0;
    p->visaoPlayer.mesa.historico.i_azul = 0;
    p->visaoPlayer.mesa.historico.i_verde = 0;
    p->visaoPlayer.mesa.historico.i_vermelho = 0;

    //Visão Jogador
    p->visaoPlayer.jogador.i_quantJogador = 0;
    p->visaoPlayer.jogador.i_quantadversario = 0;

    p->visaoPlayer.jogador.historico.i_amarelo = 0;
    p->visaoPlayer.jogador.historico.i_azul = 0;
    p->visaoPlayer.jogador.historico.i_verde = 0;
    p->visaoPlayer.jogador.historico.i_vermelho = 0;

    //Visão Mesa / Jogador - Fator número da carta
   

    for (int i = 0; i < 10; i++)
    {
        p->visaoPlayer.mesa.historico.numero[i] = 0;
        p->visaoPlayer.jogador.historico.numero[i] = 0;
    }
}

int v_QuantMesa()
{
    return contadorDeCartas(M_l);
}

int v_QuantMontante()
{
    return contadorDeCartas(G_l);
}

carta *v_VerificarCartaMesa()
{
    return lst_ObterCartaRef(M_l);
}

int v_QuantPlayer(player *jogador)
{

    return contadorDeCartas(jogador->listaMaos);
}

void executarMotorVisao(player *p)
{
    inicializarMotorVisao(p);       // Zera variáveis antes de computar as visões do player* p
    contadorDeCartasPorTipo(p);     // Conta e salva as cartas por tipo das mãos do jogador atual.     
    build_StateGame(p);             // Salva o estado atual do jogador antes da jogada

    // Visão Contagem
    p->visaoPlayer.contagem.i_quantMesa = v_QuantMesa();
    p->visaoPlayer.contagem.i_quantMontante = v_QuantMontante();

    // Visão Mesa
    p->visaoPlayer.mesa.c_cartaMesa = v_VerificarCartaMesa();
    contadorDeCartasporCorMesa(p, M_l);
    contadorDeCartasPorNumeroMesa(p, M_l);

    //Visão Jogador
    p->visaoPlayer.jogador.i_quantJogador = v_QuantPlayer(p);
    p->visaoPlayer.jogador.i_quantadversario = v_QuantPlayer(p->adversario);
    contadorDeCartasporCorJogador(p, p->listaMaos);
    contadorDeCartasPorNumeroJogador(p, p->cartasNormal);
}
