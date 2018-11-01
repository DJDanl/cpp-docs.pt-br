---
title: Compilador aviso (nível 4) C4626
ms.date: 11/04/2016
f1_keywords:
- C4626
helpviewer_keywords:
- C4626
ms.assetid: 7f822ff4-a4a3-4f17-b45b-e8b7b4659a14
ms.openlocfilehash: cb00365d12a60885a86a42417bf1c1052a5c6d6c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50538548"
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