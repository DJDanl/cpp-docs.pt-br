---
title: Erro do compilador C2803
ms.date: 11/04/2016
f1_keywords:
- C2803
helpviewer_keywords:
- C2803
ms.assetid: 2cdbe374-8cc4-4c4e-ba15-062a7479e937
ms.openlocfilehash: d39f737ba02f3fa9c9d5f61594ddf730db6739a5
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760654"
---
# <a name="compiler-error-c2803"></a>Erro do compilador C2803

' operator Operator ' deve ter pelo menos um parâmetro formal do tipo de classe

O operador sobrecarregado não tem um parâmetro de tipo de classe.

Você precisa passar pelo menos um parâmetro por referência (não usando ponteiros, mas referências) ou por valor para ser capaz de escrever "a < b" (a e b sendo do tipo classe A).

Se ambos os parâmetros forem ponteiros, será uma comparação pura de endereços de ponteiro e não usarão a conversão definida pelo usuário.

O exemplo a seguir gera C2803:

```cpp
// C2803.cpp
// compile with: /c
class A{};
bool operator< (const A *left, const A *right);   // C2803
// try the following line instead
// bool operator< (const A& left, const A& right);
```
