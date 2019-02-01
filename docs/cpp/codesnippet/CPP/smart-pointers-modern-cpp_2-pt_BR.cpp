
class ObjetoGrande
{
public:
    void FacaAlgo(){}
};

void ProcessaObjetoGrande(const ObjetoGrande& og){}
void PonteiroInteligentDemo()
{    
    // Cria o objeto e o passo ao ponteiro inteligente.
    std::unique_ptr<ObjetoGrande> pGrande(new ObjetoGrande());

    //Chama um método no objeto.
    pGrande->FacaAlgo();

    // Passa uma referência para um método.
    ProcessaObjetoGrande(*pGrande);

} //pGrande é deletado automaticamente quanto o bloco da função está fora do escopo.
