---
title: Classe istrstream
ms.date: 11/04/2016
f1_keywords:
- strstream/std::istrstream::rdbuf
- strstream/std::istrstream::str
helpviewer_keywords:
- istrstream class
ms.assetid: c2d41c75-bd2c-4437-bd77-5939ce1b97af
ms.openlocfilehash: 37118772f7cefd6f380ceb01908da55500ee7ab5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228226"
---
# <a name="istrstream-class"></a>Classe istrstream

Descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
class istrstream : public istream
```

## <a name="remarks"></a>Comentários

O objeto armazena um objeto da classe `strstreambuf`.

> [!NOTE]
> Essa classe foi preterida. Considere usar [istringstream](../standard-library/sstream-typedefs.md#istringstream) ou [wistringstream](../standard-library/sstream-typedefs.md#wistringstream) em vez disso.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[istrstream](#istrstream)|Constrói um objeto do tipo `istrstream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[rdbuf](#rdbuf)|Retorna um ponteiro para o objeto `strstreambuf` associado do fluxo.|
|[str](#str)|Chama [freeze](../standard-library/strstreambuf-class.md#freeze) e retorna um ponteiro para o início da sequência controlada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<strstream>

**Namespace:** std

## <a name="istrstreamistrstream"></a><a name="istrstream"></a>istrstream::istrstream

Constrói um objeto do tipo `istrstream`.

```cpp
explicit istrstream(
    const char* ptr);

explicit istrstream(
    char* ptr);

istrstream(
    const char* ptr,
    streamsize count);

istrstream(
    char* ptr,
    int count);
```

### <a name="parameters"></a>parâmetros

*contar*\
O comprimento do buffer (*PTR*).

*PTR*\
O conteúdo com que o buffer é inicializado.

### <a name="remarks"></a>Comentários

Todos os construtores inicializam a classe base chamando [IStream](../standard-library/istream-typedefs.md#istream)(**SB**), em que `sb` é o objeto armazenado da classe [strstreambuf](../standard-library/strstreambuf-class.md). Os dois primeiros construtores também são inicializados `sb` chamando `strstreambuf( ( const char *) ptr, 0 )` . Em vez disso, os dois construtores restantes chamam `strstreambuf( ( const char *) ptr, count )` .

## <a name="istrstreamrdbuf"></a><a name="rdbuf"></a>istrstream::rdbuf

Retorna um ponteiro para o objeto strstreambuf associado ao fluxo.

```cpp
strstreambuf *rdbuf() const
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto strstreambuf associado ao fluxo.

### <a name="remarks"></a>Comentários

A função membro retorna o endereço do buffer de fluxo armazenado do tipo pointer para [strstreambuf](../standard-library/strstreambuf-class.md).

### <a name="example"></a>Exemplo

Consulte [strstreambuf::pcount](../standard-library/strstreambuf-class.md#pcount) para ver uma amostra que usa `rdbuf`.

## <a name="istrstreamstr"></a><a name="str"></a>istrstream:: Str

Chama [freeze](../standard-library/strstreambuf-class.md#freeze) e retorna um ponteiro para o início da sequência controlada.

```cpp
char *str();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o início da sequência controlada.

### <a name="remarks"></a>Comentários

A função member retorna [rdbuf](#rdbuf)  ->  [Str](../standard-library/strstreambuf-class.md#str).

### <a name="example"></a>Exemplo

Consulte [strstream:: Str](../standard-library/strstreambuf-class.md#str) para obter um exemplo que usa `str` .

## <a name="see-also"></a>Confira também

[IStream](../standard-library/istream-typedefs.md#istream)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
