---
title: Erro do compilador C2675 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2675
dev_langs:
- C++
helpviewer_keywords:
- C2675
ms.assetid: 4b92a12b-bff8-4dd5-a109-620065fc146c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1772f6e88516e7c8c1498f84d180ab6c4e0e05ab
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46102385"
---
# <a name="compiler-error-c2675"></a>Erro do compilador C2675

unário 'operator': 'type' não define este operador ou uma conversão para um tipo aceitável ao operador pré-definido

C2675 também podem ocorrer ao usar um operador unário, e o tipo não define o operador ou uma conversão para um tipo aceitável ao operador pré-definido. Para usar o operador, você deve sobrecarregá-lo para o tipo especificado ou definir uma conversão para um tipo para o qual o operador está definido.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2675.

```
// C2675.cpp
struct C {
   C(){}
} c;

struct D {
   D(){}
   void operator-(){}
} d;

int main() {
   -c;   // C2675
   -d;   // OK
}
```