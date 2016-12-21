---
title: "Classe basic_filebuf | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std.basic_filebuf"
  - "fstream/std::basic_filebuf"
  - "std::basic_filebuf"
  - "basic_filebuf"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_filebuf"
ms.assetid: 3196ba5c-bf38-41bd-9a95-70323ddfca1a
caps.latest.revision: 24
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_filebuf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, para e de uma sequência de elementos armazenados em um arquivo externo.  
  
## Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem> >  
    class basic_filebuf : public basic_streambuf<Elem, Tr>  
```  
  
#### Parâmetros  
 `Elem`  
 O elemento básico no buffer de arquivo.  
  
 `Tr`  
 Características do elemento básico no buffer de arquivo \(geralmente `char_traits`\<`Elem`\>\).  
  
## Comentários  
 A classe de modelo descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, para e de uma sequência de elementos armazenados em um arquivo externo.  
  
> [!NOTE]
>  Objetos do tipo `basic_filebuf` são criados com um buffer interno do tipo `char *` independentemente da `char_type` especificada pelo parâmetro de tipo `Elem`.  Isso significa que uma cadeia de caracteres Unicode \(contendo `wchar_t` caracteres\) serão convertidos em uma cadeia de caracteres ANSI \(contendo `char` caracteres\) antes de ser gravada para o buffer interno.  Para armazenar cadeias de caracteres Unicode no buffer, crie um novo buffer do tipo `wchar_t` e defini\-lo usando o [basic\_streambuf::pubsetbuf](../Topic/basic_streambuf::pubsetbuf.md)`()` método.  Para ver um exemplo que demonstra esse comportamento, consulte abaixo.  
  
 Um objeto da classe `basic_filebuf`\<`Elem`, `Tr`\> armazena um ponteiro de arquivo, que designa o `FILE` objeto que controla o fluxo associado a um arquivo aberto.  Ele também armazena ponteiros para duas facetas de conversão de arquivo para uso pelas funções de membro protegido [estouro](../Topic/basic_filebuf::overflow.md) e [estouro negativo](../Topic/basic_filebuf::underflow.md).  Para obter mais informações, consulte [basic\_filebuf::open](../Topic/basic_filebuf::open.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como forçar um objeto do tipo `basic_filebuf<wchar_t>` para armazenar caracteres Unicode em seu buffer interno ao chamar o `pubsetbuf()` método.  
  
```  
// unicode_basic_filebuf.cpp  
// compile with: /EHsc  
  
#include <iostream>  
#include <string>  
#include <fstream>  
#include <iomanip>  
#include <memory.h>  
#include <string.h>  
  
#define IBUFSIZE 16  
  
using namespace std;  
  
void hexdump(const string& filename);  
  
int main()  
{  
    wchar_t* wszHello = L"Hello World";  
    wchar_t wBuffer[128];  
  
    basic_filebuf<wchar_t> wOutFile;  
  
    // Open a file, wcHello.txt, then write to it, then dump the  
    // file's contents in hex  
    wOutFile.open("wcHello.txt",  
        ios_base::out | ios_base::trunc | ios_base::binary);  
    if(!wOutFile.is_open())  
    {  
        cout << "Error Opening wcHello.txt\n";  
        return -1;  
    }  
    wOutFile.sputn(wszHello, (streamsize)wcslen(wszHello));  
    wOutFile.close();  
    cout << "Hex Dump of wcHello.txt - note that output is ANSI chars:\n";  
    hexdump(string("wcHello.txt"));  
  
    // Open a file, wwHello.txt, then set the internal buffer of  
    // the basic_filebuf object to be of type wchar_t, then write  
    // to the file and dump the file's contents in hex  
    wOutFile.open("wwHello.txt",  
        ios_base::out | ios_base::trunc | ios_base::binary);  
    if(!wOutFile.is_open())  
    {  
        cout << "Error Opening wwHello.txt\n";  
        return -1;  
    }  
    wOutFile.pubsetbuf(wBuffer, (streamsize)128);  
    wOutFile.sputn(wszHello, (streamsize)wcslen(wszHello));  
    wOutFile.close();  
    cout << "\nHex Dump of wwHello.txt - note that output is wchar_t chars:\n";  
    hexdump(string("wwHello.txt"));  
  
    return 0;  
}  
  
// dump contents of filename to stdout in hex  
void hexdump(const string& filename)  
{  
    fstream ifile(filename.c_str(),  
        ios_base::in | ios_base::binary);  
    char *ibuff = new char[IBUFSIZE];  
    char *obuff = new char[(IBUFSIZE*2)+1];  
    int i;  
  
    if(!ifile.is_open())  
    {  
        cout << "Cannot Open " << filename.c_str()  
             << " for reading\n";  
        return;  
    }  
    if(!ibuff || !obuff)  
    {  
        cout << "Cannot Allocate buffers\n";  
        ifile.close();  
        return;  
    }  
  
    while(!ifile.eof())  
    {  
        memset(obuff,0,(IBUFSIZE*2)+1);  
        memset(ibuff,0,IBUFSIZE);  
        ifile.read(ibuff,IBUFSIZE);  
  
        // corner case where file is exactly a multiple of  
        // 16 bytes in length  
        if(ibuff[0] == 0 && ifile.eof())  
            break;  
  
        for(i = 0; i < IBUFSIZE; i++)  
        {  
            if(ibuff[i] >= ' ')  
                obuff[i] = ibuff[i];  
            else  
                obuff[i] = '.';  
  
            cout << setfill('0') << setw(2) << hex  
                 << (int)ibuff[i] << ' ';  
        }  
        cout << "  " << obuff << endl;  
    }  
    ifile.close();  
}  
```  
  
  **Hexadecimais despejo de wcHello.txt \- Observe que a saída é caracteres ANSI:**  
**48 65 6f 6c 6c 20 6f 57 72 6c 64 00 00 00 00 00 Hello World...  Hexadecimais despejo de wwHello.txt \- Observe que a saída é wchar\_t caracteres:**  
**48 00 65 00 6c 00 6c 00 6f 00 20 00 57 00 6f H.e.l.l.o. 00  . W.o.  72 r.l.d. de 6c 00 64 00 00 00 00 00 00 00 00 00 00 00 00.**    
### Construtores  
  
|||  
|-|-|  
|[basic\_filebuf](../Topic/basic_filebuf::basic_filebuf.md)|Constrói um objeto do tipo `basic_filebuf`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[char\_type](../Topic/basic_filebuf::char_type.md)|Associa um nome de tipo com o `Elem` parâmetro do modelo.|  
|[int\_type](../Topic/basic_filebuf::int_type.md)|Faz com que esse tipo em `basic_filebuf`do escopo equivalente ao tipo de mesmo nome no `Tr` escopo.|  
|[off\_type](../Topic/basic_filebuf::off_type.md)|Faz com que esse tipo em `basic_filebuf`do escopo equivalente ao tipo de mesmo nome no `Tr` escopo.|  
|[pos\_type](../Topic/basic_filebuf::pos_type.md)|Faz com que esse tipo em `basic_filebuf`do escopo equivalente ao tipo de mesmo nome no `Tr` escopo.|  
|[traits\_type](../Topic/basic_filebuf::traits_type.md)|Associa um nome de tipo com o `Tr` parâmetro do modelo.|  
  
### Funções membro  
  
|||  
|-|-|  
|[close](../Topic/basic_filebuf::close.md)|Fecha um arquivo.|  
|[is\_open](../Topic/basic_filebuf::is_open.md)|Indica se um arquivo é aberto.|  
|[abrir](../Topic/basic_filebuf::open.md)|Abre um arquivo.|  
|[estouro](../Topic/basic_filebuf::overflow.md)|Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.|  
|[pbackfail](../Topic/basic_filebuf::pbackfail.md)|A função de membro virtual protegida tenta colocar um elemento em novamente o fluxo de entrada e torná\-lo o elemento atual \(apontado pelo próximo ponteiro\).|  
|[seekoff](../Topic/basic_filebuf::seekoff.md)|A função de membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|  
|[seekpos](../Topic/basic_filebuf::seekpos.md)|A função de membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|  
|[setbuf](../Topic/basic_filebuf::setbuf.md)|A função de membro virtual protegida executa uma operação específica de cada buffer de fluxo derivada.|  
|[Troque](../Topic/basic_filebuf::swap.md)|Troca o conteúdo dessa `basic_filebuf` para o conteúdo fornecido `basic_filebuf` parâmetro.|  
|[sincronização](../Topic/basic_filebuf::sync.md)|A função virtual protegida tenta sincronizar os fluxos controlados com quaisquer fluxos externos associados.|  
|[uflow](../Topic/basic_streambuf::uflow.md)|Protegido, a função virtual para extrair o elemento atual do fluxo de entrada.|  
|[estouro negativo](../Topic/basic_filebuf::underflow.md)|Protegido, a função virtual para extrair o elemento atual do fluxo de entrada.|  
  
## Requisitos  
 **Cabeçalho:** \< fstream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< Fstream \>](../standard-library/fstream.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)