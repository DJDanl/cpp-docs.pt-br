---
title: "Macros de recurs&#227;o | Microsoft Docs"
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
  - "Macros , recursão"
  - "programa NMAKE, macros de recursão"
  - "macros de recursão"
ms.assetid: c53e5ae7-619e-46b1-bdc2-86d8c7798b1d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macros de recurs&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use macros de recursão para chamar recursivamente NMAKE.  As sessões recursivos herdam macros de linha de comando e da variável de ambiente e informações de Tools.ini.  Não herdam regras de inferência makefile\-definidas ou **.SUFFIXES** e especificações de **.PRECIOUS** .  Para transmitir macros a uma sessão recursiva de NMAKE, define uma variável de ambiente com SET antes da chamada recursiva, define uma macro no comando da chamada recursiva, ou define uma macro em Tools.ini.  
  
|Macro|Definição|  
|-----------|---------------|  
|**FAÇA**|O comando usado originalmente para invocar NMAKE.<br /><br /> A macro $ \(FAÇA\) fornece o caminho completo para nmake.exe.|  
|**MAKEDIR**|Diretório atual quando NMAKE foi chamado.|  
|**MAKEFLAGS**|Opções atualmente em vigor.  Uso como `/$(MAKEFLAGS)`.  Observe que a, \/F não está incluída.|  
  
## Consulte também  
 [Macros NMAKE especiais](../build/special-nmake-macros.md)