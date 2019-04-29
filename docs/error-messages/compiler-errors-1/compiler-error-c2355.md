---
title: Erro do compilador C2355
ms.date: 11/04/2016
f1_keywords:
- C2355
helpviewer_keywords:
- C2355
ms.assetid: 0a947881-d61f-4f98-8409-32140f39500b
ms.openlocfilehash: 80871a73a7c3b4ad04b475539015f85d21ae88b7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62302638"
---
# <a name="compiler-error-c2355"></a>Erro do compilador C2355

'this': só pode ser referenciada dentro de funções de membro não estático ou inicializadores de membro de dados não estáticos

O `this` ponteiro é válido somente dentro de funções de membro não estático ou em inicializadores de membro de dados não estáticos. Esse erro pode resultar quando o escopo de classe de uma definição de função de membro fora da declaração de classe não é qualificado corretamente. O erro também pode ocorrer quando o `this` ponteiro é usado em uma função que não é declarada na classe.

Para corrigir esse problema, verifique se a definição da função de membro corresponde a uma declaração de função de membro na classe, e que ele não está declarado como estático. Inicializadores de membro de dados, verifique se que o membro de dados não está declarado estático.

O exemplo a seguir gera C2355 e mostra como corrigi-lo:

```
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