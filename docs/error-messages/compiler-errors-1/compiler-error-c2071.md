---
title: Erro do compilador C2071
ms.date: 11/04/2016
f1_keywords:
- C2071
helpviewer_keywords:
- C2071
ms.assetid: f8c09255-a5c4-47e3-8089-3d875ae43cc5
ms.openlocfilehash: 7619d968379bfc35e98bd87071b75296d10c382c
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743276"
---
# <a name="compiler-error-c2071"></a>Erro do compilador C2071

"identificador": classe de armazenamento inválido

`identifier` foi declarado com uma [classe de armazenamento](../../c-language/c-storage-classes.md)inválida. Esse erro pode ser causado quando mais de uma classe de armazenamento for especificada para um identificador ou quando a definição for incompatível com a declaração de classe de armazenamento.

Para corrigir esse problema, entenda a classe de armazenamento pretendida do identificador — por exemplo, **`static`** ou **`extern`** — e corrija a declaração para corresponder.

## <a name="examples"></a>Exemplos

O seguinte exemplo gera C2071.

```cpp
// C2071.cpp
// compile with: /c
struct C {
   extern int i;   // C2071
};
struct D {
   int i;   // OK, no extern on an automatic
};
```

O seguinte exemplo gera C2071.

```cpp
// C2071_b.cpp
// compile with: /c
typedef int x(int i) { return i; }   // C2071
typedef int (x)(int);   // OK, no local definition in typedef
```
