---
title: Erro do compilador C2062 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2062
dev_langs:
- C++
helpviewer_keywords:
- C2062
ms.assetid: 6cc98353-2ddf-43ab-88a2-9cc91cdd6033
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bbda0894b25e09681207d6447bb40727d490fc02
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46072234"
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