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
ms.openlocfilehash: fd2ab79466c01343cbdadbcb649e3b05eee3c2a0
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88561772"
---
# <a name="basic_istringstream-class"></a>Classe basic_istringstream

Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md) <  **elem**, **TR** `Alloc`>.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>
class basic_istringstream : public basic_istream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Alocação*\
A classe do alocador.

*Elem*\
O tipo do elemento básico da cadeia de caracteres.

*TR*\
As características de caractere especializadas no elemento básico da cadeia de caracteres.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo de classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md) <  **elem**, **TR** `Alloc`>, com elementos do tipo *elem*, cujas características de caractere são determinadas pela classe *TR*e cujos elementos são alocados por um alocador de classe *Alloc*. O objeto armazena um objeto da classe basic_stringbuf< **Elem**, **Tr**, `Alloc`>.

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
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado do tipo `pointer` para [basic_stringbuf](../standard-library/basic-stringbuf-class.md) <  `Elem` , `Tr` `Alloc`>.|
|[Str](#str)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|
|[permuta](#swap)|Troca os valores nesse objeto `basic_istringstream` por aqueles do objeto fornecido.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador =](#op_eq)|Atribui os valores a esse objeto `basic_istringstream` do parâmetro de objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<sstream>

**Namespace:** std

## <a name="basic_istringstreamallocator_type"></a><a name="allocator_type"></a> basic_istringstream:: allocator_type

O tipo é um sinônimo do parâmetro de modelo `Alloc`.

```cpp
typedef Alloc allocator_type;
```

## <a name="basic_istringstreambasic_istringstream"></a><a name="basic_istringstream"></a> basic_istringstream:: basic_istringstream

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

O primeiro construtor inicializa a classe base chamando [basic_istream](../standard-library/basic-istream-class.md)( `sb` ), em que `sb` é o objeto armazenado da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md) <  `Elem` , `Tr` , `Alloc`>. Também inicializa `sb` chamando `basic_stringbuf`< `Elem`, `Tr`, `Alloc`>( `_Mode` &#124; `ios_base::in`).

O segundo construtor inicializa a classe base chamando `basic_istream(sb)`. Também inicializa `sb` chamando `basic_stringbuf`< `Elem`, `Tr`, `Alloc`>( `str`, `_Mode` &#124; `ios_base::in`).

O terceiro construtor inicializa o objeto com o conteúdo de *Right*, tratado como uma referência rvalue.

## <a name="basic_istringstreamoperator"></a><a name="op_eq"></a> basic_istringstream:: Operator =

Atribui os valores a esse objeto `basic_istringstream` do parâmetro de objeto.

```cpp
basic_istringstream& operator=(basic_istringstream&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência rvalue a um objeto `basic_istringstream`.

### <a name="remarks"></a>Comentários

O operador member substitui o conteúdo do objeto pelo conteúdo de *Right*, tratado como uma atribuição de movimentação de referência de rvalue.

## <a name="basic_istringstreamrdbuf"></a><a name="rdbuf"></a> basic_istringstream:: rdbuf

Retorna o endereço do buffer de fluxo armazenado do tipo `pointer` para [basic_stringbuf](../standard-library/basic-stringbuf-class.md) <  **elem**, **TR** `Alloc`>.

```cpp
basic_stringbuf<Elem, Tr, Alloc> *rdbuf() const;
```

### <a name="return-value"></a>Valor retornado

O endereço do buffer de fluxo armazenado do tipo `pointer` para basic_stringbuf< **elem**, **TR** `Alloc`>.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.

## <a name="basic_istringstreamstr"></a><a name="str"></a> basic_istringstream:: Str

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

Retorna um objeto da classe [basic_string](../standard-library/basic-string-class.md) <  **elem**, **TR** `Alloc`>, cuja sequência controlada é uma cópia da sequência controlada por ** \* isso**.

### <a name="remarks"></a>Comentários

A primeira função de membro [rdbuf](#rdbuf)retorna o  ->  [Str](../standard-library/basic-stringbuf-class.md#str)rdbuf. A segunda função de membro chama `rdbuf`  ->  **Str**( `_Newstr` ).

### <a name="example"></a>Exemplo

Consulte [basic_stringbuf:: Str](../standard-library/basic-stringbuf-class.md#str) para obter um exemplo que usa `str` .

## <a name="basic_istringstreamswap"></a><a name="swap"></a> basic_istringstream:: swap

Troca os valores de dois objetos `basic_istringstream`.

```cpp
void swap(basic_istringstream& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência lvalue a um objeto `basic_istringstream`.

### <a name="remarks"></a>Comentários

A função membro troca os valores desse objeto e os valores de *direita*.

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
