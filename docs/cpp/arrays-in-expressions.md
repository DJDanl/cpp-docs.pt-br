---
title: Matrizes em expressões
ms.date: 11/04/2016
helpviewer_keywords:
- expressions [C++], arrays in
- arrays [C++], in expressions
ms.assetid: 6e5a795b-d6bd-4e39-b313-6a20d47c4d4b
ms.openlocfilehash: 0f2ef43c2a5bc4f8a44378c21d6d53b14f07ea07
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478163"
---
# <a name="arrays-in-expressions"></a>Matrizes em expressões

Quando um identificador de um tipo de matriz aparece em uma expressão diferente de `sizeof`, endereço de (**&**), inicialização ou de uma referência, ele será convertido em um ponteiro para o primeiro elemento da matriz. Por exemplo:

```cpp
char szError1[] = "Error: Disk drive not ready.";
char *psz = szError1;
```

O ponteiro `psz` aponta para o primeiro elemento da matriz `szError1`. Observe que as matrizes, ao contrário dos ponteiros, não são l-values modificáveis. Dessa forma, a atribuição a seguir é inválida:

```cpp
szError1 = psz;
```

## <a name="see-also"></a>Consulte também

[Matrizes](../cpp/arrays-cpp.md)