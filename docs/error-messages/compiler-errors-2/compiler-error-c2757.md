---
title: Erro do compilador C2757
ms.date: 11/04/2016
f1_keywords:
- C2757
helpviewer_keywords:
- C2757
ms.assetid: 421f102f-8a32-4d47-a109-811ddf2c909d
ms.openlocfilehash: a9f4661495e0fa5219a517b6f6ca410323a77269
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759523"
---
# <a name="compiler-error-c2757"></a>Erro do compilador C2757

' Symbol ': já existe um símbolo com este nome e, portanto, esse nome não pode ser usado como um nome de namespace

Um símbolo usado na compilação atual como um identificador de namespace já está sendo usado em um assembly referenciado.

O exemplo a seguir gera C2757:

```cpp
// C2757a.cpp
// compile with: /clr /LD
public ref class Nes {};
```

E, em seguida,

```cpp
// C2757b.cpp
// compile with: /clr /c
#using <C2757a.dll>

namespace Nes {    // C2757
// try the following line instead
// namespace Nes2 {
   public ref class X {};
}
```
