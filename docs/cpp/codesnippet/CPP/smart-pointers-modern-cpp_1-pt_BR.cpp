void UsarPonteiroBruto()
{
    // Uso de ponteiro "bruto" -- não recomendado.
    Musica* pMusica = new Musica(L"Nothing on You", L"Bruno Mars"); 

    // Usar pMusica...

    // Não se esqueça de deletar!
    delete pSong;
}


void UsarPonteiroInteligente()
{
    // Declara um ponteiro inteligente na pilha e passa ao ponteiro "bruto".
    unique_ptr<Musica> musica2(new Musica(L"Nothing on You", L"Bruno Mars"));

    // Usar musica2...
    wstring s = musica2->duracao_;
    //...

} // musica2 é deletado automaticamente aqui
