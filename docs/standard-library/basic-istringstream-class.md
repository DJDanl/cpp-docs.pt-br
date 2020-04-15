---
title: Classe basic_istringstream
ms.date: 11/04/2016
f1_keywords:
- sstream/std::basic_istringstream
- sstream/std::basic_istringstream::allocator_type
- sstream/std::basic_istringstream::rdbuf
- sstream/std::basic_istringstream::str
- sstream/std::basic_istringstream::swap
helpviewer_keywords:
- std::basic_istringstream [C++]
- std::basic_istringstream [C++], allocator_type
- std::basic_istringstream [C++], rdbuf
- std::basic_istringstream [C++], str
- std::basic_istringstream [C++], swap
ms.assetid: 1d5bb4b5-793d-4833-98e5-14676c451915
ms.openlocfilehash: 6a8ead5f1014e7f750e01988241ab020431312da
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376798"
---
# <a name="basic_istringstream-class"></a>Classe basic_istringstream

Descreve um objeto que controla a extração de elementos e objetos codificados a partir de um tampão de fluxo de classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**, `Alloc`>.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>
class basic_istringstream : public basic_istream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Alloc*\
A classe do alocador.

*Elem*\
O tipo do elemento básico da cadeia de caracteres.

*Tr*\
As características de caractere especializadas no elemento básico da cadeia de caracteres.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que controla a extração de elementos e `Alloc` objetos codificados a partir de um tampão de fluxo de classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**,>, com elementos do tipo *Elem,* cujos traços de caráter são determinados pela classe *Tr*, e cujos elementos são alocados por um alocador da classe *Alloc*. O objeto armazena um objeto da classe basic_stringbuf< **Elem**, **Tr**, `Alloc`>.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_istringstream](#basic_istringstream)|Constrói um objeto do tipo `basic_istringstream`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|O tipo é um sinônimo do parâmetro de modelo `Alloc`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer `pointer` de fluxo `Alloc` armazenado do tipo para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< `Elem`, `Tr`>.|
|[Str](#str)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|
|[Trocar](#swap)|Troca os valores nesse objeto `basic_istringstream` por aqueles do objeto fornecido.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador=](#op_eq)|Atribui os valores a esse objeto `basic_istringstream` do parâmetro de objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<sstream>

**Namespace:** std

## <a name="basic_istringstreamallocator_type"></a><a name="allocator_type"></a>basic_istringstream:allocator_type

O tipo é um sinônimo do parâmetro de modelo `Alloc`.

```cpp
typedef Alloc allocator_type;
```

## <a name="basic_istringstreambasic_istringstream"></a><a name="basic_istringstream"></a>basic_istringstream::basic_istringstream

Constrói um objeto do tipo `basic_istringstream`.

```cpp
explicit basic_istringstream(
    ios_base::openmode _Mode = ios_base::in);

explicit basic_istringstream(
    const basic_string<Elem, Tr, Alloc>& str,
    ios_base::openmode _Mode = ios_base::in);

basic_istringstream(
    basic_istringstream&& right);
```

### <a name="parameters"></a>Parâmetros

*_Mode*\
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*Str*\
Um objeto do tipo `basic_string`.

*Certo*\
Uma referência rvalue de um objeto `basic_istringstream`.

### <a name="remarks"></a>Comentários

O primeiro construtor inicia a classe base`sb`chamando `sb` [basic_istream](../standard-library/basic-istream-class.md)( ), onde `Tr` `Alloc` está o objeto armazenado de [classe basic_stringbuf](../standard-library/basic-stringbuf-class.md)< `Elem`, ,>. Também inicializa `sb` chamando `basic_stringbuf`< `Elem`, `Tr`, `Alloc`>( `_Mode` &#124; `ios_base::in`).

O segundo construtor inicializa a classe base chamando `basic_istream(sb)`. Também inicializa `sb` chamando `basic_stringbuf`< `Elem`, `Tr`, `Alloc`>( `str`, `_Mode` &#124; `ios_base::in`).

O terceiro construtor inicializa o objeto com o conteúdo do *direito,* tratado como referência de valor.

## <a name="basic_istringstreamoperator"></a><a name="op_eq"></a>basic_istringstream::operador=

Atribui os valores a esse objeto `basic_istringstream` do parâmetro de objeto.

```cpp
basic_istringstream& operator=(basic_istringstream&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência rvalue a um objeto `basic_istringstream`.

### <a name="remarks"></a>Comentários

O operador membro substitui o conteúdo do objeto pelo conteúdo do *direito,* tratado como uma atribuição de movimento de referência de valor.

## <a name="basic_istringstreamrdbuf"></a><a name="rdbuf"></a>basic_istringstream::rdbuf

Retorna o endereço do buffer `pointer` de fluxo armazenado do `Alloc` tipo para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**,>.

```cpp
basic_stringbuf<Elem, Tr, Alloc> *rdbuf() const;
```

### <a name="return-value"></a>Valor retornado

O endereço do buffer de `pointer` fluxo armazenado do tipo `Alloc` para basic_stringbuf **< Elem**, **Tr**,>.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.

## <a name="basic_istringstreamstr"></a><a name="str"></a>basic_istringstream::str

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

## <a name="basic_istringstreamswap"></a><a name="swap"></a>basic_istringstream::swap

Troca os valores de dois objetos `basic_istringstream`.

```cpp
void swap(basic_istringstream& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Certo*|Uma referência `lvalue` a um objeto `basic_istringstream`.|

### <a name="remarks"></a>Comentários

A função membro troca os valores deste objeto e os valores do *direito*.

## <a name="see-also"></a>Confira também

[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
