---
title: Compilador aviso (nível 4) C4061
ms.date: 11/30/2017
f1_keywords:
- C4061
helpviewer_keywords:
- C4061
ms.assetid: a99cf88e-7941-4519-8b1b-f6889d914b2f
ms.openlocfilehash: 8b730d561134b8b7ca4454ee74f99216fbc72cb4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50453261"
---
# <a name="compiler-warning-level-4-c4061"></a>Compilador aviso (nível 4) C4061

> enumerador '*identificador*'na opção de enumeração'*enumeração*' não é manipulado explicitamente por um rótulo case

O enumerador não tem nenhum manipulador associado um `switch` instrução.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4061; Adicione um caso de enumerador ausente corrigir:

```cpp
// C4061.cpp
// compile with: /W4
#pragma warning(default : 4061)

enum E { a, b, c };
void func ( E e )
{
   switch(e)
   {
      case a:
      case b:
      default:
         break;
   }   // C4061 c' not handled
}

int main()
{
}
```