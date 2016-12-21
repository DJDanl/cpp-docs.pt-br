---
title: "Assembler embutido (C) | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "Palavra-chave __asm [C]"
  - "assembler embutido [C]"
ms.assetid: 821acc77-60b1-434c-ba54-2ba930a25ab4
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assembler embutido (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 O assembler integrado permite inserir instruções da linguagem de assembly diretamente aos seus programas de código\-fonte C sem etapas adicionais de assembly e vinculação.  O assembler integrado é incorporado ao compilador e, portanto, não é necessário um assembler separado, como o MASM \(Microsoft Macro Assembler\).  
  
 Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado.  O código do assembly integrado pode usar qualquer nome de variável ou de função C que esteja no escopo. Portanto, ele é de fácil integração com código C do programa.  E como o código do assembly pode ser combinado com as instruções de C, ele poderá realizar as tarefas que são incômodas ou impossíveis apenas em C.  
  
 A palavra\-chave `__asm` invoca o assembler integrado e pode aparecer sempre que uma declaração C é válida.  Ela não pode aparecer sozinha.  Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves.  O termo "bloco `__asm`" refere\-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.  
  
 O código abaixo é um bloco simples de `__asm` entre chaves. \(O código é uma sequência personalizada de prólogos da função.\)  
  
```  
__asm  
{  
   push ebp  
   mov  ebp, esp  
   sub  esp, __LOCAL_SIZE  
}  
```  
  
 Como alternativa, você pode colocar `__asm` na frente de cada instrução de assemblies:  
  
```  
__asm push ebp  
__asm mov  ebp, esp  
__asm sub  esp, __LOCAL_SIZE  
```  
  
 Como a palavra\-chave `__asm` é um separador de instruções, você também pode colocar instruções de assembly na mesma linha:  
  
```  
__asm push ebp   __asm mov  ebp, esp   __asm sub  esp, __LOCAL_SIZE   
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Atributos de função](../Topic/Function%20Attributes.md)