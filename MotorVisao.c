static void inicializarMotorVisao(player* p){

    // Visão Contagem
    p->visaoPlayer.contagem.i_quantMesa = 0;
    p->visaoPlayer.contagem.i_quantMontante = 0;

    // Visão Mesa
    p->visaoPlayer.mesa.c_cartaMesa = NULL;

    //Visão Jogador
    p->visaoPlayer.jogador.i_quantJogador = 0;
    p->visaoPlayer.jogador.i_quantadversario = 0;
}

    int v_QuantMesa()
{
    return contadorDeCartas(M_l);
}

int v_QuantMontante()
{
    return contadorDeCartas(G_l);
}

carta* v_VerificarCartaMesa()
{
    return lst_ObterCartaRef(M_l);
}

int v_QuantPlayer(player* jogador)
{
	
    return contadorDeCartas(jogador->listaMaos);
}

void executarMotorVisao(player* p){

// Zera variáveis antes de computar as visões do player* p
inicializarMotorVisao(p);
contadorDeCartasPorTipo(p);

// Visão Contagem
p->visaoPlayer.contagem.i_quantMesa = v_QuantMesa();
p->visaoPlayer.contagem.i_quantMontante = v_QuantMontante();

// Visão Mesa
p->visaoPlayer.mesa.c_cartaMesa = v_VerificarCartaMesa();


//Visão Jogador
p->visaoPlayer.jogador.i_quantJogador = v_QuantPlayer(p);
p->visaoPlayer.jogador.i_quantadversario = v_QuantPlayer(p->adversario);

}
