---
title: Erro do compilador C2757 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2757
dev_langs:
- C++
helpviewer_keywords:
- C2757
ms.assetid: 421f102f-8a32-4d47-a109-811ddf2c909d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ff853ad499a9d50cc1c5c168ac13a570453dcba
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46057997"
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
