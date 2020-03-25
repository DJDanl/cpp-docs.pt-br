---
title: Aviso do compilador (nível 4) C4626
ms.date: 11/04/2016
f1_keywords:
- C4626
helpviewer_keywords:
- C4626
ms.assetid: 7f822ff4-a4a3-4f17-b45b-e8b7b4659a14
ms.openlocfilehash: 665a21d9f0221b2cf3db111142576669a3b5d728
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198258"
---
# <a name="compiler-warning-level-4-c4626"></a>Aviso do compilador (nível 4) C4626

' classe derivada ': o operador de atribuição foi implicitamente definido como excluído porque um operador de atribuição de classe base é inacessível ou excluído

Um operador de atribuição foi excluído ou não está acessível em uma classe base e, portanto, não foi gerado para uma classe derivada. Qualquer tentativa de atribuir objetos desse tipo causará um erro do compilador.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

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
