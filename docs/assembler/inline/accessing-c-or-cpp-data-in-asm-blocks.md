---
title: Acessando dados C ou C++ em blocos __asm
ms.date: 08/30/2018
helpviewer_keywords:
- data members [C++], in __asm blocks
- data access [C++], in __asm blocks
- __asm keyword [C++], data members
- structure types in __asm blocks
ms.assetid: e99f5a28-0381-4090-8ece-6af8f2436a49
ms.openlocfilehash: 8fbe855c2f5de96d81e6c8a27c4bfcee0864f12c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87193036"
---
# <a name="accessing-c-or-c-data-in-__asm-blocks"></a>Acessando dados C ou C++ em blocos __asm

**Específico da Microsoft**

Uma grande conveniência do assembly embutido é a capacidade de se referir a variáveis C ou C++ por nome. Um **`__asm`** bloco pode se referir a quaisquer símbolos, incluindo nomes de variáveis, que estão no escopo em que o bloco é exibido. Por exemplo, se a variável C `var` estiver no escopo, a instrução

```cpp
__asm mov eax, var
```

armazena o valor de `var` em EAX.

Se um membro de classe, estrutura ou União tiver um nome exclusivo, um **`__asm`** bloco poderá referir-se a ele usando apenas o nome do membro, sem especificar a variável ou o **`typedef`** nome antes do operador period (**.**). No entanto, se o nome do membro não for exclusivo, você deverá posicionar uma variável ou um **`typedef`** nome imediatamente antes do operador period. Por exemplo, os tipos de estrutura no seguinte compartilhamento de exemplo `same_name` como seu nome de membro:.

Se você declarar variáveis com os tipos

```cpp
struct first_type hal;
struct second_type oat;
```

todas as referências ao membro `same_name` devem usar o nome da variável porque `same_name` não é exclusivo. Mas o membro `weasel` tem um nome exclusivo, para que você possa consultá-lo usando apenas seu nome de membro:

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

Observe que omitir o nome da variável é meramente uma conveniência de codificação. As mesmas instruções de assembly são geradas independentemente de o nome da variável estar presente ou não.

Você pode acessar os membros de dados em C++ sem considerar as restrições de acesso. No entanto, você não pode chamar funções de membro.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando C ou C++ em blocos de __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>
