---
title: Matrizes em expressões | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- expressions [C++], arrays in
- arrays [C++], in expressions
ms.assetid: 6e5a795b-d6bd-4e39-b313-6a20d47c4d4b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 34f8a45dfa9de9a5a48e13cb6a38f667e5963f2d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46068540"
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