---
title: '&lt;sstream&gt;'
ms.date: 11/04/2016
f1_keywords:
- <sstream>
helpviewer_keywords:
- sstream header
ms.assetid: 56f55bc5-549d-4e7f-aaad-99e0ffa49c9e
ms.openlocfilehash: cc08fb426df289b3478ad9d29b03f9a6dd5d3978
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62412469"
---
# <a name="ltsstreamgt"></a>&lt;sstream&gt;

Define várias classes de modelo que dão suporte a operações de iostreams em sequências armazenadas em um objeto de matriz alocada. Essas sequências são facilmente convertidas para e de objetos da classe de modelo [basic_string](../standard-library/basic-string-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
namespace std {
template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>
class basic_stringbuf;
typedef basic_stringbuf<char>
stringbuf;
typedef basic_stringbuf<wchar_t> wstringbuf;

template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>
class basic_istringstream;
typedef basic_istringstream<char>
istringstream;
typedef basic_istringstream<wchar_t> wistringstream;

template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>
class basic_ostringstream;
typedef basic_ostringstream<char>
ostringstream;
typedef basic_ostringstream<wchar_t> wostringstream;

template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>>
class basic_stringstream;
typedef basic_stringstream<char>
stringstream;
typedef basic_stringstream<wchar_t> wstringstream;
// TEMPLATE FUNCTIONS
template <class CharType, class Traits, class Allocator>
void swap(
    basic_stringbuf<CharType, Traits, Allocator>& left,
    basic_stringbuf<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
void swap(
    basic_istringstream<CharType, Traits, Allocator>& left,
    basic_istringstream<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
void swap(
    basic_ostringstream<CharType, Traits, Allocator>& left,
    basic_ostringstream<CharType, Traits, Allocator>& right);

template <class CharType, class Traits, class Allocator>
void swap (
    basic_stringstream<CharType, Traits, Allocator>& left,
    basic_stringstream<CharType, Traits, Allocator>& right);

}  // namespace std
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*left*|Referência para um objeto `sstream`.|
|*right*|Referência para um objeto `sstream`.|

## <a name="remarks"></a>Comentários

Objetos do tipo `char *` podem usar a funcionalidade em [\<strstream>](../standard-library/strstream.md) para streaming. No entanto, \<strstream > foi preterido e o uso de \<sstream > é recomendado.

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[istringstream](../standard-library/sstream-typedefs.md#istringstream)|Cria um tipo `basic_istringstream` especializado em uma **char** parâmetro de modelo.|
|[ostringstream](../standard-library/sstream-typedefs.md#ostringstream)|Cria um tipo `basic_ostringstream` especializado em uma **char** parâmetro de modelo.|
|[stringbuf](../standard-library/sstream-typedefs.md#stringbuf)|Cria um tipo `basic_stringbuf` especializado em uma **char** parâmetro de modelo.|
|[stringstream](../standard-library/sstream-typedefs.md#stringstream)|Cria um tipo `basic_stringstream` especializado em uma **char** parâmetro de modelo.|
|[wistringstream](../standard-library/sstream-typedefs.md#wistringstream)|Cria um tipo `basic_istringstream` especializado em uma **wchar_t** parâmetro de modelo.|
|[wostringstream](../standard-library/sstream-typedefs.md#wostringstream)|Cria um tipo `basic_ostringstream` especializado em uma **wchar_t** parâmetro de modelo.|
|[wstringbuf](../standard-library/sstream-typedefs.md#wstringbuf)|Cria um tipo `basic_stringbuf` especializado em uma **wchar_t** parâmetro de modelo.|
|[wstringstream](../standard-library/sstream-typedefs.md#wstringstream)|Cria um tipo `basic_stringstream` especializado em uma **wchar_t** parâmetro de modelo.|

### <a name="manipulators"></a>Manipuladores

|||
|-|-|
|[swap](../standard-library/sstream-functions.md#sstream_swap)|Troca os valores de dois objetos `sstream`.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[basic_stringbuf](../standard-library/basic-stringbuf-class.md)|Descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, para e de uma sequência de elementos armazenados em um objeto de matriz.|
|[basic_istringstream](../standard-library/basic-istringstream-class.md)|Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)<**Elem**, **Tr**, `Alloc`>, com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, e cujos elementos são alocados por um alocador de classe `Alloc`.|
|[basic_ostringstream](../standard-library/basic-ostringstream-class.md)|Descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)<**Elem**, **Tr**, `Alloc`>, com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, e cujos elementos são alocados por um alocador de classe `Alloc`.|
|[basic_stringstream](../standard-library/basic-stringstream-class.md)|Descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)<**Elem**, **Tr**, `Alloc`>, com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, e cujos elementos são alocados por um alocador de classe `Alloc`.|

## <a name="requirements"></a>Requisitos

- **Cabeçalho:** \<sstream>

- **Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
