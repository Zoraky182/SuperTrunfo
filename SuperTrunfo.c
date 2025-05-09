void jogarRodada(Carta jogador1, Carta jogador2) {
    int atributoEscolhido;

    printf("Sua carta: %s\n", jogador1.nome);
    printf("Escolha um atributo para jogar:\n");
    printf("1. Velocidade (%d)\n", jogador1.velocidade);
    printf("2. Forca (%d)\n", jogador1.forca);
    printf("3. Inteligencia (%d)\n", jogador1.inteligencia);
    scanf("%d", &atributoEscolhido);

    printf("Carta do oponente: %s\n", jogador2.nome);

    int valorJogador1, valorJogador2;

    switch (atributoEscolhido) {
        case 1:
            valorJogador1 = jogador1.velocidade;
            valorJogador2 = jogador2.velocidade;
            printf("Atributo escolhido: Velocidade\n");
            break;
        case 2:
            valorJogador1 = jogador1.forca;
            valorJogador2 = jogador2.forca;
            printf("Atributo escolhido: Forca\n");
            break;
        case 3:
            valorJogador1 = jogador1.inteligencia;
            valorJogador2 = jogador2.inteligencia;
            printf("Atributo escolhido: Inteligencia\n");
            break;
        default:
            printf("Atributo invalido!\n");
            return;
    }

    printf("Sua carta: %d, Carta do oponente: %d\n", valorJogador1, valorJogador2);

    if (valorJogador1 > valorJogador2) {
        printf("Voce venceu a rodada!\n");
        // Lógica para transferir as cartas
    } else if (valorJogador2 > valorJogador1) {
        printf("O oponente venceu a rodada!\n");
        // Lógica para transferir as cartas
    } else {
        printf("Empate!\n");
        // Lógica para lidar com o empate
    }
}