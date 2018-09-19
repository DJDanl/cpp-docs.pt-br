---
title: Erro do compilador C2346 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2346
dev_langs:
- C++
helpviewer_keywords:
- C2346
ms.assetid: 246145be-5645-4cd6-867c-e3bc39e33dca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5ec916bcdce1a43c597d8cfae10e5393cbeb99ee
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46108606"
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