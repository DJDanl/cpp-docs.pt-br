---
title: Erro do compilador C2688
ms.date: 11/04/2016
f1_keywords:
- C2688
helpviewer_keywords:
- C2688
ms.assetid: 168c9e9d-8f65-4664-af86-db71d3e6ee46
ms.openlocfilehash: cc871467e1e3fb23edc6231c3adb182f5e26c0d8
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760238"
---
# <a name="compiler-error-c2688"></a>Erro do compilador C2688

' C2:: fgrv ': retornos covariantes com múltiplas ou herança virtual sem suporte para funções varargs

Os tipos de retorno covariantes não têm C++ suporte no Visual quando uma função contém argumentos variáveis.

Para resolver esse erro, defina suas funções para que elas não usem argumentos variáveis ou tornem os valores de retorno iguais para todas as funções virtuais.

O exemplo a seguir gera C2688:

```cpp
// C2688.cpp
struct G1 {};
struct G2 {};
struct G3 : G1, G2 {};
struct G4 {};
struct G5 {};
struct G6 : G4, G5 {};
struct G7 : G3, G6 {};

struct C1 {
   virtual G4& fgrv(int,...);
};

struct C2 : C1 {
   virtual G7& fgrv(int,...);   // C2688, does not return G4&
};
```
