---
title: Aviso do compilador (nível 1) C4183
ms.date: 11/04/2016
f1_keywords:
- C4183
helpviewer_keywords:
- C4183
ms.assetid: dc48312c-4b34-44dd-80ff-eb5f11d5ca47
ms.openlocfilehash: cff62c18442cd6d55a9444bb86944b691145b9fe
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231917"
---
# <a name="compiler-warning-level-1-c4183"></a>Aviso do compilador (nível 1) C4183

' identifier ': tipo de retorno ausente; considerado como uma função membro retornando ' int '

A definição embutida de uma função de membro em uma classe ou estrutura não tem um tipo de retorno. Presume-se que essa função de membro tenha um tipo de retorno padrão **`int`** .

O exemplo a seguir gera C4183:

```cpp
// C4183.cpp
// compile with: /W1 /c
#pragma warning(disable : 4430)
class MyClass1;
class MyClass2 {
   MyClass1() {};   // C4183
};
```
