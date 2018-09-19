---
title: Aviso (nível 1) do compilador C4600 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4600
dev_langs:
- C++
helpviewer_keywords:
- C4600
ms.assetid: f023a2a1-7fc4-463f-a434-dc93fcd3f4e9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 27b020fdd87e35633b6a6da74d8c51c63fc1604e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079356"
---
# <a name="compiler-warning-level-1-c4600"></a>Aviso (nível 1) do compilador C4600

\#pragma 'nome de macro': espera-se uma cadeia de caracteres não vazia válida

Você não pode especificar uma cadeia de caracteres vazia quando você enviar por push ou inserir um nome de macro com qualquer um de [pop_macro](../../preprocessor/pop-macro.md) ou [push_macro](../../preprocessor/push-macro.md).

O exemplo a seguir gera C4600:

```
// C4600.cpp
// compile with: /W1
int main()
{
   #pragma push_macro("")   // C4600 passing an empty string
}
```