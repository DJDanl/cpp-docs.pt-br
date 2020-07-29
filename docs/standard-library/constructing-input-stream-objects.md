---
title: Construindo objetos de fluxo de entrada
ms.date: 11/04/2016
helpviewer_keywords:
- input stream objects
ms.assetid: ab94866e-6ffe-4f15-b4db-0bd23e636075
ms.openlocfilehash: f281741979680fc03d3f96d2dbfbac6e1feefdea
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228304"
---
# <a name="constructing-input-stream-objects"></a>Construindo objetos de fluxo de entrada

Se você usar somente o objeto `cin`, não será necessário construir um fluxo de entrada. Será necessário construir um fluxo de entrada se você usar:

- [Construtores de fluxo de arquivo de entrada](#vclrfinputfilestreamconstructorsanchor8)

- [Construtores de fluxo de cadeia de caracteres de entrada](#vclrfinputstringstreamconstructorsanchor9)

## <a name="input-file-stream-constructors"></a><a name="vclrfinputfilestreamconstructorsanchor8"></a> Construtores de fluxo de arquivo de entrada

Há duas maneiras de criar um fluxo de arquivo de entrada:

- Use o **`void`** Construtor de argumento e, em seguida, chame a `open` função de membro:

   ```cpp
   ifstream myFile; // On the stack
   myFile.open("filename");

   ifstream* pmyFile = new ifstream; // On the heap
   pmyFile->open("filename");
   ```

- Especifique um nome de arquivo e sinalizadores de modo na invocação do construtor, abrindo o arquivo durante o processo de construção:

   ```cpp
   ifstream myFile("filename");
   ```

## <a name="input-string-stream-constructors"></a><a name="vclrfinputstringstreamconstructorsanchor9"></a> Construtores de fluxo de cadeia de caracteres de entrada

Construtores de fluxo de cadeia de caracteres de entrada exigem o endereço do armazenamento pré-alocado e pré-inicializado:

```cpp
string s("123.45");

double amt;
istringstream myString(s);

//istringstream myString("123.45") also works
myString>> amt; // amt contains 123.45
```

## <a name="see-also"></a>Confira também

[Fluxos de entrada](../standard-library/input-streams.md)
