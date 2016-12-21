---
title: "_lock | Microsoft Docs"
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
  - "_lock"
apilocation: 
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr100.dll"
  - "msvcr90.dll"
  - "msvcr80.dll"
  - "msvcr110.dll"
  - "msvcrt.dll"
  - "msvcr120_clr0400.dll"
apitype: "DLLExport"
f1_keywords: 
  - "lock"
  - "_lock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função lock"
  - "Função _lock"
ms.assetid: 29f77c37-30de-4b3d-91b6-030216e645a6
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _lock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adquire um bloqueio de vários segmento.  
  
> [!IMPORTANT]
>  Esta função é obsoleta. A partir do Visual Studio 2015, ele não está disponível no CRT.  
  
## Sintaxe  
  
```  
void __cdecl _lock  
   int locknum  
);  
```  
  
#### Parâmetros  
 \[in\] `locknum`  
 O identificador de bloqueio para adquirir.  
  
## Comentários  
 Se já tiver sido adquirido o bloqueio, esse método adquire o bloqueio de qualquer forma e causa um erro interno do C Runtime \(CRT\). Se o método não é possível adquirir um bloqueio, ele sai com um erro fatal e define o código de erro `_RT_LOCK`.  
  
## Requisitos  
 **Fonte:** mlock.c  
  
## Consulte também  
 [Referência da função alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [\_unlock](../Topic/_unlock.md)