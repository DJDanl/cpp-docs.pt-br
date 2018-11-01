---
title: Erro do compilador C3454
ms.date: 11/04/2016
f1_keywords:
- C3454
helpviewer_keywords:
- C3454
ms.assetid: dc4e6d57-5b4d-4114-8d6f-22f9ae62925b
ms.openlocfilehash: 94c50ccd223567281e02c407e7ee22df75f859d3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50648793"
---
# <a name="compiler-error-c3454"></a>Erro do compilador C3454

[attribute] não permitido em declaração de classe

Uma classe deve ser definida para que ele seja um atributo.

Para obter mais informações, consulte [atributo](../../windows/attributes/attribute.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3454.

```
// C3454.cpp
// compile with: /clr /c
using namespace System;

[attribute]   // C3454
ref class Attr1;

[attribute]   // OK
ref class Attr2 {};
```