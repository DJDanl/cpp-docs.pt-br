---
title: Classe basic_fstream
ms.date: 11/04/2016
f1_keywords:
- fstream/std::basic_fstream
- fstream/std::basic_fstream::close
- fstream/std::basic_fstream::is_open
- fstream/std::basic_fstream::open
- fstream/std::basic_fstream::rdbuf
- fstream/std::basic_fstream::swap
helpviewer_keywords:
- std::basic_fstream [C++]
- std::basic_fstream [C++], close
- std::basic_fstream [C++], is_open
- std::basic_fstream [C++], open
- std::basic_fstream [C++], rdbuf
- std::basic_fstream [C++], swap
ms.assetid: 8473817e-42a4-430b-82b8-b476c86bcf8a
ms.openlocfilehash: 80992430d6bef6fc46106452dfaa44cc0ed9e71c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376854"
---
# <a name="basic_fstream-class"></a>Classe basic_fstream

Descreve um objeto que controla a inserção e extração de elementos e objetos `Elem`codificados usando um tampão de fluxo de [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`de classe, `Tr`>, com elementos de tipo, cujos traços de caráter são determinados pela classe `Tr`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>>
class basic_fstream : public basic_iostream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Elem*\
O elemento básico no buffer de arquivo.

*Tr*\
As características do elemento básico no buffer de arquivo (geralmente `char_traits`< `Elem`>).

## <a name="remarks"></a>Comentários

O objeto armazena um objeto da classe `basic_filebuf`< `Elem`, `Tr`>.

> [!NOTE]
> O ponteiro get e o ponteiro put de um objeto fstream **NÃO** são independentes um do outro. Se o ponteiro se mover, o mesmo ocorrerá com o ponteiro put.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um objeto `basic_fstream` que pode ser lido e gravado.

```cpp
// basic_fstream_class.cpp
// compile with: /EHsc

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    fstream fs("fstream.txt", ios::in | ios::out | ios::trunc);
    if (!fs.bad())
    {
        // Write to the file.
        fs << "Writing to a basic_fstream object..." << endl;
        fs.close();

        // Dump the contents of the file to cout.
        fs.open("fstream.txt", ios::in);
        cout << fs.rdbuf();
        fs.close();
    }
}
```

```Output
Writing to a basic_fstream object...
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_fstream](#basic_fstream)|Constrói um objeto do tipo `basic_fstream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Perto](#close)|Fecha um arquivo.|
|[is_open](#is_open)|Determina se um arquivo está aberto.|
|[open](#open)|Abre um arquivo.|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado, do ponteiro do tipo para [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>.|
|[Trocar](#swap)|Troca o conteúdo desse objeto pelo conteúdo de outro objeto `basic_fstream`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<fstream>

**Namespace:** std

## <a name="basic_fstreambasic_fstream"></a><a name="basic_fstream"></a>basic_fstream:basic_fstream

Constrói um objeto do tipo `basic_fstream`.

```cpp
basic_fstream();

explicit basic_fstream(
    const char* _Filename,
    ios_base::openmode _Mode = ios_base::in | ios_base::out,
    int _Prot = (int)ios_base::_Openprot);

explicit basic_fstream(
    const wchar_t* _Filename,
    ios_base::openmode _Mode = ios_base::in | ios_base::out,
    int _Prot = (int)ios_base::_Openprot);

basic_fstream(basic_fstream&& right);
```

### <a name="parameters"></a>Parâmetros

*_Filename*\
O nome do arquivo a ser aberto.

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*_Prot*\
A proteção de abertura de arquivo padrão, equivalente ao parâmetro *shflag* em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

### <a name="remarks"></a>Comentários

O primeiro construtor inicia a classe base`sb`chamando `sb` [basic_iostream](../standard-library/basic-iostream-class.md)( ), onde está o objeto armazenado da classe [basic_filebuf](../standard-library/basic-filebuf-class.md) \< **Elem**, **Tr**>. Também se inicia `sb` `basic_filebuf` \< chamando **elem**, **Tr**>.

O segundo e o terceiro construtores inicializam a classe base chamando `basic_iostream`( **sb**). Também se inicia `sb` `basic_filebuf` \< chamando **elem**, **Tr**>, e, em seguida, **sb.**[open](../standard-library/basic-filebuf-class.md#open)(_ *Filename*, ). `_Mode` Se a última função retornar um ponteiro nulo, o construtor chamará [setstate](../standard-library/basic-ios-class.md#setstate)().`failbit`

O quarto construtor inicializa o objeto com o conteúdo de `right`, tratados como uma referência rvalue.

### <a name="example"></a>Exemplo

Consulte [streampos](../standard-library/ios-typedefs.md#streampos) para obter um exemplo que usa `basic_fstream`.

## <a name="basic_fstreamclose"></a><a name="close"></a>basic_fstream::fechar

Fecha um arquivo.

```cpp
void close();
```

### <a name="remarks"></a>Comentários

A função membro chama [rdbuf](#rdbuf) **->** [close](../standard-library/basic-filebuf-class.md#close).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para obter um exemplo de como usar `close`.

## <a name="basic_fstreamis_open"></a><a name="is_open"></a>basic_fstream:is_open

Determina se um arquivo está aberto.

```cpp
bool is_open() const;
```

### <a name="return-value"></a>Valor retornado

**true** se o arquivo estiver aberto; **false** caso contrário.

### <a name="remarks"></a>Comentários

A função membro retorna [rdbuf](#rdbuf)**->**[is_open](../standard-library/basic-filebuf-class.md#is_open).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::is_open](../standard-library/basic-filebuf-class.md#is_open) para obter um exemplo de como usar `is_open`.

## <a name="basic_fstreamopen"></a><a name="open"></a>basic_fstream::aberto

Abre um arquivo.

```cpp
void open(
    const char* _Filename,
    ios_base::openmode _Mode = ios_base::in | ios_base::out,
    int _Prot = (int)ios_base::_Openprot);

void open(
    const char* _Filename,
    ios_base::openmode _Mode);

void open(
    const wchar_t* _Filename,
    ios_base::openmode _Mode = ios_base::in | ios_base::out,
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
A proteção de abertura de arquivo padrão, equivalente ao parâmetro *shflag* em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

### <a name="remarks"></a>Comentários

A função de membro chama [rdbuf](#rdbuf) **->** [open](../standard-library/basic-filebuf-class.md#open)(_ Nome *de arquivo*, `_Mode`). Se essa função retornar um ponteiro nulo, a função chama [setstate](../standard-library/basic-ios-class.md#setstate)( `failbit`).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::abra](../standard-library/basic-filebuf-class.md#open) para um exemplo `open`de como usar .

## <a name="basic_fstreamoperator"></a><a name="op_eq"></a>basic_fstream::operador=

Atribui a esse objeto o conteúdo de um objeto de fluxo especificado. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.

```cpp
basic_fstream& operator=(basic_fstream&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência lvalue a um objeto `basic_fstream`.

### <a name="return-value"></a>Valor retornado

Retorna `*this`.

### <a name="remarks"></a>Comentários

O operador membro substitui o conteúdo do objeto usando o conteúdo do *direito,* tratado como uma referência de valor.

## <a name="basic_fstreamrdbuf"></a><a name="rdbuf"></a>basic_fstream:rdbuf

Retorna o endereço do buffer de fluxo armazenado do tipo ponteiro para [basic_filebuf](../standard-library/basic-filebuf-class.md)\< **Elem**, **Tr**>.

```cpp
basic_filebuf<Elem, Tr> *rdbuf() const
```

### <a name="return-value"></a>Valor retornado

O endereço do buffer de fluxo armazenado.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para obter um exemplo de como usar `rdbuf`.

## <a name="basic_fstreamswap"></a><a name="swap"></a>basic_fstream::swap

Troca o conteúdo de dois `basic_fstream` objetos.

```cpp
void swap(basic_fstream& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência `lvalue` a um objeto `basic_fstream`.

### <a name="remarks"></a>Comentários

A função do membro troca o conteúdo deste objeto e o conteúdo da *direita*.

## <a name="see-also"></a>Confira também

[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
