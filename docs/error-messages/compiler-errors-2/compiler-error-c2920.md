---
title: Erro do compilador C2920
ms.date: 11/04/2016
f1_keywords:
- C2920
helpviewer_keywords:
- C2920
ms.assetid: 0a4cb2de-00a0-4209-8160-c7ce6ed7d9ab
ms.openlocfilehash: 2b744729097f7e697c7a7695a849b5ee46d7a4ab
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761026"
---
# <a name="compiler-error-c2920"></a>Erro do compilador C2920

redefinição: ' classe ': template de classe ou genérico já foi declarado como ' type '

Uma classe genérica ou de modelo tem várias declarações, que não são equivalentes. Para corrigir esse erro, use nomes diferentes para tipos diferentes ou remova a redefinição do nome do tipo.

O exemplo a seguir gera C2920 e mostra como corrigi-lo:

```cpp
// C2920.cpp
// compile with: /c
typedef int TC1;
template <class T>
struct TC1 {};   // C2920
struct TC2 {};   // OK - fix by using a different name
```

C2920 também pode ocorrer ao usar genéricos:

```cpp
// C2920b.cpp
// compile with: /clr /c
typedef int GC1;
generic <class T>
ref struct GC1 {};   // C2920
ref struct GC2 {};   // OK - fix by using a different name
```
