---
title: "Vis&#227;o geral do assembler embutido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __asm [C++], invocando o assembler embutido"
  - "assembler embutido"
  - "assembly embutido, assembler embutido"
  - "invocando o assembler embutido"
ms.assetid: d990331a-0e33-4760-8d7a-b720b0288335
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vis&#227;o geral do assembler embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 O montador embutido permite a você incorporar instruções de linguagem assembly em seus programas de código\-fonte c e C\+\+ sem etapas adicionais de assembly e o link.  O montador in\-line baseia\-se no compilador — não é necessário um montador separado, como o Microsoft Macro Assembler \(MASM\).  
  
 Como o montador in\-line não requer assembly separado e etapas de link, é mais conveniente que um montador separado.  Código de assembly embutido pode usar qualquer c ou C\+\+ função ou variável de nome que está no escopo, portanto, é fácil de integrá\-lo ao código do seu programa de c e C\+\+.  E porque o código de assembly pode ser misturado com instruções de c e C\+\+, ele pode realizar tarefas que são incômodos ou impossíveis em c ou C\+\+ sozinho.  
  
 O  [\_\_asm](../../assembler/inline/asm.md) palavra\-chave invoca o montador in\-line e pode aparecer sempre que uma declaração de c ou C\+\+ é legal.  Ele não pode aparecer sozinha.  Ele deve ser seguido por uma instrução de assembly, um grupo de instruções entre chaves, ou, na pior das hipóteses, um par de chaves de vazio.  O termo "`__asm` bloco" aqui se refere a qualquer instrução ou o grupo de instruções, ou não entre chaves.  
  
 O código a seguir é uma simples `__asm` bloco entre chaves.  \(O código é uma seqüência de prólogo da função personalizada.\)  
  
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
  
 Como alternativa, você pode colocar `__asm` na frente de cada instrução de montagem:  
  
```  
__asm push ebp   __asm mov  ebp, esp   __asm sub  esp, __LOCAL_SIZE  
```  
  
 Desde que o `__asm` palavra\-chave é um separador de instrução, você também pode colocar instruções assembly na mesma linha:  
  
```  
__asm push ebp  
__asm mov  ebp, esp  
__asm sub  esp, __LOCAL_SIZE  
```  
  
 **Específicos do Microsoft final**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)