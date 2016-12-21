---
title: "Erro fatal U1099 (NMAKE) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "U1099"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1099"
ms.assetid: 6688a805-43e6-4247-a2d0-14be082f0b13
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1099 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

estouro de pilha  
  
 O makefile que está sendo processado era muito complexo da alocação de pilhas atual em NMAKE.  NMAKE tem uma alocação de 0x3000 \(12K\).  
  
 Para aumentar a alocação de pilha de NMAKE, execute o utilitário de [editbin \/stack](../../build/reference/stack.md) com um padrão maior de pilhas:  
  
 **editbin \/STACK:reserve NMAKE.EXE**  
  
 onde *a reserva* é um número maior que a alocação de pilhas atual em NMAKE.