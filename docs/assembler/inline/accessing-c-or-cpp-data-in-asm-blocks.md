---
title: Acessando dados C ou C++ em blocos __asm
ms.date: 08/30/2018
helpviewer_keywords:
- data members [C++], in __asm blocks
- data access [C++], in __asm blocks
- __asm keyword [C++], data members
- structure types in __asm blocks
ms.assetid: e99f5a28-0381-4090-8ece-6af8f2436a49
ms.openlocfilehash: b4341f87226118906749dcdb18b9227e68be6a23
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318085"
---
# <a name="accessing-c-or-c-data-in-__asm-blocks"></a>Acessando dados C ou C++ em blocos __asm

**Específico da Microsoft**

Uma grande conveniência da montagem inline é a capacidade de se referir às variáveis C ou C++ pelo nome. Um `__asm` bloco pode se referir a quaisquer símbolos, incluindo nomes de variáveis, que estão no escopo onde o bloco aparece. Por exemplo, se `var` a variável C estiver no escopo, a instrução

```cpp
__asm mov eax, var
```

armazena o `var` valor do in EAX.

Se um membro de classe, estrutura ou `__asm` sindicato tiver um nome único, um bloco pode `typedef` se referir a ele usando apenas o nome do membro, sem especificar a variável ou nome antes do período **(**. ) operador. Se o nome do membro não for único, `typedef` no entanto, você deve colocar uma variável ou nome imediatamente antes do operador de período. Por exemplo, os tipos de `same_name` estrutura na seguinte amostra compartilham como nome de membro:.

Se você declarar variáveis com os tipos

```cpp
struct first_type hal;
struct second_type oat;
```

todas as referências `same_name` ao membro devem `same_name` usar o nome da variável porque não é única. Mas o `weasel` membro tem um nome único, então você pode se referir a ele usando apenas o nome do membro:

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

Observe que omitir o nome da variável é apenas uma conveniência de codificação. As mesmas instruções de montagem são geradas se o nome da variável está ou não presente.

Você pode acessar membros de dados em C++ sem considerar restrições de acesso. No entanto, você não pode chamar funções de membro.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>
