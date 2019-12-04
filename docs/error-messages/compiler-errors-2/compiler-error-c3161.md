---
title: Erro do compilador C3161
ms.date: 11/04/2016
f1_keywords:
- C3161
helpviewer_keywords:
- C3161
ms.assetid: 1fe2be85-a343-487b-8476-bf9e257eb29d
ms.openlocfilehash: 7315dad7959cdd3b950ed814b13be3867399d332
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761810"
---
# <a name="compiler-error-c3161"></a>Erro do compilador C3161

' interface ': aninhar Class, struct, Union ou interface em uma interface é inválida; aninhar interface em uma classe, struct ou Union é inválida

Um [__interface](../../cpp/interface.md) só pode aparecer no escopo global ou em um namespace. Uma classe, struct ou Union não pode aparecer em uma interface.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3161.

```cpp
// C3161.cpp
// compile with: /c
__interface X {
   __interface Y {};   // C3161 A nested interface
};
```
