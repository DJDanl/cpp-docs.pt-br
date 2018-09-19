---
title: CXX0045 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0045
dev_langs:
- C++
helpviewer_keywords:
- CXX0045
- CAN0045
ms.assetid: 32181bc8-e79c-4ad7-a82f-47c62ec06d7d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d9913bc77dfc3fbc95bd03fd32c954c4d304d27
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46023196"
---
# <a name="expression-evaluator-error-cxx0045"></a>Erro CXX0045 (avaliador de expressão)

não é uma função

Uma lista de argumentos foi fornecida para um símbolo no programa que não é o nome de uma função.

## <a name="example"></a>Exemplo

```
queue( alpha, beta )
```

Quando `queue` não é uma função.

Esse erro é idêntico ao CAN0045.