---
title: "EOF, WEOF | Microsoft Docs"
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
  - "EOF"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função EOF"
  - "Função WEOF"
  - "final do arquivo"
ms.assetid: a7150563-cdae-4cdf-9798-ad509990e505
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# EOF, WEOF
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <stdio.h>  
```  
  
## Comentários  
 O EOF será retornado por uma rotina de E\/S quando participante de Arquivo \(ou em alguns casos, um erro é encontrado.\)  
  
 WEOF produz o valor de retorno, do tipo **wint\_t**, usado para sinalizar o final de um fluxo todo o servidor, ou para informar uma condição de erro.  
  
## Consulte também  
 [putc, putwc](../c-runtime-library/reference/putc-putwc.md)   
 [ungetc, ungetwc](../c-runtime-library/reference/ungetc-ungetwc.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [fflush](../Topic/fflush.md)   
 [fclose, \_fcloseall](../c-runtime-library/reference/fclose-fcloseall.md)   
 [\_ungetch, \_ungetwch, \_ungetch\_nolock, \_ungetwch\_nolock](../c-runtime-library/reference/ungetch-ungetwch-ungetch-nolock-ungetwch-nolock.md)   
 [\_putch, \_putwch](../Topic/_putch,%20_putwch.md)   
 [isascii isascii, iswascii](../c-runtime-library/reference/isascii-isascii-iswascii.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)