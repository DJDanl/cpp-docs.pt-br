---
title: "Visão geral do Assembler embutido | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- inline assembler
- __asm keyword [C++], invoking inline assembler
- invoking inline assembler
- inline assembly, inline assembler
ms.assetid: d990331a-0e33-4760-8d7a-b720b0288335
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a58d9fd2dbce875c39c4c0e9af7ae85d5b20f43d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="inline-assembler-overview"></a>Visão geral do assembler embutido
**Seção específica da Microsoft**  
  
 O assembler embutido permite inserir instruções de linguagem de assembly em seus programas de origem C e C++ sem etapas adicionais de assembly e link. O assembler integrado é incorporado ao compilador e, portanto, não é necessário um assembler separado, como o MASM (Microsoft Macro Assembler).  
  
 Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. Código de assembly embutido pode usar qualquer C ou C++ variável ou função nome que está no escopo, portanto, é fácil integrá-lo com o código do programa de C e C++. E porque o código de assembly pode ser combinado com instruções C e C++, ele pode realizar tarefas que são difícil ou impossível em C ou C++ sozinho.  
  
 O [ASM](../../assembler/inline/asm.md) palavra-chave invoca o assembler embutido e pode aparecer sempre que uma instrução de C ou C++ é válida. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo "bloco `__asm`" refere-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.  
  
 O código a seguir é um simples `__asm` bloco entre chaves. (O código é uma sequência personalizada de prólogos da função.)  
  
```  
// asm_overview.cpp  
// processor: x86  
void __declspec(naked) main()  
{  
    // Naked functions must provide their own prolog...  
    __asm {  
        push ebp  
        mov ebp, esp  
        sub esp, __LOCAL_SIZE  
    }  
  
    // ... and epilog  
    __asm {  
        pop ebp  
        ret  
    }  
}  
```  
  
 Como alternativa, você pode colocar `__asm` na frente de cada instrução de assemblies:  
  
```  
__asm push ebp  
__asm mov  ebp, esp  
__asm sub  esp, __LOCAL_SIZE  
```  
  
 Como a palavra-chave `__asm` é um separador de instruções, você também pode colocar instruções de assembly na mesma linha:  
  
```  
__asm push ebp   __asm mov  ebp, esp   __asm sub  esp, __LOCAL_SIZE  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)