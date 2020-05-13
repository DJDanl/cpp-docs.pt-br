---
title: Classe basic_ofstream
ms.date: 11/04/2016
f1_keywords:
- fstream/std::basic_ofstream
- fstream/std::basic_ofstream::close
- fstream/std::basic_ofstream::is_open
- fstream/std::basic_ofstream::open
- fstream/std::basic_ofstream::rdbuf
- fstream/std::basic_ofstream::swap
helpviewer_keywords:
- std::basic_ofstream [C++]
- std::basic_ofstream [C++], close
- std::basic_ofstream [C++], is_open
- std::basic_ofstream [C++], open
- std::basic_ofstream [C++], rdbuf
- std::basic_ofstream [C++], swap
ms.assetid: 3bcc9c51-6dfc-4844-8fcc-22ef57c9dff1
ms.openlocfilehash: f2d0facd92e0ef1935f8218a6d323a62edb81e5b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376790"
---
# <a name="basic_ofstream-class"></a>Classe basic_ofstream

Descreve um objeto que controla a inserção de elementos e objetos codificados `Elem`em um tampão de `Tr`fluxo de classe [basic_filebuf,](../standard-library/basic-filebuf-class.md)< `Elem` `Tr`>, com elementos de tipo, cujos traços de caráter são determinados pela classe .

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>>
class basic_ofstream : public basic_ostream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Elem*\
O elemento básico no buffer de arquivo.

*Tr*\
As características do elemento básico no buffer de arquivo (geralmente `char_traits`< `Elem`>).

## <a name="remarks"></a>Comentários

Quando a **wchar_t** `basic_ofstream` especialização de gravações para o arquivo, se o arquivo for aberto no modo texto, ele escreverá uma seqüência MBCS. A representação interna usará um buffer de `wchar_t` caracteres.

O objeto armazena um objeto da classe `basic_filebuf`< `Elem`, `Tr`>.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como criar um objeto `basic_ofstream` e escrever texto para ele.

```cpp
// basic_ofstream_class.cpp
// compile with: /EHsc
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ofstream ofs("ofstream.txt");
    if (!ofs.bad())
    {
        ofs << "Writing to a basic_ofstream object..." << endl;
        ofs.close();
    }
}
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_ofstream](#basic_ofstream)|Cria um objeto do tipo `basic_ofstream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Perto](#close)|Fecha um arquivo.|
|[is_open](#is_open)|Determina se um arquivo está aberto.|
|[open](#open)|Abre um arquivo.|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado.|
|[Trocar](#swap)|Troca o conteúdo desse `basic_ofstream` pelo conteúdo do `basic_ofstream` fornecido.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador=](#op_eq)|Atribui o conteúdo desse objeto de fluxo. Essa é uma atribuição de movimentação que envolve um `rvalue reference` que não deixa uma cópia.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<fstream>

**Namespace:** std

## <a name="basic_ofstreambasic_ofstream"></a><a name="basic_ofstream"></a>basic_ofstream:basic_ofstream

Cria um objeto do tipo `basic_ofstream`.

```cpp
basic_ofstream();

explicit basic_ofstream(
    const char* _Filename,
    ios_base::openmode _Mode = ios_base::out,
    int _Prot = (int)ios_base::_Openprot);

explicit basic_ofstream(
    const wchar_t* _Filename,
    ios_base::openmode _Mode = ios_base::out,
    int _Prot = (int)ios_base::_Openprot);

basic_ofstream(
    basic_ofstream&& right);
```

### <a name="parameters"></a>Parâmetros

*_Filename*\
O nome do arquivo a ser aberto.

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*_Prot*\
A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

*Certo*\
A referência rvalue para o objeto `basic_ofstream` que está sendo usado para inicializar este objeto `basic_ofstream`.

### <a name="remarks"></a>Comentários

O primeiro construtor inicia a classe base`sb`chamando `sb` [basic_ostream](../standard-library/basic-ostream-class.md)( ), onde `Tr` está o objeto armazenado de classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`,>. Também inicializa `sb` chamando `basic_filebuf`< `Elem`, `Tr`>.

O segundo e o terceiro construtores inicializam a classe base chamando `basic_ostream`( **sb**). Também se inicia `sb` chamando, `basic_filebuf` <  `Elem` `Tr`> `sb`e depois . [aberto](../standard-library/basic-filebuf-class.md#open) `_Filename`( `_Mode` `ios_base::out`, &#124;). Se a última função retornar um ponteiro nulo, o construtor chamará [setstate](../standard-library/basic-ios-class.md#setstate)().`failbit`

O quarto construtor é uma função de cópia. Ele inicializa o objeto com o conteúdo do *direito,* tratado como uma referência de valor.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como criar um objeto `basic_ofstream` e escrever texto para ele.

```cpp
// basic_ofstream_ctor.cpp
// compile with: /EHsc
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ofstream ofs("C:\\ofstream.txt");
    if (!ofs.bad())
    {
        ofs << "Writing to a basic_ofstream object..." << endl;
        ofs.close();
    }
}
```

## <a name="basic_ofstreamclose"></a><a name="close"></a>basic_ofstream::fechar

Fecha um arquivo.

```cpp
void close();
```

### <a name="remarks"></a>Comentários

A função membro chama [rdbuf](../standard-library/basic-ifstream-class.md#rdbuf)**->**[close](../standard-library/basic-filebuf-class.md#close).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `close`.

## <a name="basic_ofstreamis_open"></a><a name="is_open"></a>basic_ofstream:is_open

Indica se um arquivo está aberto.

```cpp
bool is_open() const;
```

### <a name="return-value"></a>Valor retornado

**true** se o arquivo estiver aberto; **false** caso contrário.

### <a name="remarks"></a>Comentários

A função membro retorna [rdbuf](#rdbuf) **->** [is_open](../standard-library/basic-filebuf-class.md#is_open).

### <a name="example"></a>Exemplo

```cpp
// basic_ofstream_is_open.cpp
// compile with: /EHsc
#include <fstream>
#include <iostream>

int main( )
{
   using namespace std;
   ifstream file;
   // Open and close with a basic_filebuf
   file.rdbuf( )->open( "basic_ofstream_is_open.txt", ios::in );
   file.close( );
   if (file.is_open())
      cout << "it's open" << endl;
   else
      cout << "it's closed" << endl;
}
```

## <a name="basic_ofstreamopen"></a><a name="open"></a>basic_ofstream:aberto

Abre um arquivo.

```cpp
void open(
    const char* _Filename,
    ios_base::openmode _Mode = ios_base::out,
    int _Prot = (int)ios_base::_Openprot);

void open(
    const char* _Filename,
    ios_base::openmode _Mode);

void open(
    const wchar_t* _Filename,
    ios_base::openmode _Mode = ios_base::out,
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

A função de membro chama [rdbuf](#rdbuf) **->** `ios_base::out` [open](../standard-library/basic-filebuf-class.md#open)(_ Nome de *arquivo*, `_Mode` &#124; ). Se essa função retornar um ponteiro nulo, a função chama [setstate](../standard-library/basic-ios-class.md#setstate)(`failbit`).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::abra](../standard-library/basic-filebuf-class.md#open) para um `open`exemplo que usa .

## <a name="basic_ofstreamoperator"></a><a name="op_eq"></a>basic_ofstream:operador=

Atribui o conteúdo desse objeto de fluxo. Essa é uma atribuição de movimentação que envolve um `rvalue reference` que não deixa uma cópia.

```cpp
basic_ofstream& operator=(basic_ofstream&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência rvalue a um objeto `basic_ofstream`.

### <a name="return-value"></a>Valor retornado

Retorna `*this`.

### <a name="remarks"></a>Comentários

O operador membro substitui o conteúdo do objeto usando o conteúdo do *direito,* tratado como uma referência de valor.

## <a name="basic_ofstreamrdbuf"></a><a name="rdbuf"></a>basic_ofstream:rdbuf

Retorna o endereço do buffer de fluxo armazenado.

```cpp
basic_filebuf<Elem, Tr> *rdbuf() const
```

### <a name="return-value"></a>Valor retornado

Retorna o endereço do buffer de fluxo armazenado.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.

## <a name="basic_ofstreamswap"></a><a name="swap"></a>basic_ofstream::swap

Troca o conteúdo de dois `basic_ofstream` objetos.

```cpp
void swap(basic_ofstream& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência `lvalue` a outro objeto `basic_ofstream`.

### <a name="remarks"></a>Comentários

A função membro troca o conteúdo deste objeto pelo conteúdo da *direita*.

## <a name="see-also"></a>Confira também

[basic_ostream](../standard-library/basic-ostream-class.md)\
[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
