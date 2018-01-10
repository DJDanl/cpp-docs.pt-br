---
title: Classe basic_istream | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- istream/std::basic_istream
- istream/std::basic_istream::gcount
- istream/std::basic_istream::get
- istream/std::basic_istream::getline
- 'istream/std::basic_istream::'
- istream/std::basic_istream::peek
- istream/std::basic_istream::putback
- istream/std::basic_istream::read
- istream/std::basic_istream::readsome
- istream/std::basic_istream::seekg
- istream/std::basic_istream::sentry
- istream/std::basic_istream::swap
- istream/std::basic_istream::sync
- istream/std::basic_istream::tellg
- istream/std::basic_istream::unget
dev_langs: C++
helpviewer_keywords:
- std::basic_istream [C++]
- std::basic_istream [C++], gcount
- std::basic_istream [C++], get
- std::basic_istream [C++], getline
- std::basic_istream [C++], OVERWRITE
- std::basic_istream [C++], peek
- std::basic_istream [C++], putback
- std::basic_istream [C++], read
- std::basic_istream [C++], readsome
- std::basic_istream [C++], seekg
- std::basic_istream [C++], sentry
- std::basic_istream [C++], swap
- std::basic_istream [C++], sync
- std::basic_istream [C++], tellg
- std::basic_istream [C++], unget
ms.assetid: c7c27111-de6d-42b4-95a3-a7e65259bf17
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 14f41a90aab8e95d336df6724a7217947ec1c57c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="basicistream-class"></a>Classe basic_istream
Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo com elementos do tipo `Elem`, também conhecido como [char_type](../standard-library/basic-ios-class.md#char_type), cujas características de caractere são determinadas pela classe *Tr*, também conhecida como [traits_type](../standard-library/basic-ios-class.md#traits_type).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem>>  
class basic_istream : virtual public basic_ios<Elem, Tr>  
```  
  
## <a name="remarks"></a>Comentários  
 A maioria das funções membro que sobrecarrega o [operator>>](#op_gt_gt) é composta por funções de entrada formatadas. Elas seguem o padrão:  
  
```cpp  
iostate state = goodbit;
const sentry ok(*this);

if (ok)
{
    try
    {
        /*extract elements and convert
            accumulate flags in state.
            store a successful conversion*/
    }
    catch (...)
    {
        try
        {
            setstate(badbit);

        }
        catch (...)
        {
        }
        if ((exceptions()& badbit) != 0)
            throw;
    }
}
setstate(state);

return (*this);
```  
  
 Muitas outras funções membro são funções de entrada sem formatação. Elas seguem o padrão:  
  
```cpp  
iostate state = goodbit;
count = 0;    // the value returned by gcount  
const sentry ok(*this, true);

if (ok)
{
    try
    {
        /* extract elements and deliver
            count extracted elements in count
            accumulate flags in state */
    }
    catch (...)
    {
        try
        {
            setstate(badbit);

        }
        catch (...)
        {
        }
        if ((exceptions()& badbit) != 0)
            throw;
    }
}
setstate(state);
```  
  
 Ambos os grupos de funções chamam [setstate](../standard-library/basic-ios-class.md#setstate)( **eofbit**) se encontram o final do arquivo ao extrair elementos.  
  
 Um objeto da classe `basic_istream` <  `Elem`, *Tr*> armazena:  
  
-   Um objeto base público virtual da classe [basic_ios](../standard-library/basic-ios-class.md)< `Elem`, *Tr*> `.`  
  
-   Uma contagem de extração para a última operação de entrada sem formatação (chamada **count** no código anterior).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [Classe basic_ifstream](../standard-library/basic-ifstream-class.md) para saber mais sobre fluxos de entrada.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[basic_istream](#basic_istream)|Constrói um objeto do tipo `basic_istream`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[gcount](#gcount)|Retorna o número de caracteres lidos durante a última entrada sem formatação.|  
|[get](#get)|Lê um ou mais caracteres do fluxo de entrada.|  
|[getline](#getline)|Lê uma linha do fluxo de entrada.|  
|[ignore](#ignore)|Faz vários elementos serem ignorados na posição de leitura atual.|  
|[peek](#peek)|Retorna o próximo caractere a ser lido.|  
|[putback](#putback)|Coloca um caractere especificado no fluxo.|  
|[read](#read)|Lê um número especificado de caracteres do fluxo e armazena-os em uma matriz.|  
|[readsome](#readsome)|Ler apenas do buffer.|  
|[seekg](#seekg)|Move a posição de leitura em um fluxo.|  
|[sentry](#sentry)|A classe aninhada descreve um objeto cuja declaração estrutura as funções de entrada formatadas e as funções de entrada não formatadas.|  
|[swap](#swap)|Troca esse objeto `basic_istream` pelo parâmetro do objeto `basic_istream` fornecido.|  
|[sync](#sync)|Sincroniza o dispositivo de entrada associado ao fluxo com o buffer do fluxo.|  
|[tellg](#tellg)|Relata a atual posição de leitura no fluxo.|  
|[unget](#unget)|Coloca o caractere lido mais recentemente de volta no fluxo.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator>>](#op_gt_gt)|Chama uma função no fluxo de entrada ou lê dados formatados do fluxo de entrada.|  
|[operator=](#op_eq)|Atribui o `basic_istream` no lado direito do operador para esse objeto. Essa é uma atribuição de movimentação que envolve uma referência `rvalue` que não deixa uma cópia.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<istream>  
  
 **Namespace:** std  
  
##  <a name="basic_istream"></a>  basic_istream::basic_istream  
 Constrói um objeto do tipo `basic_istream`.  
  
```  
explicit basic_istream(
    basic_streambuf<Elem, Tr>* strbuf,  
    bool _Isstd = false);

basic_istream(basic_istream&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `strbuf`  
 Um objeto do tipo [basic_streambuf](../standard-library/basic-streambuf-class.md).  
  
 `_Isstd`  
 `true` se esse for um fluxo padrão; caso contrário, `false`.  
  
 `right`  
 Um objeto `basic_istream` a ser copiado.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa a classe base chamando [init](../standard-library/basic-ios-class.md#init)(_S `trbuf`). Ele também armazena zero na contagem de extração. Para obter mais informações sobre essa contagem de extração, consulte a seção Comentários do tópico de visão geral da [Classe basic_istream](../standard-library/basic-istream-class.md).  
  
 O segundo construtor inicializa a classe base chamando `move( right)`. Ele também armazena _R `ight.gcount()` na contagem de extração e armazena zero na contagem de extração para _R `ight`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo de [basic_ifstream::basic_ifstream](../standard-library/basic-ifstream-class.md#basic_ifstream) para saber mais sobre fluxos de entrada.  
  
##  <a name="gcount"></a>  basic_istream::gcount  
 Retorna o número de caracteres lidos durante a última entrada sem formatação.  
  
```  
streamsize gcount() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de extração.  
  
### <a name="remarks"></a>Comentários  
 Use [basic_istream::get](#get) para ler caracteres sem formatação.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_gcount.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main( )   
{  
   cout << "Type the letter 'a': ";  
  
   ws( cin );  
   char c[10];  
  
   cin.get( &c[0],9 );  
   cout << c << endl;  
  
   cout << cin.gcount( ) << endl;  
}  
```  
  
```Output  
  
a  
  
```  
  
```Output  
  
      aType the letter 'a':  
a  
1  
```  
  
##  <a name="get"></a>  basic_istream::get  
 Lê um ou mais caracteres do fluxo de entrada.  
  
```  
int_type get();

basic_istream<Elem, Tr>& get(Elem& Ch);
basic_istream<Elem, Tr>& get(Elem* str, streamsize count);
basic_istream<Elem, Tr>& get(Elem* str, streamsize count, Elem Delim);

basic_istream<Elem, Tr>& get(basic_streambuf<Elem, Tr>& strbuf);
basic_istream<Elem, Tr>& get(basic_streambuf<Elem, Tr>& strbuf, Elem Delim);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O número de caracteres a serem lidos de `strbuf`.  
  
 `Delim`  
 O caractere que deve terminar a leitura se for encontrado antes de `count`.  
  
 `str`  
 Uma cadeia de caracteres na qual gravar.  
  
 `Ch`  
 Um caractere a obter.  
  
 `strbuf`  
 Um buffer no qual gravar.  
  
### <a name="return-value"></a>Valor de retorno  
 O formulário sem parâmetros de get retorna o elemento read como um inteiro ou fim do arquivo. Os formulários restantes retornaram o fluxo (* `this`).  
  
### <a name="remarks"></a>Comentários  
 A primeira dessas funções de entrada não formatadas extrai um elemento, se possível, como se estivesse retornando `rdbuf`-> `sbumpc`. Caso contrário, retornará **traits_type::**[eof](../standard-library/char-traits-struct.md#eof). Se a função não extrair nenhum elemento, ela chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**).  
  
 A segunda função extrai o elemento [int_type](../standard-library/basic-ios-class.md#int_type) `meta` da mesma maneira. Se `meta` for comparável a **traits_type::eof**, a função chamará `setstate`( **failbit**). Caso contrário, armazenará **traits_type::**[to_char_type](../standard-library/char-traits-struct.md#to_char_type)( `meta`) em `Ch`. A função retorna **\*this**.  
  
 Retorna a terceira função **obter**(_ *Str*, `count`, `widen`('\  **n** ')).  
  
 A quarta função extrai até `count` – 1 elementos e armazena-os na matriz que começa em _ *Str*. Ela sempre armazena `char_type` após quaisquer elementos extraídos que armazene. Em ordem de teste, a extração é interrompida:  
  
-   Ao final do arquivo.  
  
-   Depois que a função extrai um elemento que é comparável a `Delim`, caso em que o elemento é colocado de volta na sequência controlada.  
  
-   Depois que a função extrai `count` – 1 elementos.  
  
 Se a função não extrair nenhum elemento, chamará `setstate`( **failbit**). Em qualquer caso, ele retorna **\*this**.  
  
 Retorna a função quinto **obter**( **strbuf**, `widen`('\  **n** ')).  
  
 A sexta função extrai elementos e insere-os em **strbuf**. A extração para no fim do arquivo ou em um elemento que é comparável a _ *Delim,* que não é extraído. Ele também interrompe, sem extrair o elemento em questão, se uma inserção falhar ou gerar uma exceção (que é detectada, mas não gerada novamente). Se a função não extrair nenhum elemento, chamará `setstate`( **failbit**). Em qualquer caso, a função retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_get.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main( )   
{  
   char c[10];  
  
   c[0] = cin.get( );  
   cin.get( c[1] );  
   cin.get( &c[2],3 );  
   cin.get( &c[4], 4, '7' );  
  
   cout << c << endl;  
}  
```  
  
```Output  
  
1111  
```  
  
##  <a name="getline"></a>  basic_istream::getline  
 Obtém uma linha do fluxo de entrada.  
  
```  
basic_istream<Elem, Tr>& getline(
    char_type* str,   
    streamsize count);

basic_istream<Elem, Tr>& getline(
    char_type* str,   
    streamsize count,   
    char_type Delim);
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O número de caracteres a serem lidos de **strbuf**.  
  
 `Delim`  
 O caractere que deve terminar a leitura se for encontrado antes de `count`.  
  
 `str`  
 Uma cadeia de caracteres na qual gravar.  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo (**\*isso**).  
  
### <a name="remarks"></a>Comentários  
 O primeiro deles não formatado de entrada retorna funções **getline**(_ *Str*, `count`, `widen`(' `\`  **n** ')).  
  
 A segunda função extrai até `count` – 1 elementos e armazena-os na matriz que começa em _ *Str*. Ela sempre armazena o caractere de terminação de cadeia de caracteres depois de quaisquer os elementos extraídos que ela armazene. Em ordem de teste, a extração é interrompida:  
  
-   Ao final do arquivo.  
  
-   Depois que a função extrai um elemento comparável a `Delim`, caso em que o elemento não é recolocado nem acrescentado à sequência controlada.  
  
-   Depois que a função extrai `count` – 1 elementos.  
  
 Se a função não extrair nenhum elemento ou `count` – 1 elementos, ela chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**). Em qualquer caso, ele retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_getline.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main( )   
{  
   char c[10];  
  
   cin.getline( &c[0], 5, '2' );  
   cout << c << endl;  
}  
```  
  
```Output  
  
121  
```  
  
##  <a name="ignore"></a>  basic_istream::ignore  
 Faz vários elementos serem ignorados na posição de leitura atual.  
  
```  
basic_istream<Elem, Tr>& ignore(
    streamsize count = 1,  
    int_type Delim = traits_type::eof());
```  
  
### <a name="parameters"></a>Parâmetros  
 `count`  
 O número de elementos a ignorar da posição atual de leitura.  
  
 `Delim`  
 O elemento que, se encontrado antes da contagem, faz com que **ignore** retorne, permitindo que todos os elementos após `Delim` sejam lidos.  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo (**\*isso**).  
  
### <a name="remarks"></a>Comentários  
 A função de entrada não formatada extrai até `count` elementos e descarta-os. Se `count` for igual a **numeric_limits\<int>::max**, no entanto, ela será considerada arbitrariamente grande. Extração interrompe no início no final do arquivo ou em um elemento `Ch` , de modo que **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#to_int_type)( `Ch`) compara igual a *Delim* (que também é extraído). A função retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_ignore.cpp  
// compile with: /EHsc  
#include <iostream>  
int main( )   
{  
   using namespace std;  
   char chararray[10];  
   cout << "Type 'abcdef': ";  
   cin.ignore( 5, 'c' );  
   cin >> chararray;  
   cout << chararray;  
}  
```  
  
```Output  
Type 'abcdef': abcdef  
def  
```  
  
##  <a name="op_gt_gt"></a>básico\_istream::operator >>
  
Chama uma função no fluxo de entrada ou lê dados formatados do fluxo de entrada.  
  
```  
basic_istream& operator>>(basic_istream& (* Pfn)(basic_istream&));
basic_istream& operator>>(ios_base& (* Pfn)(ios_base&));
basic_istream& operator>>(basic_ios<Elem, Tr>& (* Pfn)(basic_ios<Elem, Tr>&));  
basic_istream& operator>>(basic_streambuf<Elem, Tr>* strbuf);
basic_istream& operator>>(bool& val);
basic_istream& operator>>(short& val);
basic_istream& operator>>(unsigned short& val);
basic_istream& operator>>(int& val);
basic_istream& operator>>(unsigned int& val);
basic_istream& operator>>(long& val);
basic_istream& operator>>(unsigned long& val);
basic_istream& operator>>(long long& val);
basic_istream& operator>>(unsigned long long& val);
basic_istream& operator>>(void *& val);
basic_istream& operator>>(float& val);
basic_istream& operator>>(double& val);
basic_istream& operator>>(long double& val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Pfn`  
 Um ponteiro de função.  
  
 `strbuf`  
 Um objeto do tipo **stream_buf**.  
  
 `val`  
 O valor a ser lido do fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo (**\*isso**).  
  
### <a name="remarks"></a>Comentários  
 O cabeçalho `<istream>` também define vários operadores de extração global. Para obter mais informações, consulte [operator>> (\<istream>)](../standard-library/istream-operators.md#op_gt_gt).  
  
 A primeira função membro garante que uma expressão do formulário **istr** >> `ws` chame [ws](../standard-library/istream-functions.md#ws)( **istr**) e, em seguida, retorne  **\*this**. A segunda e a terceira funções garantem que outros manipuladores, como [hexa](../standard-library/ios-functions.md#hex), comportem-se de modo semelhante. As funções restantes constituem as funções de entrada formatadas.  
  
 A função:  
  
```  
basic_istream& operator>>(
    basic_streambuf<Elem, Tr>* strbuf);
```  
  
 extrai elementos se _ *Strbuf* não for um ponteiro nulo e insere-os em `strbuf`. A extração para no fim do arquivo. Ela também parará sem extrair o elemento em questão se uma inserção falhar ou gerar uma exceção (que é detectada, mas não gerada novamente). Se a função não extrair nenhum elemento, ela chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**). Em qualquer caso, a função retorna **\*this**.  
  
 A função:  
  
```  
basic_istream& operator>>(bool& val);
```  
  
 extrai um campo e converte-o em um valor Booliano chamando [use_facet](../standard-library/basic-filebuf-class.md#open) < `num_get`\< **Elem**, **InIt**>( [getloc](../standard-library/ios-base-class.md#getloc)). [get](../standard-library/ios-base-class.md#getloc)( **InIt**( [rdbuf](../standard-library/basic-ios-class.md#rdbuf)), `Init`(0), **\*this**, `getloc`, `val`). Aqui, **InIt** é definido como [istreambuf_iterator](../standard-library/istreambuf-iterator-class.md)\< **Elem**, **Tr**>. A função retorna **\*this**.  
  
 As funções:  
  
```  
basic_istream& operator>>(short& val);
basic_istream& operator>>(unsigned short& val);
basic_istream& operator>>(int& val);
basic_istream& operator>>(unsigned int& val);
basic_istream& operator>>(long& val);
basic_istream& operator>>(unsigned long& val); 
basic_istream& operator>>(long long& val);
basic_istream& operator>>(unsigned long long& val); 
basic_istream& operator>>(void *& val);
```  
  
 extraem cada uma um campo e convertem-no em um valor numérico chamando `use_facet`< `num_get`\< **Elem**, **InIt**>( `getloc`). [get](#get)( **InIt**( `rdbuf`), `Init`(0), **\*this**, `getloc`, `val`). Aqui, **InIt** é definido como `istreambuf_iterator` \< **Elem**, **Tr**>, e `val` tem tipo **longo**,`unsigned long`, ou **void \***  conforme necessário.  
  
 Se o valor convertido não puder ser representado como o tipo de `val`, a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**). Em qualquer caso, a função retorna **\*this**.  
  
 As funções:  
  
```  
basic_istream& operator>>(float& val);
basic_istream& operator>>(double& val);
basic_istream& operator>>(long double& val);
```  
  
 extraem cada uma um campo e convertem-no em um valor numérico chamando `use_facet`< `num_get`\< **Elem**, **InIt**>( `getloc`). **get**( **InIt**( `rdbuf`), `Init`(0), **\*this**, `getloc`, `val`). Aqui, **InIt** é definido como `istreambuf_iterator`\< **Elem**, **Tr**> e `val` tem o tipo **duplo** ou `long double`, conforme necessário.  
  
 Se o valor convertido não puder ser representado como o tipo de `val`, a função chamará `setstate`( **failbit**). Em qualquer caso, ele retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// istream_basic_istream_op_is.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
  
ios_base& hex2( ios_base& ib )   
{  
   ib.unsetf( ios_base::dec );  
   ib.setf( ios_base::hex );  
   return ib;  
}  
  
basic_istream<char, char_traits<char> >& somefunc(basic_istream<char, char_traits<char> > &i)  
{  
   if ( i == cin )   
   {  
      cerr << "i is cin" << endl;  
   }  
   return i;  
}  
  
int main( )   
{  
   int i = 0;  
   cin >> somefunc;  
   cin >> i;  
   cout << i << endl;  
   cin >> hex2;  
   cin >> i;  
   cout << i << endl;  
}  
```  
  
##  <a name="op_eq"></a>  basic_istream::operator=  
 Atribui o `basic_istream` no lado direito do operador para esse objeto. Essa é uma atribuição de movimentação que envolve uma referência `rvalue` que não deixa uma cópia.  
  
```  
basic_istream& operator=(basic_istream&& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 Uma referência `rvalue` a um objeto `basic_ifstream`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna *this.  
  
### <a name="remarks"></a>Comentários  
 O operador do membro chama `( right)` de troca.  
  
##  <a name="peek"></a>  basic_istream::peek  
 Retorna o próximo caractere a ser lido.  
  
```  
int_type peek();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O próximo caractere que será lido.  
  
### <a name="remarks"></a>Comentários  
 A função de entrada não formatada extrai um elemento, se possível, como se retornando por `rdbuf` -> [sgetc](../standard-library/basic-streambuf-class.md#sgetc). Caso contrário, retornará **traits_type::**[eof](../standard-library/char-traits-struct.md#eof).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_peek.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main( )   
{  
   char c[10], c2;  
   cout << "Type 'abcde': ";  
  
   c2 = cin.peek( );  
   cin.getline( &c[0], 9 );  
  
   cout << c2 << " " << c << endl;  
}  
```  
  
```Output  
  
abcde  
  
```  
  
```Output  
  
      abcdeType 'abcde': abcde  
a abcde  
```  
  
##  <a name="putback"></a>  basic_istream::putback  
 Coloca um caractere especificado no fluxo.  
  
```  
basic_istream<Elem, Tr>& putback(
    char_type Ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Ch`  
 Um caractere a colocar de volta no fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo (**\*isso**).  
  
### <a name="remarks"></a>Comentários  
 A [função de entrada não formatada](../standard-library/basic-istream-class.md) recoloca `Ch`, se possível, como se estivesse chamando [rdbuf](../standard-library/basic-ios-class.md#rdbuf)`->`[sputbackc](../standard-library/basic-streambuf-class.md#sputbackc). Se rdbuf for um ponteiro nulo ou se a chamada para `sputbackc` retornar **traits_type::**[eof](../standard-library/char-traits-struct.md#eof), a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **badbit**). Em qualquer caso, ele retorna **\*this**.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_putback.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main( )   
{  
   char c[10], c2, c3;  
  
   c2 = cin.get( );  
   c3 = cin.get( );  
   cin.putback( c2 );  
   cin.getline( &c[0], 9 );  
   cout << c << endl;  
}  
```  
  
```Output  
  
qwq  
```  
  
##  <a name="read"></a>  basic_istream::read  
 Lê um número especificado de caracteres do fluxo e armazena-os em uma matriz.  
  
 Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos.  
  
```  
basic_istream<Elem, Tr>& read(
    char_type* str,   
    streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 A matriz na qual ler os caracteres.  
  
 `count`  
 O número de caracteres a serem lidos.  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo ( `*this`).  
  
### <a name="remarks"></a>Comentários  
 A função de entrada não formatada extrai até `count` elementos e armazena-os no início da matriz em _ `Str`. A extração para cedo no fim do arquivo, caso em que a função chama [setstate](../standard-library/basic-ios-class.md#setstate)( `failbit`). Em qualquer caso, retorna `*this`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_read.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main()  
{  
    char c[10];  
    int count = 5;  
  
    cout << "Type 'abcde': ";  
  
    // Note: cin::read is potentially unsafe, consider  
    // using cin::_Read_s instead.  
    cin.read(&c[0], count);  
    c[count] = 0;  
  
    cout << c << endl;  
}  
```  
  
```Output  
  
abcde  
  
```  
  
```Output  
  
      abcdeType 'abcde': abcde  
abcde  
```  
  
##  <a name="readsome"></a>  basic_istream::readsome  
 Lê o número especificado de valores de caractere.  
  
 Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos.  
  
```  
streamsize readsome(
    char_type* str,  
    streamsize count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `str`  
 A matriz na qual `readsome` armazena os caracteres que lê.  
  
 `count`  
 O número de caracteres a serem lidos.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres realmente lidos, [gcount](#gcount).  
  
### <a name="remarks"></a>Comentários  
 Essa função de entrada não formatada extrai até `count` elementos do fluxo de entrada e armazena-os na matriz `str`.  
  
 Essa função não aguarda entrada. Ela lê os dados que estão disponíveis.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_readsome.cpp  
// compile with: /EHsc /W3  
#include <iostream>  
using namespace std;  
  
int main( )  
{  
   char c[10];  
   int count = 5;  
  
   cout << "Type 'abcdefgh': ";  
  
   // cin.read blocks until user types input.  
   // Note: cin::read is potentially unsafe, consider  
   // using cin::_Read_s instead.  
   cin.read(&c[0], 2);  
  
   // Note: cin::readsome is potentially unsafe, consider  
   // using cin::_Readsome_s instead.  
   int n = cin.readsome(&c[0], count);  // C4996  
   c[n] = 0;  
   cout << n << " characters read" << endl;  
   cout << c << endl;  
}  
```  
  
##  <a name="seekg"></a>  basic_istream::seekg  
 Move a posição de leitura em um fluxo.  
  
```  
basic_istream<Elem, Tr>& seekg(pos_type pos);

basic_istream<Elem, Tr>& seekg(off_type off, ios_base::seekdir way);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 A posição absoluta na qual mover o ponteiro de leitura.  
  
 `off`  
 Um deslocamento para mover o ponteiro de leitura com relação a `way`.  
  
 `way`  
 Uma das enumerações de [ios_base::seekdir](../standard-library/ios-base-class.md#seekdir).  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo (**\*isso**).  
  
### <a name="remarks"></a>Comentários  
 A primeira função membro realiza uma busca absoluta, a segunda função membro executa uma busca relativa.  
  
> [!NOTE]
>  Não use a segunda função membro com arquivos de texto, porque C++ Padrão não dá suporte a buscas relativas em arquivos de texto.  
  
 Se [fail](../standard-library/basic-ios-class.md#fail) for false, a primeira função membro chamará **newpos** = [rdbuf](../standard-library/basic-ios-class.md#rdbuf) -> [pubseekpos](../standard-library/basic-streambuf-class.md#pubseekpos)( `pos`), para algum objeto temporário **pos_type** **newpos**. Se **fail** for false, a segunda função chamará **newpos** = **rdbuf** -> [pubseekoff](../standard-library/basic-streambuf-class.md#pubseekoff)( `off`, `way`). Em ambos os casos, se ( `off_type`) **newpos** == ( `off_type`)(-1) (a operação de posicionamento falhar), a função chamará **istr**. [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**). Ambas as funções retornam **\*this**.  
  
 Se [fail](../standard-library/basic-ios-class.md#fail) for true, as funções membro não farão nada.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_seekg.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main ( )   
{  
   using namespace std;  
   ifstream file;  
   char c, c1;  
  
   file.open( "basic_istream_seekg.txt" );  
   file.seekg(2);   // seek to position 2  
   file >> c;  
   cout << c << endl;  
}  
```  
  
##  <a name="sentry"></a>  basic_istream::sentry  
 A classe aninhada descreve um objeto cuja declaração estrutura as funções de entrada formatadas e não formatadas.  
  
class sentry {  
   public:  
   explicit sentry( basic_istream\<Elem, Tr>& _Istr,  
   bool _Noskip = false); operator bool() const; };  
  
### <a name="remarks"></a>Comentários  
 Se `_Istr.`[good](../standard-library/basic-ios-class.md#good) for true, o construtor:  
  
-   Chama `_Istr`. [tie](../standard-library/basic-ios-class.md#tie) -> [flush](../standard-library/basic-ostream-class.md#flush) se `_Istr`. `tie` não é um ponteiro nulo  
  
-   Efetivamente chama [ws](../standard-library/istream-functions.md#ws)( `_Istr`) se `_Istr`. [flags](../standard-library/ios-base-class.md#flags)**&**[skipws](../standard-library/ios-functions.md#skipws) é diferente de zero  
  
 Se, depois de qualquer preparação assim, `_Istr`. **good** for false, o construtor chamará `_Istr`. [setstate](../standard-library/basic-ios-class.md#setstate)( **failbit**). Em qualquer caso, o construtor armazena o valor retornado por `_Istr`. **good** no **status**. Uma chamada posterior a **operador bool** entrega esse valor armazenado.  
  
##  <a name="swap"></a>  basic_istream::swap  
 Troca o conteúdo de dois `basic_istream` objetos.  
  
```  
void swap(basic_istream& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 Uma referência lvalue a um objeto `basic_istream`.  
  
### <a name="remarks"></a>Comentários  
 A função membro chama [basic_ios::swap](../standard-library/basic-ios-class.md#swap)`(right)`. Ela também troca a contagem de extração com a contagem de extração para `right`.  
  
##  <a name="sync"></a>  basic_istream::sync  
 Sincroniza o dispositivo de entrada associado ao fluxo com o buffer do fluxo.  
  
```  
int sync();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se [rdbuf](../standard-library/basic-ios-class.md#rdbuf) for um ponteiro nulo, a função retornará -1. Caso contrário, chamará `rdbuf` -> [pubsync](../standard-library/basic-streambuf-class.md#pubsync). Se isso retornar -1, a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **badbit**) e retornará -1. Caso contrário, a função retorna zero.  
  
##  <a name="tellg"></a>  basic_istream::tellg  
 Relata a atual posição de leitura no fluxo.  
  
```  
pos_type tellg();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição atual no fluxo.  
  
### <a name="remarks"></a>Comentários  
 Se [fail](../standard-library/basic-ios-class.md#fail) for false, a função membro retornará [rdbuf](../standard-library/basic-ios-class.md#rdbuf) -> [pubseekoff](../standard-library/basic-streambuf-class.md#pubseekoff)(0, `cur`, **in**). Caso contrário, retornará `pos_type`(-1).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_tellg.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main()  
{  
    using namespace std;  
    ifstream file;  
    char c;  
    streamoff i;  
  
    file.open("basic_istream_tellg.txt");  
    i = file.tellg();  
    file >> c;  
    cout << c << " " << i << endl;  
  
    i = file.tellg();  
    file >> c;  
    cout << c << " " << i << endl;  
}  
```  
  
##  <a name="unget"></a>  basic_istream::unget  
 Coloca o caractere lido mais recentemente de volta no fluxo.  
  
```  
basic_istream<Elem, Tr>& unget();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O fluxo (**\*isso**).  
  
### <a name="remarks"></a>Comentários  
 A [função de entrada não formatada](../standard-library/basic-istream-class.md) coloca o elemento anterior de volta no fluxo, se possível, como se estivesse chamando `rdbuf` -> [sungetc](../standard-library/basic-streambuf-class.md#sungetc). Se [rdbuf](../standard-library/basic-ios-class.md#rdbuf) for um ponteiro nulo ou se a chamada para `sungetc` retornar **traits_type::**[eof](../standard-library/basic-ios-class.md#eof), a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **badbit**). Em qualquer caso, ele retorna **\*this**.  
  
 Para obter informações sobre como `unget` poderia falhar, consulte [basic_streambuf::sungetc](../standard-library/basic-streambuf-class.md#sungetc).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// basic_istream_unget.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
int main( )   
{  
   char c[10], c2;  
  
   cout << "Type 'abc': ";  
   c2 = cin.get( );  
   cin.unget( );  
   cin.getline( &c[0], 9 );  
   cout << c << endl;  
}  
```  
  
```Output  
  
abc  
  
```  
  
```Output  
  
      abcType 'abc': abc  
abc  
```  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)

