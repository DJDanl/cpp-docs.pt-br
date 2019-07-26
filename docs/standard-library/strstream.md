---
title: '&lt;strstream&gt;'
ms.date: 11/04/2016
f1_keywords:
- <strstream>
helpviewer_keywords:
- strstream header
ms.assetid: eaa9d0d4-d217-4f28-8a68-9b9ad7b1c0f5
ms.openlocfilehash: ecf8499a07f03c00588e7b7fd83b8d41a23e8e7a
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459093"
---
# <a name="ltstrstreamgt"></a>&lt;strstream&gt;

Define várias classes que dão suporte a operações iostreams em sequências armazenadas em uma matriz alocada de objeto **Char** . Essas sequências facilmente são convertidas em cadeias de caracteres C.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<strstream>

**Namespace:** std

## <a name="remarks"></a>Comentários

Objetos do tipo `strstream` funcionam com `char` *, que são cadeias de caracteres C. Use [ \<sstream >](../standard-library/sstream.md) para trabalhar com objetos do tipo [basic_string](../standard-library/basic-string-class.md).

> [!NOTE]
> As classes em \<strstream > foram preteridas. Considere usar as classes em \<sstream > em vez disso.

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe strstreambuf](../standard-library/strstreambuf-class.md)|A classe descreve um buffer de fluxo que controla a transmissão de elementos de e para uma sequência de elementos armazenados em um objeto de matriz **Char** .|
|[Classe istrstream](../standard-library/istrstream-class.md)|A classe descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|
|[Classe ostrstream](../standard-library/ostrstream-class.md)|A classe descreve um objeto que controla a inserção de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|
|[Classe strstream](../standard-library/strstream-class.md)|A classe descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|

### <a name="functions"></a>Funções

```cpp
void freeze(bool freezefl = true);
char* str();
int pcount();
```

## <a name="see-also"></a>Consulte também

[\<strstream>](../standard-library/strstream.md)\
[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
