---
title: Compilador aviso (nível 4) C4061
ms.date: 04/05/2019
f1_keywords:
- C4061
helpviewer_keywords:
- C4061
ms.assetid: a99cf88e-7941-4519-8b1b-f6889d914b2f
ms.openlocfilehash: 073e3e9cb1cb5bb6b0f66157c986072227960212
ms.sourcegitcommit: 35c4b3478f8cc310ebbd932a18963ad8ab846ed9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/08/2019
ms.locfileid: "59237114"
---
# <a name="compiler-warning-level-4-c4061"></a>Compilador aviso (nível 4) C4061

> enumerador '*identificador*'na opção de enumeração'*enumeração*' não é manipulado explicitamente por um rótulo case

O enumerador especificado *identificador* não tem nenhum manipulador associado em um `switch` instrução que tem um `default` caso. O caso ausente pode ser uma falha ou não pode ser um problema. Ele pode depender se o enumerador é tratado pelo caso padrão ou não. Para um aviso relacionado em enumeradores não utilizados no `switch` instruções que não têm nenhum `default` case, consulte [C4062](compiler-warning-level-4-c4062.md).

Esse aviso é desativado por padrão. Para obter mais informações sobre como habilitar os avisos são desativados por padrão, consulte [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

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

## <a name="see-also"></a>Consulte também

[Compilador aviso (nível 4) C4062](compiler-warning-level-4-c4062.md)
