---
title: Classe basic_stringstream
ms.date: 11/04/2016
f1_keywords:
- sstream/std::basic_stringstream
- sstream/std::basic_stringstream::allocator_type
- sstream/std::basic_stringstream::rdbuf
- sstream/std::basic_stringstream::str
helpviewer_keywords:
- std::basic_stringstream [C++]
- std::basic_stringstream [C++], allocator_type
- std::basic_stringstream [C++], rdbuf
- std::basic_stringstream [C++], str
ms.assetid: 49629814-ca37-45c5-931b-4ff894e6ebd2
ms.openlocfilehash: f08689b1080837f042abfb3c4c52bb0ad558a448
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364865"
---
# <a name="basic_stringstream-class"></a>Classe basic_stringstream

Descreve um objeto que controla a inserção e extração de elementos e `Alloc` objetos codificados usando um buffer de fluxo de classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**,>.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>
class basic_stringstream : public basic_iostream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Alloc*\
A classe do alocador.

*Elem*\
O tipo do elemento básico da cadeia de caracteres.

*Tr*\
As características de caractere especializadas no elemento básico da cadeia de caracteres.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que controla a inserção e extração de `Alloc` elementos e objetos codificados usando um `Tr`tampão de fluxo de classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**,>, com elementos de tipo, `Elem`cujos traços de caráter são determinados pela classe, e cujos elementos são alocados por um alocador de classe. `Alloc` O objeto armazena um objeto da classe basic_stringbuf< **Elem**, **Tr**, `Alloc`>.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_stringstream](#basic_stringstream)|Constrói um objeto do tipo `basic_stringstream`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|O tipo é um sinônimo do parâmetro de modelo `Alloc`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer `pointer` de fluxo `Alloc` armazenado do tipo para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< `Elem`, `Tr`>.|
|[Str](#str)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<sstream>

**Namespace:** std

## <a name="basic_stringstreamallocator_type"></a><a name="allocator_type"></a>basic_stringstream:allocator_type

O tipo é um sinônimo do parâmetro de modelo `Alloc`.

```cpp
typedef Alloc allocator_type;
```

## <a name="basic_stringstreambasic_stringstream"></a><a name="basic_stringstream"></a>basic_stringstream:basic_stringstream

Constrói um objeto do tipo `basic_stringstream`.

```cpp
explicit basic_stringstream(ios_base::openmode _Mode = ios_base::in | ios_base::out);

explicit basic_stringstream(const basic_string<Elem, Tr, Alloc>& str, ios_base::openmode _Mode = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*Str*\
Um objeto do tipo `basic_string`.

### <a name="remarks"></a>Comentários

O primeiro construtor inicia a classe [basic_iostream](../standard-library/basic-iostream-class.md)base chamando basic_iostream `sb` ( **sb),** onde está o `Alloc` objeto armazenado da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**,>. Também se inicia `sb` chamando basic_stringbuf< **Elem** `_Mode`, **Tr**, `Alloc`>.

O segundo construtor inicializa a classe base chamando basic_iostream(**sb**). Também se inicia `sb` chamando basic_stringbuf **< Elem**, **Tr**, `Alloc`>(_ *Str).* `_Mode`

## <a name="basic_stringstreamrdbuf"></a><a name="rdbuf"></a>basic_stringstream:rdbuf

Retorna o endereço do buffer de fluxo armazenado do tipo **pointer** para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**, `Alloc`>.

```cpp
basic_stringbuf<Elem, Tr, Alloc> *rdbuf() const;
```

### <a name="return-value"></a>Valor retornado

O endereço do buffer de `pointer` fluxo armazenado do tipo `Alloc` para basic_stringbuf **< Elem**, **Tr**,>.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.

## <a name="basic_stringstreamstr"></a><a name="str"></a>basic_stringstream::str

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
