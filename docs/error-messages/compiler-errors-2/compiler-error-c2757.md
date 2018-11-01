---
title: Erro do compilador C2757
ms.date: 11/04/2016
f1_keywords:
- C2757
helpviewer_keywords:
- C2757
ms.assetid: 421f102f-8a32-4d47-a109-811ddf2c909d
ms.openlocfilehash: 98b43a2f3c0888fc385226cd80889b9911c84690
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50668514"
---
# <a name="compiler-error-c2757"></a>Erro do compilador C2757

'symbol': um símbolo com este nome já existe e, portanto, esse nome não pode ser usado como um nome de namespace

Um símbolo usado na compilação atual como um identificador de namespace já está sendo usado em um assembly referenciado.

O exemplo a seguir gera C2757:

```
// C2757a.cpp
// compile with: /clr /LD
public ref class Nes {};
```

E, em seguida,

```
// C2757b.cpp
// compile with: /clr /c
#using <C2757a.dll>

namespace Nes {    // C2757
// try the following line instead
// namespace Nes2 {
   public ref class X {};
}
```
