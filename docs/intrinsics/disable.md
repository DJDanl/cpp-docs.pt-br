---
title: "_disable | Microsoft Docs"
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
  - "_disable_cpp"
  - "_disable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_disable intrínseca"
  - "Desativar intrínseca"
  - "instrução RSM"
ms.assetid: 52da3df9-815c-4524-9839-6d1742cff5c6
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _disable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Desabilita interrupções.  
  
## Sintaxe  
  
```  
void _disable(void);  
```  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`_disable`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 `_disable` instrui o processador para limpar o sinalizador de interrupção.  Em sistemas x86, essa função gera a instrução Limpar Sinalizador de Interrupção \(`cli`\).  
  
 Essa função só está disponível no modo de kernel.  Se usado no modo de usuário, uma exceção de instrução privilegiada será gerada em tempo de execução.  
  
 Em plataformas ARM, essa rotina só está disponível como um intrínseco.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)