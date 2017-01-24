---
title: "Pseudoinstru&#231;&#227;o _emit | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_emit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pseudoinstrução _emit"
  - "definição de byte (assembly embutido)"
ms.assetid: 004c48f3-364c-4e82-9a51-e326f9cc7b2b
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Pseudoinstru&#231;&#227;o _emit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 O pseudoinstruction de **\_emit** define um byte no local atual no segmento de texto atual.  O pseudoinstruction de **\_emit** é semelhante à política de [DB](../../assembler/masm/db.md) de MASM.  
  
 O seguinte fragmento coloca os bytes 0x4A, 0x43, e 0x4B no código:  
  
```  
#define randasm __asm _emit 0x4A __asm _emit 0x43 __asm _emit 0x4B  
 .  
 .  
 .  
__asm {  
     randasm  
     }  
```  
  
> [!CAUTION]
>  Se `_emit` gera instruções que alteram o registros, e cria o aplicativo com otimizações, o compilador não pode determinar quais registros são afetadas.  Por exemplo, se `_emit` gera uma instrução que altere o registro de **rax** , o compilador não sabe que **rax** foi alterado.  O compilador pode então fazer uma suposição incorreta sobre o valor no registro depois que o código de assembler embutido executa.  Portanto, o aplicativo pode exibir o comportamento imprevisível quando executa.  
  
 **Específico da Microsoft de END**  
  
## Consulte também  
 [Usando linguagem de assembly em blocos de \_\_asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)