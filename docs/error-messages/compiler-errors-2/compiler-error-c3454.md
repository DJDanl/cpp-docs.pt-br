---
title: Erro do compilador C3454
ms.date: 11/04/2016
f1_keywords:
- C3454
helpviewer_keywords:
- C3454
ms.assetid: dc4e6d57-5b4d-4114-8d6f-22f9ae62925b
ms.openlocfilehash: 1909dc772413c16d39271dc839a0ec0db206da03
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756676"
---
# <a name="compiler-error-c3454"></a>Erro do compilador C3454

[attribute] não permitido em declaração de classe

Uma classe deve ser definida para ser um atributo.

Para obter mais informações, consulte [atributo](../../windows/attributes/attribute.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3454.

```cpp
// C3454.cpp
// compile with: /clr /c
using namespace System;

[attribute]   // C3454
ref class Attr1;

[attribute]   // OK
ref class Attr2 {};
```
