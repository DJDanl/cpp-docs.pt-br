---
title: Classe basic_istream
ms.date: 11/04/2016
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
ms.openlocfilehash: da53db594e057449f2d227f57c902d26396000b7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219242"
---
# <a name="basic_istream-class"></a>Classe basic_istream

Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo com elementos do tipo `Char_T`, também conhecido como [char_type](../standard-library/basic-ios-class.md#char_type), cujas características de caractere são determinadas pela classe *Tr*, também conhecida como [traits_type](../standard-library/basic-ios-class.md#traits_type).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Char_T, class Tr = char_traits<Char_T>>
class basic_istream : virtual public basic_ios<Char_T, Tr>
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

Ambos os grupos de funções chamam [`setstate`](../standard-library/basic-ios-class.md#setstate) `(eofbit)` se eles encontrarem o final do arquivo durante a extração de elementos.

Um objeto de `basic_istream<Char_T, Tr>` armazenamentos de classe:

- Um objeto base público virtual da classe [`basic_ios`](../standard-library/basic-ios-class.md) `<Char_T, Tr>` .

- Uma contagem de extração para a última operação de entrada não formatada (chamada `count` no código anterior).

## <a name="example"></a>Exemplo

Veja o exemplo de [Classe basic_ifstream](../standard-library/basic-ifstream-class.md) para saber mais sobre fluxos de entrada.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_istream](#basic_istream)|Constrói um objeto do tipo `basic_istream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[gcount](#gcount)|Retorna o número de caracteres lidos durante a última entrada sem formatação.|
|[get](#get)|Lê um ou mais caracteres do fluxo de entrada.|
|[getline](#getline)|Lê uma linha do fluxo de entrada.|
|[ignorar](#ignore)|Faz vários elementos serem ignorados na posição de leitura atual.|
|[piada](#peek)|Retorna o próximo caractere a ser lido.|
|[putback](#putback)|Coloca um caractere especificado no fluxo.|
|[leitura](#read)|Lê um número especificado de caracteres do fluxo e armazena-os em uma matriz.|
|[readsome](#readsome)|Ler apenas do buffer.|
|[seekg](#seekg)|Move a posição de leitura em um fluxo.|
|[sentry](#sentry)|A classe aninhada descreve um objeto cuja declaração estrutura as funções de entrada formatadas e as funções de entrada não formatadas.|
|[permuta](#swap)|Troca esse objeto `basic_istream` pelo parâmetro do objeto `basic_istream` fornecido.|
|[sincronizá](#sync)|Sincroniza o dispositivo de entrada associado do fluxo com o buffer do fluxo.|
|[tellg](#tellg)|Relata a atual posição de leitura no fluxo.|
|[unget](#unget)|Coloca o caractere lido mais recentemente de volta no fluxo.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[>>do operador](#op_gt_gt)|Chama uma função no fluxo de entrada ou lê dados formatados do fluxo de entrada.|
|[operador =](#op_eq)|Atribui o `basic_istream` no lado direito do operador para esse objeto. É uma atribuição de movimentação que envolve uma `rvalue` referência que não deixa uma cópia para trás.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<istream>

**Namespace:** std

## <a name="basic_istreambasic_istream"></a><a name="basic_istream"></a>basic_istream:: basic_istream

Constrói um objeto do tipo `basic_istream`.

```cpp
explicit basic_istream(
    basic_streambuf<Char_T, Tr>* strbuf,
    bool _Isstd = false);

basic_istream(basic_istream&& right);
```

### <a name="parameters"></a>parâmetros

*strbuf*\
Um objeto do tipo [basic_streambuf](../standard-library/basic-streambuf-class.md).

*_Isstd*\
**`true`** Se for um fluxo padrão; caso contrário, **`false`** .

*Certo*\
Um objeto `basic_istream` a ser copiado.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa a classe base chamando [`init`](../standard-library/basic-ios-class.md#init) `(strbuf)` . Ele também armazena zero na contagem de extração. Para obter mais informações sobre essa contagem de extração, consulte a seção comentários da visão geral da [classe basic_istream](../standard-library/basic-istream-class.md) .

O segundo construtor inicializa a classe base chamando `move(right)`. Ele também armazena `right.gcount()` na contagem de extração e armazena zero na contagem de extração para * direita * *.

### <a name="example"></a>Exemplo

Consulte o exemplo de [basic_ifstream::basic_ifstream](../standard-library/basic-ifstream-class.md#basic_ifstream) para saber mais sobre fluxos de entrada.

## <a name="basic_istreamgcount"></a><a name="gcount"></a>basic_istream:: gCount

Retorna o número de caracteres lidos durante a última entrada sem formatação.

```cpp
streamsize gcount() const;
```

### <a name="return-value"></a>Valor retornado

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

```Input
a
```

```Output
Type the letter 'a': a
1
```

## <a name="basic_istreamget"></a><a name="get"></a>basic_istream:: Get

Lê um ou mais caracteres do fluxo de entrada.

```cpp
int_type get();

basic_istream<Char_T, Tr>& get(Char_T& Ch);
basic_istream<Char_T, Tr>& get(Char_T* str, streamsize count);
basic_istream<Char_T, Tr>& get(Char_T* str, streamsize count, Char_T delimiter);

basic_istream<Char_T, Tr>& get(basic_streambuf<Char_T, Tr>& strbuf);
basic_istream<Char_T, Tr>& get(basic_streambuf<Char_T, Tr>& strbuf, Char_T delimiter);
```

### <a name="parameters"></a>parâmetros

*contar*\
O número de caracteres a serem lidos de *strbuf*.

*delimitador*\
O caractere que deve terminar a leitura se for encontrado antes da *contagem*.

*Str*\
Uma cadeia de caracteres na qual gravar.

*CH*\
Um caractere a obter.

*strbuf*\
Um buffer no qual gravar.

### <a name="return-value"></a>Valor retornado

O formulário sem parâmetros de get retorna o elemento read como um inteiro ou fim do arquivo. Os formulários restantes retornam o fluxo (* **`this`** ).

### <a name="remarks"></a>Comentários

A primeira função de entrada não formatada extrai um elemento, se possível, como se retornar `rdbuf->sbumpc` . Caso contrário, retornará `traits_type::` [`eof`](../standard-library/char-traits-struct.md#eof) . Se a função extrair nenhum elemento, ele chamará [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)` .

A segunda função extrai o elemento [int_type](../standard-library/basic-ios-class.md#int_type)`meta` da mesma maneira. Se `meta` comparar igual a `traits_type::eof` , a função chama `setstate(failbit)` . Caso contrário, ele será armazenado `traits_type::` [`to_char_type`](../standard-library/char-traits-struct.md#to_char_type) `(meta)` em *ch*. A função retorna __* isso__.

A terceira função retorna `get(str, count, widen('\n'))` .

A quarta função extrai até `count - 1` elementos e armazena-os na matriz, começando em *Str*. Ela sempre armazena `char_type` após quaisquer elementos extraídos que armazene. Em ordem de teste, a extração é interrompida:

- Ao final do arquivo.

- Depois que a função extrai um elemento que compara igual ao *delimitador*. Nesse caso, o elemento é colocado de volta para a sequência controlada.

- Depois que a função extrai `count - 1` elementos.

Se a função não extrair nenhum elemento, ela chamará `setstate(failbit)`. Em qualquer caso, ele retorna __*__.

A quinta função retorna `get(strbuf, widen('\n'))` .

A sexta função extrai elementos e insere-os em *strbuf*. A extração é interrompida no fim do arquivo ou em um elemento que compara o mesmo que o *delimitador*, que não é extraído. Ele também interrompe, sem extrair o elemento em questão, se uma inserção falhar ou gerar uma exceção (que é detectada, mas não gerada novamente). Se a função não extrair nenhum elemento, ela chamará `setstate(failbit)`. Em qualquer caso, a função retorna __*__.

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

## <a name="basic_istreamgetline"></a><a name="getline"></a>basic_istream:: getline

Obtém uma linha do fluxo de entrada.

```cpp
basic_istream<Char_T, Tr>& getline(
    char_type* str,
    streamsize count);

basic_istream<Char_T, Tr>& getline(
    char_type* str,
    streamsize count,
    char_type delimiter);
```

### <a name="parameters"></a>parâmetros

*contar*\
O número de caracteres a serem lidos de *strbuf*.

*delimitador*\
O caractere que deve terminar a leitura se for encontrado antes da *contagem*.

*Str*\
Uma cadeia de caracteres na qual gravar.

### <a name="return-value"></a>Valor retornado

O fluxo (__* isso__).

### <a name="remarks"></a>Comentários

A primeira dessas funções de entrada não formatadas retorna `getline(str, count, widen('\n'))` .

A segunda função extrai até `count - 1` elementos e os armazena na matriz, começando em *Str*. Ela sempre armazena o caractere de terminação de cadeia de caracteres depois de quaisquer os elementos extraídos que ela armazene. Em ordem de teste, a extração é interrompida:

- Ao final do arquivo.

- Depois que a função extrai um elemento que compara igual ao *delimitador*. Nesse caso, o elemento não é colocado de volta e não é acrescentado à sequência controlada.

- Depois que a função extrai `count - 1` elementos.

Se a função extrair nenhum elemento ou `count - 1` elemento, ela chamará [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)` . Em qualquer caso, ele retorna __*__.

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

## <a name="basic_istreamignore"></a><a name="ignore"></a>basic_istream:: ignorar

Faz vários elementos serem ignorados na posição de leitura atual.

```cpp
basic_istream<Char_T, Tr>& ignore(
    streamsize count = 1,
    int_type delimiter = traits_type::eof());
```

### <a name="parameters"></a>parâmetros

*contar*\
O número de elementos a ignorar da posição atual de leitura.

*delimitador*\
O elemento que, se encontrado antes da contagem, faz com que o `ignore` retorne e permita que todos os elementos após o *delimitador* sejam lidos.

### <a name="return-value"></a>Valor retornado

O fluxo (__* isso__).

### <a name="remarks"></a>Comentários

A função de entrada não formatada extrai até elementos de *contagem* e os descarta. No entanto, se *Count* for igual a for `numeric_limits<int>::max` considerado arbitrariamente grande. A extração pára no final do arquivo ou em um elemento `Ch` , de modo a `traits_type::` [`to_int_type`](../standard-library/char-traits-struct.md#to_int_type) `(Ch)` comparar igual ao *delimitador* (que também é extraído). A função retorna __* isso__.

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

## <a name="basic_istreamoperator"></a><a name="op_gt_gt"></a>\_operador básico IStream:: operator>>

Chama uma função no fluxo de entrada ou lê dados formatados do fluxo de entrada.

```cpp
basic_istream& operator>>(basic_istream& (* Pfn)(basic_istream&));
basic_istream& operator>>(ios_base& (* Pfn)(ios_base&));
basic_istream& operator>>(basic_ios<Char_T, Tr>& (* Pfn)(basic_ios<Char_T, Tr>&));
basic_istream& operator>>(basic_streambuf<Char_T, Tr>* strbuf);
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

### <a name="parameters"></a>parâmetros

*PFN*\
Um ponteiro de função.

*strbuf*\
Um objeto do tipo `stream_buf`.

*Val*\
O valor a ser lido do fluxo.

### <a name="return-value"></a>Valor retornado

O fluxo (__* isso__).

### <a name="remarks"></a>Comentários

O cabeçalho \<istream> também define vários operadores de extração global. Para obter mais informações, consulte [operator>>  ( \<istream> )](../standard-library/istream-operators.md#op_gt_gt).

A primeira função de membro garante que uma expressão do formulário `istr >> ws` chame [`ws`](../standard-library/istream-functions.md#ws) `(istr)` e, em seguida, retorna __* isso__. A segunda e terceira funções garantem que outros manipuladores, como [`hex`](../standard-library/ios-functions.md#hex) , se comportem de forma semelhante. As funções restantes são as funções de entrada formatadas.

A função:

```cpp
basic_istream& operator>>(
    basic_streambuf<Char_T, Tr>* strbuf);
```

extrai elementos, se *strbuf* não for um ponteiro nulo e os inserir em *strbuf*. A extração para no fim do arquivo. Ela também parará sem extrair o elemento em questão se uma inserção falhar ou gerar uma exceção (que é detectada, mas não gerada novamente). Se a função extrair nenhum elemento, ela chamará [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)` . Em qualquer caso, a função retorna __*__.

A função:

```cpp
basic_istream& operator>>(bool& val);
```

extrai um campo e o converte em um valor booliano chamando [`use_facet`](../standard-library/basic-filebuf-class.md#open) `< num_get<Char_T, InIt>(` [`getloc`](../standard-library/ios-base-class.md#getloc) `).` [`get`](../standard-library/ios-base-class.md#getloc) `( InIt(` [`rdbuf`](../standard-library/basic-ios-class.md#rdbuf) `), Init(0), *this, getloc, val)` . Aqui, `InIt` é definido como [`istreambuf_iterator`](../standard-library/istreambuf-iterator-class.md) `<Char_T, Tr>` . A função retorna __* isso__.

Cada uma das funções:

```cpp
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

Extraia um campo e converta-o em um valor numérico chamando `use_facet<num_get<Char_T, InIt>(getloc).` [`get`](#get) `(InIt(rdbuf), Init(0), *this, getloc, val)` . Aqui, `InIt` é definido como `istreambuf_iterator<Char_T, Tr>` , e *Val* tem tipo **`long`** , **`unsigned long`** ou **`void`** <strong>\*</strong> conforme necessário.

Se o valor convertido não puder ser representado como o tipo de *Val*, a função chamará [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)` . Em qualquer caso, a função retorna __*__.

Cada uma das funções:

```cpp
basic_istream& operator>>(float& val);
basic_istream& operator>>(double& val);
basic_istream& operator>>(long double& val);
```

Extraia um campo e converta-o em um valor numérico chamando `use_facet<num_get<Char_T, InIt>(getloc).get(InIt(rdbuf), Init(0), *this, getloc, val)` . Aqui, `InIt` é definido como `istreambuf_iterator<Char_T, Tr>` , e *Val* tem tipo **`double`** ou **`long double`** conforme necessário.

Se o valor convertido não puder ser representado como o tipo de *Val*, a função chamará `setstate(failbit)` . Em qualquer caso, ele retorna __*__.

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

## <a name="basic_istreamoperator"></a><a name="op_eq"></a>basic_istream:: Operator =

Atribui o `basic_istream` no lado direito do operador para esse objeto. É uma atribuição de movimentação que envolve uma `rvalue` referência que não deixa uma cópia para trás.

```cpp
basic_istream& operator=(basic_istream&& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
Uma referência `rvalue` a um objeto `basic_ifstream`.

### <a name="return-value"></a>Valor retornado

Retorna __* isso__.

### <a name="remarks"></a>Comentários

As chamadas de operador de membro `swap(right)` .

## <a name="basic_istreampeek"></a><a name="peek"></a>basic_istream::p o EEK

Retorna o próximo caractere a ser lido.

```cpp
int_type peek();
```

### <a name="return-value"></a>Valor retornado

O próximo caractere que será lido.

### <a name="remarks"></a>Comentários

A função de entrada não formatada extrai um elemento, se possível, como se retornar `rdbuf->` [`sgetc`](../standard-library/basic-streambuf-class.md#sgetc) . Caso contrário, retornará `traits_type::` [`eof`](../standard-library/char-traits-struct.md#eof) .

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

```Input
abcde
```

```Output
Type 'abcde': abcde
a abcde
```

## <a name="basic_istreamputback"></a><a name="putback"></a>basic_istream::p utback

Coloca um caractere especificado no fluxo.

```cpp
basic_istream<Char_T, Tr>& putback(
    char_type Ch);
```

### <a name="parameters"></a>parâmetros

*CH*\
Um caractere a colocar de volta no fluxo.

### <a name="return-value"></a>Valor retornado

O fluxo (__* isso__).

### <a name="remarks"></a>Comentários

A [função de entrada não formatada](../standard-library/basic-istream-class.md) retorna *ch*, se possível, como se chamar [`rdbuf`](../standard-library/basic-ios-class.md#rdbuf) `->` [`sputbackc`](../standard-library/basic-streambuf-class.md#sputbackc) . Se `rdbuf` for um ponteiro nulo ou se a chamada para `sputbackc` retornar `traits_type::` [`eof`](../standard-library/char-traits-struct.md#eof) , a função chamará [`setstate`](../standard-library/basic-ios-class.md#setstate) `(badbit)` . Em qualquer caso, ele retorna __*__.

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

## <a name="basic_istreamread"></a><a name="read"></a>basic_istream:: ler

Lê um número especificado de caracteres do fluxo e armazena-os em uma matriz.

Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos.

```cpp
basic_istream<Char_T, Tr>& read(
    char_type* str,
    streamsize count);
```

### <a name="parameters"></a>parâmetros

*Str*\
A matriz na qual ler os caracteres.

*contar*\
O número de caracteres a serem lidos.

### <a name="return-value"></a>Valor retornado

O fluxo ( **`*this`** ).

### <a name="remarks"></a>Comentários

A função de entrada não formatada extrai até elementos de *contagem* e os armazena na matriz, começando em *Str*. A extração pára no final do arquivo e, nesse caso, a função é chamada [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)` . Em qualquer caso, ele retorna __*__.

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

```Input
abcde
```

```Output
Type 'abcde': abcde
abcde
```

## <a name="basic_istreamreadsome"></a><a name="readsome"></a>basic_istream:: readsome

Lê o número especificado de valores de caractere.

Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos.

```cpp
streamsize readsome(
    char_type* str,
    streamsize count);
```

### <a name="parameters"></a>parâmetros

*Str*\
A matriz na qual `readsome` armazena os caracteres que lê.

*contar*\
O número de caracteres a serem lidos.

### <a name="return-value"></a>Valor retornado

O número de caracteres realmente lidos, [`gcount`](#gcount) .

### <a name="remarks"></a>Comentários

Essa função de entrada não formatada extrai os elementos de *contagem* do fluxo de entrada e os armazena no *Str*de matriz.

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

## <a name="basic_istreamseekg"></a><a name="seekg"></a>basic_istream:: seekg

Move a posição de leitura em um fluxo.

```cpp
basic_istream<Char_T, Tr>& seekg(pos_type pos);

basic_istream<Char_T, Tr>& seekg(off_type off, ios_base::seekdir way);
```

### <a name="parameters"></a>parâmetros

*pos*\
A posição absoluta na qual mover o ponteiro de leitura.

*desconto*\
Um deslocamento para mover o ponteiro de leitura em relação ao *caminho*.

*aparência*\
Uma das enumerações de [ios_base::seekdir](../standard-library/ios-base-class.md#seekdir).

### <a name="return-value"></a>Valor retornado

O fluxo (__* isso__).

### <a name="remarks"></a>Comentários

A primeira função membro realiza uma busca absoluta, a segunda função membro executa uma busca relativa.

> [!NOTE]
> Não use a segunda função membro com arquivos de texto, porque C++ Padrão não dá suporte a buscas relativas em arquivos de texto.

Se [`fail`](../standard-library/basic-ios-class.md#fail) for false, a primeira função de membro chamará `newpos =` [`rdbuf`](../standard-library/basic-ios-class.md#rdbuf) `->` [`pubseekpos`](../standard-library/basic-streambuf-class.md#pubseekpos) `(pos)` , para algum `pos_type` objeto temporário `newpos` . Se `fail` for false, a segunda função será chamada `newpos = rdbuf->` [`pubseekoff`](../standard-library/basic-streambuf-class.md#pubseekoff) `( off, way)` . Em ambos os casos, se `(off_type)newpos == (off_type)(-1)` (a operação de posicionamento falhar), as chamadas de função `istr.` [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)` . Ambas as funções retornam __*__.

Se [`fail`](../standard-library/basic-ios-class.md#fail) for true, as funções de membro não farão nada.

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

## <a name="basic_istreamsentry"></a><a name="sentry"></a>basic_istream:: Sentry

A classe aninhada descreve um objeto cuja declaração estrutura as funções de entrada formatadas e não formatadas.

```cpp
class sentry {
   public:
   explicit sentry(
      basic_istream<Char_T, Tr>& _Istr,
      bool _Noskip = false);
   operator bool() const;
   };
```

### <a name="remarks"></a>Comentários

Se `_Istr.` [`good`](../standard-library/basic-ios-class.md#good) for true, o construtor:

- Chama `_Istr.` [`tie`](../standard-library/basic-ios-class.md#tie) `->` [`flush`](../standard-library/basic-ostream-class.md#flush) se `_Istr.tie` não é um ponteiro nulo.

- Chama efetivamente [`ws`](../standard-library/istream-functions.md#ws) `(_Istr)` se `_Istr.` [`flags`](../standard-library/ios-base-class.md#flags) `&` [`skipws`](../standard-library/ios-functions.md#skipws) é diferente de zero.

Se depois de qualquer preparação, `_Istr.good` for false, o Construtor chamará `_Istr.` [`setstate`](../standard-library/basic-ios-class.md#setstate) `(failbit)` . Em qualquer caso, o Construtor armazena o valor retornado por `_Istr.good` no `status` . Uma chamada posterior para `operator bool` entrega esse valor armazenado.

## <a name="basic_istreamswap"></a><a name="swap"></a>basic_istream:: swap

Troca o conteúdo de dois `basic_istream` objetos.

```cpp
void swap(basic_istream& right);
```

### <a name="parameters"></a>parâmetros

*Certo*\
Uma referência lvalue a um objeto `basic_istream`.

### <a name="remarks"></a>Comentários

As chamadas de função de membro [`basic_ios::swap`](../standard-library/basic-ios-class.md#swap) `(right)` . Ele também troca a contagem de extração com a contagem de extração para *direita*.

## <a name="basic_istreamsync"></a><a name="sync"></a>basic_istream:: Sync

Sincroniza o dispositivo de entrada associado do fluxo com o buffer do fluxo.

```cpp
int sync();
```

### <a name="return-value"></a>Valor retornado

Se [`rdbuf`](../standard-library/basic-ios-class.md#rdbuf) for um ponteiro nulo, a função retornará-1. Caso contrário, ele chama `rdbuf->` [`pubsync`](../standard-library/basic-streambuf-class.md#pubsync) . Se essa chamada retornar-1, a função chamará [`setstate`](../standard-library/basic-ios-class.md#setstate) `(badbit)` e retornará-1. Caso contrário, a função retorna zero.

## <a name="basic_istreamtellg"></a><a name="tellg"></a>basic_istream:: tellg

Relata a atual posição de leitura no fluxo.

```cpp
pos_type tellg();
```

### <a name="return-value"></a>Valor retornado

A posição atual no fluxo.

### <a name="remarks"></a>Comentários

Se [`fail`](../standard-library/basic-ios-class.md#fail) for false, a função de membro retornará [`rdbuf`](../standard-library/basic-ios-class.md#rdbuf) `->` [`pubseekoff`](../standard-library/basic-streambuf-class.md#pubseekoff) `(0, cur, in)` . Caso contrário, ele retornará `pos_type(-1)`.

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

## <a name="basic_istreamunget"></a><a name="unget"></a>basic_istream:: unget

Coloca o caractere lido mais recentemente de volta no fluxo.

```cpp
basic_istream<Char_T, Tr>& unget();
```

### <a name="return-value"></a>Valor retornado

O fluxo (__* isso__).

### <a name="remarks"></a>Comentários

A [função de entrada não formatada](../standard-library/basic-istream-class.md) retorna o elemento anterior no fluxo, se possível, como se chamar `rdbuf->` [`sungetc`](../standard-library/basic-streambuf-class.md#sungetc) . Se [`rdbuf`](../standard-library/basic-ios-class.md#rdbuf) for um ponteiro nulo ou se a chamada para `sungetc` retornar `traits_type::` [`eof`](../standard-library/basic-ios-class.md#eof) , a função chamará [`setstate`](../standard-library/basic-ios-class.md#setstate) `(badbit)` . Em qualquer caso, ele retorna __*__.

Para obter informações sobre como a `unget` pode falhar, consulte [`basic_streambuf::sungetc`](../standard-library/basic-streambuf-class.md#sungetc) .

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

```Input
abc
```

```Output
Type 'abc': abc
abc
```

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
