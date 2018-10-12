---
title: Compilador aviso (nível 4) C4127 | Microsoft Docs
ms.custom: ''
ms.date: 09/13/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4127
dev_langs:
- C++
helpviewer_keywords:
- C4127
ms.assetid: f59ded9e-5227-45bd-ac43-2aa861581363
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 80f831d527e918fce0551f6a1336fd2fe994917d
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49161275"
---
# <a name="compiler-warning-level-4-c4127"></a>Compilador aviso (nível 4) C4127

> expressão condicional é constante

## <a name="remarks"></a>Comentários

A expressão de controle de um **se** instrução ou **enquanto** loop for avaliada como uma constante. Devido ao seu uso de expressões idiomática comuns, a partir do Visual Studio 2015 atualização 3, constantes triviais, como 1 ou **verdadeira** não disparam o aviso, a menos que eles são o resultado de uma operação em uma expressão.

Se a expressão de controle de um **enquanto** loop é uma constante, porque o loop é encerrado no meio, considere substituir o **enquanto** loop com um **para** loop. Você pode omitir a inicialização, o teste de encerramento e executar um loop incremento de uma **para** loop, o que faz com que o loop infinito, assim como `while(1)`, e você pode sair do loop do corpo dos **para** instrução.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra duas maneiras de C4127 é gerado e mostra como usar um loop evitar o aviso for:

```cpp
// C4127.cpp
// compile with: /W4
#include <stdio.h>
int main() {
   if (true) {}           // OK in VS2015 update 3 and later
   if (1 == 1) {}         // C4127
   while (42) { break; }  // C4127

   // OK
   for ( ; ; ) {
      printf("test\n");
      break;
   }
}
```