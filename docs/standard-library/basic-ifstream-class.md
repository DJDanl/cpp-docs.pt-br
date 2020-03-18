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
ms.openlocfilehash: 1e5e22c837ca2d6389591cec6d2cdd256ca50b1a
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421964"
---
# <a name="basic_ifstream-class"></a>Classe basic_ifstream

Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>, com elementos do tipo `Elem` cujas características dos caracteres são determinadas pela classe `Tr`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>>
class basic_ifstream : public basic_istream<Elem, Tr>
```

### <a name="parameters"></a>parâmetros

\ *elem*
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

|Construtor|DESCRIÇÃO|
|-|-|
|[basic_ifstream](#basic_ifstream)|Inicializa uma nova instância de um objeto `basic_ifstream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|DESCRIÇÃO|
|-|-|
|[close](#close)|Fecha um arquivo.|
|[is_open](#is_open)|Determina se um arquivo está aberto.|
|[abrir](#open)|Abre um arquivo.|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado.|
|[swap](#swap)|Troca o conteúdo desse `basic_ifstream` pelo conteúdo do `basic_ifstream` fornecido.|

### <a name="operators"></a>Operadores

|Operador|DESCRIÇÃO|
|-|-|
|[operator=](#op_eq)|Atribui o conteúdo desse objeto de fluxo. Essa é uma atribuição de movimentação que envolve um `rvalue` que não deixa uma cópia.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<fstream >

**Namespace:** std

## <a name="basic_ifstream"></a>  basic_ifstream::basic_ifstream

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

### <a name="parameters"></a>parâmetros

*_Filename*\
O nome do arquivo a ser aberto.

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*_Prot*\
A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa a classe base chamando [basic_istream](../standard-library/basic-istream-class.md)( `sb`), em que `sb` é o objeto armazenado da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>. Também inicializa `sb` chamando `basic_filebuf`< `Elem`, `Tr`>.

O segundo e o terceiro construtores inicializam a classe base chamando `basic_istream`( `sb`). Também inicializa `sb` chamando [basic_filebuf](../standard-library/basic-filebuf-class.md#basic_filebuf)< `Elem`, `Tr`> e, em seguida, `sb`. [open](../standard-library/basic-filebuf-class.md#open)( `_Filename`, `_Mode` &#124; `ios_base::in`). Se a última função retornar um ponteiro nulo, o construtor chamará **setstate**( `failbit`).

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

## <a name="close"></a>  basic_ifstream::close

Fecha um arquivo.

```cpp
void close();
```

### <a name="remarks"></a>Comentários

A função de membro chama [rdbuf](#rdbuf) **->** [Fechar](../standard-library/basic-filebuf-class.md#close).

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `close`.

## <a name="is_open"></a>  basic_ifstream::is_open

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

## <a name="open"></a>  basic_ifstream::open

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

### <a name="parameters"></a>parâmetros

*_Filename*\
O nome do arquivo a ser aberto.

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*_Prot*\
A proteção de abertura de arquivo padrão, equivalente ao parâmetro `shflag` em [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md).

### <a name="remarks"></a>Comentários

A função de membro chama [rdbuf](#rdbuf) **->** [Open](../standard-library/basic-filebuf-class.md#open)(_ *filename*, &#124; `_Mode` **ios_base:: in**). Se abrir falhar, a função chamará [SetState](../standard-library/basic-ios-class.md#setstate)(`failbit`), o que pode gerar uma exceção ios_base:: Failure.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf:: Open](../standard-library/basic-filebuf-class.md#open) para obter um exemplo que usa `open`.

## <a name="op_eq"></a>  basic_ifstream::operator=

Atribui o conteúdo desse objeto de fluxo. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.

```cpp
basic_ifstream& operator=(basic_ifstream&& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
Uma referência rvalue a um objeto `basic_ifstream`.

### <a name="return-value"></a>Valor retornado

Retorna `*this`.

### <a name="remarks"></a>Comentários

O operador member substitui o conteúdo do objeto usando o conteúdo de *Right*, tratado como uma referência rvalue. Para obter mais informações, consulte [Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md).

## <a name="rdbuf"></a>  basic_ifstream::rdbuf

Retorna o endereço do buffer de fluxo armazenado.

```cpp
basic_filebuf<Elem, Tr> *rdbuf() const
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [basic_filebuf](../standard-library/basic-filebuf-class.md) que representa o buffer de fluxo armazenado.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.

## <a name="swap"></a>  basic_ifstream::swap

Troca o conteúdo de dois `basic_ifstream` objetos.

```cpp
void swap(basic_ifstream& right);
```

### <a name="parameters"></a>parâmetros

\ *à direita*
Uma referência a outro buffer de fluxo.

### <a name="remarks"></a>Comentários

A função membro troca o conteúdo deste objeto pelo conteúdo de *direita*.

## <a name="see-also"></a>Confira também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
