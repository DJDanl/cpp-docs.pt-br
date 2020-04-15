---
title: Classe basic_ifstream
ms.date: 11/04/2016
f1_keywords:
- fstream/std::basic_ifstream
- fstream/std::basic_ifstream::close
- fstream/std::basic_ifstream::is_open
- fstream/std::basic_ifstream::open
- fstream/std::basic_ifstream::rdbuf
- fstream/std::basic_ifstream::swap
helpviewer_keywords:
- std::basic_ifstream [C++]
- std::basic_ifstream [C++], close
- std::basic_ifstream [C++], is_open
- std::basic_ifstream [C++], open
- std::basic_ifstream [C++], rdbuf
- std::basic_ifstream [C++], swap
ms.assetid: 366cd9a7-efc4-4b7f-ba10-c8271e47ffcf
ms.openlocfilehash: 85a315ee393a002da4d0999569d4af6c34a37ee3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376838"
---
# <a name="basic_ifstream-class"></a>Classe basic_ifstream

Descreve um objeto que controla a extração de elementos e `Tr` objetos codificados `Elem`a partir de um tampão de fluxo de [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`de classe,>, com elementos de tipo, cujos traços de caráter são determinados pela classe `Tr`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>>
class basic_ifstream : public basic_istream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Elem*\
O elemento básico no buffer de arquivo.

*Tr*\
As características do elemento básico no buffer de arquivo (geralmente `char_traits`< `Elem`>).

## <a name="remarks"></a>Comentários

O objeto armazena um objeto da classe `basic_filebuf`< `Elem`, `Tr`>.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como ler texto de um arquivo.

```cpp
// basic_ifstream_class.cpp
// compile with: /EHsc

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream ifs("basic_ifstream_class.txt");
    if (!ifs.bad())
    {
        // Dump the contents of the file to cout.
        cout << ifs.rdbuf();
        ifs.close();
    }
}
```

## <a name="input-basic_ifstream_classtxt"></a>Entrada: basic_ifstream_class.txt

```cpp
This is the contents of basic_ifstream_class.txt.
```

## <a name="output"></a>Saída

```cpp
This is the contents of basic_ifstream_class.txt.
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_ifstream](#basic_ifstream)|Inicializa uma nova instância de um objeto `basic_ifstream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Perto](#close)|Fecha um arquivo.|
|[is_open](#is_open)|Determina se um arquivo está aberto.|
|[open](#open)|Abre um arquivo.|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado.|
|[Trocar](#swap)|Troca o conteúdo desse `basic_ifstream` pelo conteúdo do `basic_ifstream` fornecido.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador=](#op_eq)|Atribui o conteúdo desse objeto de fluxo. Essa é uma atribuição de movimentação que envolve um `rvalue` que não deixa uma cópia.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<fstream>

**Namespace:** std

## <a name="basic_ifstreambasic_ifstream"></a><a name="basic_ifstream"></a>basic_ifstream:basic_ifstream

Constrói um objeto do tipo `basic_ifstream`.

```cpp
basic_ifstream();

explicit basic_ifstream(
    const char* _Filename,
    ios_base::openmode _Mode = ios_base::in,
    int _Prot = (int)ios_base::_Openprot);

explicit basic_ifstream(
    const wchar_t* _Filename,
    ios_base::openmode _Mode = ios_base::in,
    int _Prot = (int)ios_base::_Openprot);

basic_ifstream(basic_ifstream&& right);
```

### <a name="parameters"></a>Parâmetros

*_Filename*\
O nome do arquivo a ser aberto.

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*_Prot*\
A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

### <a name="remarks"></a>Comentários

O primeiro construtor inicia a classe base `sb`chamando `sb` [basic_istream](../standard-library/basic-istream-class.md)( ), onde `Tr` está o objeto armazenado de classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`,>. Também inicializa `sb` chamando `basic_filebuf`< `Elem`, `Tr`>.

O segundo e o terceiro construtores inicializam a classe base chamando `basic_istream`( `sb`). Também se inicia `sb` chamando `Tr` [basic_filebuf,](../standard-library/basic-filebuf-class.md#basic_filebuf)< `Elem` `sb`>, então . [aberto](../standard-library/basic-filebuf-class.md#open) `_Filename`( `_Mode` `ios_base::in`, &#124;). Se a última função retornar um ponteiro nulo, o construtor chamará **setstate**(). `failbit`

O quarto construtor inicializa o objeto com o conteúdo de `right`, tratados como uma referência rvalue.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como ler texto de um arquivo. Para criar o arquivo, consulte o exemplo para [basic_ofstream::basic_ofstream](../standard-library/basic-ofstream-class.md#basic_ofstream).

```cpp
// basic_ifstream_ctor.cpp
// compile with: /EHsc

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream ifs("basic_ifstream_ctor.txt");
    if (!ifs.bad())
    {
        // Dump the contents of the file to cout.
        cout << ifs.rdbuf();
        ifs.close();
    }
}
```

## <a name="basic_ifstreamclose"></a><a name="close"></a>basic_ifstream::fechar

Fecha um arquivo.

```cpp
void close();
```

### <a name="remarks"></a>Comentários

A função membro chama [rdbuf](#rdbuf) **->** [close](../standard-library/basic-filebuf-class.md#close).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `close`.

## <a name="basic_ifstreamis_open"></a><a name="is_open"></a>basic_ifstream:is_open

Determina se um arquivo está aberto.

```cpp
bool is_open() const;
```

### <a name="return-value"></a>Valor retornado

**true** se o arquivo estiver aberto; **false** caso contrário.

### <a name="remarks"></a>Comentários

A função membro retorna [rdbuf](#rdbuf) **->** [is_open](../standard-library/basic-filebuf-class.md#is_open).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::is_open](../standard-library/basic-filebuf-class.md#is_open) para ver um exemplo que usa `is_open`.

## <a name="basic_ifstreamopen"></a><a name="open"></a>basic_ifstream:aberto

Abre um arquivo.

```cpp
void open(
    const char* _Filename,
    ios_base::openmode _Mode = ios_base::in,
    int _Prot = (int)ios_base::_Openprot);

void open(
    const char* _Filename,
    ios_base::openmode _Mode);

void open(
    const wchar_t* _Filename,
    ios_base::openmode _Mode = ios_base::in,
    int _Prot = (int)ios_base::_Openprot);

void open(
    const wchar_t* _Filename,
    ios_base::openmode _Mode);
```

### <a name="parameters"></a>Parâmetros

*_Filename*\
O nome do arquivo a ser aberto.

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*_Prot*\
A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

### <a name="remarks"></a>Comentários

A função membro chama [rdbuf](#rdbuf) **->** [open](../standard-library/basic-filebuf-class.md#open)(_ Nome *de arquivo*, `_Mode` &#124; **ios_base::in**). Se falhar, a função chama`failbit` [setstate](../standard-library/basic-ios-class.md#setstate)(), o que pode lançar uma exceção ios_base::falha.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::abra](../standard-library/basic-filebuf-class.md#open) para um `open`exemplo que usa .

## <a name="basic_ifstreamoperator"></a><a name="op_eq"></a>basic_ifstream::operador=

Atribui o conteúdo desse objeto de fluxo. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.

```cpp
basic_ifstream& operator=(basic_ifstream&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência rvalue a um objeto `basic_ifstream`.

### <a name="return-value"></a>Valor retornado

Retorna `*this`.

### <a name="remarks"></a>Comentários

O operador membro substitui o conteúdo do objeto usando o conteúdo do *direito,* tratado como uma referência de valor. Para obter mais informações, consulte [Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md).

## <a name="basic_ifstreamrdbuf"></a><a name="rdbuf"></a>basic_ifstream:rdbuf

Retorna o endereço do buffer de fluxo armazenado.

```cpp
basic_filebuf<Elem, Tr> *rdbuf() const
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [basic_filebuf](../standard-library/basic-filebuf-class.md) que representa o buffer de fluxo armazenado.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.

## <a name="basic_ifstreamswap"></a><a name="swap"></a>basic_ifstream::swap

Troca o conteúdo de dois `basic_ifstream` objetos.

```cpp
void swap(basic_ifstream& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência a outro buffer de fluxo.

### <a name="remarks"></a>Comentários

A função membro troca o conteúdo deste objeto pelo conteúdo da *direita*.

## <a name="see-also"></a>Confira também

[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
