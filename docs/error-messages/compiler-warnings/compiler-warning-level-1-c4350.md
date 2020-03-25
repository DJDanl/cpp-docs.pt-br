---
title: Aviso do compilador (nível 1) C4350
ms.date: 11/04/2016
f1_keywords:
- C4350
helpviewer_keywords:
- C4350
ms.assetid: 4cc8ed67-64c4-4da5-a7a5-a639232baa23
ms.openlocfilehash: 890ecd4fcec1212fa04a58b0eaab8c2eb4206763
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187213"
---
# <a name="compiler-warning-level-1-c4350"></a>Aviso do compilador (nível 1) C4350

alteração de comportamento: 'member1' chamado no lugar de 'member2'

Um rvalue não pode ser associado a uma referência não const. Em versões do Visual C++ antes do visual Studio 2003, era possível associar um Rvalue a uma referência não const em uma inicialização direta. Esse código agora apresenta um aviso.

Para compatibilidade com versões anteriores, ainda é possível associar rvalues a referências não const, mas as conversões padrão são preferenciais sempre que possível.

Este aviso representa uma alteração de comportamento do compilador do C++ Visual .NET 2002. Se habilitada, esse aviso pode ser fornecido para o código correto. Por exemplo, pode ser dado ao usar o modelo de classe **std:: auto_ptr** .

Se você receber esse aviso, examine seu código para ver se ele depende da Associação de rvalues a referências não const. Adicionar uma const à referência ou fornecer uma sobrecarga de referência const adicional pode resolver o problema.

Esse aviso está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

O exemplo a seguir gera C4350:

```cpp
// C4350.cpp
// compile with: /W1
#pragma warning (default : 4350)
class A {};

class B
{
public:
   B(B&){}
   // try the following instead:
   // B(const B&){}

   B(A){}
   operator A(){ return A();}
};

B source() { return A(); }

int main()
{
   B ap(source());   // C4350
}
```
