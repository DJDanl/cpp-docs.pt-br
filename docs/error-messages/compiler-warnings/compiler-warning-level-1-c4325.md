---
title: "Aviso do compilador (n&#237;vel 1) C4325 | Microsoft Docs"
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
  - "C4325"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4325"
ms.assetid: 8127a08c-d626-481b-aa7b-04a3fdc9a9ec
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4325
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**attributes for standard section '**   
 ***section* ' ignored**  
  
 Você não pode alterar os atributos de uma seção padrão.  Por exemplo:  
  
```  
#pragma section(".sdata", long)  
```  
  
 Ele substituiria a seção padrão de `.sdata` que usa o tipo de dados de **short** com o tipo de dados **long** .  
  
 Seções padrão cujos atributos que você não pode ser alterado, inclua  
  
-   .data  
  
-   .sdata  
  
-   .bss  
  
-   .sbss  
  
-   .text  
  
-   .const  
  
-   .sconst  
  
-   .rdata  
  
-   .srdata  
  
 As seções adicionais podem ser adicionadas posteriormente.  
  
## Consulte também  
 [section](../../preprocessor/section.md)