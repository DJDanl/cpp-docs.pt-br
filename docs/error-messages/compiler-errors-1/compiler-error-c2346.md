---
title: Erro do compilador C2346
ms.date: 11/04/2016
f1_keywords:
- C2346
helpviewer_keywords:
- C2346
ms.assetid: 246145be-5645-4cd6-867c-e3bc39e33dca
ms.openlocfilehash: a6d75ca671e22203cb40ca18de21606834eeefa8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50527355"
---
# <a name="compiler-error-c2346"></a>Erro do compilador C2346

'function' não pode ser compilada como nativa: motivo

O compilador não pôde compilar uma função para MSIL.

Para obter mais informações, consulte [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md) e [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md).

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Remova o código na função que não pode ser compilada para MSIL.

1. A não compilar o módulo com **/clr**, ou marcar a função como não gerenciados com o pragma não gerenciado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2346.

```
// C2346.cpp
// processor: x86
// compile with: /clr
// C2346 expected
struct S
{
   S()
   {
      { __asm { nop } }
   }
   virtual __clrcall ~S() { }
};

void main()
{
   S s;
}
```