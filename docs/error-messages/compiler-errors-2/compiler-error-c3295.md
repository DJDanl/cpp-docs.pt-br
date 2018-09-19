---
title: Erro do compilador C3295 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3295
dev_langs:
- C++
helpviewer_keywords:
- C3295
ms.assetid: 83f0aa4d-0e0a-4905-9f66-fcf9991fc07a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7b8210aacf60c4c53faf50278e7494c90c58aa67
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076418"
---
# <a name="compiler-error-c3295"></a>Erro do compilador C3295

'#pragma pragma' só pode ser usada em global ou escopo de namespace

Alguns pragmas não pode ser usado em uma função.  Ver [diretivas Pragma e a palavra-chave pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3295.

```
// C3295.cpp
int main() {
   #pragma managed   // C3295
}
```