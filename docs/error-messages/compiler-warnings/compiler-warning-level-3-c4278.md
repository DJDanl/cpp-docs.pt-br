---
title: "Aviso do compilador (n&#237;vel 3) C4278 | Microsoft Docs"
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
  - "C4278"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4278"
ms.assetid: 4b6053fb-df62-4c04-b6c8-c011759557b8
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4278
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: o identificador da biblioteca “tlb” do tipo já é uma macro; use “” renomeia o qualificador  
  
 Ao usar [\#import](../Topic/%23import%20Directive%20\(C++\).md), um identificador em typelib que você está importando está tentando declarar um identificador ***identifier***.  Porém, este já for um símbolo válido.  
  
 Use o atributo de `#import`**rename** para atribuir um alias ao símbolo na biblioteca de tipos.