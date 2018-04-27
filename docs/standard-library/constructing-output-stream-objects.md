---
title: Construindo objetos de fluxo de saída | Microsoft Docs
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
- output stream objects
ms.assetid: 93c8eab6-610c-4f48-b76d-1d960cac7641
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: debc39987efffe149b8b7834ba5416027acadf4e
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="constructing-output-stream-objects"></a>Construindo objetos de fluxo de saída

Se você usar apenas os objetos `cout`, `cerr` ou `clog` predefinidos, não será necessário construir um fluxo de saída. É necessário usar construtores para:

- [Construtores de fluxo de arquivo de saída](#vclrfoutputfilestreamconstructorsanchor1)

- [Construtores de fluxo de cadeia de caracteres de saída](#vclrfoutputstringstreamconstructorsanchor2)

## <a name="vclrfoutputfilestreamconstructorsanchor1"></a> Construtores de fluxo de arquivo de saída

É possível construir um fluxo de arquivo de saída de duas maneiras:

- Usar o construtor padrão e, em seguida, chamar a função de membro `open`.

   ```cpp
   ofstream myFile; // Static or on the stack
   myFile.open("filename");

   ofstream* pmyFile = new ofstream; // On the heap
   pmyFile->open("filename");
   ```

- Especificar um nome de arquivo e sinalizadores de modo na chamada do construtor.

   ```cpp
   ofstream myFile("filename", ios_base::out);
   ```

## <a name="vclrfoutputstringstreamconstructorsanchor2"></a> Construtores de fluxo de cadeia de caracteres de saída

Para construir um fluxo de cadeia de caracteres de saída, é possível usar `ostringstream` da seguinte maneira:

```cpp
using namespace std;
// ...
ostringstream myString;
myString << "this is a test" << ends;

string sp = myString.str(); // Obtain string
cout << sp << endl;
```

O “manipulador” `ends` adiciona o caractere nulo de terminação necessário à cadeia de caracteres.

## <a name="see-also"></a>Consulte também

[Fluxos de saída](../standard-library/output-streams.md)<br/>
