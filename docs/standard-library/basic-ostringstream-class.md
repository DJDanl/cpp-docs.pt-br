---
title: Classe basic_ostringstream | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- sstream/std::basic_ostringstream
- sstream/std::basic_ostringstream::allocator_type
- sstream/std::basic_ostringstream::rdbuf
- sstream/std::basic_ostringstream::str
dev_langs:
- C++
helpviewer_keywords:
- std::basic_ostringstream [C++]
- std::basic_ostringstream [C++], allocator_type
- std::basic_ostringstream [C++], rdbuf
- std::basic_ostringstream [C++], str
ms.assetid: aea699f7-350f-432a-acca-adbae7b483fb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1fb0027ba6afbceed8cc5f1daafef8cb183759ce
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38955228"
---
# <a name="basicostringstream-class"></a>Classe basic_ostringstream

Descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**, `Alloc`>.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>, class Alloc = allocator<Elem>>
class basic_ostringstream : public basic_ostream<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*Alocação* a classe do alocador.

*Elem* o tipo do elemento básico da cadeia de caracteres.

*TR* as características de caractere especializadas no elemento básico da cadeia de caracteres.

## <a name="remarks"></a>Comentários

A classe descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, e cujos elementos são alocados por um alocador de classe `Alloc`. O objeto armazena um objeto da classe basic_stringbuf< **Elem**, **Tr**, `Alloc`>.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_ostringstream](#basic_ostringstream)|Constrói um objeto do tipo `basic_ostringstream`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|O tipo é um sinônimo do parâmetro de modelo *Alloc*.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[rdbuf](#rdbuf)|Retorna o endereço do buffer de fluxo armazenado do tipo `pointer` para [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< `Elem`, `Tr`, `Alloc`>.|
|[str](#str)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<sstream>

**Namespace:** std

## <a name="allocator_type"></a>  basic_ostringstream::allocator_type

O tipo é um sinônimo do parâmetro de modelo *Alloc*.

```cpp
typedef Alloc allocator_type;
```

## <a name="basic_ostringstream"></a>  basic_ostringstream::basic_ostringstream

Constrói um objeto do tipo basic_ostringstream.

```cpp
explicit basic_ostringstream(ios_base::openmode _Mode = ios_base::out);

explicit basic_ostringstream(const basic_string<Elem, Tr, Alloc>& str, ios_base::openmode _Mode = ios_base::out);
```

### <a name="parameters"></a>Parâmetros

*Modo* uma das enumerações nos [ios_base:: OpenMode](../standard-library/ios-base-class.md#openmode).

*STR* um objeto do tipo `basic_string`.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa a classe base chamando [basic_ostream](../standard-library/basic-ostream-class.md)( **sb**), onde `sb` é o objeto armazenado da classe [basic_stringbuf](../standard-library/basic-stringbuf-class.md) <  **Elem**, **Tr**, `Alloc`>. Também inicializa **sb** chamando basic_stringbuf< **Elem**, **Tr**, `Alloc`>( `_Mode` &#124; `ios_base::out`).

O segundo construtor inicializa a classe base chamando basic_ostream( **sb**). Também inicializa `sb` chamando basic_stringbuf < **Elem**, **Tr**, `Alloc`> (_ *Str*, `_Mode` &#124; `ios_base::out`).

## <a name="rdbuf"></a>  basic_ostringstream::rdbuf

Retorna o endereço do buffer de fluxo armazenado do tipo `pointer` à [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< **Elem**, **Tr**, `Alloc`>.

```cpp
basic_stringbuf<Elem, Tr, Alloc> *rdbuf() const;
```

### <a name="return-value"></a>Valor de retorno

O endereço do buffer de fluxo armazenado, do tipo `pointer` para basic_stringbuf < **Elem**, **Tr**, `Alloc`>.

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do buffer de fluxo armazenado do tipo `pointer` para basic_stringbuf < **Elem**, **Tr**, `Alloc`>.

### <a name="example"></a>Exemplo

Consulte [basic_filebuf::close](../standard-library/basic-filebuf-class.md#close) para ver um exemplo que usa `rdbuf`.

## <a name="str"></a>  basic_ostringstream::str

Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.

```cpp
basic_string<Elem, Tr, Alloc> str() const;


void str(
    const basic_string<Elem, Tr, Alloc>& _Newstr);
```

### <a name="parameters"></a>Parâmetros

*_Newstr* nova cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna um objeto da classe [basic_string](../standard-library/basic-string-class.md)< **Elem**, **Tr**, `Alloc`>, cuja sequência controlada é uma cópia da sequência controlada por **\*this**.

### <a name="remarks"></a>Comentários

A primeira função membro retorna [rdbuf](#rdbuf) -> [str](../standard-library/basic-stringbuf-class.md#str). As segunda função membro chama `rdbuf` -> **str**( `_Newstr`).

### <a name="example"></a>Exemplo

Ver [basic_stringbuf:: STR](../standard-library/basic-stringbuf-class.md#str) para obter um exemplo que usa `str`.

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
