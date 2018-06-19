---
title: Acessando dados C ou C++ em blocos ASM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- data members [C++], in __asm blocks
- data access [C++], in __asm blocks
- __asm keyword [C++], data members
- structure types in __asm blocks
ms.assetid: e99f5a28-0381-4090-8ece-6af8f2436a49
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9631db3c09c19e38791a6c909be02acd1c91601b
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32049753"
---
# <a name="accessing-c-or-c-data-in-asm-blocks"></a>Acessando dados C ou C++ em blocos __asm
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Uma ótima conveniência de assembly embutido é a capacidade de fazer referência a variáveis de C ou C++ por nome. Um `__asm` bloco pode se referir a qualquer símbolos, incluindo nomes de variáveis que estão no escopo em que o bloco é exibido. Por exemplo, se a variável de C `var` está no escopo, a instrução  
  
```  
__asm mov eax, var  
```  
  
 armazena o valor de `var` em EAX.  
  
 Se uma classe, estrutura ou membro de união tiver um nome exclusivo, uma `__asm` bloco pode fazer referência a ele usando apenas o nome de membro, sem especificar a variável ou `typedef` nome antes do período (**.**) operador. Se o nome do membro não for exclusivo, no entanto, você deve colocar uma variável ou `typedef` nome imediatamente antes do operador de período. Por exemplo, os tipos de estrutura no compartilhamento de exemplo a seguir `same_name` como seu nome de membro:.  
  
 Se você declarar variáveis com os tipos de  
  
```  
struct first_type hal;  
struct second_type oat;  
```  
  
 todas as referências para o membro `same_name` deve usar o nome da variável, pois `same_name` não é exclusivo. O membro, mas `weasel` tem um nome exclusivo, você pode fazer referência a ele usando seu nome de membro:  
  
```  
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
  
 Observe que omitir o nome da variável é simplesmente uma codificação conveniência. As mesmas instruções assembly são geradas se o nome da variável está presente ou não.  
  
 Você pode acessar membros de dados em C++, independentemente de restrições de acesso. No entanto, você não pode chamar membro funções.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)