void PonteiroInteligenteDemo4()
{
    // Cria o objeto e o passo ao ponteiro inteligente
    std::unique_ptr<ObjetoGrande> pGrande(new ObjetoGrande());

    //Chama um método no objeto
    pGrande->FacaAlgo();

    // Passar ponteiro bruto para uma API legada
    FuncaoLegadaObjetoGrande(pGrande.get());
}
