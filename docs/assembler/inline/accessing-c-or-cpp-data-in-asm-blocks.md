---
title: Acessando dados C ou C++ em blocos __asm
ms.date: 08/30/2018
helpviewer_keywords:
- data members [C++], in __asm blocks
- data access [C++], in __asm blocks
- __asm keyword [C++], data members
- structure types in __asm blocks
ms.assetid: e99f5a28-0381-4090-8ece-6af8f2436a49
ms.openlocfilehash: 1f56cc5c049c1501ea09c76f31be3ab9dea5ed10
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50433053"
---
# <a name="accessing-c-or-c-data-in-asm-blocks"></a>Acessando dados C ou C++ em blocos __asm

**Seção específica da Microsoft**

Uma ótima conveniência do assembly embutido é a capacidade de se referir a variáveis de C ou C++ por nome. Um `__asm` bloco pode se referir a qualquer símbolo, incluindo nomes de variáveis que estão no escopo em que o bloco é exibido. Por exemplo, se a variável de C `var` está no escopo, a instrução

```cpp
__asm mov eax, var
```

armazena o valor do `var` em EAX.

Se uma classe, estrutura ou membro de união tiver um nome exclusivo, uma `__asm` bloco pode se referir a ele usando apenas o nome do membro, sem especificar a variável ou `typedef` nome antes do período (**.**) operador. Se o nome do membro não for exclusivo, no entanto, você deve colocar uma variável ou `typedef` nome imediatamente antes do operador de período. Por exemplo, os tipos de estrutura no compartilhamento de amostra a seguir `same_name` como seu nome de membro:.

Se você declarar variáveis com os tipos

```cpp
struct first_type hal;
struct second_type oat;
```

todas as referências para o membro `same_name` deve usar o nome da variável, pois `same_name` não é exclusivo. Mas o membro `weasel` tem um nome exclusivo, portanto, você pode fazer referência a ele usando apenas seu nome de membro:

```cpp
// InlineAssembler_Accessing_C_asm_Blocks.cpp
// processor: x86
#include <stdio.h>
struct first_type
{
   char *weasel;
   int same_name;
};

struct second_type
{
   int wonton;
   long same_name;
};

int main()
{
   struct first_type hal;
   struct second_type oat;

   __asm
   {
      lea ebx, hal
      mov ecx, [ebx]hal.same_name ; Must use 'hal'
      mov esi, [ebx].weasel       ; Can omit 'hal'
   }
   return 0;
}
```

Observe que omitir o nome da variável é apenas uma conveniência de codificação. As mesmas instruções de assembly são geradas se o nome da variável está presente ou não.

Você pode acessar membros de dados em C++, sem levar em consideração as restrições de acesso. No entanto, você não pode chamar membro funções.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>