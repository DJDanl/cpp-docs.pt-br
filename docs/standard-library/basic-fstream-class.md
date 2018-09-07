---
title: Classe basic_fstream | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- fstream/std::basic_fstream
- fstream/std::basic_fstream::close
- fstream/std::basic_fstream::is_open
- fstream/std::basic_fstream::open
- fstream/std::basic_fstream::rdbuf
- fstream/std::basic_fstream::swap
dev_langs:
- C++
helpviewer_keywords:
- std::basic_fstream [C++]
- std::basic_fstream [C++], close
- std::basic_fstream [C++], is_open
- std::basic_fstream [C++], open
- std::basic_fstream [C++], rdbuf
- std::basic_fstream [C++], swap
ms.assetid: 8473817e-42a4-430b-82b8-b476c86bcf8a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2b4712a76be411d237ee2abc97ddbdd4b67e57f2
ms.sourcegitcommit: 761c5f7c506915f5a62ef3847714f43e9b815352
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/07/2018
ms.locfileid: "44108347"
---
# <a name="basicfstream-class"></a>Classe basic_fstream

Descreve um objeto que controla a inserção e a extração de elementos e objetos codificados usando um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>, com elementos do tipo `Elem` cujas características dos caracteres são determinadas pela classe `Tr`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>>
class basic_fstream : public basic_iostream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Elem*<br/>
O elemento básico no buffer de arquivo.

*Tr*<br/>
As características do elemento básico no buffer de arquivo (geralmente `char_traits` <  `Elem`>).

## <a name="remarks"></a>Comentários

O objeto armazena um objeto da classe `basic_filebuf` <  `Elem`, `Tr`>.

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
|[close](#close)|Fecha um arquivo.|
|[is_open](#is_open)|Determina se um arquivo está aberto.|
|[open](#open)|Abre um arquivo.|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado do tipo ponteiro para [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>.|
|[swap](#swap)|Troca o conteúdo desse objeto pelo conteúdo de outro objeto `basic_fstream`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<fstream>

**Namespace:** std

## <a name="basic_fstream"></a>  basic_fstream::basic_fstream

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

*Nome de arquivo*<br/>
O nome do arquivo a ser aberto.

*Modo*<br/>
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*_Prot*<br/>
Proteção, equivalente de abertura de arquivo padrão a *shflag* parâmetro na [fsopen, wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa a classe base chamando [basic_iostream](../standard-library/basic-iostream-class.md)(`sb`), onde `sb` é o objeto armazenado da classe [basic_filebuf](../standard-library/basic-filebuf-class.md) \< **Elem**, **Tr**>. Também inicializa `sb` chamando `basic_filebuf` \< **Elem**, **Tr**>.

O segundo e o terceiro construtores inicializam a classe base chamando `basic_iostream`( **sb**). Também inicializa `sb` chamando `basic_filebuf` \< **Elem**, **Tr**> e então **SB.**[abrir](../standard-library/basic-filebuf-class.md#open)( _ *Filename*, `_Mode`). Se a última função retornará um ponteiro nulo, o construtor chamará [setstate](../standard-library/basic-ios-class.md#setstate)(`failbit`).

O quarto construtor inicializa o objeto com o conteúdo de `right`, tratados como uma referência rvalue.

### <a name="example"></a>Exemplo

Consulte [streampos](../standard-library/ios-typedefs.md#streampos) para obter um exemplo que usa `basic_fstream`.

## <a name="close"></a>  basic_fstream::close

Fecha um arquivo.

```cpp
void close();
```

### <a name="remarks"></a>Comentários

A função membro chama [rdbuf](#rdbuf)**->** [close](../standard-library/basic-filebuf-class.md#close).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para obter um exemplo de como usar `close`.

## <a name="is_open"></a>  basic_fstream::is_open

Determina se um arquivo está aberto.

```cpp
bool is_open() const;
```

### <a name="return-value"></a>Valor de retorno

**true** se o arquivo estiver aberto; **false** caso contrário.

### <a name="remarks"></a>Comentários

A função membro retorna [rdbuf](#rdbuf)**->**[is_open](../standard-library/basic-filebuf-class.md#is_open).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::is_open](../standard-library/basic-filebuf-class.md#is_open) para obter um exemplo de como usar `is_open`.

## <a name="open"></a>  basic_fstream::open

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

*Nome de arquivo*<br/>
O nome do arquivo a ser aberto.

*Modo*<br/>
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*_Prot*<br/>
Proteção, equivalente de abertura de arquivo padrão a *shflag* parâmetro na [fsopen, wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

### <a name="remarks"></a>Comentários

A função membro chama [rdbuf](#rdbuf) **->** [open](../standard-library/basic-filebuf-class.md#open)(_ *Filename*, `_Mode`). Se essa função retorna um ponteiro nulo, a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)( `failbit`).

### <a name="example"></a>Exemplo

Ver [basic_filebuf:: Open](../standard-library/basic-filebuf-class.md#open) para obter um exemplo de como usar `open`.

## <a name="op_eq"></a>  basic_fstream::operator=

Atribui a esse objeto o conteúdo de um objeto de fluxo especificado. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.

```cpp
basic_fstream& operator=(basic_fstream&& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
Uma referência lvalue a um objeto `basic_fstream`.

### <a name="return-value"></a>Valor de retorno

Retorna `*this`.

### <a name="remarks"></a>Comentários

O operador membro substitui o conteúdo do objeto usando o conteúdo de *certa*, tratado como uma referência de rvalue.

## <a name="rdbuf"></a>  basic_fstream::rdbuf

Retorna o endereço do buffer de fluxo armazenado do tipo ponteiro para [basic_filebuf](../standard-library/basic-filebuf-class.md)\< **Elem**, **Tr**>.

```cpp
basic_filebuf<Elem, Tr> *rdbuf() const
```

### <a name="return-value"></a>Valor de retorno

O endereço do buffer de fluxo armazenado.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para obter um exemplo de como usar `rdbuf`.

## <a name="swap"></a>  basic_fstream::swap

Troca o conteúdo de dois `basic_fstream` objetos.

```cpp
void swap(basic_fstream& right);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
Uma referência `lvalue` a um objeto `basic_fstream`.

### <a name="remarks"></a>Comentários

A função membro troca o conteúdo deste objeto e o conteúdo do *certa*.

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
