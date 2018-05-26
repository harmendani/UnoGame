

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

int v_QuantPlayer(player jogador)
{
	
    return contadorDeCartas(jogador.listaMaos);
}
