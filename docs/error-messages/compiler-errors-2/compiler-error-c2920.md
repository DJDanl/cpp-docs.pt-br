---
title: Erro do compilador C2920
ms.date: 11/04/2016
f1_keywords:
- C2920
helpviewer_keywords:
- C2920
ms.assetid: 0a4cb2de-00a0-4209-8160-c7ce6ed7d9ab
ms.openlocfilehash: 28bbbd30bcb16e2ea5fc14fe0f48f86814ee13c4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50616442"
---
# <a name="compiler-error-c2920"></a>Erro do compilador C2920

redefinição: 'class': classe de modelo ou genérico já foi declarado como 'type'

Uma classe genérica ou modelo tem várias declarações, que não são equivalentes. Para corrigir esse erro, use nomes diferentes para diferentes tipos ou remova a redefinição do nome do tipo.

O exemplo a seguir gera C2920 e mostra como corrigi-lo:

```
// C2920.cpp
// compile with: /c
typedef int TC1;
template <class T>
struct TC1 {};   // C2920
struct TC2 {};   // OK - fix by using a different name
```

C2920 também podem ocorrer ao usar genéricos:

```
// C2920b.cpp
// compile with: /clr /c
typedef int GC1;
generic <class T>
ref struct GC1 {};   // C2920
ref struct GC2 {};   // OK - fix by using a different name
```