---
title: '&lt;strstream&gt;'
ms.date: 11/04/2016
f1_keywords:
- <strstream>
helpviewer_keywords:
- strstream header
ms.assetid: eaa9d0d4-d217-4f28-8a68-9b9ad7b1c0f5
ms.openlocfilehash: 13eea1101abca0f79f0d7c15405ceb3118707b67
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845647"
---
# <a name="ltstrstreamgt"></a>&lt;strstream&gt;

Define várias classes que dão suporte a operações iostreams em sequências armazenadas em uma matriz alocada de **`char`** objeto. Essas sequências facilmente são convertidas em cadeias de caracteres C.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<strstream>

**Namespace:** std

## <a name="remarks"></a>Comentários

Objetos do tipo `strstream` funcionam com **`char`** *, que são C cadeias de caracteres. Use [\<sstream>](../standard-library/sstream.md) para trabalhar com objetos do tipo [basic_string](../standard-library/basic-string-class.md).

> [!NOTE]
> As classes em \<strstream> são preteridas. Considere usar as classes em \<sstream>, em vez disso.

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[Classe strstreambuf](../standard-library/strstreambuf-class.md)|A classe descreve um buffer de fluxo que controla a transmissão de elementos de e para uma sequência de elementos armazenados em um **`char`** objeto de matriz.|
|[Classe istrstream](../standard-library/istrstream-class.md)|A classe descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|
|[Classe ostrstream](../standard-library/ostrstream-class.md)|A classe descreve um objeto que controla a inserção de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|
|[Classe strstream](../standard-library/strstream-class.md)|A classe descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|

### <a name="functions"></a>Funções

```cpp
void freeze(bool freezefl = true);
char* str();
int pcount();
```

## <a name="see-also"></a>Confira também

[\<strstream>](../standard-library/strstream.md)\
[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
