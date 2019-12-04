---
title: Erro do compilador C2775
ms.date: 11/04/2016
f1_keywords:
- C2775
helpviewer_keywords:
- C2775
ms.assetid: 9c488508-ade0-48f1-b94f-d538d15f807a
ms.openlocfilehash: be858c7508aa520f78ec144b02738af02099b49b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74740046"
---
# <a name="compiler-error-c2775"></a>Erro do compilador C2775

' identifier ': nenhum método ' Get ' está associado a esta propriedade

Um membro de dados declarado com o atributo estendido de [Propriedade](../../cpp/property-cpp.md) não tem uma função `get` especificada, mas uma expressão tenta recuperar seu valor.

O exemplo a seguir gera C2775:

```cpp
// C2775.cpp
struct A {
   __declspec(property(put=PutProp2, get=GetProp2)) int prop2;
   int GetProp2(){return 0;}
   void PutProp2(int){}

   __declspec(property(put=PutProp)) int prop;
   int PutProp(void){}

};

int main() {
   A* pa = new A;
   int x;
   x = pa->prop;   // C2775
   x = pa->prop2;
}
```
