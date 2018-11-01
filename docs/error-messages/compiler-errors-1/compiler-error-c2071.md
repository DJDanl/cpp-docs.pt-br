---
title: Erro do compilador C2071
ms.date: 11/04/2016
f1_keywords:
- C2071
helpviewer_keywords:
- C2071
ms.assetid: f8c09255-a5c4-47e3-8089-3d875ae43cc5
ms.openlocfilehash: 95344b5ef675f566f433dfeaed9dee5c38ef77d4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50598270"
---
# <a name="compiler-error-c2071"></a>Erro do compilador C2071

"identificador": classe de armazenamento inválido

`identifier` foi declarado com um inválido [classe de armazenamento](../../c-language/c-storage-classes.md). Esse erro pode ser causado quando mais de uma classe de armazenamento for especificada para um identificador ou quando a definição for incompatível com a declaração de classe de armazenamento.

Para corrigir esse problema, entenda a classe de armazenamento pretendida do identificador — por exemplo, `static` ou `extern`— e corrija a declaração para corresponder.

## <a name="example"></a>Exemplo

O seguinte exemplo gera C2071.

```
// C2071.cpp
// compile with: /c
struct C {
   extern int i;   // C2071
};
struct D {
   int i;   // OK, no extern on an automatic
};
```

## <a name="example"></a>Exemplo

O seguinte exemplo gera C2071.

```
// C2071_b.cpp
// compile with: /c
typedef int x(int i) { return i; }   // C2071
typedef int (x)(int);   // OK, no local definition in typedef
```