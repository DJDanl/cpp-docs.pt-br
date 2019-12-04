---
title: Erro do compilador C3880
ms.date: 11/04/2016
f1_keywords:
- C3880
helpviewer_keywords:
- C3880
ms.assetid: b0e05d1e-32d0-4034-9246-f37d23573ea9
ms.openlocfilehash: 54fd65fb4fe23a5c493a4e9ac83a5e44b0596362
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74736666"
---
# <a name="compiler-error-c3880"></a>Erro do compilador C3880

' var ': não pode ser um membro de dados literal

O tipo de um atributo [literal](../../extensions/literal-cpp-component-extensions.md) deve ser ou conversível em tempo de compilação para, um dos seguintes tipos:

- tipo integral

- string

- enum com um tipo integral ou subjacente

O exemplo a seguir gera C3880:

```cpp
// C3880.cpp
// compile with: /clr /c
ref struct Y1 {
   literal System::Decimal staticConst1 = 10;   // C3880
   literal int staticConst2 = 10;   // OK
};
```
