void PonteiroInteligenteDemo2()
{
    // Cria um objeto e o passa a um ponteiro inteligent
    std::unique_ptr<ObjetoGrand> pGrande(new LargeObject());

    //Chama um método no objeto
    pGrande->FacaAlgo();

    // Libera a memória antes de sairmos do bloco da função
    pGrade.reset();

    // Faça alguma outra coisa...

}
