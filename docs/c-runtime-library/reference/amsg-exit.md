---
title: "_amsg_exit | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_amsg_exit"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_amsg_exit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_amsg_exit"
ms.assetid: 146d4faf-d763-43a4-b264-12711196456b
caps.latest.revision: 2
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _amsg_exit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Emite uma mensagem de erro especificada de tempo de execução e sai\-se em seu aplicativo com o código de erro 255.  
  
## Sintaxe  
  
```cpp  
void _amsg_exit (  
   int rterrnum  
   )  
  
```  
  
#### Parâmetros  
 `rterrnum`  
 O número de identificação de uma mensagem de erro definida pelo sistema de tempo de execução.  
  
## Comentários  
 Essa função emite a mensagem de erro de tempo de execução a **stderr** para aplicativos do console, ou exibe\-se a mensagem em uma caixa de mensagem para aplicativos do Windows.  No modo de depuração, você pode escolher para chamar o depurador antes de sair.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|\_amsg\_exit|internal.h|