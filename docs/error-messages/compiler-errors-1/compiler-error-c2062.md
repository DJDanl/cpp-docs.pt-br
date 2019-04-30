---
title: Erro do compilador C2062
ms.date: 11/04/2016
f1_keywords:
- C2062
helpviewer_keywords:
- C2062
ms.assetid: 6cc98353-2ddf-43ab-88a2-9cc91cdd6033
ms.openlocfilehash: dcfac9629a90b82744f87ec105c30301b2102cdf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408739"
---
# <a name="compiler-error-c2062"></a>Erro do compilador C2062

tipo 'type' inesperado

O compilador não esperava um nome de tipo.

O exemplo a seguir gera C2062:

```
// C2062.cpp
// compile with: /c
struct A {  : int l; };   // C2062
struct B { private: int l; };   // OK
```

C2062 também pode ocorrer devido à maneira como o compilador identificadores de tipos indefinidos na lista de parâmetros de um construtor. Se o compilador encontrar um tipo de indefinido (incorreta?), ele pressupõe que o construtor é uma expressão e emite C2062. Para resolver, use somente tipos definidos em uma lista de parâmetros do construtor.