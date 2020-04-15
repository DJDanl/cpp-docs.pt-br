---
title: Classe basic_ostream
ms.date: 03/27/2019
f1_keywords:
- ostream/std::basic_ostream
- ostream/std::basic_ostream::flush
- ostream/std::basic_ostream::put
- ostream/std::basic_ostream::seekp
- ostream/std::basic_ostream::sentry
- ostream/std::basic_ostream::swap
- ostream/std::basic_ostream::tellp
- ostream/std::basic_ostream::write
helpviewer_keywords:
- std::basic_ostream [C++]
- std::basic_ostream [C++], flush
- std::basic_ostream [C++], put
- std::basic_ostream [C++], seekp
- std::basic_ostream [C++], sentry
- std::basic_ostream [C++], swap
- std::basic_ostream [C++], tellp
- std::basic_ostream [C++], write
ms.assetid: 5baadc65-b662-4fab-8c9f-94457c58cda1
ms.openlocfilehash: e074eb30d31c316411dd43f9a7a019defb64e9fe
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376758"
---
# <a name="basic_ostream-class"></a>Classe basic_ostream

Este modelo de classe descreve um objeto que controla a inserção de `Elem`elementos e objetos codificados em `Tr`um buffer de fluxo com elementos de tipo, também conhecidos como [char_type,](../standard-library/basic-ios-class.md#char_type)cujos traços de caractere são determinados pela classe, também conhecido como [traits_type](../standard-library/basic-ios-class.md#traits_type).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>>
class basic_ostream : virtual public basic_ios<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Elem*\
Um `char_type`.

*Tr*\
O caractere `traits_type`.

## <a name="remarks"></a>Comentários

A maioria das funções membro que sobrecarrega o [operator<<](#basic_ostream_operator_lt_lt) é composta por funções de entrada formatadas. Elas seguem o padrão:

```cpp
iostate state = goodbit;
const sentry ok(*this);

if (ok)
{try
{<convert and insert elements
    accumulate flags in state> }
    catch (...)
{try
{setstate(badbit);

}
    catch (...)
{}
    if ((exceptions()& badbit) != 0)
    throw; }}
width(0);
// Except for operator<<(Elem)
setstate(state);

return (*this);
```

Duas outras funções membro são funções de saída sem formatação. Elas seguem o padrão:

```cpp
iostate state = goodbit;
const sentry ok(*this);

if (!ok)
    state |= badbit;
else
{try
{<obtain and insert elements
    accumulate flags in state> }
    catch (...)
{try
{setstate(badbit);

}
    catch (...)
{}
    if ((exceptions()& badbit) != 0)
    throw; }}
setstate(state);

return (*this);
```

Ambos os grupos de funções chamam [setstate](../standard-library/basic-ios-class.md#setstate)**(badbit)** se encontrarem uma falha ao inserir elementos.

Um objeto da classe basic_istream\< **Elem**, **Tr**> armazena somente um objeto base virtual público da classe [basic_ios](../standard-library/basic-ios-class.md)**\<Elem**, **Tr >**.

## <a name="example"></a>Exemplo

Consulte o exemplo de [Classe basic_ifstream](../standard-library/basic-ofstream-class.md) para saber mais sobre fluxos de saída.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_ostream](#basic_ostream)|Constrói um objeto `basic_ostream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[flush](#flush)|Libera o buffer.|
|[Colocar](#put)|Coloca um caractere em um fluxo.|
|[seekp](#seekp)|Redefine a posição no fluxo de saída.|
|[sentry](#sentry)|A classe aninhada descreve um objeto cuja declaração estrutura as funções de saída formatadas e as funções de saída não formatadas.|
|[Trocar](#swap)|Troca os valores desse objeto `basic_ostream` por aqueles do objeto `basic_ostream` fornecido.|
|[tellp](#tellp)|Relata a posição no fluxo de saída.|
|[Escrever](#write)|Coloca caracteres em um fluxo.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador=](#op_eq)|Atribui o valor do objeto parâmetro `basic_ostream` fornecido para esse objeto.|
|[operador<<](#basic_ostream_operator_lt_lt)|Grava no fluxo.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<ostream >

**Namespace:** std

## <a name="basic_ostreambasic_ostream"></a><a name="basic_ostream"></a>basic_ostream:basic_ostream

Constrói um objeto `basic_ostream`.

```cpp
explicit basic_ostream(
    basic_streambuf<Elem, Tr>* strbuf,
    bool _Isstd = false);

basic_ostream(basic_ostream&& right);
```

### <a name="parameters"></a>Parâmetros

*strbuf*\
Um objeto do tipo [basic_streambuf](../standard-library/basic-streambuf-class.md).

*_Isstd*\
**verdade** se este é um fluxo padrão; caso contrário, **falso**.

*Certo*\
Uma referência rvalue a um objeto do tipo `basic_ostream`.

### <a name="remarks"></a>Comentários

O primeiro construtor inicia a classe base chamando [init](../standard-library/basic-ios-class.md#init)().`strbuf` O segundo construtor inicia a classe base chamando [basic_ios::move](../standard-library/basic-ios-class.md#move)`(right)`.

### <a name="example"></a>Exemplo

Consulte o exemplo de [basic_ofstream::basic_ofstream](../standard-library/basic-ofstream-class.md#basic_ofstream) para saber mais sobre fluxos de saída.

## <a name="basic_ostreamflush"></a><a name="flush"></a>basic_ostream::flush

Libera o buffer.

```cpp
basic_ostream<Elem, Tr>& flush();
```

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto basic_ostream.

### <a name="remarks"></a>Comentários

Se [rdbuf](../standard-library/basic-ios-class.md#rdbuf) não for um ponteiro nulo, a função chamará **rdbuf->**[pubsync](../standard-library/basic-streambuf-class.md#pubsync). Se isso retornar -1, a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( **badbit**). Ele devolve ** \*isso.**

### <a name="example"></a>Exemplo

```cpp
// basic_ostream_flush.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
   using namespace std;
   cout << "test";
   cout.flush();
}
```

```Output
test
```

## <a name="basic_ostreamoperatorltlt"></a><a name="basic_ostream_operator_lt_lt"></a>basic_ostream::operador&lt;&lt;

Grava no fluxo.

```cpp
basic_ostream<Elem, Tr>& operator<<(
    basic_ostream<Elem, Tr>& (* Pfn)(basic_ostream<Elem, Tr>&));

basic_ostream<Elem, Tr>& operator<<(
    ios_base& (* Pfn)(ios_base&));

basic_ostream<Elem, Tr>& operator<<(
    basic_ios<Elem, Tr>& (* Pfn)(basic_ios<Elem, Tr>&));

basic_ostream<Elem, Tr>& operator<<(basic_streambuf<Elem, Tr>* strbuf);
basic_ostream<Elem, Tr>& operator<<(bool val);
basic_ostream<Elem, Tr>& operator<<(short val);
basic_ostream<Elem, Tr>& operator<<(unsigned short val);
basic_ostream<Elem, Tr>& operator<<(int __w64  val);
basic_ostream<Elem, Tr>& operator<<(unsigned int __w64  val);
basic_ostream<Elem, Tr>& operator<<(long val);
basic_ostream<Elem, Tr>& operator<<(unsigned long __w64  val);
basic_ostream<Elem, Tr>& operator<<(long long val);
basic_ostream<Elem, Tr>& operator<<(unsigned long long val);
basic_ostream<Elem, Tr>& operator<<(float val);
basic_ostream<Elem, Tr>& operator<<(double val);
basic_ostream<Elem, Tr>& operator<<(long double val);
basic_ostream<Elem, Tr>& operator<<(const void* val);
```

### <a name="parameters"></a>Parâmetros

*Pfn*\
Um ponteiro de função.

*strbuf*\
Um ponteiro para um objeto `stream_buf`.

*Val*\
Um elemento para gravar no fluxo.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto basic_ostream.

### <a name="remarks"></a>Comentários

O \<cabeçalho de> ostream também define vários operadores de inserção globais. Para obter mais informações, consulte [o operador<<](../standard-library/ostream-operators.md#op_lt_lt).

A primeira função do membro garante `ostr << endl` que uma expressão do formulário chame [endl](../standard-library/ostream-functions.md#endl)**(ostr)** e, em seguida, retorne ** \*isso**. A segunda e a terceira funções garantem que outros manipuladores, como [hexa](../standard-library/ios-functions.md#hex), comportem-se de modo semelhante. As funções restantes são todas as funções de saída formatadas.

A função

```cpp
basic_ostream<Elem, Tr>& operator<<(basic_streambuf<Elem, Tr>* strbuf);
```

extrai elementos de *strbuf,* se *strbuf* não for um ponteiro nulo, e os insere. A extração para no fim do arquivo ou se uma extração gerar uma exceção (que é gerada novamente). Ela também parará, sem extrair o elemento em questão, se uma inserção falhar. Se a função não inserir nenhum elemento ou se uma extração gerar uma exceção, a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)(**failbit**). Em qualquer caso, ** \*** a função retorna isso .

A função

```cpp
basic_ostream<Elem, Tr>& operator<<(bool val);
```

`_Val` converte-se em um campo booleano e insere-o chamando [use_facet](../standard-library/basic-filebuf-class.md#open) **<num_put\<Elem, OutIt>** `(` [getloc](../standard-library/ios-base-class.md#getloc)). [put](#put)(**OutIt**([rdbuf](../standard-library/basic-ios-class.md#rdbuf)), **\*this**, `getloc`, **val**). Aqui, `OutIt` é definido como [ostreambuf_iterator](../standard-library/ostreambuf-iterator-class.md)**\<Elem, Tr>**. A função ** \*** retorna isso .

As funções

```cpp
basic_ostream<Elem, Tr>& operator<<(short val);
basic_ostream<Elem, Tr>& operator<<(unsigned short val);
basic_ostream<Elem, Tr>& operator<<(int val);
basic_ostream<Elem, Tr>& operator<<(unsigned int __w64  val);
basic_ostream<Elem, Tr>& operator<<(long val);
basic_ostream<Elem, Tr>& operator<<(unsigned long val);
basic_ostream<Elem, Tr>& operator<<(long long val);
basic_ostream<Elem, Tr>& operator<<(unsigned long long val);
basic_ostream<Elem, Tr>& operator<<(const void* val);
```

cada *um* converte val em um campo numérico e inseri-lo chamando **use_facet<num_put\<Elem, OutIt>**( ).`getloc` **colocar**(**OutIt**(),`rdbuf` `getloc` ** \*isso,** **val**). Aqui, **OutIt** é definido como **ostreambuf_iterator\<Elem, Tr>**. A função ** \*** retorna isso .

As funções

```cpp
basic_ostream<Elem, Tr>& operator<<(float val);
basic_ostream<Elem, Tr>& operator<<(double val);
basic_ostream<Elem, Tr>& operator<<(long double val);
```

cada *um converte val* em um campo numérico e inseri-lo chamando`rdbuf`use_facet<`getloc` **\<num_put Elem, OutIt>**(`getloc`)**put**(**OutIt**( ), ** \*este**, val ). **val** Aqui, **OutIt** é definido como **ostreambuf_iterator\<Elem, Tr>**. A função ** \*** retorna isso .

### <a name="example"></a>Exemplo

```cpp
// basic_ostream_op_write.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>

using namespace std;

ios_base& hex2( ios_base& ib )
{
   ib.unsetf( ios_base::dec );
   ib.setf( ios_base::hex );
   return ib;
}

basic_ostream<char, char_traits<char> >& somefunc(basic_ostream<char, char_traits<char> > &i)
{
    if (i == cout)
    {
        i << "i is cout" << endl;
    }
    return i;
}

class CTxtStreambuf : public basic_streambuf< char, char_traits< char > >
{
public:
    CTxtStreambuf(char *_pszText)
    {
        pszText = _pszText;
        setg(pszText, pszText, pszText + strlen(pszText));
    };
    char *pszText;
};

int main()
{
    cout << somefunc;
    cout << 21 << endl;

    hex2(cout);
    cout << 21 << endl;

    CTxtStreambuf f("text in streambuf");
    cout << &f << endl;
}
```

## <a name="basic_ostreamoperator"></a><a name="op_eq"></a>basic_ostream::operador=

Atribui valores para o parâmetro de objeto `basic_ostream` fornecido para esse objeto.

```cpp
basic_ostream& operator=(basic_ostream&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência `rvalue` a um objeto `basic_ostream`.

### <a name="remarks"></a>Comentários

O operador do membro chama `(right)` de troca.

## <a name="basic_ostreamput"></a><a name="put"></a>basic_ostream::put

Coloca um caractere em um fluxo.

```cpp
basic_ostream<Elem, Tr>& put(char_type _Ch);
```

### <a name="parameters"></a>Parâmetros

*_Ch*\
Um caractere.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto basic_ostream.

### <a name="remarks"></a>Comentários

A função de saída não formatada insere o elemento *_Ch*. Ele devolve ** \*isso.**

### <a name="example"></a>Exemplo

```cpp
// basic_ostream_put.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
   using namespace std;
   cout.put( 'v' );
   cout << endl;
   wcout.put( L'l' );
}
```

```Output
v
l
```

## <a name="basic_ostreamseekp"></a><a name="seekp"></a>basic_ostream::seekp

Redefine a posição no fluxo de saída.

```cpp
basic_ostream<Elem, Tr>& seekp(pos_type _Pos);

basic_ostream<Elem, Tr>& seekp(off_type _Off, ios_base::seekdir _Way);
```

### <a name="parameters"></a>Parâmetros

*_Pos*\
A posição no fluxo.

*_Off*\
O deslocamento em relação ao *_Way*.

*_Way*\
Uma das enumerações de [ios_base::seekdir](../standard-library/ios-base-class.md#seekdir).

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto basic_ostream.

### <a name="remarks"></a>Comentários

Se [a falha](../standard-library/basic-ios-class.md#fail) for **falsa,** a primeira função de membro chama **newpos =** [rdbuf](../standard-library/basic-ios-class.md#rdbuf) **->** [pubseekpos](../standard-library/basic-streambuf-class.md#pubseekpos)*(_Pos),* para algum `pos_type` objeto `newpos`temporário . Se `fail` for falsa, a segunda função chama **newpos = pubseekoff rdbuf->** [pubseekoff](../standard-library/basic-streambuf-class.md#pubseekoff)*(_Off, _Way*). Em ambos os`off_type`casos, se (`off_type`)**newpos ==** ()(-1) (a operação de posicionamento falha), então a função chama **istr.** [setstate](../standard-library/basic-ios-class.md#setstate)**(failbit).** Ambas as ** \*** funções retornam isso .

### <a name="example"></a>Exemplo

```cpp
// basic_ostream_seekp.cpp
// compile with: /EHsc
#include <fstream>
#include <iostream>

int main()
{
    using namespace std;
    ofstream x("basic_ostream_seekp.txt");
    streamoff i = x.tellp();
    cout << i << endl;
    x << "testing";
    i = x.tellp();
    cout << i << endl;
    x.seekp(2);   // Put char in third char position in file
    x << " ";

    x.seekp(2, ios::end);   // Put char two after end of file
    x << "z";
}
```

```Output
0
7
```

## <a name="basic_ostreamsentry"></a><a name="sentry"></a>basic_ostream::sentinela

A classe aninhada descreve um objeto cuja declaração estrutura as funções de saída formatadas e as funções de saída não formatadas.

sentinela de classe { público:\<sentinela explícita (basic_ostream Elem, Tr>& _Ostr); operador bool() const; ~sentinela(); };

### <a name="remarks"></a>Comentários

A classe aninhada descreve um objeto cuja declaração estrutura as funções de saída formatadas e as funções de saída não formatadas. Se **ostr.**[good](../standard-library/basic-ios-class.md#good) for **true** e **ostr.**[tie](../standard-library/basic-ios-class.md#tie) não for um ponteiro nulo, o construtor chamará **ostr.tie->**[flush](#flush). A construtora então armazena o `ostr.good` valor `status`devolvido em . Uma chamada `operator bool` posterior para entregar esse valor armazenado.

Se `uncaught_exception` retornar **false** e [flags](../standard-library/ios-base-class.md#flags) **&** [unitbuf](../standard-library/ios-functions.md#unitbuf) for diferente de zero, o destruidor chamará [flush](#flush).

## <a name="basic_ostreamswap"></a><a name="swap"></a>basic_ostream::swap

Troca os valores desse `basic_ostream` objeto pelo valores do `basic_ostream` fornecido.

```cpp
void swap(basic_ostream& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência a um objeto `basic_ostream`.

### <a name="remarks"></a>Comentários

A função membro chama [basic_ios::swap](../standard-library/basic-ios-class.md#swap) `(right)` para trocar o conteúdo deste objeto pelo conteúdo da *direita*.

## <a name="basic_ostreamtellp"></a><a name="tellp"></a>basic_ostream::tellp

Relata a posição no fluxo de saída.

```cpp
pos_type tellp();
```

### <a name="return-value"></a>Valor retornado

Posição no fluxo de saída.

### <a name="remarks"></a>Comentários

Se [fail](../standard-library/basic-ios-class.md#fail) for **false**, a função membro retornará [rdbuf](../standard-library/basic-ios-class.md#rdbuf)**->** [pubseekoff](../standard-library/basic-streambuf-class.md#pubseekoff)(0, `cur`, **in**). Caso contrário, retornará `pos_type`(-1).

### <a name="example"></a>Exemplo

Consulte [seekp](#seekp) para obter um exemplo usando `tellp`.

## <a name="basic_ostreamwrite"></a><a name="write"></a>basic_ostream::write

Coloque caracteres em um fluxo.

```cpp
basic_ostream<Elem, Tr>& write(const char_type* str, streamsize count);
```

### <a name="parameters"></a>Parâmetros

*Contar*\
Contagem de caracteres a colocar no fluxo.

*Str*\
Caracteres a colocar no fluxo.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto basic_ostream.

### <a name="remarks"></a>Comentários

A [função de saída não formatada](../standard-library/basic-ostream-class.md) insere a seqüência de elementos de *contagem* que começam em *str*.

### <a name="example"></a>Exemplo

Consulte [streamsize](../standard-library/ios-typedefs.md#streamsize) para obter um exemplo usando `write`.

## <a name="see-also"></a>Confira também

[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
