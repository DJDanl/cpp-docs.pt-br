---
title: Aviso do compilador (nível 1) C4183
ms.date: 11/04/2016
f1_keywords:
- C4183
helpviewer_keywords:
- C4183
ms.assetid: dc48312c-4b34-44dd-80ff-eb5f11d5ca47
ms.openlocfilehash: 4c2c7ce23cfaea5ebf31e78d84b7ff7fbdbf4c85
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175929"
---
# <a name="compiler-warning-level-1-c4183"></a>Aviso do compilador (nível 1) C4183

' identifier ': tipo de retorno ausente; considerado como uma função membro retornando ' int '

A definição embutida de uma função de membro em uma classe ou estrutura não tem um tipo de retorno. Presume-se que essa função de membro tenha um tipo de retorno padrão de `int`.

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
