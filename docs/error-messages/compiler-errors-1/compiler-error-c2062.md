---
title: Erro do compilador C2062
ms.date: 11/04/2016
f1_keywords:
- C2062
helpviewer_keywords:
- C2062
ms.assetid: 6cc98353-2ddf-43ab-88a2-9cc91cdd6033
ms.openlocfilehash: a709a540b24756a7e08f98552c5888a55c3ea601
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74735964"
---
# <a name="compiler-error-c2062"></a>Erro do compilador C2062

tipo ' type ' inesperado

O compilador não esperava um nome de tipo.

O exemplo a seguir gera C2062:

```cpp
// C2062.cpp
// compile with: /c
struct A {  : int l; };   // C2062
struct B { private: int l; };   // OK
```

C2062 também pode ocorrer devido à maneira como o compilador manipula tipos indefinidos na lista de parâmetros de um construtor. Se o compilador encontrar um tipo indefinido (com grafia incorreta?), ele assumirá que o construtor é uma expressão e emitirá C2062. Para resolver, use apenas os tipos definidos em uma lista de parâmetros de construtor.
