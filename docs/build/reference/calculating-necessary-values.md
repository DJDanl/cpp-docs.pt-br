---
title: "Calculando valores necess&#225;rios | Microsoft Docs"
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
  - "funções auxiliares, calculando valores necessários"
ms.assetid: 4f037d0f-881a-4a48-a9d2-9f8872dfccb7
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Calculando valores necess&#225;rios
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Duas informações críticas precisam ser calculados por rotina de auxiliar de atraso.  Com esse fim, há duas funções embutidas em delayhlp.cpp para calcular essas informações.  
  
-   O primeiro calcula o índice de importação atual em três tabelas diferentes \(tabela de endereço \(IAT\) de importação de tabela, endereço \(BIAT\) de importação do limite, e a tabela de endereço desvinculada \(UIAT\) de importação\).  
  
-   O segundo conta o número das importações em um IAT válido.  
  
```  
// utility function for calculating the index of the current import  
// for all the tables (INT, BIAT, UIAT, and IAT).  
__inline unsigned  
IndexFromPImgThunkData(PCImgThunkData pitdCur, PCImgThunkData pitdBase) {  
    return pitdCur - pitdBase;  
    }  
  
// utility function for calculating the count of imports given the base  
// of the IAT. NB: this only works on a valid IAT!  
__inline unsigned  
CountOfImports(PCImgThunkData pitdBase) {  
    unsigned        cRet = 0;  
    PCImgThunkData  pitd = pitdBase;  
    while (pitd->u1.Function) {  
        pitd++;  
        cRet++;  
        }  
    return cRet;  
    }  
```  
  
## Consulte também  
 [Understanding the Helper Function](http://msdn.microsoft.com/pt-br/6279c12c-d908-4967-b0b3-cabfc3e91d3d)