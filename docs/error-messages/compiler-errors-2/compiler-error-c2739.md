---
title: Erro do compilador C2739 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2739
dev_langs:
- C++
helpviewer_keywords:
- C2739
ms.assetid: 5b63e435-7631-43d7-805e-f2adefb7e517
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b4e6c757823caa25bd9df890dce35035642e5212
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46046661"
---
# <a name="compiler-error-c2739"></a>Erro do compilador C2739

'número': gerenciado explícita ou dimensões de matriz do WinRT devem estar entre 1 e 32

Uma dimensão de matriz não era entre 1 e 32.

O exemplo a seguir gera C2739 e mostra como corrigi-lo:

```
// C2739.cpp
// compile with: /clr
int main() {
   array<int, -1>^a;   // C2739
   // try the following line instead
   // array<int, 2>^a;
}
```