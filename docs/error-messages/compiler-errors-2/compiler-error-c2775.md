---
title: Erro do compilador C2775
ms.date: 11/04/2016
f1_keywords:
- C2775
helpviewer_keywords:
- C2775
ms.assetid: 9c488508-ade0-48f1-b94f-d538d15f807a
ms.openlocfilehash: b0f04a64354f549115c8636cf6130d6e96470016
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50547154"
---
# <a name="compiler-error-c2775"></a>Erro do compilador C2775

'identifier': nenhum método 'get' está associado essa propriedade

Um membro de dados declarado com o [propriedade](../../cpp/property-cpp.md) atributo estendido não tem um `get` função especificada, mas uma expressão tenta recuperar seu valor.

O exemplo a seguir gera C2775:

```
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