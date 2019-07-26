---
title: Classe strstream
ms.date: 11/04/2016
f1_keywords:
- strstream/std::strstream::freeze
- strstream/std::strstream::pcount
- strstream/std::strstream::rdbuf
- strstream/std::strstream::str
helpviewer_keywords:
- std::strstream [C++], freeze
- std::strstream [C++], pcount
- std::strstream [C++], rdbuf
- std::strstream [C++], str
ms.assetid: 63f3be31-9e36-42b1-9715-a474a5997e2a
ms.openlocfilehash: 53baa350121796d5198211e1fdb08f4341df6b80
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459098"
---
# <a name="strstream-class"></a>Classe strstream

Descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
class strstream : public iostream
```

## <a name="remarks"></a>Comentários

O objeto armazena um objeto da classe `strstreambuf`.

> [!NOTE]
> Essa classe foi preterida. Considere usar [ostringstream](../standard-library/sstream-typedefs.md#stringstream) ou [wstringstream](../standard-library/sstream-typedefs.md#wstringstream) em vez disso.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[strstream](#strstream)|Constrói um objeto do tipo `strstream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[freeze](#freeze)|Faz com que um buffer de fluxo esteja indisponível por meio de operações de buffer de fluxo.|
|[pcount](#pcount)|Retorna uma contagem do número de elementos gravados na sequência controlada.|
|[rdbuf](#rdbuf)|Retorna um ponteiro para o objeto `strstreambuf` associado do fluxo.|
|[str](#str)|Chama [freeze](../standard-library/strstreambuf-class.md#freeze) e retorna um ponteiro para o início da sequência controlada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<strstream>

**Namespace:** std

## <a name="freeze"></a>  strstream::freeze

Faz com que um buffer de fluxo esteja indisponível por meio de operações de buffer de fluxo.

```cpp
void freeze(bool _Freezeit = true);
```

### <a name="parameters"></a>Parâmetros

*_Freezeit*\
Um **bool** que indica se você deseja que o fluxo seja congelado.

### <a name="remarks"></a>Comentários

A função membro chama [rdbuf](#rdbuf) -> [freeze](../standard-library/strstreambuf-class.md#freeze)(_ *Freezeit*).

### <a name="example"></a>Exemplo

Consulte [strstreambuf:: Freeze](../standard-library/strstreambuf-class.md#freeze) para obter um exemplo que `freeze`usa.

## <a name="pcount"></a>  strstream::pcount

Retorna uma contagem do número de elementos gravados na sequência controlada.

```cpp
streamsize pcount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos gravados na sequência controlada.

### <a name="remarks"></a>Comentários

A função membro retorna [rdbuf](#rdbuf) -> [pcount](../standard-library/strstreambuf-class.md#pcount).

### <a name="example"></a>Exemplo

Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#pcount) para ver uma amostra que usa pcount.

## <a name="rdbuf"></a>  strstream::rdbuf

Retorna um ponteiro para o objeto strstreambuf associado ao fluxo.

```cpp
strstreambuf *rdbuf() const
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto strstreambuf associado ao fluxo.

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do buffer de fluxo armazenado do tipo `pointer` para [strstreambuf](../standard-library/strstreambuf-class.md).

### <a name="example"></a>Exemplo

Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#pcount) para ver uma amostra que usa `rdbuf`.

## <a name="str"></a>  strstream::str

Chama [freeze](../standard-library/strstreambuf-class.md#freeze) e retorna um ponteiro para o início da sequência controlada.

```cpp
char *str();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o início da sequência controlada.

### <a name="remarks"></a>Comentários

A função membro retorna [rdbuf](#rdbuf) -> [str](../standard-library/strstreambuf-class.md#str).

### <a name="example"></a>Exemplo

Consulte [strstreambuf:: Str](../standard-library/strstreambuf-class.md#str) para obter um exemplo que `str`usa.

## <a name="strstream"></a>  strstream::strstream

Constrói um objeto do tipo `strstream`.

```cpp
strstream();

strstream(char* ptr,
    streamsize count,
    ios_base::openmode _Mode = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

*contar*\
O tamanho do buffer.

*_Mode*\
O modo de entrada e saída do buffer. Consulte [ios_base::openmode](../standard-library/ios-base-class.md#openmode) para obter mais informações.

*PTR*\
O buffer.

### <a name="remarks"></a>Comentários

Ambos os construtores inicializam a classe base chamando [streambuf](../standard-library/streambuf-typedefs.md#streambuf)( **SB**), em `sb` que é o objeto armazenado da classe [strstreambuf](../standard-library/strstreambuf-class.md). O primeiro construtor também é `sb` inicializado chamando [strstreambuf](../standard-library/strstreambuf-class.md#strstreambuf). O segundo construtor inicializa a classe base com uma de duas maneiras:

- Se `_Mode` `strstreambuf` `ptr` `count` `count` `ptr`  ios_base:: App = = 0, PTR deverá designar o primeiro elemento de uma matriz de elementos e o Construtor chamará (,,)  &  .

- Caso contrário *, PTR* deve designar o primeiro elemento de uma matriz de elementos de contagem que contém uma cadeia de caracteres C cujo primeiro elemento é designado por *PTR*e `strstreambuf`o construtor `count`chama `ptr` ( `ptr`,,  +  `strlen`( `ptr`) ).

## <a name="see-also"></a>Consulte também

[iostream](../standard-library/istream-typedefs.md#iostream)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
