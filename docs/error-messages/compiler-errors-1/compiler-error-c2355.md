---
title: Erro do compilador C2355
ms.date: 11/04/2016
f1_keywords:
- C2355
helpviewer_keywords:
- C2355
ms.assetid: 0a947881-d61f-4f98-8409-32140f39500b
ms.openlocfilehash: e44501f7df05a8b277cd52107ff35c4c4d30578f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759939"
---
# <a name="compiler-error-c2355"></a>Erro do compilador C2355

' this ': só pode ser referenciada dentro de funções de membro não estáticas ou inicializadores de membro de dados não estáticos

O ponteiro de `this` é válido somente dentro de funções de membro não estáticas ou em inicializadores de membro de dados não estáticos. Esse erro pode ocorrer quando o escopo de classe de uma definição de função membro fora da declaração de classe não está devidamente qualificado. O erro também pode ocorrer quando o ponteiro de `this` é usado em uma função que não está declarada na classe.

Para corrigir esse problema, verifique se a definição da função membro corresponde a uma declaração de função de membro na classe e se ela não está declarada estática. Para inicializadores de membro de dados, verifique se o membro de dados não está declarado estático.

O exemplo a seguir gera C2355 e mostra como corrigi-lo:

```cpp
// C2355.cpp
// compile with: /c
class MyClass {};
MyClass *p = this;   // C2355

// OK
class MyClass2 {
public:
   void Test() {
      MyClass2 *p = this;
   }
};
```
