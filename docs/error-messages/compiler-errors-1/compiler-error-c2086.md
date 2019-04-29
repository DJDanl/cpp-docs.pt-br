---
title: Erro do compilador C2086
ms.date: 11/04/2016
f1_keywords:
- C2086
helpviewer_keywords:
- C2086
ms.assetid: 4329bf72-90c8-444c-8524-4ef75e6b2139
ms.openlocfilehash: 094a794627b886abc7db5ba4d74c6fe97ff82461
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62216120"
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