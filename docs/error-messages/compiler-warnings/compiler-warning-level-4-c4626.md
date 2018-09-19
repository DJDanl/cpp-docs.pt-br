---
title: Compilador aviso (nível 4) C4626 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4626
dev_langs:
- C++
helpviewer_keywords:
- C4626
ms.assetid: 7f822ff4-a4a3-4f17-b45b-e8b7b4659a14
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 16ae3e9d9e54d54a419bfde2250fc02f780e8e54
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46083648"
---
# <a name="compiler-warning-level-4-c4626"></a>Compilador aviso (nível 4) C4626

'derived class': operador de atribuição foi implicitamente definido como excluído como um operador de atribuição de classe base é inacessível ou foi excluído

Um operador de atribuição foi excluído ou não está acessível em uma classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de atribuir objetos desse tipo fará com que um erro do compilador.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4626 e mostra como corrigi-lo:

```
// C4626
// compile with: /W4
#pragma warning(default : 4626)
class B
{
// public:
   B& operator = (const B&)
   {
      return *this;
   }
};

class D : public B
{

}; // C4626 - to fix, make B's copy constructor public

int main()
{
   D m;
   D n;
   // m = n;   // this line will cause an error
}
```