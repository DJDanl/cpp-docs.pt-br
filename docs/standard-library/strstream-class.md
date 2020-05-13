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
ms.openlocfilehash: 047b7e9d7fdece75137980b013d43abf1d5e3ec3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376624"
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
|[Congelar](#freeze)|Faz com que um buffer de fluxo esteja indisponível por meio de operações de buffer de fluxo.|
|[pcount](#pcount)|Retorna uma contagem do número de elementos gravados na sequência controlada.|
|[rdbuf](#rdbuf)|Retorna um ponteiro para o objeto `strstreambuf` associado do fluxo.|
|[Str](#str)|Chama [freeze](../standard-library/strstreambuf-class.md#freeze) e retorna um ponteiro para o início da sequência controlada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<strstream>

**Namespace:** std

## <a name="strstreamfreeze"></a><a name="freeze"></a>strstream::congelamento

Faz com que um buffer de fluxo esteja indisponível por meio de operações de buffer de fluxo.

```cpp
void freeze(bool _Freezeit = true);
```

### <a name="parameters"></a>Parâmetros

*_Freezeit*\
Uma **vaia** indicando se você quer que o córrego seja congelado.

### <a name="remarks"></a>Comentários

A função membro chama [rdbuf](#rdbuf) -> [freeze](../standard-library/strstreambuf-class.md#freeze)(_ *Freezeit*).

### <a name="example"></a>Exemplo

Consulte [strstreambuf::freeze](../standard-library/strstreambuf-class.md#freeze) para um `freeze`exemplo que usa .

## <a name="strstreampcount"></a><a name="pcount"></a>strstream::pcontagem

Retorna uma contagem do número de elementos gravados na sequência controlada.

```cpp
streamsize pcount() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos gravados na sequência controlada.

### <a name="remarks"></a>Comentários

A função membro retorna [a contagem rdbuf](#rdbuf) -> [pcount](../standard-library/strstreambuf-class.md#pcount).

### <a name="example"></a>Exemplo

Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#pcount) para ver uma amostra que usa pcount.

## <a name="strstreamrdbuf"></a><a name="rdbuf"></a>strstream::rdbuf

Retorna um ponteiro para o objeto strstreambuf associado ao fluxo.

```cpp
strstreambuf *rdbuf() const
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto strstreambuf associado ao fluxo.

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do `pointer` buffer de fluxo armazenado do tipo para [strstreambuf](../standard-library/strstreambuf-class.md).

### <a name="example"></a>Exemplo

Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#pcount) para ver uma amostra que usa `rdbuf`.

## <a name="strstreamstr"></a><a name="str"></a>strstream::str

Chama [freeze](../standard-library/strstreambuf-class.md#freeze) e retorna um ponteiro para o início da sequência controlada.

```cpp
char *str();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o início da sequência controlada.

### <a name="remarks"></a>Comentários

A função membro retorna [rdbuf](#rdbuf) -> [str](../standard-library/strstreambuf-class.md#str).

### <a name="example"></a>Exemplo

Consulte [strstreambuf::str](../standard-library/strstreambuf-class.md#str) para obter `str`uma amostra que usa .

## <a name="strstreamstrstream"></a><a name="strstream"></a>strstream::strstream

Constrói um objeto do tipo `strstream`.

```cpp
strstream();

strstream(char* ptr,
    streamsize count,
    ios_base::openmode _Mode = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

*Contar*\
O tamanho do buffer.

*_Mode*\
O modo de entrada e saída do buffer. Consulte [ios_base::openmode](../standard-library/ios-base-class.md#openmode) para obter mais informações.

*Ptr*\
O buffer.

### <a name="remarks"></a>Comentários

Ambos os construtores inicializam a classe base chamando `sb` [streambuf](../standard-library/streambuf-typedefs.md#streambuf) **(sb),** onde está o objeto armazenado de [classe strstreambuf](../standard-library/strstreambuf-class.md). O primeiro construtor também `sb` se inicia chamando [de strstreambuf](../standard-library/strstreambuf-class.md#strstreambuf). O segundo construtor inicializa a classe base com uma de duas maneiras:

- Se `_Mode`  &  **ios_base::app**== 0, então *ptr* deve designar o primeiro elemento de uma matriz de `count` elementos, e o construtor `strstreambuf`chama ( `ptr`, `count`, ). `ptr`

- Caso contrário, *ptr* deve designar o primeiro elemento de uma matriz de elementos de contagem que contém `ptr`  +  `strlen`uma `ptr`seqüência C cujo primeiro elemento é designado por *ptr*, e o construtor chama `strstreambuf`( `ptr`, `count`, ( ) .

## <a name="see-also"></a>Confira também

[Iostream](../standard-library/istream-typedefs.md#iostream)\
[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
