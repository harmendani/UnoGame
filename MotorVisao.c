

int v_QuantMesa()
{
    return contadorDeCartas(M_l);
}

int v_QuantMontante()
{
    return contadorDeCartas(G_l);
}

carta v_VerificarCartaMesa()
{
    return lst_ObterCarta(M_l);
}

int v_QuantPlayer(player* jogador)
{
	
    return contadorDeCartas(jogador->listaMaos);
}

void executarMotorVisao(player* p){


// Visão Contagem
p->visaoPlayer.contagem.i_quantMesa = v_QuantMesa();
p->visaoPlayer.contagem.i_quantMontante = v_QuantMontante();

// Visão Mesa
//p->visaoPlayer.mesa.c_cartaMesa = v_VerificarCartaMesa();


//Visão Jogador
p->visaoPlayer.jogador.i_quantJogador = v_QuantPlayer(p);
p->visaoPlayer.jogador.i_quantadversario = v_QuantPlayer(p->adversario);


}
