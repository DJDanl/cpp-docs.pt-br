---
title: Erro do compilador C2355 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2355
dev_langs:
- C++
helpviewer_keywords:
- C2355
ms.assetid: 0a947881-d61f-4f98-8409-32140f39500b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 456049c60ce39fce3cdbf04512f306027e30db25
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46035182"
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