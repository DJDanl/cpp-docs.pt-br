---
title: "Classe basic_filebuf | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
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
  - "basic_filebuf class"
ms.assetid: 3196ba5c-bf38-41bd-9a95-70323ddfca1a
caps.latest.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "cs-cz"
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "pl-pl"
  - "pt-br"
  - "ru-ru"
  - "tr-tr"
  - "zh-cn"
  - "zh-tw"
---
# <a name="basicfilebuf-class"></a>Classe basic_filebuf
Descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características dos caracteres são determinadas pela classe `Tr`, para e de uma sequência de elementos armazenados em um arquivo externo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem>>  
class basic_filebuf : public basic_streambuf<Elem, Tr>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Elem`  
 O elemento básico no buffer de arquivo.  
  
 `Tr`  
 As características do elemento básico no buffer de arquivo (geralmente `char_traits` <  `Elem`>).  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características dos caracteres são determinadas pela classe `Tr`, para e de uma sequência de elementos armazenados em um arquivo externo.  
  
> [!NOTE]
>  Objetos do tipo `basic_filebuf` são criados com um buffer interno do tipo `char *` independentemente do `char_type` especificado pelo parâmetro de tipo `Elem`. Isso significa que uma cadeia de caracteres Unicode (contendo `wchar_t` caracteres) será convertida em uma cadeia de caracteres ANSI (contendo `char` caracteres) antes de ser gravada no buffer interno. Para armazenar cadeias de caracteres Unicode no buffer, crie um novo buffer do tipo `wchar_t` e defina-o usando o método [basic_streambuf::pubsetbuf](../standard-library/basic-streambuf-class.md#basic_streambuf__pubsetbuf)`()`. Para ver um exemplo que demonstra esse comportamento, consulte abaixo.  
  
 Um objeto da classe `basic_filebuf`< `Elem`, `Tr`> armazena um ponteiro de arquivo, que designa o objeto `FILE` que controla o fluxo associado a um arquivo aberto. Ele também armazena ponteiros para duas facetas de conversão de arquivo para uso pelas funções membro protegidas [estouro](#basic_filebuf__overflow) e [estouro negativo](#basic_filebuf__underflow). Para obter mais informações, consulte [basic_filebuf::open](#basic_filebuf__open).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como forçar um objeto do tipo `basic_filebuf<wchar_t>` a armazenar caracteres Unicode em seu buffer interno chamando o método `pubsetbuf()`.  
  
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
  
```Output  
Hex Dump of wcHello.txt - note that output is ANSI chars:  
48 65 6c 6c 6f 20 57 6f 72 6c 64 00 00 00 00 00   Hello World.....  
  
Hex Dump of wwHello.txt - note that output is wchar_t chars:  
48 00 65 00 6c 00 6c 00 6f 00 20 00 57 00 6f 00   H.e.l.l.o. .W.o.  
72 00 6c 00 64 00 00 00 00 00 00 00 00 00 00 00   r.l.d...........  
```  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_filebuf](#basic_filebuf__basic_filebuf)|Constrói um objeto do tipo `basic_filebuf`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[char_type](#basic_filebuf__char_type)|Associa um nome de tipo ao parâmetro de modelo `Elem`.|  
|[int_type](#basic_filebuf__int_type)|Faz com que esse tipo no escopo de `basic_filebuf` seja equivalente ao tipo com o mesmo nome no escopo de `Tr`.|  
|[off_type](#basic_filebuf__off_type)|Faz com que esse tipo no escopo de `basic_filebuf` seja equivalente ao tipo com o mesmo nome no escopo de `Tr`.|  
|[pos_type](#basic_filebuf__pos_type)|Faz com que esse tipo no escopo de `basic_filebuf` seja equivalente ao tipo com o mesmo nome no escopo de `Tr`.|  
|[traits_type](#basic_filebuf__traits_type)|Associa um nome de tipo ao parâmetro de modelo `Tr`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[close](#basic_filebuf__close)|Fecha um arquivo.|  
|[is_open](#basic_filebuf__is_open)|Indica se um arquivo está aberto.|  
|[open](#basic_filebuf__open)|Abre um arquivo.|  
|[overflow](#basic_filebuf__overflow)|Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.|  
|[pbackfail](#basic_filebuf__pbackfail)|Uma função membro virtual protegida que tenta colocar um elemento de volta no fluxo de entrada, então torná-lo elemento atual (apontando para o ponteiro seguinte).|  
|[seekoff](#basic_filebuf__seekoff)|A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|  
|[seekpos](#basic_filebuf__seekpos)|A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|  
|[setbuf](#basic_filebuf__setbuf)|A função membro virtual protegida executa uma operação que específica para cada buffer de fluxo derivado.|  
|[Swap](#basic_filebuf__swap)|Troca o conteúdo deste `basic_filebuf` pelo o conteúdo do parâmetro `basic_filebuf` fornecido.|  
|[sync](#basic_filebuf__sync)|A função virtual protegida tenta sincronizar os fluxos controlados com quaisquer fluxos externos associados.|  
|[uflow](../standard-library/basic-streambuf-class.md#basic_streambuf__uflow)|Função virtual protegida para extrair o elemento atual do fluxo de entrada.|  
|[underflow](#basic_filebuf__underflow)|Função virtual protegida para extrair o elemento atual do fluxo de entrada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<fstream>  
  
 **Namespace:** std  
  
##  <a name="a-namebasicfilebufbasicfilebufa--basicfilebufbasicfilebuf"></a><a name="basic_filebuf__basic_filebuf"></a>  basic_filebuf::basic_filebuf  
 Constrói um objeto do tipo `basic_filebuf`.  
  
```  
basic_filebuf();

basic_filebuf(basic_filebuf&& right);
```  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor armazena um ponteiro nulo em todos os ponteiros que controlam o buffer de entrada e o buffer de saída. Ele também armazena um ponteiro nulo no ponteiro do arquivo.  
  
 O segundo construtor inicializa o objeto com o conteúdo de `right`, tratado como uma referência rvalue.  
  
##  <a name="a-namebasicfilebufchartypea--basicfilebufchartype"></a><a name="basic_filebuf__char_type"></a>  basic_filebuf::char_type  
 Associa um nome de tipo ao parâmetro do modelo **Elem**.  
  
```  
typedef Elem char_type;  
```  
  
##  <a name="a-namebasicfilebufclosea--basicfilebufclose"></a><a name="basic_filebuf__close"></a>  basic_filebuf::close  
 Fecha um arquivo.  
  
```  
basic_filebuf<Elem, Tr> *close();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro retornará um ponteiro nulo se o ponteiro de arquivo for um ponteiro nulo.  
  
### <a name="remarks"></a>Comentários  
 **close** chama `fclose`( **fp**). Se essa função retornar um valor diferente de zero, a função retornará um ponteiro nulo. Caso contrário, retornará **this** para indicar que o arquivo foi fechado com êxito.  
  
 Para um fluxo amplo, se qualquer inserções tiverem ocorrido desde que o fluxo foi aberto ou desde a última chamada a `streampos`, as chamadas de função [estourarão](#basic_filebuf__overflow). Ele também insere qualquer sequência necessária para restaurar o estado de conversão inicial usando a faceta de conversão de arquivo **fac** para chamar **fac.unshift** conforme necessário. Cada **byte** de elemento do tipo `char` produzido assim é gravado no fluxo associado designado pelo ponteiro de arquivo **fp** como se fosse por chamadas sucessivas do formulário `fputc`( **byte**, **fp**). Se a chamada para **fac.unshift** ou qualquer gravação falhar, a função não terá êxito.  
  
### <a name="example"></a>Exemplo  
  A amostra a seguir assume dois arquivos no diretório atual: basic_filebuf_close.txt (o conteúdo é "teste") e iotest.txt (o conteúdo é "ssss").  
  
```  
// basic_filebuf_close.cpp  
// compile with: /EHsc  
#include <fstream>  
#include <iostream>  
  
int main() {  
   using namespace std;  
   ifstream file;  
   basic_ifstream <wchar_t> wfile;  
   char c;  
   // Open and close with a basic_filebuf  
   file.rdbuf()->open( "basic_filebuf_close.txt", ios::in );  
   file >> c;  
   cout << c << endl;  
   file.rdbuf( )->close( );  
  
   // Open/close directly  
   file.open( "iotest.txt" );  
   file >> c;  
   cout << c << endl;  
   file.close( );  
  
   // open a file with a wide character name  
   wfile.open( L"iotest.txt" );  
  
   // Open and close a nonexistent with a basic_filebuf  
   file.rdbuf()->open( "ziotest.txt", ios::in );  
   cout << file.fail() << endl;  
   file.rdbuf( )->close( );  
  
   // Open/close directly  
   file.open( "ziotest.txt" );  
   cout << file.fail() << endl;  
   file.close( );  
}  
```  
  
```Output  
t  
s  
0  
1  
```  
  
##  <a name="a-namebasicfilebufinttypea--basicfilebufinttype"></a><a name="basic_filebuf__int_type"></a>  basic_filebuf::int_type  
 Torna esse tipo no escopo de basic_filebuf equivalente ao tipo de mesmo nome no escopo de **Tr**.  
  
```  
typedef typename traits_type::int_type int_type;  
```  
  
##  <a name="a-namebasicfilebufisopena--basicfilebufisopen"></a><a name="basic_filebuf__is_open"></a>  basic_filebuf::is_open  
 Indica se um arquivo está aberto.  
  
```  
bool is_open() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 **true** se o ponteiro do arquivo não for um ponteiro nulo.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_filebuf_is_open.cpp  
// compile with: /EHsc  
#include <fstream>  
#include <iostream>  
  
int main( )   
{  
   using namespace std;  
   ifstream file;  
   cout << boolalpha << file.rdbuf( )->is_open( ) << endl;  
  
   file.open( "basic_filebuf_is_open.cpp" );  
   cout << file.rdbuf( )->is_open( ) << endl;  
}  
```  
  
```Output  
false  
true  
```  
  
##  <a name="a-namebasicfilebufofftypea--basicfilebufofftype"></a><a name="basic_filebuf__off_type"></a>  basic_filebuf::off_type  
 Torna esse tipo no escopo de basic_filebuf equivalente ao tipo de mesmo nome no escopo de **Tr**.  
  
```  
typedef typename traits_type::off_type off_type;  
```  
  
##  <a name="a-namebasicfilebufopena--basicfilebufopen"></a><a name="basic_filebuf__open"></a>  basic_filebuf::open  
 Abre um arquivo.  
  
```  
basic_filebuf<Elem, Tr> *open(
    const char* _Filename,  
    ios_base::openmode _Mode,  
    int _Prot = (int)ios_base::_Openprot);

basic_filebuf<Elem, Tr> *open(
    const char* _Filename,  
    ios_base::openmode _Mode);

basic_filebuf<Elem, Tr> *open(
    const wchar_t* _Filename,  
    ios_base::openmode _Mode,  
    int _Prot = (int)ios_base::_Openprot);

basic_filebuf<Elem, Tr> *open(
    const wchar_t* _Filename,  
    ios_base::openmode _Mode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Filename`  
 O nome do arquivo a ser aberto.  
  
 `_Mode`  
 Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#ios_base__openmode).  
  
 `_Prot`  
 A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).  
  
### <a name="return-value"></a>Valor de retorno  
 Se o ponteiro do arquivo for um ponteiro nulo, a função retornará um ponteiro nulo. Caso contrário, retornará **this**.  
  
### <a name="remarks"></a>Comentários  
 A função membro abre o arquivo com o nome do arquivo *filename*, chamando [fopen](../c-runtime-library/reference/fopen-wfopen.md)( *filename*, **strmode**). **strmode** é determinado de **mode &**~( [ate](../standard-library/ios-base-class.md#ios_base__openmode) & &#124; [binary](../standard-library/ios-base-class.md#ios_base__openmode)):  
  
- **ios_base::in** torna-se **"r"** (abrir arquivo existente para leitura).  
  
- [ios_base::out](../standard-library/ios-base-class.md#ios_base__fmtflags) ou **ios_base::out &#124; ios_base::trunc** se torna **"w"** (truncar o arquivo existente ou criar para gravação).  
  
- **ios_base::out &#124; app** torna-se **"a"** (abrir arquivo existente para acrescentar todas as gravações).  
  
- **ios_base::in &#124; ios_base::out** se torna **"r+"** (abrir arquivo existente para leitura e gravação).  
  
- **ios_base::in &#124; ios_base::out &#124; ios_base::trunc** se torna **"w +"** (truncar o arquivo existente ou criar para leitura e gravação).  
  
- **ios_base::in &#124; ios_base::out &#124; ios_base::app** se torna **"+"** (abrir arquivo existente para leitura e para acrescentar todas as gravações).  
  
 Se **mode & ios_base::binary** for diferente de zero, a função acrescentará **b** a **strmode** para abrir um fluxo binário, em vez de um fluxo de texto. Em seguida, armazena o valor retornado por `fopen` no ponteiro do arquivo **fp**. Se **mode & ios_base::ate** for diferente de zero e o ponteiro do arquivo não for um ponteiro nulo, a função chamará `fseek`( **fp**, 0, `SEEK_END`) para posicionar o fluxo no final do arquivo. Se essa operação posicionamento falhar, a função chamará [close](#basic_filebuf__close)( **fp**) e armazenará um ponteiro nulo no ponteiro do arquivo.  
  
 Se o ponteiro do arquivo não for um ponteiro nulo, a função determinará a faceta de conversão de arquivo: `use_facet`< `codecvt`< **Elem**, `char`, **traits_type::**[state_type](../standard-library/char-traits-struct.md#char_traits__state_type)> >( [getloc](../standard-library/basic-streambuf-class.md#basic_streambuf__getloc)), para uso por [underflow](#basic_filebuf__underflow) e [overflow](#basic_filebuf__overflow).  
  
 Se o ponteiro do arquivo for um ponteiro nulo, a função retornará um ponteiro nulo. Caso contrário, retornará **this**.  
  
### <a name="example"></a>Exemplo  
  Consulte [basic_filebuf::close](#basic_filebuf__close) para ver um exemplo que usa **open**.  
  
##  <a name="a-namebasicfilebufoperatoreqa--basicfilebufoperator"></a><a name="basic_filebuf__operator_eq"></a>  basic_filebuf::operator=  
 Atribua o conteúdo deste objeto de buffer de fluxo. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.  
  
```  
basic_filebuf& operator=(basic_filebuf&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Uma referência rvalue para um objeto [basic_filebuf](../standard-library/basic-filebuf-class.md).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna *this.  
  
### <a name="remarks"></a>Comentários  
 O operador membro substitui o conteúdo do objeto usando o conteúdo de ` right`, tratado como uma referência rvalue. Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
##  <a name="a-namebasicfilebufoverflowa--basicfilebufoverflow"></a><a name="basic_filebuf__overflow"></a>  basic_filebuf::overflow  
 Chamado quando um novo caractere é inserido em um buffer cheio.  
  
```  
virtual int_type overflow(int_type _Meta = traits_type::eof);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Meta`  
 O caractere a inserir no buffer ou **traits_type::eof**.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função não conseguir obter êxito, ela retornará **traits_type::eof**. Caso contrário, retornará **traits_type::**[not_eof](../standard-library/char-traits-struct.md#char_traits__not_eof)(_ *Meta*).  
  
### <a name="remarks"></a>Comentários  
 Se _ *Meta***!= traits_type::**[eof](../standard-library/char-traits-struct.md#char_traits__eof), a função membro virtual protegida buscará inserir o elemento **ch = traits_type::**[to_char_type](../standard-library/char-traits-struct.md#char_traits__to_char_type)(\_ *Meta*) no buffer de saída. Isso pode ser feito de várias maneiras:  
  
-   Se houver uma posição de gravação disponível, ela poderá armazenar o elemento na posição de gravação e incrementar o próximo ponteiro para o buffer de saída.  
  
-   Ele pode disponibilizar uma posição de gravação alocando armazenamento novo ou adicional ao buffer de saída.  
  
-   Pode converter qualquer saída pendente no buffer de saída, seguido por **ch**, usando a faceta de conversão de arquivo **fac** para chamar **fac.out** conforme necessário. Cada elemento `ch` do tipo *char* produzido assim é gravado no fluxo associado designado pelo ponteiro de arquivo **fp** como se fosse por chamadas sucessivas da forma `fputc`( **ch**, **fp**). Se qualquer conversão ou gravação falhar, a função não será bem-sucedida.  
  
##  <a name="a-namebasicfilebufpbackfaila--basicfilebufpbackfail"></a><a name="basic_filebuf__pbackfail"></a>  basic_filebuf::pbackfail  
 Tenta colocar um elemento de volta no fluxo de entrada e torná-lo o elemento atual (apontado pelo ponteiro seguinte).  
  
```  
virtual int_type pbackfail(int_type _Meta = traits_type::eof);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Meta`  
 O caractere a ser inserido no buffer, ou **traits_type::eof**.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função não conseguir obter êxito, ela retornará **traits_type::eof**. Caso contrário, retornará **traits_type::**[not_eof](../standard-library/char-traits-struct.md#char_traits__not_eof)(_ *Meta*).  
  
### <a name="remarks"></a>Comentários  
 A função membro virtual protegida coloca um elemento de volta no buffer de entrada, então o torna o elemento atual (apontando para o ponteiro seguinte). Se _ *Meta* **== traits_type::**[eof](../standard-library/char-traits-struct.md#char_traits__eof), o elemento a ser recuado será efetivamente aquele que já estava no fluxo antes do elemento atual. Caso contrário, esse elemento será substituído por **ch = traits_type::**[to_char_type](../standard-library/char-traits-struct.md#char_traits__to_char_type)(\_ *Meta*). A função pode colocar um elemento de volta de várias maneiras:  
  
-   Se uma posição putback estiver disponível e o elemento armazenado lá for comparável a **ch**, ele pode diminuir o próximo ponteiro para o buffer de entrada.  
  
-   Se a função puder disponibilizar uma posição `putback`, ela poderá fazer isso; defina o ponteiro seguinte para apontar para aquela posição e armazene **ch** naquela posição.  
  
-   Se a função puder recuar um elemento para o fluxo de entrada, ela poderá pode fazer isso, como chamando `ungetc` para um elemento do tipo `char`*.*  
  
##  <a name="a-namebasicfilebufpostypea--basicfilebufpostype"></a><a name="basic_filebuf__pos_type"></a>  basic_filebuf::pos_type  
 Torna esse tipo no escopo de basic_filebuf equivalente ao tipo de mesmo nome no escopo de **Tr**.  
  
```  
typedef typename traits_type::pos_type pos_type;  
```  
  
##  <a name="a-namebasicfilebufseekoffa--basicfilebufseekoff"></a><a name="basic_filebuf__seekoff"></a>  basic_filebuf::seekoff  
 Tenta alterar as posições atuais para os fluxos controlados.  
  
```  
virtual pos_type seekoff(off_type _Off,
    ios_base::seekdir _Way,
    ios_base::openmode _Which = ios_base::in | ios_base::out);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 A posição pela qual buscar com relação a `_Way`.  
  
 `_Way`  
 O ponto de partida para operações de deslocamento. Consulte [seekdir](../standard-library/ios-base-class.md#ios_base__seekdir) para valores possíveis.  
  
 `_Which`  
 Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a nova posição ou uma posição de fluxo inválida.  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegida busca alterar as posições atuais para os fluxos controlados. Para um objeto da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>, uma posição de fluxo pode ser representada por um objeto do tipo `fpos_t`, que armazena um deslocamento e quaisquer informações de estado necessárias analisar um fluxo grande. Deslocamento zero designa o primeiro elemento do fluxo. (Um objeto do tipo [pos_type](../standard-library/basic-streambuf-class.md#basic_streambuf__pos_type) armazena a pelo menos um objeto `fpos_t`.)  
  
 Para um arquivo aberto para leitura e gravação, os fluxos de entrada e saída são posicionados em tandem. Para mudar entre a inserção e extração, chame [pubseekoff](../standard-library/basic-streambuf-class.md#basic_streambuf__pubseekoff) ou [pubseekpos](../standard-library/basic-streambuf-class.md#basic_streambuf__pubseekpos). Chamadas para `pubseekoff` (e, portanto, para `seekoff`) têm várias limitações para [fluxos de texto](../c-runtime-library/text-and-binary-streams.md), [fluxos binários](../c-runtime-library/text-and-binary-streams.md) e [fluxos largos](../c-runtime-library/byte-and-wide-streams.md).  
  
 Se o ponteiro do arquivo **fp** for um ponteiro nulo, a função falhará. Caso contrário, ele busca alterar a posição do fluxo chamando `fseek`( **fp**, `_Off`, `_Way`). Se essa função for bem-sucedida e a posição resultante **fposn** puder ser determinada chamando `fgetpos`( **fp**, **&fposn**), a função será bem-sucedida. Se a função for bem-sucedida, ela retornará um valor do tipo **pos_type** contendo **fposn**. Caso contrário, retorna uma posição de fluxo inválida.  
  
##  <a name="a-namebasicfilebufseekposa--basicfilebufseekpos"></a><a name="basic_filebuf__seekpos"></a>  basic_filebuf::seekpos  
 Tenta alterar as posições atuais para os fluxos controlados.  
  
```  
virtual pos_type seekpos(pos_type _Sp, ios_base::openmode _Which = ios_base::in | ios_base::out);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Sp`  
 A posição pela qual buscar.  
  
 `_Which`  
 Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o ponteiro do arquivo **fp** for um ponteiro nulo, a função falhará. Caso contrário, buscará alterar a posição do fluxo chamando `fsetpos`( **fp**, **&fposn**), em que **fposn** é o objeto `fpos_t` armazenado em `pos`. Se essa função for bem-sucedida, a função retornará `pos`. Caso contrário, retorna uma posição de fluxo inválida. Para determinar se a posição de fluxo é inválida, compare o valor retornado com `pos_type(off_type(-1))`.  
  
### <a name="remarks"></a>Comentários  
 A função de membro virtual protegida busca alterar as posições atuais para os fluxos controlados. Para um objeto da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)\< **Elem**, **Tr**>, uma posição de fluxo pode ser representada por um objeto do tipo `fpos_t`, que armazena um deslocamento e quaisquer informações de estado necessárias analisar um fluxo grande. Deslocamento zero designa o primeiro elemento do fluxo. (Um objeto do tipo `pos_type` armazena a pelo menos um objeto `fpos_t`.)  
  
 Para um arquivo aberto para leitura e gravação, os fluxos de entrada e saída são posicionados em tandem. Para mudar entre a inserção e extração, chame [pubseekoff](../standard-library/basic-streambuf-class.md#basic_streambuf__pubseekoff) ou [pubseekpos](../standard-library/basic-streambuf-class.md#basic_streambuf__pubseekpos). Chamadas para `pubseekoff` (e, portanto, para `seekoff`) têm várias limitações para fluxos de texto, fluxos binários e fluxos largos.  
  
 Para um fluxo amplo, se qualquer inserções tiverem ocorrido desde que o fluxo foi aberto ou desde a última chamada a `streampos`, as chamadas de função [estourarão](#basic_filebuf__overflow). Ele também insere qualquer sequência necessária para restaurar o estado de conversão inicial usando a faceta de conversão de arquivo **fac** para chamar **fac**`.``unshift` conforme necessário. Cada **byte** de elemento do tipo `char` produzido assim é gravado no fluxo associado designado pelo ponteiro de arquivo **fp** como se fosse por chamadas sucessivas do formulário `fputc`( **byte**, **fp**). Se a chamada para **fac.unshift** ou qualquer gravação falhar, a função não terá êxito.  
  
##  <a name="a-namebasicfilebufsetbufa--basicfilebufsetbuf"></a><a name="basic_filebuf__setbuf"></a>  basic_filebuf::setbuf  
 Executa um operação específica para cada buffer de fluxo derivado.  
  
```  
virtual basic_streambuf<Elem, Tr> *setbuf(
    char_type* _Buffer,  
    streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Buffer`  
 Ponteiro para um buffer.  
  
 ` count`  
 O tamanho do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro protegido retornará zero se o ponteiro do arquivo `fp` for um ponteiro nulo.  
  
### <a name="remarks"></a>Comentários  
 `setbuf` chama `setvbuf`( **fp**, ( `char` \*) `_Buffer`, `_IOFBF`, ` count` \* `sizeof` ( **Elem**) ) para oferecer a matriz de elementos ` count` começando no _ *Buffer* como um buffer para o fluxo. Se essa função retornar um valor diferente de zero, a função retornará um ponteiro nulo. Caso contrário, retornará **this** para indicar o sucesso.  
  
##  <a name="a-namebasicfilebufswapa--basicfilebufswap"></a><a name="basic_filebuf__swap"></a>  basic_filebuf::swap  
 Troca o conteúdo desse `basic_filebuf` pelo conteúdo do `basic_filebuf` fornecido.  
  
```  
void swap(basic_filebuf& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 ` right`  
 Um `lvalue` referência a outro `basic_filebuf`.  
  
##  <a name="a-namebasicfilebufsynca--basicfilebufsync"></a><a name="basic_filebuf__sync"></a>  basic_filebuf::sync  
 Tenta sincronizar os fluxos controlados com quaisquer fluxos externos associados.  
  
```  
virtual int sync();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará zero se o ponteiro do arquivo **fp** for um ponteiro nulo. Caso contrário, retornará zero somente se chamadas tanto para [overflow](#basic_filebuf__overflow) quanto para `fflush`( **fp**) obtiverem sucesso em liberar qualquer saída para o fluxo.  
  
##  <a name="a-namebasicfilebuftraitstypea--basicfilebuftraitstype"></a><a name="basic_filebuf__traits_type"></a>  basic_filebuf::traits_type  
 Associa um nome de tipo ao parâmetro de modelo **Tr**.  
  
```  
typedef Tr traits_type;  
```  
  
##  <a name="a-namebasicfilebufunderflowa--basicfilebufunderflow"></a><a name="basic_filebuf__underflow"></a>  basic_filebuf::underflow  
 Extrai o elemento atual do fluxo de entrada.  
  
```  
virtual int_type underflow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se a função não conseguir obter êxito, ela retornará **traits_type::**[eof](../standard-library/char-traits-struct.md#char_traits__eof). Caso contrário, retornará **ch**, convertidos conforme descrito na seção Comentários.  
  
### <a name="remarks"></a>Comentários  
 A função membro virtual protegida busca extrair o elemento atual **ch** do fluxo de entrada e retorna o elemento como **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#char_traits__to_int_type)( **ch**). Isso pode ser feito de várias maneiras:  
  
-   Se houver uma posição de leitura estiver disponível, ela pegará **ch** como o elemento armazenado na posição leitura e avançará o próximo ponteiro para o buffer de entrada.  
  
-   Ele pode ler um ou mais elementos do tipo `char`*,* como se por chamadas sucessivas do formulário `fgetc`( **fp**) e convertê-los em um elemento **ch** do tipo **Elem** utilizando a faceta de conversão de arquivo fac para chamar **fac.in** conforme necessário. Se qualquer leitura ou conversão falhar, a função não será bem-sucedida.  
  
## <a name="see-also"></a>Consulte também  
 [\<fstream>](../standard-library/fstream.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)

