---
title: Construindo objetos de fluxo de entrada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- input stream objects
ms.assetid: ab94866e-6ffe-4f15-b4db-0bd23e636075
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a63ba3d8e54e416313ec24d7455ca4cf70979b9f
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="constructing-input-stream-objects"></a>Construindo objetos de fluxo de entrada

Se você usar somente o objeto `cin`, não será necessário construir um fluxo de entrada. Será necessário construir um fluxo de entrada se você usar:

- [Construtores de fluxo de arquivo de entrada](#vclrfinputfilestreamconstructorsanchor8)

- [Construtores de fluxo de cadeia de caracteres de entrada](#vclrfinputstringstreamconstructorsanchor9)

## <a name="vclrfinputfilestreamconstructorsanchor8"></a> Construtores de fluxo de arquivo de entrada

Há duas maneiras de criar um fluxo de arquivo de entrada:

- Use o construtor de argumento `void` e, em seguida, chame a função de membro `open`:

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

## <a name="vclrfinputstringstreamconstructorsanchor9"></a> Construtores de fluxo de cadeia de caracteres de entrada

Construtores de fluxo de cadeia de caracteres de entrada exigem o endereço do armazenamento pré-alocado e pré-inicializado:

```cpp
string s("123.45");

double amt;
istringstream myString(s);

//istringstream myString("123.45") also works
myString>> amt; // amt contains 123.45
```

## <a name="see-also"></a>Consulte também

[Fluxos de entrada](../standard-library/input-streams.md)<br/>
