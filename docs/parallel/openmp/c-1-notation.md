---
title: "C.1 Notation | Microsoft Docs"
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
ms.assetid: a23b2631-8096-4bf3-ac23-ba4f4bd7a52a
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# C.1 Notation
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As regras gramaticais consistem no nome de um não terminal, seguido de dois pontos, seguido por alternativas de substituição em linhas separadas.  
  
 O termo de expressão sintáticaopt  indica que o termo é opcional dentro de substituição.  
  
 A expressão sintática  *termo*optseq    é equivalente a  *termo\-seq*opt  com as seguintes regras adicionais:  
  
 *termo\-seq* :  
  
 *termo*  
  
 *termo de termo\-seq*  
  
 *termo\-seq* ,  *termo*