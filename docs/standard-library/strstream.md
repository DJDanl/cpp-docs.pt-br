---
title: '&lt;strstream&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- <strstream>
dev_langs:
- C++
helpviewer_keywords:
- strstream header
ms.assetid: eaa9d0d4-d217-4f28-8a68-9b9ad7b1c0f5
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f63ecc2f24431e54042a1b995762806f87c691da
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="ltstrstreamgt"></a>&lt;strstream&gt;

Define várias classes que dão suporte a operações de iostreams em sequências armazenadas em uma matriz alocada do `char` objeto. Essas sequências facilmente são convertidas em cadeias de caracteres C.

## <a name="syntax"></a>Sintaxe

```cpp
#include <strstream>

```

## <a name="remarks"></a>Comentários

Objetos do tipo `strstream` funcionam com `char` *, que são cadeias de caracteres C. Use [ \<sstream >](../standard-library/sstream.md) para trabalhar com objetos do tipo [basic_string](../standard-library/basic-string-class.md).

> [!NOTE]
> As classes no \<strstream > foram preteridos. Considere usar as classes em \<sstream > em vez disso.

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe strstreambuf](../standard-library/strstreambuf-class.md)|A classe descreve um buffer de fluxo que controla a transmissão de elementos em uma sequência de elementos armazenados em um `char` objeto de matriz.|
|[Classe istrstream](../standard-library/istrstream-class.md)|A classe descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|
|[Classe ostrstream](../standard-library/ostrstream-class.md)|A classe descreve um objeto que controla a inserção de elementos e objetos codificados de um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|
|[Classe strstream](../standard-library/strstream-class.md)|A classe descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [strstreambuf](../standard-library/strstreambuf-class.md).|

## <a name="see-also"></a>Consulte também

[\<strstream>](../standard-library/strstream.md)<br/>
[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
