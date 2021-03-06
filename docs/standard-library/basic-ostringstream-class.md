---
title: Classe basic_ostringstream
ms.date: 11/04/2016
f1_keywords:
- sstream/std::basic_ostringstream
- sstream/std::basic_ostringstream::allocator_type
- sstream/std::basic_ostringstream::rdbuf
- sstream/std::basic_ostringstream::str
helpviewer_keywords:
- std::basic_ostringstream [C++]
- std::basic_ostringstream [C++], allocator_type
- std::basic_ostringstream [C++], rdbuf
- std::basic_ostringstream [C++], str
ms.assetid: aea699f7-350f-432a-acca-adbae7b483fb
ms.openlocfilehash: 9e10474d3e4fb2a37e8ab52f77495758c37e8a5b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376774"
---
# <a name="basic_ostringstream-class"></a>Classe basic_ostringstream

Descreve um objeto que controla a inserção de elementos e objetos `Alloc` codificados em um buffer de fluxo de classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**,>.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>
class basic_ostringstream : public basic_ostream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Alloc*\
A classe do alocador.

*Elem*\
O tipo do elemento básico da cadeia de caracteres.

*Tr*\
As características de caractere especializadas no elemento básico da cadeia de caracteres.

## <a name="remarks"></a>Comentários

A classe descreve um objeto que controla a inserção de elementos `Elem`e objetos codificados em `Tr`um buffer de fluxo, com elementos `Alloc`de tipo, cujos traços de caráter são determinados pela classe, e cujos elementos são alocados por um alocador de classe. O objeto armazena um objeto da classe basic_stringbuf< **Elem**, **Tr**, `Alloc`>.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_ostringstream](#basic_ostringstream)|Constrói um objeto do tipo `basic_ostringstream`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|O tipo é um sinônimo para o parâmetro de modelo *Alloc*.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer `pointer` de fluxo `Alloc` armazenado do tipo para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< `Elem`, `Tr`>.|
|[Str](#str)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<sstream>

**Namespace:** std

## <a name="basic_ostringstreamallocator_type"></a><a name="allocator_type"></a>basic_ostringstream:allocator_type

O tipo é um sinônimo para o parâmetro de modelo *Alloc*.

```cpp
typedef Alloc allocator_type;
```

## <a name="basic_ostringstreambasic_ostringstream"></a><a name="basic_ostringstream"></a>basic_ostringstream:basic_ostringstream

Constrói um objeto do tipo basic_ostringstream.

```cpp
explicit basic_ostringstream(ios_base::openmode _Mode = ios_base::out);

explicit basic_ostringstream(const basic_string<Elem, Tr, Alloc>& str, ios_base::openmode _Mode = ios_base::out);
```

### <a name="parameters"></a>Parâmetros

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*Str*\
Um objeto do tipo `basic_string`.

### <a name="remarks"></a>Comentários

O primeiro construtor inicia a classe [basic_ostream](../standard-library/basic-ostream-class.md)base chamando basic_ostream `sb` ( **sb),** onde está o `Alloc` objeto armazenado da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**,>. Também inicializa **sb** chamando basic_stringbuf< **Elem**, **Tr**, `Alloc`>( `_Mode` &#124; `ios_base::out`).

O segundo construtor inicializa a classe base chamando basic_ostream( **sb**). Também se inicia `sb` chamando basic_stringbuf **< Elem**, **Tr**, `Alloc`>(_ *Str*, `_Mode` &#124; `ios_base::out`).

## <a name="basic_ostringstreamrdbuf"></a><a name="rdbuf"></a>basic_ostringstream:rdbuf

Retorna o endereço do buffer `pointer` de fluxo armazenado do `Alloc` tipo para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**,>.

```cpp
basic_stringbuf<Elem, Tr, Alloc> *rdbuf() const;
```

### <a name="return-value"></a>Valor retornado

O endereço do buffer de `pointer` fluxo armazenado, de tipo `Alloc` para basic_stringbuf< **Elem**, **Tr**,>.

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do `pointer` buffer de fluxo armazenado `Alloc` do tipo para basic_stringbuf< **Elem**, **Tr**,>.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.

## <a name="basic_ostringstreamstr"></a><a name="str"></a>basic_ostringstream::str

Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.

```cpp
basic_string<Elem, Tr, Alloc> str() const;

void str(
    const basic_string<Elem, Tr, Alloc>& _Newstr);
```

### <a name="parameters"></a>Parâmetros

*_Newstr*\
A nova cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

Retorna um objeto [basic_string](../standard-library/basic-string-class.md)< de classe basic_string `Alloc` **Elem**, **Tr**,>, cuja seqüência controlada é uma cópia da seqüência controlada por ** \*esta**.

### <a name="remarks"></a>Comentários

A função do primeiro membro retorna [rdbuf](#rdbuf) -> [str](../standard-library/basic-stringbuf-class.md#str). A função do `rdbuf`  -> segundo `_Newstr`membro chama **str**( ).

### <a name="example"></a>Exemplo

Consulte [basic_stringbuf::str](../standard-library/basic-stringbuf-class.md#str) para um `str`exemplo que usa .

## <a name="see-also"></a>Confira também

[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
