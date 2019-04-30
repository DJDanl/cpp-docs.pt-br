---
title: Compilador aviso (nível 1) C4350
ms.date: 11/04/2016
f1_keywords:
- C4350
helpviewer_keywords:
- C4350
ms.assetid: 4cc8ed67-64c4-4da5-a7a5-a639232baa23
ms.openlocfilehash: 8f23751151d8d83c68608d926ef422d56dde41a6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384199"
---
# <a name="compiler-warning-level-1-c4350"></a>Compilador aviso (nível 1) C4350

alteração de comportamento: 'member1' chamado no lugar de 'member2'

Um rvalue não pode ser associado a uma referência não const. Nas versões do Visual C++ anteriores ao Visual Studio 2003, era possível associar um rvalue a uma referência não const em uma inicialização direta. Esse código agora dá um aviso.

Para compatibilidade com versões anteriores, ainda é possível associar rvalues a referências não const, mas conversões padrão são preferenciais sempre que possível.

Esse aviso representa uma alteração de comportamento do compilador do Visual C++ .NET 2002. Se habilitado, este aviso, possivelmente, poderia ser fornecido para o código correto. Por exemplo, ele pode receber ao usar o **std::auto_ptr** modelo de classe.

Se você receber esse aviso, examine o código para ver se ele depende rvalues de associação para referências não const. Adicionando uma constante para a referência ou fornecendo uma sobrecarga adicional de referência const pode resolver o problema.

Esse aviso é desativado por padrão. Para obter mais informações, consulte [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

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