---
title: Erro do compilador C2086
ms.date: 11/04/2016
f1_keywords:
- C2086
helpviewer_keywords:
- C2086
ms.assetid: 4329bf72-90c8-444c-8524-4ef75e6b2139
ms.openlocfilehash: 094a794627b886abc7db5ba4d74c6fe97ff82461
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50649729"
---
# <a name="compiler-error-c2086"></a>Erro do compilador C2086

'identifier': redefinição

O identificador está definido mais de uma vez, ou uma declaração subsequente é diferente da anterior.

C2086 também pode ser o resultado da compilação incremental para um assembly do c# referenciado. Recompile o assembly do c# para resolver esse erro.

O exemplo a seguir gera C2086:

```
// C2086.cpp
main() {
  int a;
  int a;   // C2086 not an error in ANSI C
}
```