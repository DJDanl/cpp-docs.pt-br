---
title: Construindo objetos de fluxo de saída | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- output stream objects
ms.assetid: 93c8eab6-610c-4f48-b76d-1d960cac7641
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ff3c924327c11d00dd9137a91ebd19ef7bdc9eaa
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33850060"
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
