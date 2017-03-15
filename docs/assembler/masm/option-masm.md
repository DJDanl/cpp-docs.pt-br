---
title: "OPTION (MASM) | Microsoft Docs"
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
  - "option"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "OPTION directive"
ms.assetid: 8e10dabd-e36f-4586-ab01-ada96736b0bd
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# OPTION (MASM)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilita e desabilita recursos do montador.  
  
## Sintaxe  
  
```  
  
OPTION   
optionlist  
  
```  
  
## Comentários  
 Opções disponíveis incluem:  
  
|||||  
|-|-|-|-|  
|**CASEMAP**|**DOTNAME**|**NODOTNAME**|**EMULADOR**|  
|**NOEMULATOR**|**EPÍLOGO**|**EXPR16**|**EXPR32**|  
|**IDIOMA**|**LJMP**|**NOLJMP**|**M510**|  
|**NOM510**|**NOKEYWORD**|**NOSIGNEXTEND**|**DESLOCAMENTO**|  
|**OLDMACROS**|**NOOLDMACROS**|**OLDSTRUCTS**|**NOOLDSTRUCTS**|  
|**PROC**|**PRÓLOGO**|**SOMENTE LEITURA**|**NOREADONLY**|  
|**O ESCOPO**|**NOSCOPED**|**SEGMENTO**|**SETIF2**.|  
  
 A sintaxe de LINGUAGEM é  **opção de LINGUAGEM:***x*, onde  *x* é um dos C, SYSCALL, STDCALL, PASCAL, FORTRAN ou BASIC.  SYSCALL, PASCAL, FORTRAN e BASIC não são compatíveis com usada com [.MODEL](../../assembler/masm/dot-model.md) simples.  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)