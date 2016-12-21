---
title: "ML Nonfatal Error A2050 | Microsoft Docs"
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
  - "A2050"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A2050"
ms.assetid: 16f3a58f-4bde-48f1-b0e3-2ed9612780a5
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Nonfatal Error A2050
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**real ou o número de BCD não permitido**  
  
 Um número de ponto flutuante \(real\) ou a constante de binary coded decimal \(BCD\) foi seja usado como um inicializador de dados.  
  
 Ao se um destes procedimentos:  
  
-   Um número real ou um BCD foi usado em uma expressão.  
  
-   Um número real foi usado para inicializar uma diretiva diferente de  [DWORD](../../assembler/masm/dword.md),  [QWORD](../../assembler/masm/qword.md), ou  [TBYTE](../../assembler/masm/tbyte.md).  
  
-   Um BCD foi usado para inicializar uma diretiva diferente de `TBYTE`.  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)