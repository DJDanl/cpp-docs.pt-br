---
title: Erro do compilador C2346
ms.date: 11/04/2016
f1_keywords:
- C2346
helpviewer_keywords:
- C2346
ms.assetid: 246145be-5645-4cd6-867c-e3bc39e33dca
ms.openlocfilehash: 91f2bac38166a8972193a7aaa7e84913b941c799
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76518316"
---
# <a name="compiler-error-c2346"></a>Erro do compilador C2346

' function ' não pode ser compilado como nativo: Reason

O compilador não pôde compilar uma função para MSIL.

Para obter mais informações, consulte [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md) e [/CLR (compilação em tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md).

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Remova o código na função que não pode ser compilado para MSIL.

1. Não compile o módulo com **/CLR**ou marque a função como não gerenciada com o pragma não gerenciado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2346.

```cpp
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

int main()
{
   S s;
}
```
